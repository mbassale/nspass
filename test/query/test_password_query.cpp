//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../catch.hpp"
#include "../SampleStorageFixture.h"
#include "../../src/query/Query.h"
#include "../../src/query/PasswordQuery.h"

using OwnPass::Query::PasswordQuery;

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
		const auto& results = password_query.execute();
		REQUIRE_FALSE(results.empty());
		REQUIRE(results.size() == result_size);
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
