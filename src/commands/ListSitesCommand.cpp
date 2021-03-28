//
// Created by Marco Bassaletti on 27-03-21.
//
#include "CannotUndoException.h"
#include "ListSitesCommand.h"

namespace OwnPass::Commands {

	void ListSitesCommand::execute()
	{
		throw std::runtime_error("Not implemented.");
	}

	void ListSitesCommand::undo()
	{
		throw CannotUndoException();
	}
}
