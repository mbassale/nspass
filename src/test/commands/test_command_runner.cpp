//
// Created by Marco Bassaletti on 17-03-21.
//

#include "../catch.hpp"
#include <memory>
#include "../../Application.h"
#include "../../cli/CommandParser.h"
#include "../../commands/CommandRunner.h"

using namespace std;
using OwnPass::Application;
using OwnPass::CLI::CommandParser;
using OwnPass::Commands::CommandRunner;

class CommandRunnerFixture {
public:
	CommandRunnerFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;
};

TEST_CASE_METHOD(CommandRunnerFixture, "CommandRunner - construct", "[command runner]")
{
	const char* argv[] = {
			"ownpass",
			"--help",
			"--verbose",
			"--version",
			nullptr
	};
	int argc = 4;
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	auto& commands = command_parser.get_commands();
	REQUIRE_NOTHROW(CommandRunner{ commands });
}

TEST_CASE_METHOD(CommandRunnerFixture, "CommandRunner - run several commands", "[command runner]")
{
	const char* argv[] = {
			"ownpass",
			"--help",
			"--verbose",
			"--version",
			nullptr
	};
	int argc = 4;
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	auto& commands = command_parser.get_commands();
	CommandRunner command_runner{ commands };
	REQUIRE_NOTHROW(command_runner.run());
	REQUIRE_FALSE(command_runner.get_executed_commands().empty());
	REQUIRE(command_runner.get_executed_commands().size() == 3);
}
