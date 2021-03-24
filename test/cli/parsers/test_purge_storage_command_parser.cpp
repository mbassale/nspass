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
using OwnPass::Commands::CommandPtr;
using OwnPass::Commands::PurgeStorageCommand;

class PurgeStorageCommandParserFixture {
public:
	static constexpr auto Tag = "[purge storage command]";
	PurgeStorageCommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;

	void assertPurgeCommand(const CommandPtr& command_ptr)
	{
		auto purge_command_ptr = dynamic_cast<PurgeStorageCommand*>(command_ptr.get());
		REQUIRE(purge_command_ptr);
		REQUIRE(purge_command_ptr->get_name() == PurgeStorageCommand::Name);
	}

	void assertParsePurgeCommand(int argc, char** argv)
	{
		CommandParser command_parser{ app, argc, argv };
		REQUIRE_FALSE(command_parser.get_commands().empty());
		assertPurgeCommand(command_parser.get_commands().front());
	}
};

TEST_CASE_METHOD(PurgeStorageCommandParserFixture, "PurgeStorageCommandParser - construct",
		PurgeStorageCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"purge",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParsePurgeCommand(argc, const_cast<char**>(argv));
}

TEST_CASE_METHOD(PurgeStorageCommandParserFixture, "PurgeStorageCommandParser - construct 2",
		PurgeStorageCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"--command=purge",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParsePurgeCommand(argc, const_cast<char**>(argv));
}
