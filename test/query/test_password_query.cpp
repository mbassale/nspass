//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../catch.hpp"
#include "../SampleStorageFixture.h"
#include "../../src/query/Query.h"
#include "../../src/query/PasswordQuery.h"

using NSPass::Query::PasswordNotFoundException;
using NSPass::Query::PasswordQueryItem;
using NSPass::Query::PasswordQuery;

class PasswordQueryFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[password query]";
	PasswordQueryFixture()
			:SampleStorageFixture()
	{
		reset_sample_storage();
	};

protected:
	void assertQueryPasswords(std::string_view category_search, std::string_view group_search,
			std::string_view password_search, size_t result_size = 1)
	{
		auto& storage = get_storage();
		PasswordQuery::QueryArguments args;
		args.category_search = category_search;
		args.group_search = group_search;
		args.username = password_search;
		PasswordQuery password_query{ storage, args };
		const auto& results = password_query.find();
		REQUIRE_FALSE(results.empty());
		REQUIRE(results.size() == result_size);
	}

	void assert_find_first(std::string_view category_search, std::string_view group_search,
			std::string_view password_search)
	{
		PasswordQuery::QueryArguments args;
		args.category_search = category_search;
		args.group_search = group_search;
		args.username = password_search;
		PasswordQuery password_query{ get_storage(), args };
		auto result = password_query.find_first();
		REQUIRE_FALSE(password_query.empty());
		REQUIRE(password_query.size() == 1);
		REQUIRE(result.category);
		REQUIRE(result.group);
		REQUIRE(result.password);
		REQUIRE((category_search.empty() || boost::icontains(result.category->get_name(), category_search)));
		REQUIRE((group_search.empty() || boost::icontains(result.group->get_name(), group_search)));
		REQUIRE((password_search.empty() || boost::icontains(result.password->get_username(), password_search)));
	}
};

TEST_CASE_METHOD(PasswordQueryFixture, "PasswordQuery - construct", PasswordQueryFixture::Tag)
{
	auto& storage = get_storage();
	PasswordQuery::QueryArguments args;
	REQUIRE_NOTHROW(PasswordQuery{ storage, args });
}

TEST_CASE_METHOD(PasswordQueryFixture, "PasswordQuery - query password", PasswordQueryFixture::Tag)
{
	assertQueryPasswords("category #5", "group #5_2", "user5_2_4");
	assertQueryPasswords("category #5", "", "user5_2_4");
	assertQueryPasswords("category #5", "group #5_6", "", 10);
}

TEST_CASE_METHOD(PasswordQueryFixture, "PasswordQuery - find_first", PasswordQueryFixture::Tag)
{
	REQUIRE_NOTHROW(assert_find_first("", "", ""));
	REQUIRE_NOTHROW(assert_find_first("category #6", "", "user6_3_5"));
	REQUIRE_NOTHROW(assert_find_first("", "group #4", "user4"));
	REQUIRE_NOTHROW(assert_find_first("", "group #8", "user8_4_3"));
	REQUIRE_THROWS_AS(assert_find_first("Foo", "Bar", "Fuh"), PasswordNotFoundException);
	REQUIRE_THROWS_AS(assert_find_first("4", "4_", "user6_"), PasswordNotFoundException);
}
