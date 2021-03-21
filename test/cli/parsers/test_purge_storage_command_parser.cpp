//
// Created by Marco Bassaletti on 21-03-21.
//

#include "../../TestUtility.h"
#include "../../../src/Application.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/commands/PurgeStorageCommand.h"

using namespace std;
using OwnPass::Application;
using OwnPass::CLI::CommandParser;
using OwnPass::Commands::PurgeStorageCommand;

class PurgeStorageCommandParserFixture {
public:
	PurgeStorageCommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;
};

TEST_CASE_METHOD(PurgeStorageCommandParserFixture, "PurgeStorageCommandParser - construct")
{
	const char* argv[] = {
			"ownpass",
			"purge",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));

	CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
	REQUIRE_FALSE(command_parser.get_commands().empty());
	auto command_ptr = command_parser.get_commands().front().get();
	auto purge_command_ptr = dynamic_cast<PurgeStorageCommand*>(command_ptr);
	REQUIRE(purge_command_ptr);
	REQUIRE(purge_command_ptr->get_name() == PurgeStorageCommand::Name);
}
