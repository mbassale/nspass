//
// Created by Marco Bassaletti on 27-03-21.
//
#include "../../catch.hpp"
#include "../../TestUtility.h"
#include "../../../src/OwnPass.h"
#include "../../../src/Password.h"
#include "../../../src/Group.h"
#include "../../../src/storage/serializer/GroupSerializer.h"

using namespace std;
using OwnPass::IdGenerator;
using OwnPass::Password;
using OwnPass::PasswordPtr;
using OwnPass::PasswordFactory;
using OwnPass::Group;
using OwnPass::GroupFactory;
using OwnPass::Crypto::SecureString;
using OwnPass::Storage::Serializer::GroupSerializer;

class GroupSerializerFixture {
public:
	GroupSerializerFixture() = default;
protected:
	static void assert_group_serialization(string_view name, string_view url, string_view description,
			const vector<PasswordPtr>& passwords = vector<PasswordPtr>())
	{
		auto group1 = GroupFactory::make_site(IdGenerator::make(), name, passwords, url, description);
		GroupSerializer group_serializer;
		auto group_json = group_serializer.serialize(group1);
		auto json_string = TestUtility::convert_json_to_string(group_json);
		auto group_json2 = TestUtility::convert_string_to_json(json_string);
		GroupSerializer group_serializer2;
		auto group2 = group_serializer2.deserialize(group_json2);
		REQUIRE(group1.get_id() == group2.get_id());
		REQUIRE(group1.get_name() == group2.get_name());
		REQUIRE(group1.get_url() == group2.get_url());
		REQUIRE(group1.get_description() == group2.get_description());
		REQUIRE(group1.get_passwords().size() == group2.get_passwords().size());
		if (!passwords.empty()) {
			for (const auto& password1 : passwords) {
				auto password2 = group2.find_password(password1->get_id());
				REQUIRE(password2);
				REQUIRE(password1->get_id() == password2->get_id());
			}
		}
	}
};

TEST_CASE_METHOD(GroupSerializerFixture, "GroupSerializer - serialize/deserialize", "[group serializer]")
{
	assert_group_serialization("", "", "");
	assert_group_serialization(" ", " ", " ");
	assert_group_serialization("    ", "    ", "    ");
	assert_group_serialization("name", "url", "description");
}

TEST_CASE_METHOD(GroupSerializerFixture, "GroupSerializer - serialize/deserialize with passwords", "[group serializer]")
{
	vector<PasswordPtr> passwords;
	passwords.push_back(PasswordFactory::make("username",
			SecureString::FromPlainText("username", "password"), "url", "description"));
	assert_group_serialization("", "", "", passwords);
	assert_group_serialization(" ", " ", " ", passwords);
	assert_group_serialization("    ", "    ", "    ", passwords);
	assert_group_serialization("name", "url", "description", passwords);
}
