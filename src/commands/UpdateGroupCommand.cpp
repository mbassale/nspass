//
// Created by Marco Bassaletti on 12-04-21.
//

#include "../query/GroupQuery.h"
#include "UpdateGroupCommand.h"

namespace NSPass::Commands {
	using NSPass::Query::GroupQuery;

	void UpdateGroupCommand::execute()
	{
		GroupPtr group_to_update = find_first_group_by_id();
		if (update_data.name) {
			group_to_update->set_name(*(update_data.name));
		}
		if (update_data.description) {
			group_to_update->set_description(*(update_data.description));
		}
		if (update_data.url) {
			group_to_update->set_url(*(update_data.url));
		}
		updated_group = group_to_update;
		get_storage().flush();
		// invoke signal
		app.get_signal_context().get_group_updated().invoke(group_to_update);
	}

	void UpdateGroupCommand::undo()
	{
		throw CannotUndoException();
	}

	GroupPtr UpdateGroupCommand::find_first_group_by_id()
	{
		GroupQuery group_query{ get_storage() };
		auto result = group_query.find(group_id);
		return result.group;
	}
}
