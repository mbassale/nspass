//
// Created by Marco Bassaletti on 02-04-21.
//

#include "../query/PasswordQuery.h"
#include "UpdatePasswordCommand.h"

namespace OwnPass::Commands {
	using OwnPass::Query::PasswordQuery;

	void UpdatePasswordCommand::execute()
	{
		PasswordQuery::QueryArguments args;
		args.category_search = filter.category_search;
		args.group_search = filter.application_search.empty() ? filter.site_search : filter.application_search;
		args.username = filter.username_search;
		PasswordQuery password_query{ get_storage(), args };
		auto result = password_query.find_first();
		auto password_to_update = result.password;
		if (update_data.username) {
			password_to_update->set_username(*(update_data.username));
		}
		if (update_data.password) {
			auto secure_password = SecureString::FromPlainText(password_to_update->get_username(),
					*(update_data.password));
			password_to_update->set_password(secure_password);
		}
		if (update_data.description) {
			password_to_update->set_description(*(update_data.description));
		}
		if (update_data.url) {
			password_to_update->set_url(*(update_data.url));
		}
		updated_password = password_to_update;
		get_storage().flush();
	}

	void UpdatePasswordCommand::undo()
	{
		throw CannotUndoException();
	}
}
