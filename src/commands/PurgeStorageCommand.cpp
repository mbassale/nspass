//
// Created by Marco Bassaletti on 21-03-21.
//

#include "PurgeStorageCommand.h"

namespace OwnPass::Commands {

	void PurgeStorageCommand::execute()
	{
		auto& storage = app.get_vault().get_storage();
		storage.purge();
	}

	void PurgeStorageCommand::undo()
	{
		throw CannotUndoException();
	}
}
