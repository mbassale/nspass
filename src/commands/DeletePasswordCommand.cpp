//
// Created by Marco Bassaletti on 04-04-21.
//
#include "../query/PasswordQuery.h"
#include "DeletePasswordCommand.h"

namespace NSPass::Commands {
	using NSPass::Query::PasswordQuery;
	using NSPass::Query::PasswordQueryItem;

	void DeletePasswordCommand::execute()
	{
		PasswordQueryItem result = !password_id.is_nil() ? find_first_password_by_id()
														 : find_first_password_by_filter();
		auto& group = result.group;
		auto& password = result.password;
		group->remove_password(password);
		get_storage().flush();
		// invoke signal
		(get_signal_context().get_password_deleted())(password);
	}

	void DeletePasswordCommand::undo()
	{
		throw CannotUndoException();
	}

	PasswordQueryItem DeletePasswordCommand::find_first_password_by_id()
	{
		PasswordQuery password_query{ get_storage() };
		return password_query.find(password_id);
	}

	PasswordQueryItem DeletePasswordCommand::find_first_password_by_filter()
	{
		PasswordQuery::QueryArguments args;
		args.category_search = filter.category_search;
		args.group_search = filter.site_search;
		args.username = filter.username_search;
		PasswordQuery password_query{ get_storage(), args };
		return password_query.find_first();
	}
}
