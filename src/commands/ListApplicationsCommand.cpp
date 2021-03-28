//
// Created by Marco Bassaletti on 27-03-21.
//
#include "CannotUndoException.h"
#include "ListApplicationsCommand.h"

namespace OwnPass::Commands {

	void ListApplicationsCommand::execute()
	{
		throw std::runtime_error("Not implemented.");
	}

	void ListApplicationsCommand::undo()
	{
		throw CannotUndoException();
	}
}
