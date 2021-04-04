//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../catch.hpp"
#include "../SampleStorageFixture.h"
#include "../../src/query/Query.h"
#include "../../src/query/CategoryNotFoundException.h"
#include "../../src/query/CategoryQuery.h"

using NSPass::Category;
using NSPass::CategoryPtr;
using NSPass::Query::CategoryNotFoundException;
using NSPass::Query::CategoryQuery;

class CategoryQueryFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[category query]";
	CategoryQueryFixture()
			:SampleStorageFixture()
	{
		reset_sample_storage();
	};
protected:
	void assert_find_first(std::string_view category_search, std::string_view category_name)
	{
		CategoryQuery category_query{ get_storage(), category_search };
		auto category = category_query.find_first();
		REQUIRE_FALSE(category_query.empty());
		REQUIRE(category_query.size() == 1);
		REQUIRE(category);
		REQUIRE(category->get_name() == category_name);
	}
};

TEST_CASE_METHOD(CategoryQueryFixture, "CategoryQuery - construct", CategoryQueryFixture::Tag)
{
	REQUIRE_NOTHROW(CategoryQuery{ get_storage(), std::string() });
}

TEST_CASE_METHOD(CategoryQueryFixture, "CategoryQuery - find all categories", CategoryQueryFixture::Tag)
{
	CategoryQuery category_query{ get_storage(), std::string() };
	auto results = category_query.find();
	REQUIRE_FALSE(results.empty());
	auto& categories = get_storage().get_categories();
	REQUIRE(results.size() == categories.size());
	for (const auto& category : results) {
		auto it = std::find_if(categories.begin(), categories.end(), [&category](const CategoryPtr& category2) {
			return category->get_id() == category2->get_id();
		});
		REQUIRE(it != categories.end());
		REQUIRE((*it)->get_id() == category->get_id());
	}
}

TEST_CASE_METHOD(CategoryQueryFixture, "CategoryQuery - find_first", CategoryQueryFixture::Tag)
{
	REQUIRE_NOTHROW(assert_find_first("category #5", "Category #5"));
	REQUIRE_NOTHROW(assert_find_first("9", "Category #9"));
	REQUIRE_NOTHROW(assert_find_first("", "Category #0"));
	REQUIRE_THROWS_AS(assert_find_first("Foo", ""), CategoryNotFoundException);
	REQUIRE_THROWS_AS(assert_find_first("%$$", ""), CategoryNotFoundException);
}
