//
// Created by Marco Bassaletti on 24-03-21.
//
#include "../../TestUtility.h"
#include "../../../src/Application.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/commands/InspectStorageCommand.h"

using namespace std;
using OwnPass::Application;
using OwnPass::CLI::CommandParser;
using OwnPass::Commands::CommandPtr;
using OwnPass::Commands::InspectStorageCommand;

class InspectStorageCommandParserFixture {
public:
	static constexpr auto Tag = "[inspect storage command]";
	InspectStorageCommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;

	void assertInspectCommand(const CommandPtr& command_ptr)
	{
		auto purge_command_ptr = dynamic_cast<InspectStorageCommand*>(command_ptr.get());
		REQUIRE(purge_command_ptr);
		REQUIRE(purge_command_ptr->get_name() == InspectStorageCommand::Name);
		REQUIRE(purge_command_ptr->requires_master_password());
		REQUIRE_FALSE(purge_command_ptr->requires_confirmation());
	}

	void assertParseInspectCommand(int argc, char** argv)
	{
		CommandParser command_parser{ app, argc, argv };
		REQUIRE_FALSE(command_parser.get_commands().empty());
		assertInspectCommand(command_parser.get_commands().front());
	}
};

TEST_CASE_METHOD(InspectStorageCommandParserFixture, "InspectStorageCommandParser - construct",
		InspectStorageCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"inspect",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseInspectCommand(argc, const_cast<char**>(argv));
}

TEST_CASE_METHOD(InspectStorageCommandParserFixture, "InspectStorageCommandParser - construct 2",
		InspectStorageCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"--command=inspect",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseInspectCommand(argc, const_cast<char**>(argv));
}
