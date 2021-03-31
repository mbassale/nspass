//
// Created by Marco Bassaletti on 27-03-21.
//
#include "../OwnPass.h"
#include "../Group.h"
#include "CannotUndoException.h"
#include "ListPasswordsCommand.h"

namespace OwnPass::Commands {
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
		auto& categories = app.get_vault().get_storage().get_categories();
		std::vector<PasswordItem> password_items;
		for (auto& category : categories) {
			auto& groups = category->get_groups();
			for (auto& group : groups) {
				auto& passwords = group->get_passwords();
				for (auto& password : passwords) {
					password_items.emplace_back(password->get_id(), category->get_name(), group->get_name(),
							password->get_username(), password->get_url());
				}
			}
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
