//
// Created by Marco Bassaletti on 18-03-21.
//

#include "VerboseCommand.h"

namespace NSPass::Commands {

	void VerboseCommand::execute()
	{
		app.config(Application::LogMode::VERBOSE);
	}

	void VerboseCommand::undo()
	{
		app.config(Application::LogMode::NORMAL);
	}
}
