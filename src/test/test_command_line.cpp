//
// Created by Marco Bassaletti on 17-03-21.
//
#include "catch.hpp"
#include "../Application.h"
#include "../cli/CommandLine.h"
#include "../cli/input/StringSecretInput.h"

using OwnPass::Application;
using OwnPass::CLI::CommandLine;
using OwnPass::CLI::Input::StringSecretInput;

class CommandLineFixture {
public:
	CommandLineFixture() = default;
protected:
	StringSecretInput string_secret_input{ "test1234" };
};

TEST_CASE_METHOD(CommandLineFixture, "CommandLine - construct", "[command line]")
{
	const char* argv[] = {
			"ownpass",
			nullptr
	};
	int argc = 1;

	REQUIRE_NOTHROW(CommandLine{ argc, const_cast<char**>(argv), string_secret_input });
}

TEST_CASE_METHOD(CommandLineFixture, "CommandLine - run command", "[command line]")
{
	const char* argv[] = {
			"ownpass",
			"--help",
			"--verbose",
			"--version",
			nullptr
	};
	int argc = 4;
	CommandLine command_line{ argc, const_cast<char**>(argv), string_secret_input };
	REQUIRE_NOTHROW(command_line.run());
}
