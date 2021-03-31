//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../catch.hpp"
#include "../SampleStorageFixture.h"
#include "../../src/query/Query.h"
#include "../../src/query/GroupQuery.h"

using OwnPass::Group;
using OwnPass::Query::GroupQuery;

class GroupQueryFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[group query]";
	GroupQueryFixture()
			:SampleStorageFixture()
	{
	};
};

TEST_CASE_METHOD(GroupQueryFixture, "GroupQuery - construct", GroupQueryFixture::Tag)
{
	GroupQuery::QueryArguments args;
	REQUIRE_NOTHROW(GroupQuery{ get_storage(), args });
}

TEST_CASE_METHOD(GroupQueryFixture, "GroupQuery - find all groups", GroupQueryFixture::Tag)
{
	reset_sample_storage();
	GroupQuery::QueryArguments args;
	GroupQuery group_query{ get_storage(), args };
	auto results = group_query.execute();
	REQUIRE_FALSE(results.empty());
	auto& categories = get_storage().get_categories();
	REQUIRE(results.size() == categories.size() * categories.front()->get_groups().size());
}

TEST_CASE_METHOD(GroupQueryFixture, "GroupQuery - find one group", GroupQueryFixture::Tag)
{
	reset_sample_storage();
	GroupQuery::QueryArguments args;
	args.category_search = "category #5";
	args.search = "_5";
	GroupQuery group_query{ get_storage(), args };
	auto results = group_query.execute();
	REQUIRE_FALSE(results.empty());
	REQUIRE(results.size() == 1);
	auto group_ref = results.front();
	auto& group = group_ref.get();
	REQUIRE(group.get_name() == "Group #5_5");
}
