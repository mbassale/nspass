//
// Created by Marco Bassaletti on 01-04-21.
//
#include "../../TestUtility.h"
#include "../../../src/Application.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/cli/InvalidCommandSyntaxException.h"
#include "../../../src/commands/HelpCommand.h"
#include "../../../src/commands/CopyPasswordCommand.h"

using namespace std;
using OwnPass::Application;
using OwnPass::Category;
using OwnPass::CLI::CommandParser;
using OwnPass::CLI::InvalidCommandSyntaxException;
using OwnPass::Commands::HelpCommand;
using OwnPass::Commands::CopyPasswordCommand;

class CopyPasswordCommandParserFixture {
public:
	static constexpr auto Tag = "[copy password command parser]";
	CopyPasswordCommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;
};

TEST_CASE_METHOD(CopyPasswordCommandParserFixture, "CopyPasswordCommandParser - invalid command, missing required argument",
		CopyPasswordCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"copy",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_THROWS_AS((CommandParser{ app, argc, const_cast<char**>(argv) }), InvalidCommandSyntaxException);
}

TEST_CASE_METHOD(CopyPasswordCommandParserFixture, "CopyPasswordCommandParser - help",
		CopyPasswordCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"copy",
			"-h",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	auto& commands = command_parser.get_commands();
	REQUIRE_FALSE(commands.empty());
	auto command_ptr = command_parser.get_commands().front().get();
	auto help_command_ptr = dynamic_cast<HelpCommand*>(command_ptr);
	REQUIRE(help_command_ptr);
	REQUIRE_NOTHROW(help_command_ptr->execute());
}

TEST_CASE_METHOD(CopyPasswordCommandParserFixture, "CopyPasswordCommandParser - long options",
		CopyPasswordCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"copy",
			"--category=category #5",
			"--site=group #2",
			"--username=user5_2_4",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	auto& commands = command_parser.get_commands();
	REQUIRE_FALSE(commands.empty());
	auto command_ptr = command_parser.get_commands().front().get();
	auto copy_password_command = dynamic_cast<CopyPasswordCommand*>(command_ptr);
	REQUIRE(copy_password_command);
	REQUIRE(copy_password_command->get_name() == CopyPasswordCommand::Name);
	REQUIRE(copy_password_command->get_category_filter() == "category #5");
	REQUIRE(copy_password_command->get_group_filter() == "group #2");
	REQUIRE(copy_password_command->get_password_filter() == "user5_2_4");
}

TEST_CASE_METHOD(CopyPasswordCommandParserFixture, "CopyPasswordCommandParser - short options",
		CopyPasswordCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"copy",
			"-ccategory #5",
			"-sgroup #2",
			"-uuser5_2_4",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	auto& commands = command_parser.get_commands();
	REQUIRE_FALSE(commands.empty());
	auto command_ptr = command_parser.get_commands().front().get();
	auto copy_password_command = dynamic_cast<CopyPasswordCommand*>(command_ptr);
	REQUIRE(copy_password_command);
	REQUIRE(copy_password_command->get_name() == CopyPasswordCommand::Name);
	REQUIRE(copy_password_command->get_category_filter() == "category #5");
	REQUIRE(copy_password_command->get_group_filter() == "group #2");
	REQUIRE(copy_password_command->get_password_filter() == "user5_2_4");
}
