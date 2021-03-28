//
// Created by Marco Bassaletti on 27-03-21.
//
#include "../../TestUtility.h"
#include "../../../src/Application.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/commands/ListCategoriesCommand.h"
#include "../../../src/commands/ListSitesCommand.h"
#include "../../../src/commands/ListApplicationsCommand.h"
#include "../../../src/commands/ListPasswordsCommand.h"

using namespace std;
using OwnPass::Application;
using OwnPass::CLI::CommandParser;
using OwnPass::Commands::CommandPtr;
using OwnPass::Commands::ListCategoriesCommand;
using OwnPass::Commands::ListSitesCommand;
using OwnPass::Commands::ListApplicationsCommand;
using OwnPass::Commands::ListPasswordsCommand;

class ListCommandParserFixture {
public:
	static constexpr auto Tag = "[list command]";
	ListCommandParserFixture()
			:app{ Application::instance() } { }
protected:
	Application& app;

	void assertParseCommand(int argc, char** argv, std::string_view command_name)
	{
		CommandParser command_parser{ app, argc, argv };
		REQUIRE_FALSE(command_parser.get_commands().empty());
		auto& command_ptr = command_parser.get_commands().front();
		REQUIRE(command_ptr->get_name() == command_name);
	}
};

TEST_CASE_METHOD(ListCommandParserFixture, "ListCommandParser - Categories", ListCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"list",
			"-c",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseCommand(argc, const_cast<char**>(argv), ListCategoriesCommand::Name);
}

TEST_CASE_METHOD(ListCommandParserFixture, "ListCommandParser - Categories 2", ListCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"--command=list",
			"-c",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseCommand(argc, const_cast<char**>(argv), ListCategoriesCommand::Name);
}

TEST_CASE_METHOD(ListCommandParserFixture, "ListCommandParser - Sites", ListCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"list",
			"-s",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseCommand(argc, const_cast<char**>(argv), ListSitesCommand::Name);
}

TEST_CASE_METHOD(ListCommandParserFixture, "ListCommandParser - Applications", ListCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"list",
			"-a",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseCommand(argc, const_cast<char**>(argv), ListApplicationsCommand::Name);
}

TEST_CASE_METHOD(ListCommandParserFixture, "ListCommandParser - Passwords", ListCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"list",
			"-p",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_NOTHROW((CommandParser{ app, argc, const_cast<char**>(argv) }));
	assertParseCommand(argc, const_cast<char**>(argv), ListPasswordsCommand::Name);
}
