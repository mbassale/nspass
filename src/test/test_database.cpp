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

using namespace std;
using namespace OwnPass;
using namespace OwnPass::DB;


TEST_CASE("make instance") {
    REQUIRE_NOTHROW(StorageFactory::make());
}

TEST_CASE("categories") {
    shared_ptr<Storage> db = StorageFactory::make();
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