//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../catch.hpp"
#include "../SampleStorageFixture.h"
#include "../../src/query/Query.h"
#include "../../src/query/GroupNotFoundException.h"
#include "../../src/query/GroupQuery.h"

using OwnPass::Group;
using OwnPass::Query::GroupNotFoundException;
using OwnPass::Query::GroupQuery;

class GroupQueryFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[group query]";
	GroupQueryFixture()
			:SampleStorageFixture()
	{
		reset_sample_storage();
	};
protected:
	void assert_find_first(std::string_view category_search, std::string_view category_name,
			std::string_view group_search, std::string_view group_name)
	{
		GroupQuery::QueryArguments args;
		args.category_search = category_search;
		args.search = group_search;
		GroupQuery group_query{ get_storage(), args };
		const auto result = group_query.find_first();
		REQUIRE_FALSE(group_query.empty());
		REQUIRE(group_query.size() == 1);
		REQUIRE(result.category);
		const auto& category = result.category;
		REQUIRE((category_search.empty() || boost::iequals(category->get_name(), category_name)));
		REQUIRE(result.group);
		const auto& group = result.group;
		REQUIRE((group_search.empty() || boost::iequals(group->get_name(), group_name)));
	}
};

TEST_CASE_METHOD(GroupQueryFixture, "GroupQuery - construct", GroupQueryFixture::Tag)
{
	GroupQuery::QueryArguments args;
	REQUIRE_NOTHROW(GroupQuery{ get_storage(), args });
}

TEST_CASE_METHOD(GroupQueryFixture, "GroupQuery - find all groups", GroupQueryFixture::Tag)
{
	GroupQuery::QueryArguments args;
	GroupQuery group_query{ get_storage(), args };
	const auto results = group_query.find();
	REQUIRE_FALSE(group_query.empty());
	const auto& categories = get_storage().get_categories();
	REQUIRE(group_query.size() == categories.size() * categories.front()->get_groups().size());
}

TEST_CASE_METHOD(GroupQueryFixture, "GroupQuery - find_first", GroupQueryFixture::Tag)
{
	REQUIRE_NOTHROW(assert_find_first("category #5", "Category #5", "_5", "Group #5_5"));
	REQUIRE_NOTHROW(assert_find_first("#3", "Category #3", "3_5", "Group #3_5"));
	REQUIRE_NOTHROW(assert_find_first("", "Category #1", "1_9", "Group #1_9"));
	REQUIRE_NOTHROW(assert_find_first("", "Category #1", "", "Group #1_1"));
	REQUIRE_THROWS_AS(assert_find_first("Foo", "", "Bar", ""), GroupNotFoundException);
	REQUIRE_THROWS_AS(assert_find_first("#3", "", "1_9", ""), GroupNotFoundException);
}
