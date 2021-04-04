//
// Created by Marco Bassaletti on 27-03-21.
//

#include <iostream>
#include "CannotUndoException.h"
#include "DumpStorageCommand.h"

namespace NSPass::Commands {
	using namespace std;

	void DumpStorageCommand::execute()
	{
		auto& storage = app.get_vault().get_storage();
		std::cout << storage.dump() << std::endl;
	}

	void DumpStorageCommand::undo()
	{
		throw CannotUndoException();
	}
}
