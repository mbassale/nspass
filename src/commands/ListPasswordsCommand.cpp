//
// Created by Marco Bassaletti on 27-03-21.
//
#include "CannotUndoException.h"
#include "ListPasswordsCommand.h"

namespace OwnPass::Commands {

	void ListPasswordsCommand::execute()
	{
		throw std::runtime_error("Not implemented.");
	}

	void ListPasswordsCommand::undo()
	{
		throw CannotUndoException();
	}
}
