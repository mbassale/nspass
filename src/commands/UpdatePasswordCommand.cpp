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
		args.category_search = category;
		args.group_search = application.empty() ? site : application;
		args.username = username;
		PasswordQuery password_query{ get_storage(), args };
		auto result = password_query.find_first();
		auto password_to_update = result.password;
		auto secure_password = SecureString::FromPlainText(app.get_vault().get_master_password(), password);
		password_to_update->set_username(username);
		password_to_update->set_password(secure_password);
		password_to_update->set_description(description);
		password_to_update->set_url(url);
		get_storage().flush();
	}

	void UpdatePasswordCommand::undo()
	{
		throw CannotUndoException();
	}
}
