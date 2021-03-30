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
	};
};

TEST_CASE_METHOD(PasswordQueryFixture, "PasswordQuery - construct", PasswordQueryFixture::Tag)
{
	reset_sample_storage();
	auto& storage = get_storage();
	PasswordQuery::QueryArguments args;
	REQUIRE_NOTHROW(PasswordQuery{ storage, args });
}
