//
// Created by Marco Bassaletti on 19-04-21.
//

#include "DeleteGroupCommand.h"

namespace NSPass::Commands {
	using NSPass::Query::GroupQuery;
	using NSPass::Query::GroupQueryItem;

	void DeleteGroupCommand::execute()
	{
		auto result = find_group();
		auto category = result.category;
		auto group = result.group;
		category->remove_group(group);
		get_storage().flush();
		deleted_group = group;
		// invoke signal
		(get_signal_context().get_group_deleted())(group);
	}

	void DeleteGroupCommand::undo()
	{
		throw CannotUndoException();
	}

	GroupQueryItem DeleteGroupCommand::find_group()
	{
		GroupQuery group_query{ get_storage() };
		return group_query.find(group_id);
	}
}
