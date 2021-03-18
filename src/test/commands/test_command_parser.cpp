//
// Created by Marco Bassaletti on 18-03-21.
//
#include "../catch.hpp"

#include <typeinfo>
#include "../../Application.h"
#include "../../cli/CommandParser.h"
#include "../../commands/HelpCommand.h"
#include "../../commands/VerboseCommand.h"
#include "../../commands/VersionCommand.h"

using OwnPass::Application;
using OwnPass::CLI::CommandParser;
using namespace std;
using namespace OwnPass::Commands;

class CommandParserFixture {
public:
	CommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;

	void require_type_id(const shared_ptr<Command>& command, const std::type_info& type)
	{
		auto command_ptr = command.get();
		REQUIRE(typeid(*command_ptr) == type);
	}
};

TEST_CASE_METHOD(CommandParserFixture, "CommandParser - constructor", "[command parser]")
{
	const char* argv[] = {
			"ownpass",
			nullptr
	};
	int argc = 1;
	REQUIRE_NOTHROW(CommandParser{ app, argc, const_cast<char**>(argv) });
}

TEST_CASE_METHOD(CommandParserFixture, "CommandParser - help command", "[command parser]")
{
	const char* argv[] = {
			"ownpass",
			"--help",
			nullptr
	};
	int argc = 2;
	REQUIRE_NOTHROW(CommandParser{ app, argc, const_cast<char**>(argv) });
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	auto& commands = command_parser.get_commands();
	REQUIRE(commands.size() == 1);
	require_type_id(command_parser.get_commands().front(), typeid(HelpCommand));
}

TEST_CASE_METHOD(CommandParserFixture, "CommandParser - verbose command", "[command parser]")
{
	const char* argv[] = {
			"ownpass",
			"--verbose",
			nullptr
	};
	int argc = 2;
	REQUIRE_NOTHROW(CommandParser{ app, argc, const_cast<char**>(argv) });
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	auto& commands = command_parser.get_commands();
	REQUIRE(commands.size() == 1);
	require_type_id(command_parser.get_commands().front(), typeid(VerboseCommand));
}

TEST_CASE_METHOD(CommandParserFixture, "CommandParser - version command", "[command parser]")
{
	const char* argv[] = {
			"ownpass",
			"--version",
			nullptr
	};
	int argc = 2;
	REQUIRE_NOTHROW(CommandParser{ app, argc, const_cast<char**>(argv) });
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	auto& commands = command_parser.get_commands();
	REQUIRE(commands.size() == 1);
	require_type_id(command_parser.get_commands().front(), typeid(VersionCommand));
}
