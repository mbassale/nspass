//
// Created by Marco Bassaletti on 27-03-21.
//
#include "../OwnPass.h"
#include "../Group.h"
#include "../query/PasswordQuery.h"
#include "CannotUndoException.h"
#include "ListPasswordsCommand.h"

namespace OwnPass::Commands {
	using OwnPass::Query::PasswordQuery;

	struct PasswordItem {
		ObjectId id;
		std::string_view category_name;
		std::string_view group_name;
		std::string_view username;
		std::string_view url;
		PasswordItem(ObjectId id, std::string_view category_name, std::string_view group_name,
				std::string_view username, std::string_view url)
				:id{ id }, category_name{ category_name }, group_name{ group_name }, username{ username },
				 url{ url } { }
	};

	void ListPasswordsCommand::execute()
	{
		PasswordQuery::QueryArguments args;
		args.category_search = filter.category_filter;
		args.group_search = filter.group_filter;
		args.username = filter.password_filter;
		PasswordQuery password_query{ get_storage(), args };
		auto results = password_query.execute();
		std::vector<PasswordItem> password_items;
		password_items.reserve(results.size());
		for (auto& result_item : results) {
			password_items.emplace_back(result_item.password->get_id(), result_item.category->get_name(),
					result_item.group->get_name(), result_item.password->get_username(),
					result_item.password->get_url());
		}
		std::vector<std::string> headers = { "Category", "Site/App", "Username", "URL" };
		auto out = create_table_output(headers);
		out->print_headers();
		for (auto& password_item : password_items) {
			std::vector<std::string> row = { std::string{ password_item.category_name },
											 std::string{ password_item.group_name },
											 std::string{ password_item.username }, std::string{ password_item.url }};
			out->print_row(row);
		}
	}

	void ListPasswordsCommand::undo()
	{
		throw CannotUndoException();
	}
}
