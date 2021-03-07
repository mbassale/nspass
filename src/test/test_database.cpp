//
// Created by Marco Bassaletti on 05-03-21.
//
#include "catch.hpp"
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <list>
#include <sstream>
#include "../storage/Storage.h"

using namespace std;
using namespace OwnPass;
using namespace OwnPass::Storage;


TEST_CASE("make instance") {
    REQUIRE_NOTHROW(StorageFactory::make());
}

TEST_CASE("categories") {
    shared_ptr<OwnPass::Storage::Storage> db = StorageFactory::make();
    db->purge();

    SECTION("empty") {
        list<Category> categories = db->list_categories();
        REQUIRE(categories.empty());
    }
    SECTION("add 10 list again") {
        for (auto i = 0; i < 10; i++) {
            stringstream category_name;
            category_name << "Category #" << i;
            Category category{ category_name.str() };
            db->save_category(category);
        }
        list<Category> categories = db->list_categories();
        REQUIRE(categories.size() == 10);
        for (auto& category : categories) {
             REQUIRE(category.get_name().find("Category #") != string::npos);
        }
    }
    SECTION("search for specific string") {
        using namespace string_literals;
        for (auto i = 0; i < 10; i++) {
            stringstream category_name;
            category_name << "Category #" << i;
            Category category{ category_name.str() };
            db->save_category(category);
        }
        auto category_name = "Category #5"s;
        auto category = db->find_category(category_name);
        REQUIRE(category.get_name() == category_name);
        auto category_name2 = "category #5"s;
        auto category2 = db->find_category(category_name2);
        REQUIRE(boost::algorithm::icontains(category2.get_name(), category_name2));
    }
}

TEST_CASE("groups") {
    shared_ptr<OwnPass::Storage::Storage> db = StorageFactory::make();
    {
        db->purge();
        Category category;
        db->save_category(category);
        db->flush();
        db->reload();
    }

    auto& categories = db->list_categories();
    auto& first_category = categories.front();

    SECTION("new category with no group") {
        REQUIRE(first_category.get_groups().empty());
    }
    SECTION("add group to existing category") {

        Group group{ "Group #1" };
        first_category.add_group(group);
        db->save_category(first_category);
        db->flush();
        db->reload();
        auto& first_category2 = db->list_categories().front();
        REQUIRE_FALSE(first_category2.get_groups().empty());

        SECTION("modify a copy of existing category and group and then save it") {
            Category first_category_copy = db->list_categories().front();
            first_category_copy.set_name("Updated Category");
            first_category_copy.get_groups().front().set_name("Updated Group");
            db->save_category(first_category_copy);
            db->flush();
            db->reload();
            auto& updated_category = db->list_categories().front();
            REQUIRE(updated_category.get_name() == "Updated Category");
            auto& updated_group = updated_category.get_groups().front();
            REQUIRE(updated_group.get_name() == "Updated Group");
        }
    }
}