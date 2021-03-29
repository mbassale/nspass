//
// Created by Marco Bassaletti on 27-03-21.
//
#include "../OwnPass.h"
#include "../Group.h"
#include "../cli/output/TableOutputFactory.h"
#include "CannotUndoException.h"
#include "ListGroupsCommand.h"

namespace OwnPass::Commands {
	using OwnPass::CLI::Output::StreamTableOutputOptions;
	using OwnPass::CLI::Output::TableOutputFactory;

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
		auto& categories = app.get_vault().get_storage().list_categories();
		std::vector<GroupItem> group_items;
		for (auto& category : categories) {
			auto& groups = category.get_groups();
			for (auto& group : groups) {
				group_items.emplace_back(group.get_id(), category.get_name(), group.get_name(),
						group.get_passwords().size());
			}
		}
		StreamTableOutputOptions table_options{ std::cout, ColumnWidth, 0 };
		std::vector<std::string> headers = { "Category", get_group_column_header(), "# Passwords" };
		auto out = TableOutputFactory::create(table_options, headers);
		out.print_headers();
		for (auto& group_item : group_items) {
			std::vector<std::string> row = { std::string{ group_item.category_name }, std::string{ group_item.name },
											 std::to_string(group_item.number_passwords) };
			out.print_row(row);
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
