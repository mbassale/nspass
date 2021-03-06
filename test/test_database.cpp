//
// Created by Marco Bassaletti on 05-03-21.
//
#include "catch.hpp"
#include <string>
#include <algorithm>
#include "../Database.h"
#include "../SQLite3Database.h"
#include "../Category.h"
#include "../Site.h"
#include "../Application.h"

using namespace std;
using namespace OwnPass;
using namespace OwnPass::DB;


TEST_CASE("open database") {
    REQUIRE_NOTHROW(Database::get_instance());
}