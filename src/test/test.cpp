//
// Created by Marco Bassaletti on 22-02-21.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <algorithm>
#include "../Category.h"
#include "../Site.h"
#include "../Application.h"

using namespace std;
using namespace OwnPass;

TEST_CASE("Default Group")
{
	auto group = Group::get_default();
	REQUIRE(group.get_name() == Group::DefaultGroupName);
}

TEST_CASE("Create passwords")
{
	auto username_s = "test@test.com";
	auto password_s = "test1234";
	auto description = "lorem_ipsum";
	SECTION("in default group") {
		Group& group = Group::get_default();
		Password password{ group, username_s, password_s, description };
		REQUIRE(password.get_username() == username_s);
		REQUIRE(password.get_password() == password_s);
		REQUIRE(password.get_description() == description);
		REQUIRE(password.get_group().get_name() == Group::DefaultGroupName);
	}

	SECTION("in a site") {
		auto site_name = "test.com";
		Site site{ site_name };
		REQUIRE(site.get_name() == site_name);
		Password password{ site, username_s, password_s, description };
		REQUIRE(password.get_username() == username_s);
		REQUIRE(password.get_password() == password_s);
		REQUIRE(password.get_description() == description);
		REQUIRE(&(password.get_group()) == &site);
	}

	SECTION("in an application") {
		auto app_name = "myawesomeapp";
		Application app{ app_name };
		REQUIRE(app.get_name() == app_name);
		Password password{ app, username_s, password_s, description };
		REQUIRE(password.get_username() == username_s);
		REQUIRE(password.get_password() == password_s);
		REQUIRE(password.get_description() == description);
		REQUIRE(&(password.get_group()) == &app);
	}
}

TEST_CASE("Categories")
{
	SECTION("Create category") {
		auto category_name = "Category #0";
		Category category{ category_name };
		REQUIRE(category.get_name() == category_name);
	}

	SECTION("add/find/remove groups") {
		auto category_name = "Category #0";
		Category category{ category_name };
		for (auto i = 0; i < 100; i++) {
			ostringstream group_name;
			group_name << "Group #" << i;
			Group group{ group_name.str() };
			category.add_group(group);
		}

		auto group_name = "Group #5";
		auto group = category.find_group(group_name);
		REQUIRE(group.has_value());
		REQUIRE(group.value().get_name() == group_name);
		auto group_name2 = "Group #1000";
		auto group2 = category.find_group(group_name2);
		REQUIRE_FALSE(group2.has_value());

		// Case-insensitive search of groups
		auto search_str = "Group #2";
		auto results = category.find_groups(search_str);
		REQUIRE(results.size() == 11);
		for (auto group_ref : results) {
			REQUIRE(group_ref.get().get_name().find("Group #2") != string::npos);
		}
		results.clear();

		// remove Group #5 by reference
		category.remove_group(group.value());
		REQUIRE(category.get_groups().size() == 99);

		// remove Group #2 by name
		auto group_name3 = "Group #2";
		category.remove_group(group_name3);
		results = category.find_groups(search_str);
		REQUIRE(results.size() == 10);
		REQUIRE(category.get_groups().size() == 98);
	}
}

TEST_CASE("Groups")
{
	SECTION("Create Sites") {
		auto site_name = "Site 0";
		Site site{ site_name };
		REQUIRE(site.get_name() == site_name);
		REQUIRE(site.get_passwords().empty());
	}

	SECTION("Create Applications") {
		auto app_name = "App 0";
		Application app{ app_name };
		REQUIRE(app.get_name() == app_name);
		REQUIRE(app.get_passwords().empty());
	}
}
