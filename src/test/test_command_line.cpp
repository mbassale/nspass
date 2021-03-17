//
// Created by Marco Bassaletti on 17-03-21.
//
#include "catch.hpp"
#include "../Application.h"
#include "../CommandLine.h"
#include "../commands/VersionCommand.h"

using OwnPass::Application;
using OwnPass::CommandLine;
using OwnPass::Commands::VersionCommand;

class CommandLineFixture {
public:
	CommandLineFixture() = default;
};

TEST_CASE_METHOD(CommandLineFixture, "CommandLine - construct", "[command line]")
{
	const char* argv[] = {
			"ownpass",
			nullptr
	};
	int argc = 1;
	REQUIRE_NOTHROW(CommandLine{ argc, const_cast<char**>(argv) });
}

TEST_CASE_METHOD(CommandLineFixture, "CommandLine - run command", "[command line]")
{
	const char* argv[] = {
			"ownpass",
			"--version",
			nullptr
	};
	int argc = 2;
	CommandLine command_line{ argc, const_cast<char**>(argv) };
	REQUIRE_FALSE(command_line.get_variables_map().empty());
	REQUIRE(command_line.get_variables_map().count("version") > 0);
	REQUIRE_NOTHROW(command_line.run());
	REQUIRE(command_line.get_executed_commands().size() == 1);
	REQUIRE(command_line.get_executed_commands().front() == VersionCommand::Name);
}
