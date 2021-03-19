//
// Created by Marco Bassaletti on 22-02-21.
//
#include "catch.hpp"
#include <string>
#include <algorithm>
#include <sstream>
#include "../crypto/SecureString.h"
#include "../Category.h"

using namespace std;
using namespace OwnPass;

TEST_CASE("Create passwords")
{
	auto username_s = "test@test.com";
	auto password_s = SecureString::FromPlainText("test1234", "test1234");
	auto url = "https://site.com";
	auto description = "lorem_ipsum";
	SECTION("in a group") {
		auto group_name = "Group #1";
		Group group = GroupFactory::make_group(group_name);
		Password password = PasswordFactory::make(group, username_s, password_s, url, description);
		REQUIRE_FALSE(password.get_id().is_nil());
		REQUIRE(password.get_username() == username_s);
		REQUIRE(password.get_password() == password_s);
		REQUIRE(password.get_url() == url);
		REQUIRE(password.get_description() == description);
		REQUIRE(password.get_group().get_name() == group_name);
	}

	SECTION("in a site") {
		auto site_name = "test.com";
		Group site = GroupFactory::make_site(site_name);
		REQUIRE(site.get_name() == site_name);
		Password password = PasswordFactory::make(site, username_s, password_s, url, description);
		REQUIRE_FALSE(password.get_id().is_nil());
		REQUIRE(password.get_username() == username_s);
		REQUIRE(password.get_password() == password_s);
		REQUIRE(password.get_description() == description);
		REQUIRE(&(password.get_group()) == &site);
	}

	SECTION("in an application") {
		auto app_name = "myawesomeapp";
		Group app = GroupFactory::make_application(app_name);
		REQUIRE(app.get_name() == app_name);
		Password password = PasswordFactory::make(app, username_s, password_s, url, description);
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
			Group group = GroupFactory::make_group(group_name.str());
			category.add_group(group);
		}

		auto group_name = "Group #5";
		auto group_opt = category.find_group(group_name);
		REQUIRE(group_opt.has_value());
		auto& group = group_opt.value().get();
		REQUIRE(group.get_name() == group_name);
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
		category.remove_group(group);
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
		auto site_url = "https://www.site.com";
		auto site_description = "lorem ipsum dolor senet";
		Group site = GroupFactory::make_site(site_name, site_url, site_description);
		REQUIRE(site.get_name() == site_name);
		REQUIRE(site.get_url() == site_url);
		REQUIRE(site.get_description() == site_description);
		REQUIRE(site.get_passwords().empty());
	}

	SECTION("Create Applications") {
		auto app_name = "App 0";
		auto app_url = "https://www.app.com";
		auto app_description = "lorem ipsum dolor senet";
		Group app = GroupFactory::make_application(app_name, app_url, app_description);
		REQUIRE(app.get_name() == app_name);
		REQUIRE(app.get_url() == app_url);
		REQUIRE(app.get_description() == app_description);
		REQUIRE(app.get_passwords().empty());
	}
}
