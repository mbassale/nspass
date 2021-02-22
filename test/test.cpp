//
// Created by Marco Bassaletti on 22-02-21.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include "../Group.h"
#include "../Site.h"
#include "../Application.h"
#include "../Password.h"


TEST_CASE("Default Group") {
    auto group = Group::get_default();
    REQUIRE(group.get_name() == Group::DefaultGroupName);
}

TEST_CASE("Create passwords") {
    std::string username_s("test@test.com");
    std::string password_s("test1234");
    std::string description("lorem_ipsum");
    SECTION("in default group") {
        Password password{ username_s, password_s, description };
        REQUIRE(password.get_username() == "test@test.com");
        REQUIRE(password.get_password() == "test1234");
        REQUIRE(password.get_description() == "lorem_ipsum");
        REQUIRE(password.get_group().get_name() == Group::DefaultGroupName);
    }
    SECTION("in a site") {
        std::string site_name{ "test.com" };
        Site site{ site_name };
        REQUIRE(site.get_name() == "test.com");
        Password password{ site, username_s, password_s, description };
        REQUIRE(password.get_username() == "test@test.com");
        REQUIRE(password.get_password() == "test1234");
        REQUIRE(password.get_description() == "lorem_ipsum");
        REQUIRE(&(password.get_group()) == &site);
    }
    SECTION("in an application") {
        std::string app_name{ "myawesomeapp" };
        Application app{ app_name };
        REQUIRE(app.get_name() == "myawesomeapp");
        Password password{ app, username_s, password_s, description };
        REQUIRE(password.get_username() == "test@test.com");
        REQUIRE(password.get_password() == "test1234");
        REQUIRE(password.get_description() == "lorem_ipsum");
        REQUIRE(&(password.get_group()) == &app);
    }
}
