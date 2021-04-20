//
// Created by Marco Bassaletti on 19-04-21.
//

#include "../query/CategoryQuery.h"
#include "CreateGroupCommand.h"

namespace NSPass::Commands {
	using NSPass::Query::CategoryQuery;

	void CreateGroupCommand::execute()
	{
		auto category = find_category();
		auto group = GroupFactory::make_group(create_data.name, create_data.url, create_data.description);
		category->add_group(group);
		get_storage().flush();
		created_group = group;
		// invoke signal
		(get_signal_context().get_group_created())(group);
	}

	void CreateGroupCommand::undo()
	{
		throw CannotUndoException();
	}

	CategoryPtr CreateGroupCommand::find_category()
	{
		CategoryQuery category_query{ get_storage() };
		return category_query.find(create_data.category_id);
	}
}
