//
// Created by Marco Bassaletti on 17-03-21.
//

#ifndef OWNPASS_COMMANDRUNNER_H
#define OWNPASS_COMMANDRUNNER_H

#include <utility>

#include "../NSPass.h"
#include "../Application.h"
#include "../commands/Command.h"

namespace NSPass::Commands {
	class CommandRunner {
	public:
		CommandRunner() = default;
		explicit CommandRunner(std::vector<CommandPtr> commands)
				:commands{ std::move(commands) } { }

		void run();
		void run_command(const CommandPtr& command);
		[[nodiscard]] const std::vector<CommandPtr>& get_executed_commands() const { return executed_commands; }

	protected:
		std::vector<CommandPtr> commands;
		std::vector<CommandPtr> executed_commands;
	};
}

#endif //OWNPASS_COMMANDRUNNER_H
