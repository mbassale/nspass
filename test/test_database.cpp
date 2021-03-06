//
// Created by Marco Bassaletti on 05-03-21.
//
#include "catch.hpp"
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include "../Storage.h"
#include "../SQLite3Storage.h"
#include "../Category.h"
#include "../Site.h"
#include "../Application.h"

using namespace std;
using namespace OwnPass;
using namespace OwnPass::DB;


TEST_CASE("make instance") {
    REQUIRE_NOTHROW(StorageFactory::make());
}

TEST_CASE("categories") {
    shared_ptr<Storage> db = StorageFactory::make();

    SECTION("empty") {
        vector<Category> categories = db->list_categories();
        REQUIRE(categories.empty());
    }
    SECTION("add 10 list again") {
        for (auto i = 0; i < 10; i++) {
            stringstream category_name;
            category_name << "Category #" << i;
            Category category{ category_name.str() };
            db->save_category(category);
        }
        vector<Category> categories = db->list_categories();
        REQUIRE(categories.size() == 0);
    }
}