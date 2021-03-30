//
// Created by Marco Bassaletti on 30-03-21.
//

#include "../OwnPass.h"
#include "../../clip/clip.h"
#include "CannotUndoException.h"
#include "CopyPasswordCommand.h"

namespace OwnPass::Commands {

	void CopyPasswordCommand::execute()
	{
		clip::set_text("Hello world!");
		std::string value;
		clip::get_text(value);
		std::cout << "Clipboard: " << value << std::endl;
	}

	void CopyPasswordCommand::undo()
	{
		throw CannotUndoException();
	}
}
