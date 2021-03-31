//
// Created by Marco Bassaletti on 27-03-21.
//
#include "../OwnPass.h"
#include "../Group.h"
#include "../query/GroupQuery.h"
#include "CannotUndoException.h"
#include "ListGroupsCommand.h"

namespace OwnPass::Commands {
	using OwnPass::Query::GroupQuery;

	struct GroupItem {
		ObjectId id;
		std::string_view category_name;
		std::string_view name;
		size_t number_passwords;
		GroupItem(ObjectId id, std::string_view category_name, std::string_view name, size_t number_passwords)
				:id{ id }, category_name{ category_name }, name{ name }, number_passwords{ number_passwords } { }
	};

	void ListGroupsCommand::execute()
	{
		GroupQuery::QueryArguments args;
		args.search = filter;
		GroupQuery group_query{ app.get_vault().get_storage(), args };
		const auto groups = group_query.execute();
		std::vector<GroupItem> group_items;
		group_items.reserve(groups.size());
		for (const auto& group_item : groups) {
			const auto& category = group_item.category;
			const auto& group = group_item.group;
			group_items.emplace_back(group->get_id(), category->get_name(), group->get_name(),
					group->get_passwords().size());
		}
		std::vector<std::string> headers = { "Category", get_group_column_header(), "# Passwords" };
		auto out = create_table_output(headers);
		out->print_headers();
		for (auto& group_item : group_items) {
			std::vector<std::string> row = { std::string{ group_item.category_name }, std::string{ group_item.name },
											 std::to_string(group_item.number_passwords) };
			out->print_row(row);
		}
	}

	void ListGroupsCommand::undo()
	{
		throw CannotUndoException();
	}

	std::string ListGroupsCommand::get_group_column_header()
	{
		switch (group_type) {
		case GroupType::Group:
			return "Group";
		case GroupType::Site:
			return "Site";
		case GroupType::Application:
			return "Application";
		}
		throw ApplicationException("Invalid group type.");
	}
}
