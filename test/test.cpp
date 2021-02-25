//
// Created by Marco Bassaletti on 22-02-21.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <vector>
#include <boost/algorithm/string/predicate.hpp>
#include "../Category.h"
#include "../Group.h"
#include "../Site.h"
#include "../Application.h"
#include "../Password.h"

using namespace std;

TEST_CASE("Default Group") {
    auto group = Group::get_default();
    REQUIRE(group.get_name() == Group::DefaultGroupName);
}

TEST_CASE("Create passwords") {
    std::string username_s("test@test.com");
    std::string password_s("test1234");
    std::string description("lorem_ipsum");
    SECTION("in default group") {
        Group& group = Group::get_default();
        Password password{ group, username_s, password_s, description };
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

TEST_CASE("Create a category") {
    Category category;
    for (auto i = 0; i < 10; i++) {
        ostringstream username;
        username << "test" << i <<  "@test.com";
        ostringstream password_s;
        password_s << "test" << i;
        ostringstream description;
        description << "lorem_ipsum_" << i;
        ostringstream group_name;
        group_name << "Group #" << i;
        shared_ptr<Group> group = std::make_shared<Group>(group_name.str());
        shared_ptr<Password> password = std::make_shared<Password>(*group, username.str(), password_s.str(), description.str());
        group->add_password(password);
        category.add_group(group);
    }
    REQUIRE(category.get_groups().size() == 10);
    for (const auto& group : category.get_groups()) {
        REQUIRE(boost::starts_with(group->get_name(), "Group #"));
        for (const auto& password : group->get_passwords()) {
            REQUIRE(boost::starts_with(password->get_username(), "test"));
            REQUIRE(boost::ends_with(password->get_username(), "@test.com"));
            REQUIRE(boost::starts_with(password->get_password(), "test"));
            REQUIRE(boost::starts_with(password->get_description(), "lorem_ipsum_"));
        }
    }
}
