//
// Created by Marco Bassaletti on 27-03-21.
//
#include "../../catch.hpp"
#include "../../TestUtility.h"
#include "../../../src/OwnPass.h"
#include "../../../src/Group.h"
#include "../../../src/Category.h"
#include "../../../src/storage/serializer/CategorySerializer.h"

using namespace std;
using OwnPass::IdGenerator;
using OwnPass::GroupPtr;
using OwnPass::GroupFactory;
using OwnPass::Category;
using OwnPass::CategoryFactory;
using OwnPass::Crypto::SecureString;
using OwnPass::Storage::Serializer::CategorySerializer;

class CategorySerializerFixture {
public:
	CategorySerializerFixture() = default;

protected:
	static void assert_category_serializer(string_view name, const vector<GroupPtr>& groups = vector<GroupPtr>())
	{
		auto category1 = CategoryFactory::make(name, groups);
		CategorySerializer category_serializer1;
		auto category_json1 = category_serializer1.serialize(category1);
		auto json_string = TestUtility::convert_json_to_string(category_json1);
		auto category_json2 = TestUtility::convert_string_to_json(json_string);
		CategorySerializer category_serializer2;
		auto category2 = category_serializer2.deserialize(category_json2);
		REQUIRE(category1.get_id() == category2.get_id());
		REQUIRE(category1.get_name() == category2.get_name());
		REQUIRE(category1.get_groups().size() == category2.get_groups().size());
		if (!groups.empty()) {
			for (const auto& group : groups) {
				auto group2 = category2.find_group(group->get_id());
				REQUIRE(group2);
				REQUIRE(group2->get_id() == group->get_id());
			}
		}
	}
};

TEST_CASE_METHOD(CategorySerializerFixture, "CategorySerializer - serialize/deserialize", "[category serializer]")
{
	assert_category_serializer("");
	assert_category_serializer(" ");
	assert_category_serializer("    ");
	assert_category_serializer("category");
}

TEST_CASE_METHOD(CategorySerializerFixture, "CategorySerializer - serialize/deserialize with groups",
		"[category serializer]")
{
	vector<GroupPtr> groups;
	for (auto i = 0; i < 5; i++) {
		stringstream ss;
		ss << "Group #" << i;
		groups.push_back(GroupFactory::make_site(ss.str()));
	}
	assert_category_serializer("", groups);
	assert_category_serializer(" ", groups);
	assert_category_serializer("    ", groups);
	assert_category_serializer("category", groups);
}
