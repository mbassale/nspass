//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../catch.hpp"
#include "../SampleStorageFixture.h"
#include "../../src/query/Query.h"
#include "../../src/query/CategoryQuery.h"

using OwnPass::Category;
using OwnPass::CategoryPtr;
using OwnPass::Query::CategoryQuery;

class CategoryQueryFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[category query]";
	CategoryQueryFixture()
			:SampleStorageFixture()
	{
	};
};

TEST_CASE_METHOD(CategoryQueryFixture, "CategoryQuery - construct", CategoryQueryFixture::Tag)
{
	REQUIRE_NOTHROW(CategoryQuery{ get_storage(), std::string() });
}

TEST_CASE_METHOD(CategoryQueryFixture, "CategoryQuery - find all categories", CategoryQueryFixture::Tag)
{
	reset_sample_storage();
	CategoryQuery category_query{ get_storage(), std::string() };
	auto results = category_query.execute();
	REQUIRE_FALSE(results.empty());
	auto& categories = get_storage().get_categories();
	REQUIRE(results.size() == categories.size());
	for (const auto& category : results) {
		auto it = std::find_if(categories.begin(), categories.end(), [&category](const CategoryPtr& category2){
			return category->get_id() == category2->get_id();
		});
		REQUIRE(it != categories.end());
		REQUIRE((*it)->get_id() == category->get_id());
	}
}

TEST_CASE_METHOD(CategoryQueryFixture, "CategoryQuery - find one category", CategoryQueryFixture::Tag)
{
	reset_sample_storage();
	CategoryQuery category_query{ get_storage(), "category #5" };
	auto results = category_query.execute();
	REQUIRE_FALSE(results.empty());
	REQUIRE(results.size() == 1);
	auto& category = results.front();
	REQUIRE(category->get_name() == "Category #5");
}
