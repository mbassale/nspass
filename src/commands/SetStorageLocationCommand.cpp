//
// Created by Marco Bassaletti on 27-03-21.
//

#include "CannotUndoException.h"
#include "SetStorageLocationCommand.h"

namespace NSPass::Commands {
	void SetStorageLocationCommand::execute()
	{
		app.get_vault().set_storage_location(storage_location);
	}

	void SetStorageLocationCommand::undo()
	{
		throw CannotUndoException();
	}
}
