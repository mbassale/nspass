//
// Created by Marco Bassaletti on 27-03-21.
//
#include "../../TestUtility.h"
#include "../../../src/Application.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/commands/DumpStorageCommand.h"

using namespace std;
using OwnPass::Application;
using OwnPass::CLI::CommandParser;
using OwnPass::Commands::CommandPtr;
using OwnPass::Commands::DumpStorageCommand;

class DumpStorageCommandParserFixture {
public:
	static constexpr auto Tag = "[dump storage command]";
	DumpStorageCommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;

	static void assertDumpCommand(const CommandPtr& command_ptr)
	{
		auto p_dump_storage_command = dynamic_cast<DumpStorageCommand*>(command_ptr.get());
		REQUIRE(p_dump_storage_command);
		REQUIRE(p_dump_storage_command->get_name() == DumpStorageCommand::Name);
		REQUIRE(p_dump_storage_command->requires_master_password());
		REQUIRE(p_dump_storage_command->requires_confirmation());
	}

	void assertParseDumpCommand(int argc, char** argv)
	{
		CommandParser command_parser{ app, argc, argv };
		REQUIRE_FALSE(command_parser.get_commands().empty());
		assertDumpCommand(command_parser.get_commands().front());
	}
};

TEST_CASE_METHOD(DumpStorageCommandParserFixture, "DumpStorageCommandParser - construct",
		DumpStorageCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"dump",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseDumpCommand(argc, const_cast<char**>(argv));
}

TEST_CASE_METHOD(DumpStorageCommandParserFixture, "DumpStorageCommandParser - construct 2",
		DumpStorageCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"--command=dump",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseDumpCommand(argc, const_cast<char**>(argv));
}
