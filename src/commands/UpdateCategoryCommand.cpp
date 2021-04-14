//
// Created by Marco Bassaletti on 13-04-21.
//
#include "../query/CategoryQuery.h"
#include "UpdateCategoryCommand.h"

namespace NSPass::Commands {
	using NSPass::Query::CategoryQuery;

	void UpdateCategoryCommand::execute()
	{
		auto category = find_first_category_by_id();
		if (update_data.name) {
			category->set_name(*(update_data.name));
		}
		updated_category = category;
		get_storage().flush();
		(get_signal_context().get_category_updated())(category);
	}

	void UpdateCategoryCommand::undo()
	{
		throw CannotUndoException();
	}

	CategoryPtr UpdateCategoryCommand::find_first_category_by_id()
	{
		CategoryQuery category_query{ get_storage() };
		return category_query.find(category_id);
	}

}
