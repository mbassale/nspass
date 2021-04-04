//
// Created by Marco Bassaletti on 03-04-21.
//
#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../SampleStorageFixture.h"
#include "../TestUtility.h"
#include "../../src/query/PasswordNotFoundException.h"
#include "../../src/commands/UpdatePasswordCommand.h"

using namespace std;
using NSPass::Application;
using NSPass::ApplicationException;
using NSPass::Query::PasswordNotFoundException;
using NSPass::Commands::UpdatePasswordCommand;

class UpdatePasswordCommandFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[update command]";
	UpdatePasswordCommandFixture() = default;
};

TEST_CASE_METHOD(UpdatePasswordCommandFixture, "UpdatePasswordCommand - Construct", UpdatePasswordCommandFixture::Tag)
{
	reset_sample_storage();
	UpdatePasswordCommand::Filter filter;
	UpdatePasswordCommand::UpdateData update_data;
	REQUIRE_NOTHROW(UpdatePasswordCommand{ Application::instance(), filter, update_data });
}

TEST_CASE_METHOD(UpdatePasswordCommandFixture, "UpdatePasswordCommand - Execute", UpdatePasswordCommandFixture::Tag)
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
		UpdatePasswordCommand::Filter filter;
		filter.category_search = category_filter.str();
		filter.site_search = group_filter.str();
		filter.username_search = username_filter.str();
		UpdatePasswordCommand::UpdateData update_data;
		update_data.username = "updated-"+username_filter.str()+"@test.com";
		update_data.password = "updated password";
		update_data.url = "updated url";
		update_data.description = "updated description";
		UpdatePasswordCommand update_password_command{ Application::instance(), filter, update_data };
		REQUIRE_NOTHROW(update_password_command.execute());
		auto& updated_password_weak_ptr = update_password_command.get_updated_password();
		auto updated_password = updated_password_weak_ptr.lock();
		REQUIRE(updated_password);
		REQUIRE(updated_password->get_username() == update_data.username);
		REQUIRE(updated_password->get_password().get_plain_text(*(update_data.username)) == update_data.password);
		REQUIRE(updated_password->get_url() == update_data.url);
		REQUIRE(updated_password->get_description() == update_data.description);
	}
}

TEST_CASE_METHOD(UpdatePasswordCommandFixture, "UpdatePasswordCommand - Password not found",
		UpdatePasswordCommandFixture::Tag)
{
	reset_sample_storage();
	UpdatePasswordCommand::Filter filter;
	filter.category_search = "fooh";
	filter.site_search = "faah";
	filter.username_search = "fiih";
	UpdatePasswordCommand::UpdateData update_data;
	UpdatePasswordCommand update_password_command{ Application::instance(), filter, update_data };
	REQUIRE_THROWS_AS(update_password_command.execute(), PasswordNotFoundException);
}
