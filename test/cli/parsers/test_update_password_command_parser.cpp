//
// Created by Marco Bassaletti on 03-04-21.
//

#include "../../TestUtility.h"
#include "../../SampleStorageFixture.h"
#include "../../../src/cli/CommandParser.h"
#include "../../../src/cli/InvalidCommandSyntaxException.h"
#include "../../../src/commands/HelpCommand.h"
#include "../../../src/commands/UpdatePasswordCommand.h"

using namespace std;
using OwnPass::Application;
using OwnPass::Category;
using OwnPass::CLI::CommandParser;
using OwnPass::CLI::InvalidCommandSyntaxException;
using OwnPass::Commands::HelpCommand;
using OwnPass::Commands::UpdatePasswordCommand;

class UpdateCommandParserFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[update password command]";
	UpdateCommandParserFixture()
			:SampleStorageFixture()
	{
		reset_sample_storage();
	}
protected:
	static std::pair<int, std::unique_ptr<const char*>> create_command_line_args(const std::vector<string>& args)
	{
		const char** argv = new const char* [args.size()+1];
		for (size_t i = 0; i < args.size(); i++) {
			argv[i] = args[i].c_str();
		}
		argv[args.size()] = nullptr;
		int argc = TestUtility::get_argc(argv);
		return std::pair<int, std::unique_ptr<const char*>>{ argc, std::unique_ptr<const char*>(argv) };
	}

	void assert_update_password_command(int argc, const char** argv, std::string_view category_name,
			std::string_view site_name, std::string_view username, std::string_view password, std::string_view url,
			std::string_view description)
	{
		CommandParser command_parser{ app, argc, const_cast<char**>(argv) };
		REQUIRE_FALSE(command_parser.get_commands().empty());
		auto command_ptr = command_parser.get_commands().front().get();
		auto update_password_command = dynamic_cast<UpdatePasswordCommand*>(command_ptr);
		REQUIRE(update_password_command);
		REQUIRE(update_password_command->get_name() == UpdatePasswordCommand::Name);

		auto& filter = update_password_command->get_filter();
		REQUIRE(filter.category_search == category_name);
		REQUIRE(filter.site_search == site_name);
		REQUIRE(filter.username_search == username);

		auto& update_data = update_password_command->get_update_data();
		REQUIRE(update_data.password == password);
		REQUIRE(update_data.url == url);
		REQUIRE(update_data.description == description);
	}
};

TEST_CASE_METHOD(UpdateCommandParserFixture, "UpdateCommandParser - invalid command", UpdateCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"update",
			nullptr
	};
	int argc = TestUtility::get_argc(argv);
	REQUIRE_THROWS_AS((CommandParser{ app, argc, const_cast<char**>(argv) }), InvalidCommandSyntaxException);
}

TEST_CASE_METHOD(UpdateCommandParserFixture, "UpdateCommandParser - help", UpdateCommandParserFixture::Tag)
{
	const char* argv[] = {
			"ownpass",
			"update",
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

TEST_CASE_METHOD(UpdateCommandParserFixture, "UpdateCommandParser - update password with full arguments",
		UpdateCommandParserFixture::Tag)
{
	string category{ "Category #5" };
	string group{ "Group #5" };
	string username{ "test5_5_1@test.com" };
	string password{ "updated-password" };
	string url{ "test.com" };
	string description{ "lorem ipsum dolor set" };
	vector<string> args = {
			"ownpass",
			"update",
			"--category="+category,
			"--site="+group,
			"--username="+username,
			"--password="+password,
			"--url="+url,
			"--description="+description
	};
	auto args_pair = create_command_line_args(args);
	int argc = args_pair.first;
	const char** argv = args_pair.second.get();
	REQUIRE_NOTHROW(assert_update_password_command(argc, argv, category, group, username, password, url, description));
}

TEST_CASE_METHOD(UpdateCommandParserFixture, "UpdateCommandParser - update site password with minimal arguments",
		UpdateCommandParserFixture::Tag)
{
	string site{ "Group #9" };
	string username{ "user9_1_1@test.com" };
	string password{ "updated-password" };
	vector<string> args = {
			"ownpass",
			"update",
			"--site="+site,
			"--username="+username,
			"--password="+password
	};
	auto args_pair = create_command_line_args(args);
	int argc = args_pair.first;
	const char** argv = args_pair.second.get();
	REQUIRE_NOTHROW(assert_update_password_command(argc, argv, "", site, username, password, "", ""));
}
