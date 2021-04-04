//
// Created by Marco Bassaletti on 01-04-21.
//
#include "../../TestUtility.h"
#include "../../../src/Application.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/commands/ImportLastPassCommand.h"

using namespace std;
using NSPass::Application;
using NSPass::CLI::CommandParser;
using NSPass::Commands::CommandPtr;
using NSPass::Commands::ImportLastPassCommand;

class ImportCommandParserFixture {
public:
	static constexpr auto Tag = "[import command]";
	ImportCommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;

	static void assertImportCommand(const CommandPtr& command_ptr, std::string_view filename)
	{
		auto import_command = dynamic_cast<ImportLastPassCommand*>(command_ptr.get());
		REQUIRE(import_command);
		REQUIRE(import_command->get_name() == ImportLastPassCommand::Name);
		REQUIRE(import_command->requires_master_password());
		REQUIRE(import_command->requires_confirmation());
		REQUIRE(import_command->get_filename() == filename);
	}

	void assertParseImportCommand(int argc, char** argv, std::string_view filename)
	{
		CommandParser command_parser{ app, argc, argv };
		REQUIRE_FALSE(command_parser.get_commands().empty());
		assertImportCommand(command_parser.get_commands().front(), filename);
	}
};

TEST_CASE_METHOD(ImportCommandParserFixture, "ImportCommandParser - construct", ImportCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"import",
			"-flast_pass.csv",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
}

TEST_CASE_METHOD(ImportCommandParserFixture, "ImportCommandParser - parse long option", ImportCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"import",
			"--filename=last_pass.csv",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseImportCommand(argc, const_cast<char**>(argv), "last_pass.csv");
}


TEST_CASE_METHOD(ImportCommandParserFixture, "ImportCommandParser - parse short option", ImportCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"import",
			"-flast_pass.csv",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseImportCommand(argc, const_cast<char**>(argv), "last_pass.csv");
}
