//
// Created by Marco Bassaletti on 17-03-21.
//

#include "VersionCommand.h"
#include "CommandRunner.h"

namespace OwnPass::Commands {

	void CommandRunner::run()
	{
		for (auto& command_ptr : commands) {
			command_ptr->execute();
			executed_commands.push_back(command_ptr);
		}
	}
}
