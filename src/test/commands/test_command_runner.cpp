//
// Created by Marco Bassaletti on 17-03-21.
//
#include "../catch.hpp"
#include <boost/program_options.hpp>
#include "../../Application.h"
#include "../../CommandLine.h"
#include "../../commands/VersionCommand.h"
#include "../../commands/CommandRunner.h"

using OwnPass::Application;
using OwnPass::CommandLine;
using OwnPass::Commands::VersionCommand;
using OwnPass::Commands::CommandRunner;
namespace po = boost::program_options;

class CommandRunnerFixture {
public:
	CommandRunnerFixture() = default;
};

TEST_CASE_METHOD(CommandRunnerFixture, "CommandRunner - construct", "[command runner]")
{
	po::variables_map vm;
	REQUIRE_NOTHROW((CommandRunner{ Application::instance(), vm }));
}

TEST_CASE_METHOD(CommandRunnerFixture, "CommandRunner - run version command", "[command runner]")
{
	const char* argv[] = {
			"ownpass",
			"--version",
			nullptr
	};
	int argc = 2;
	CommandLine command_line{ argc, const_cast<char**>(argv) };
	auto& vm = command_line.get_variables_map();
	CommandRunner command_runner{ Application::instance(), vm };
	command_runner.run();
	REQUIRE(command_runner.get_executed_commands().size() == 1);
	REQUIRE(command_runner.get_executed_commands().front() == VersionCommand::Name);
}
