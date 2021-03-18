//
// Created by Marco Bassaletti on 17-03-21.
//

#ifndef OWNPASS_COMMANDRUNNER_H
#define OWNPASS_COMMANDRUNNER_H

#include <memory>
#include <string>
#include <vector>
#include "../Application.h"
#include "../commands/Command.h"

namespace OwnPass::Commands {
	class CommandRunner {
	public:
		explicit CommandRunner(const std::vector<std::shared_ptr<OwnPass::Commands::Command>>& commands)
				:commands{ commands } { }

		void run();
		[[nodiscard]] const std::vector<std::shared_ptr<OwnPass::Commands::Command>>& get_executed_commands() const { return executed_commands; }

	protected:
		const std::vector<std::shared_ptr<OwnPass::Commands::Command>>& commands;
		std::vector<std::shared_ptr<OwnPass::Commands::Command>> executed_commands;
	};
}

#endif //OWNPASS_COMMANDRUNNER_H
