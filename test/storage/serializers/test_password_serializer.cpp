//
// Created by Marco Bassaletti on 27-03-21.
//
#include "../../catch.hpp"
#include "../../TestUtility.h"
#include "../../../src/NSPass.h"
#include "../../../src/Password.h"
#include "../../../src/storage/serializer/PasswordSerializer.h"

using namespace std;
using NSPass::Password;
using NSPass::PasswordFactory;
using NSPass::Crypto::SecureString;
using NSPass::Storage::Serializer::PasswordSerializer;

class PasswordSerializerFixture {
public:
	PasswordSerializerFixture() = default;
protected:
	static void assert_password_serialization(string_view username, string_view password, string_view url, string_view description) {
		auto secure_password = SecureString::FromPlainText(username, password);
		auto password_obj = PasswordFactory::make(username, secure_password, url, description);
		PasswordSerializer password_serializer{};
		auto password_json = password_serializer.serialize(password_obj);
		auto json_str = TestUtility::convert_json_to_string(password_json);
		auto password_json2 = TestUtility::convert_string_to_json(json_str);
		PasswordSerializer password_serializer2{};
		auto password_obj2 = password_serializer2.deserialize(password_json2);
		REQUIRE(password_obj->get_id() == password_obj2->get_id());
		REQUIRE(password_obj->get_username() == password_obj2->get_username());
		REQUIRE(password_obj->get_password() == password_obj2->get_password());
		REQUIRE(password_obj->get_url() == password_obj2->get_url());
		REQUIRE(password_obj->get_description() == password_obj2->get_description());
	}
};

TEST_CASE_METHOD(PasswordSerializerFixture, "PasswordSerializer - serialize/deserialize", "[password serializer]")
{
	assert_password_serialization("", "", "", "");
	assert_password_serialization(" ", " ", " ", " ");
	assert_password_serialization("    ", "    ", "    ", "    ");
	assert_password_serialization("username", "password", "url", "description");
}
