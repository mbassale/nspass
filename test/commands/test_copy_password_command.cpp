//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../SampleStorageFixture.h"
#include "../TestUtility.h"
#include "../../src/commands/CopyPasswordCommand.h"

using namespace std;
using NSPass::Application;
using NSPass::ApplicationException;
using NSPass::PasswordWeakPtr;
using NSPass::Commands::CopyPasswordCommand;

class CopyPasswordCommandFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[copy command]";
	CopyPasswordCommandFixture()
	{
		reset_sample_storage();
	};
protected:
	static void assert_password_copied(const std::string& password_str, const PasswordWeakPtr& copied_password)
	{
		REQUIRE_FALSE(copied_password.expired());
		auto password = copied_password.lock();
		REQUIRE(password);
		auto plaintext_password = password->get_password().get_plain_text(password->get_username());
		REQUIRE(plaintext_password == password_str);
	}
};

TEST_CASE_METHOD(CopyPasswordCommandFixture, "CopyPasswordCommand - Construct", CopyPasswordCommandFixture::Tag)
{
	REQUIRE_NOTHROW(CopyPasswordCommand{ Application::instance(), "", "", "" });
}

TEST_CASE_METHOD(CopyPasswordCommandFixture, "CopyPasswordCommand - Execute", CopyPasswordCommandFixture::Tag)
{
	size_t passes = 5;
	while (passes-- > 0) {
		auto category_number = TestUtility::random_integer(0, 9);
		auto group_number = TestUtility::random_integer(0, 9);
		auto password_number = TestUtility::random_integer(0, 9);
		ostringstream category_filter, group_filter, password_filter;
		category_filter << "category #" << category_number;
		group_filter << "group #" << category_number << "_" << group_number;
		password_filter << "user" << category_number << "_" << group_number << "_" << password_number;
		CopyPasswordCommand copy_password_command{ Application::instance(), category_filter.str(),
												   group_filter.str(), password_filter.str() };
		REQUIRE_NOTHROW(copy_password_command.execute());
		auto copied_password_str = TestUtility::get_clipboard_text();
		auto copied_password = copy_password_command.get_copied_password();
		assert_password_copied(copied_password_str, copied_password);

		auto password_id = copied_password.lock()->get_id();
		CopyPasswordCommand copy_password_command_by_id{ Application::instance(), password_id };
		REQUIRE_NOTHROW(copy_password_command_by_id.execute());
		assert_password_copied(TestUtility::get_clipboard_text(), copy_password_command_by_id.get_copied_password());
	}
}

TEST_CASE_METHOD(CopyPasswordCommandFixture, "CopyPasswordCommand - Password not found",
		CopyPasswordCommandFixture::Tag)
{
	CopyPasswordCommand copy_password_command{ Application::instance(), "fooh", "faah", "fiih" };
	REQUIRE_THROWS_AS(copy_password_command.execute(), ApplicationException);
}
