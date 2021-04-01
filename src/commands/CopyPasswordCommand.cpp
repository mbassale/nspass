//
// Created by Marco Bassaletti on 30-03-21.
//

#include "../OwnPass.h"
#include "../../clip/clip.h"
#include "../query/PasswordQuery.h"
#include "CopyPasswordCommand.h"

namespace OwnPass::Commands {
	using OwnPass::Query::PasswordQuery;

	void CopyPasswordCommand::execute()
	{
		auto password_obj = find_first_password();
		copied_password = password_obj;
		auto& password_str = password_obj->get_password();
		auto password = password_str.get_plain_text(password_obj->get_username());
		clip::set_text(password);
	}

	void CopyPasswordCommand::undo()
	{
		clip::set_text("");
	}

	PasswordPtr CopyPasswordCommand::find_first_password()
	{
		PasswordQuery::QueryArguments args;
		args.category_search = category_filter;
		args.group_search = group_filter;
		args.username = password_filter;

		PasswordQuery password_query{ app.get_storage(), args };
		auto passwords = password_query.execute();
		if (passwords.empty()) {
			throw ApplicationException("Password not found.");
		}

		return passwords.front();
	}
}
