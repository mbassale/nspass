//
// Created by Marco Bassaletti on 18-03-21.
//

#include "../../TestUtility.h"
#include "../../../src/Application.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/cli/InvalidCommandSyntaxException.h"
#include "../../../src/commands/HelpCommand.h"
#include "../../../src/commands/CreatePasswordCommand.h"

using namespace std;
using OwnPass::Application;
using OwnPass::Category;
using OwnPass::CLI::CommandParser;
using OwnPass::CLI::InvalidCommandSyntaxException;
using OwnPass::Commands::HelpCommand;
using OwnPass::Commands::CreatePasswordCommand;

class CreateCommandParserFixture {
public:
	static constexpr auto Tag = "[create password command]";
	CreateCommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;
};

TEST_CASE_METHOD(CreateCommandParserFixture, "CreateCommandParser - invalid command", CreateCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"create",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_THROWS_AS((CommandParser{ app, argc, const_cast<char**>(argv) }), InvalidCommandSyntaxException);
}

TEST_CASE_METHOD(CreateCommandParserFixture, "CreateCommandParser - help", CreateCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"create",
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

TEST_CASE_METHOD(CreateCommandParserFixture, "CreateCommandParser - create password with full arguments",
		CreateCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"create",
			"--category=Retail",
			"--site=Test.com",
			"--username=test@test.com",
			"--password=test1234",
			"--url=test.com",
			"--description=\"lorem ipsum dolor senet\"",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	REQUIRE_FALSE(command_parser.get_commands().empty());
	auto command_ptr = command_parser.get_commands().front().get();
	auto create_command_ptr = dynamic_cast<CreatePasswordCommand*>(command_ptr);
	REQUIRE(create_command_ptr);
	REQUIRE(create_command_ptr->get_name() == CreatePasswordCommand::Name);
	REQUIRE(create_command_ptr->get_category() == "Retail");
	REQUIRE(create_command_ptr->get_site() == "Test.com");
	REQUIRE(create_command_ptr->get_username() == "test@test.com");
	REQUIRE(create_command_ptr->get_password() == "test1234");
	REQUIRE(create_command_ptr->get_url() == "test.com");
	REQUIRE(create_command_ptr->get_description() == "\"lorem ipsum dolor senet\"");
}

TEST_CASE_METHOD(CreateCommandParserFixture, "CreateCommandParser - create site password with minimal arguments",
		CreateCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"create",
			"--site=Test.com",
			"--username=test@test.com",
			"--password=test1234",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	REQUIRE_FALSE(command_parser.get_commands().empty());
	auto command_ptr = command_parser.get_commands().front().get();
	auto create_command_ptr = dynamic_cast<CreatePasswordCommand*>(command_ptr);
	REQUIRE(create_command_ptr);
	REQUIRE(create_command_ptr->get_name() == CreatePasswordCommand::Name);
	REQUIRE(create_command_ptr->get_category() == Category::DefaultName);
	REQUIRE(create_command_ptr->get_site() == "Test.com");
	REQUIRE(create_command_ptr->get_username() == "test@test.com");
	REQUIRE(create_command_ptr->get_password() == "test1234");
}

TEST_CASE_METHOD(CreateCommandParserFixture, "CreateCommandParser - create application password with minimal arguments",
		CreateCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"create",
			"--application=TestApp",
			"--username=test@test.com",
			"--password=test1234",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	REQUIRE_FALSE(command_parser.get_commands().empty());
	auto command_ptr = command_parser.get_commands().front().get();
	auto create_command_ptr = dynamic_cast<CreatePasswordCommand*>(command_ptr);
	REQUIRE(create_command_ptr);
	REQUIRE(create_command_ptr->get_name() == CreatePasswordCommand::Name);
	REQUIRE(create_command_ptr->get_category() == Category::DefaultName);
	REQUIRE(create_command_ptr->get_application() == "TestApp");
	REQUIRE(create_command_ptr->get_username() == "test@test.com");
	REQUIRE(create_command_ptr->get_password() == "test1234");
}
