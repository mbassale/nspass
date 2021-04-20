//
// Created by Marco Bassaletti on 20-04-21.
//

#include "CreateCategoryCommand.h"

namespace NSPass::Commands {

	void CreateCategoryCommand::execute()
	{
		auto category = CategoryFactory::make(name);
		get_storage().save_category(category);
		get_storage().flush();
		created_category = category;
		// invoke signal
		(get_signal_context().get_category_created())(category);
	}

	void CreateCategoryCommand::undo()
	{
		throw CannotUndoException();
	}
}
