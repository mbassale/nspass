//
// Created by Marco Bassaletti on 17-03-21.
//

#ifndef OWNPASS_COMMANDRUNNER_H
#define OWNPASS_COMMANDRUNNER_H

#include "../OwnPass.h"
#include "../Application.h"
#include "../commands/Command.h"

namespace OwnPass::Commands {
	class CommandRunner {
	public:
		explicit CommandRunner(const std::vector<CommandPtr>& commands)
				:commands{ commands } { }

		void run();
		[[nodiscard]] const std::vector<CommandPtr>& get_executed_commands() const { return executed_commands; }

	protected:
		const std::vector<CommandPtr>& commands;
		std::vector<CommandPtr> executed_commands;
	};
}

#endif //OWNPASS_COMMANDRUNNER_H
