//
// Created by Marco Bassaletti on 05-03-21.
//
#include "catch.hpp"
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <list>
#include <sstream>
#include "../storage/Storage.h"
#include "../Group.h"

using namespace std;
using namespace std::string_literals;
using namespace OwnPass;
using namespace OwnPass::Storage;

class JsonStorageFixture {
public:
	JsonStorageFixture()
	{
		db = StorageFactory::make();
		db->purge();
	}
protected:
	shared_ptr<OwnPass::Storage::Storage> db;

	void save_category(const string& prefix, int index = 0)
	{
		stringstream category_name;
		category_name << prefix << index;
		Category category{ category_name.str() };
		db->save_category(category);
	}

	void save_group(Category& category, const string& name)
	{
		Group group = GroupFactory::make_group(name);
		category.add_group(group);
		db->save_category(category);
	}

	void save_site(Category& category, const string& name, const string& url)
	{
		Group site = GroupFactory::make_site(name, url);
		category.add_group(site);
		db->save_category(category);
	}

	void flush_and_reload()
	{
		db->flush();
		db->reload();
	}

	tuple<shared_ptr<OwnPass::Storage::Storage>, list<Category>&, Category&> initialize_db_with_category() {
		shared_ptr<OwnPass::Storage::Storage> db2 = StorageFactory::make();
		{
			db2->purge();
			Category category;
			db2->save_category(category);
			db2->flush();
			db2->reload();
		}
		auto& categories = db2->list_categories();
		auto& first_category = categories.front();
		return tuple<shared_ptr<OwnPass::Storage::Storage>, list<Category>&, Category&>(db2, categories, first_category);
	}
};

TEST_CASE_METHOD(JsonStorageFixture, "make instance")
{
	REQUIRE_NOTHROW(StorageFactory::make());
}

TEST_CASE_METHOD(JsonStorageFixture, "categories")
{
	SECTION("empty") {
		list<Category> categories = db->list_categories();
		REQUIRE(categories.empty());
	}

	SECTION("add 10 list again") {
		for (auto i = 0; i < 10; i++) {
			save_category("Category #", i);
		}
		list<Category> categories = db->list_categories();
		REQUIRE(categories.size() == 10);
		for (auto& category : categories) {
			REQUIRE(category.get_name().find("Category #") != string::npos);
		}
	}

	SECTION("search for specific string") {
		for (auto i = 0; i < 10; i++) {
			save_category("Category #", i);
		}
		auto category_name = "Category #5";
		auto category = db->find_category(category_name);
		REQUIRE(category.get_name() == category_name);
		auto category_name2 = "category #5";
		auto category2 = db->find_category(category_name2);
		REQUIRE(boost::algorithm::icontains(category2.get_name(), category_name2));
	}
}

TEST_CASE_METHOD(JsonStorageFixture, "groups")
{
	auto [db, categories, first_category] = initialize_db_with_category();

	SECTION("new category with no group") {
		REQUIRE(first_category.get_groups().empty());
	}

	SECTION("add group to existing category") {
		save_group(first_category, "Group #1");
		flush_and_reload();
		auto& first_category2 = db->list_categories().front();
		REQUIRE_FALSE(first_category2.get_groups().empty());

		SECTION("modify a copy of existing category and group and then save it") {
			Category first_category_copy = db->list_categories().front();
			first_category_copy.set_name("Updated Category");
			first_category_copy.get_groups().front().set_name("Updated Group");
			db->save_category(first_category_copy);
			flush_and_reload();
			auto& updated_category = db->list_categories().front();
			REQUIRE(updated_category.get_name() == "Updated Category");
			auto& updated_group = updated_category.get_groups().front();
			REQUIRE(updated_group.get_name() == "Updated Group");
		}
	}

	SECTION("remove group from existing category") {
		save_group(first_category, "Group #1");
		flush_and_reload();

		auto& first_category2 = db->list_categories().front();
		REQUIRE_FALSE(first_category2.get_groups().empty());
		auto& groups = first_category2.get_groups();
		groups.clear();
		REQUIRE(groups.empty());
		flush_and_reload();

		auto& first_category3 = db->list_categories().front();
		REQUIRE(first_category3.get_groups().empty());
	}
}

TEST_CASE_METHOD(JsonStorageFixture, "sites") {
	auto [db, categories, first_category] = initialize_db_with_category();

	SECTION("add site to existing category") {
		save_site(first_category, "Site #1", "https://www.site.com");
		flush_and_reload();
		auto& first_category2 = db->list_categories().front();
		REQUIRE_FALSE(first_category2.get_groups().empty());
	}
}
