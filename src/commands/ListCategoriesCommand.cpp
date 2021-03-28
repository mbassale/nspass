//
// Created by Marco Bassaletti on 27-03-21.
//
#include "CannotUndoException.h"
#include "ListCategoriesCommand.h"

namespace OwnPass::Commands {

	void ListCategoriesCommand::execute()
	{
		throw std::runtime_error("Not implemented.");
	}

	void ListCategoriesCommand::undo()
	{
		throw CannotUndoException();
	}
}
