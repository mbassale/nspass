//
// Created by Marco Bassaletti on 18-03-21.
//

#include "../TestUtility.h"
#include "../../src/Application.h"
#include "../../src/cli/CommandParser.h"
#include "../../src/commands/HelpCommand.h"
#include "../../src/commands/VerboseCommand.h"
#include "../../src/commands/VersionCommand.h"
#include "../../src/commands/SetStorageLocationCommand.h"

using NSPass::Application;
using NSPass::CLI::CommandParser;
using namespace std;
using namespace NSPass::Commands;

class CommandParserFixture {
public:
	CommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;

	static void require_type_id(const shared_ptr<Command>& command, const std::type_info& type)
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
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW(CommandParser{ app, argc, const_cast<char**>(argv) });
}

TEST_CASE_METHOD(CommandParserFixture, "CommandParser - help command", "[command parser]")
{
	const char* argv[] = {
			"ownpass",
			"--help",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
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
	int argc = TestUtility::get_argc(argv);
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
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW(CommandParser{ app, argc, const_cast<char**>(argv) });
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	auto& commands = command_parser.get_commands();
	REQUIRE(commands.size() == 1);
	require_type_id(command_parser.get_commands().front(), typeid(VersionCommand));
}

TEST_CASE_METHOD(CommandParserFixture, "CommandParser - storage command", "[command parser]") {
	const char* argv[] = {
			"ownpass",
			"--storage=test.db",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW(CommandParser{ app, argc, const_cast<char**>(argv)});
	CommandParser command_parser{ app, argc, const_cast<char**>(argv)};
	auto& commands = command_parser.get_commands();
	REQUIRE(commands.size() == 1);
	require_type_id(command_parser.get_commands().front(), typeid(SetStorageLocationCommand));
}
