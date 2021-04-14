//
// Created by Marco Bassaletti on 02-04-21.
//

#include "../query/PasswordQuery.h"
#include "UpdatePasswordCommand.h"

namespace NSPass::Commands {
	using NSPass::Query::PasswordQuery;

	void UpdatePasswordCommand::execute()
	{
		PasswordPtr password_to_update;
		if (!password_id.is_nil()) {
			password_to_update = find_first_password_by_id();
		}
		else {
			password_to_update = find_first_password_by_filter();
		}
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
		// invoke signal
		app.get_signal_context().get_password_updated().invoke(password_to_update);
	}

	void UpdatePasswordCommand::undo()
	{
		throw CannotUndoException();
	}

	PasswordPtr UpdatePasswordCommand::find_first_password_by_id()
	{
		PasswordQuery password_query{ get_storage() };
		auto result = password_query.find(password_id);
		return result.password;
	}

	PasswordPtr UpdatePasswordCommand::find_first_password_by_filter()
	{
		PasswordQuery::QueryArguments args;
		args.category_search = filter.category_search;
		args.group_search = filter.application_search.empty() ? filter.site_search : filter.application_search;
		args.username = filter.username_search;
		PasswordQuery password_query{ get_storage(), args };
		auto result = password_query.find_first();
		return result.password;
	}
}
