//
// Created by Marco Bassaletti on 04-04-21.
//
#include "../../TestUtility.h"
#include "../../SampleStorageFixture.h"
#include "../../../src/Application.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/cli/InvalidCommandSyntaxException.h"
#include "../../../src/commands/HelpCommand.h"
#include "../../../src/commands/DeletePasswordCommand.h"

using namespace std;
using NSPass::Application;
using NSPass::Category;
using NSPass::CLI::CommandParser;
using NSPass::CLI::InvalidCommandSyntaxException;
using NSPass::Commands::HelpCommand;
using NSPass::Commands::DeletePasswordCommand;

class DeletePasswordCommandParserFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[delete password command parser]";
	DeletePasswordCommandParserFixture()
			:SampleStorageFixture() { }
protected:
	void assert_delete_password_command(const vector<string>& args, std::string_view category_filter,
			std::string_view site_filter, std::string_view username_filter)
	{
		auto args_pair = TestUtility::create_command_line_args(args);
		auto&[argc, argv] = args_pair;
		CommandParser command_parser{ app, argc, const_cast<char**>(argv.get()) };
		auto& commands = command_parser.get_commands();
		REQUIRE_FALSE(commands.empty());
		auto command_ptr = command_parser.get_commands().front().get();
		auto delete_password_command = dynamic_cast<DeletePasswordCommand*>(command_ptr);
		REQUIRE(delete_password_command);
		REQUIRE(delete_password_command->get_name() == DeletePasswordCommand::Name);
		auto filter = delete_password_command->get_filter();
		REQUIRE(filter.category_search == category_filter);
		REQUIRE(filter.site_search == site_filter);
		REQUIRE(filter.username_search == username_filter);
	}
};

TEST_CASE_METHOD(DeletePasswordCommandParserFixture,
		"DeletePasswordCommandParser - invalid command, missing required argument",
		DeletePasswordCommandParserFixture::Tag)
{
	vector<string> args = {
			"ownpass",
			"delete"
	};
	auto args_pair = TestUtility::create_command_line_args(args);
	auto&[argc, argv] = args_pair;
	REQUIRE_THROWS_AS((CommandParser{ app, argc, const_cast<char**>(argv.get()) }), InvalidCommandSyntaxException);
}

TEST_CASE_METHOD(DeletePasswordCommandParserFixture, "DeletePasswordCommandParser - help",
		DeletePasswordCommandParserFixture::Tag)
{
	vector<string> args = {
			"ownpass",
			"delete",
			"-h"
	};
	auto args_pair = TestUtility::create_command_line_args(args);
	auto&[argc, argv] = args_pair;
	CommandParser command_parser{ app, argc, const_cast<char**>(argv.get()) };
	auto& commands = command_parser.get_commands();
	REQUIRE_FALSE(commands.empty());
	auto command_ptr = command_parser.get_commands().front().get();
	auto help_command_ptr = dynamic_cast<HelpCommand*>(command_ptr);
	REQUIRE(help_command_ptr);
	REQUIRE_NOTHROW(help_command_ptr->execute());
}

TEST_CASE_METHOD(DeletePasswordCommandParserFixture, "DeletePasswordCommandParser - long options",
		DeletePasswordCommandParserFixture::Tag)
{
	string category{ "Category #5" };
	string site{ "Group #5" };
	string username{ "user5_2_4@test.com" };
	vector<string> args = {
			"ownpass",
			"delete",
			"--category="+category,
			"--site="+site,
			"--username="+username
	};
	REQUIRE_NOTHROW(assert_delete_password_command(args, category, site, username));
}

TEST_CASE_METHOD(DeletePasswordCommandParserFixture, "DeletePasswordCommandParser - short options",
		DeletePasswordCommandParserFixture::Tag)
{
	string category{ "Category #5" };
	string site{ "Group #5" };
	string username{ "user5_2_4@test.com" };
	vector<string> args = {
			"ownpass",
			"delete",
			"-c"+category,
			"-s"+site,
			"-u"+username
	};
	REQUIRE_NOTHROW(assert_delete_password_command(args, category, site, username));
}

TEST_CASE_METHOD(DeletePasswordCommandParserFixture, "DeletePasswordCommandParser - only group and username",
		DeletePasswordCommandParserFixture::Tag)
{
	string group{ "Group #5" };
	string username{ "user5_2_4@test.com" };
	vector<string> args = {
			"ownpass",
			"delete",
			"-s"+group,
			"-u"+username
	};
	REQUIRE_NOTHROW(assert_delete_password_command(args, "", group, username));
}
