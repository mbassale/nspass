//
// Created by Marco Bassaletti on 18-03-21.
//

#include "../../catch.hpp"
#include "../../../src/Application.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/commands/CreateCommand.h"

using namespace std;
using OwnPass::Application;
using OwnPass::CLI::CommandParser;
using OwnPass::Commands::CreateCommand;

class CreateCommandParserFixture {
public:
	CreateCommandParserFixture() : app{ Application::instance() } { }
protected:
	Application& app;
};

TEST_CASE_METHOD(CreateCommandParserFixture, "CreateCommandParser - constructor")
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
	int argc = 8;
	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	REQUIRE_FALSE(command_parser.get_commands().empty());
	auto command_ptr = command_parser.get_commands().front().get();
	auto create_command_ptr = dynamic_cast<CreateCommand*>(command_ptr);
	REQUIRE(create_command_ptr);
	REQUIRE(create_command_ptr->get_name() == CreateCommand::Name);
	REQUIRE(create_command_ptr->get_category() == "Retail");
	REQUIRE(create_command_ptr->get_site() == "Test.com");
	REQUIRE(create_command_ptr->get_username() == "test@test.com");
	REQUIRE(create_command_ptr->get_password() == "test1234");
	REQUIRE(create_command_ptr->get_url() == "test.com");
	REQUIRE(create_command_ptr->get_description() == "\"lorem ipsum dolor senet\"");
}
