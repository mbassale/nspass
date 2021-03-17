//
// Created by Marco Bassaletti on 17-03-21.
//

#ifndef OWNPASS_COMMANDRUNNER_H
#define OWNPASS_COMMANDRUNNER_H

#include <string>
#include <vector>
#include "../Application.h"
#include <boost/program_options.hpp>

namespace OwnPass::Commands {
	class CommandRunner {
	public:
		explicit CommandRunner(const OwnPass::Application& app, const boost::program_options::variables_map& vm)
				:app{ app }, vm{ vm } { }

		void run();
		[[nodiscard]] const std::vector<std::string_view>& get_executed_commands() const { return executed_commands; }

	protected:
		const OwnPass::Application app;
		const boost::program_options::variables_map& vm;
		std::vector<std::string_view> executed_commands;

		void run_version_command();
	};
}

#endif //OWNPASS_COMMANDRUNNER_H
