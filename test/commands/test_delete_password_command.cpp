//
// Created by Marco Bassaletti on 04-04-21.
//
#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../SampleStorageFixture.h"
#include "../TestUtility.h"
#include "../../src/query/PasswordQuery.h"
#include "../../src/query/PasswordNotFoundException.h"
#include "../../src/commands/DeletePasswordCommand.h"

using namespace std;
using NSPass::Application;
using NSPass::ApplicationException;
using NSPass::Query::PasswordQuery;
using NSPass::Query::PasswordNotFoundException;
using NSPass::Commands::DeletePasswordCommand;

class DeletePasswordCommandFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[delete password command]";
	DeletePasswordCommandFixture() = default;
};

TEST_CASE_METHOD(DeletePasswordCommandFixture, "DeletePasswordCommand - Construct", DeletePasswordCommandFixture::Tag)
{
	reset_sample_storage();
	DeletePasswordCommand::Filter filter;
	REQUIRE_NOTHROW(DeletePasswordCommand{ Application::instance(), filter });
}

TEST_CASE_METHOD(DeletePasswordCommandFixture, "DeletePasswordCommand - Execute", DeletePasswordCommandFixture::Tag)
{
	size_t passes = 5;
	while (passes-- > 0) {
		reset_sample_storage();
		auto category_number = TestUtility::random_integer(0, 9);
		auto group_number = TestUtility::random_integer(0, 9);
		auto username_number = TestUtility::random_integer(0, 9);
		ostringstream category_filter, group_filter, username_filter;
		category_filter << "category #" << category_number;
		group_filter << "group #" << category_number << "_" << group_number;
		username_filter << "user" << category_number << "_" << group_number << "_" << username_number;
		DeletePasswordCommand::Filter filter;
		filter.category_search = category_filter.str();
		filter.site_search = group_filter.str();
		filter.username_search = username_filter.str();
		DeletePasswordCommand delete_password_command{ Application::instance(), filter };
		REQUIRE_NOTHROW(delete_password_command.execute());
		PasswordQuery::QueryArguments args;
		args.category_search = category_filter.str();
		args.group_search = group_filter.str();
		args.username = username_filter.str();
		PasswordQuery password_query{ get_storage(), args };
		REQUIRE_THROWS_AS(password_query.find_first(), PasswordNotFoundException);
	}
}

TEST_CASE_METHOD(DeletePasswordCommandFixture, "DeletePasswordCommand - Password not found",
		DeletePasswordCommandFixture::Tag)
{
	reset_sample_storage();
	DeletePasswordCommand::Filter filter;
	filter.category_search = "fooh";
	filter.site_search = "faah";
	filter.username_search = "fiih";
	DeletePasswordCommand update_password_command{ Application::instance(), filter };
	REQUIRE_THROWS_AS(update_password_command.execute(), PasswordNotFoundException);
}
