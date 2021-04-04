//
// Created by Marco Bassaletti on 04-04-21.
//
#include "../query/PasswordQuery.h"
#include "DeletePasswordCommand.h"

namespace OwnPass::Commands {
	using OwnPass::Query::PasswordQuery;

	void DeletePasswordCommand::execute()
	{
		PasswordQuery::QueryArguments args;
		args.category_search = filter.category_search;
		args.group_search = filter.site_search;
		args.username = filter.username_search;
		PasswordQuery password_query{ get_storage(), args };
		auto result = password_query.find_first();
		auto& group = result.group;
		auto& password = result.password;
		group->remove_password(password);
		get_storage().flush();
	}

	void DeletePasswordCommand::undo()
	{
		throw CannotUndoException();
	}
}
