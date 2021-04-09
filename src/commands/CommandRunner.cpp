//
// Created by Marco Bassaletti on 17-03-21.
//

#include "VersionCommand.h"
#include "CommandRunner.h"

namespace NSPass::Commands {

	void CommandRunner::run()
	{
		for (auto& command_ptr : commands) {
			command_ptr->execute();
			executed_commands.push_back(command_ptr);
		}
	}

	void CommandRunner::run_command(const CommandPtr& command)
	{
		command->execute();
		executed_commands.push_back(command);
	}
}
