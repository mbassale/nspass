//
// Created by Marco Bassaletti on 27-03-21.
//
#include "CannotUndoException.h"
#include "ListGroupsCommand.h"

namespace OwnPass::Commands {

	void ListGroupsCommand::execute()
	{
		throw std::runtime_error("Not implemented.");
	}

	void ListGroupsCommand::undo()
	{
		throw CannotUndoException();
	}
}
