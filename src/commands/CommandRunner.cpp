//
// Created by Marco Bassaletti on 17-03-21.
//

#include "VersionCommand.h"
#include "CommandRunner.h"

namespace OwnPass::Commands {

	void CommandRunner::run()
	{
		if (vm.count("version")) {
			run_version_command();
		}
	}

	void CommandRunner::run_version_command()
	{
		VersionCommand version_command{ app };
		version_command.execute();
		executed_commands.push_back(version_command.get_name());
	}
}
