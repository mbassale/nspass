//
// Created by Marco Bassaletti on 17-03-21.
//
#include "catch.hpp"
#include "../src/Application.h"
#include "../src/cli/CommandLine.h"
#include "../src/cli/input/StringSecretInput.h"
#include "../src/cli/input/BoolConfirmInput.h"

using NSPass::Application;
using NSPass::CLI::CommandLine;
using NSPass::CLI::Input::StringSecretInput;
using NSPass::CLI::Input::BoolConfirmInput;

class CommandLineFixture {
public:
	CommandLineFixture() = default;
protected:
	StringSecretInput string_secret_input{ "test1234" };
	BoolConfirmInput bool_confirm_input{ true };
};

TEST_CASE_METHOD(CommandLineFixture, "CommandLine - construct", "[command line]")
{
	const char* argv[] = {
			"ownpass",
			nullptr
	};
	int argc = 1;

	REQUIRE_NOTHROW(CommandLine{ argc, const_cast<char**>(argv), string_secret_input, bool_confirm_input });
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
	CommandLine command_line{ argc, const_cast<char**>(argv), string_secret_input, bool_confirm_input };
	REQUIRE_NOTHROW(command_line.run());
}
