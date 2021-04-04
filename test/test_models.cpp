//
// Created by Marco Bassaletti on 22-02-21.
//
#include "catch.hpp"
#include <string>
#include <algorithm>
#include <sstream>
#include "../src/crypto/SecureString.h"
#include "../src/Category.h"

using namespace std;
using namespace NSPass;

TEST_CASE("Create passwords")
{
	auto username_s = "test@test.com";
	auto password_s = SecureString::FromPlainText("test1234", "test1234");
	auto url = "https://site.com";
	auto description = "lorem_ipsum";
	SECTION("in a group") {
		auto group_name = "Group #1";
		auto group = GroupFactory::make_group(group_name);
		auto password = PasswordFactory::make(username_s, password_s, url, description);
		REQUIRE_FALSE(password->get_id().is_nil());
		REQUIRE(password->get_username() == username_s);
		REQUIRE(password->get_password() == password_s);
		REQUIRE(password->get_url() == url);
		REQUIRE(password->get_description() == description);
		group->add_password(password);

		// test copy constructor
		Group group2{ *group };
		REQUIRE(group2.get_passwords().size() == group->get_passwords().size());
		auto password2 = group2.get_passwords().front();
		REQUIRE(password2->get_id() == password->get_id());
	}

	SECTION("in a site") {
		auto site_name = "test.com";
		auto site = GroupFactory::make_site(site_name);
		REQUIRE(site->get_name() == site_name);
		auto password = PasswordFactory::make(username_s, password_s, url, description);
		REQUIRE_FALSE(password->get_id().is_nil());
		REQUIRE(password->get_username() == username_s);
		REQUIRE(password->get_password() == password_s);
		REQUIRE(password->get_description() == description);
		site->add_password(password);

		// test copy constructor
		Group site2{ *site };
		REQUIRE(site2.get_passwords().size() == 1);
		auto password2 = site2.get_passwords().front();
		REQUIRE(password2->get_id() == password->get_id());
	}

	SECTION("in an application") {
		auto app_name = "myawesomeapp";
		auto app = GroupFactory::make_application(app_name);
		REQUIRE(app->get_name() == app_name);
		auto password = PasswordFactory::make(username_s, password_s, url, description);
		REQUIRE(password->get_username() == username_s);
		REQUIRE(password->get_password() == password_s);
		REQUIRE(password->get_description() == description);
		app->add_password(password);

		// test copy constructor
		Group app2{ *app };
		REQUIRE(app2.get_passwords().size() == 1);
		auto password2 = app2.get_passwords().front();
		REQUIRE(password2->get_id() == password->get_id());
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
		vector<ObjectId> group_ids;
		for (auto i = 0; i < 100; i++) {
			ostringstream group_name;
			group_name << "Group #" << i;
			auto group = GroupFactory::make_group(group_name.str());
			category.add_group(group);
			group_ids.push_back(group->get_id());
		}

		// find group by id
		for (auto group_id : group_ids) {
			auto group = category.find_group(group_id);
			REQUIRE(group);
			REQUIRE(group->get_id() == group_id);
		}

		// find group by name
		auto group_name = "Group #5";
		auto group = category.find_group(group_name);
		REQUIRE(group);
		REQUIRE(group->get_name() == group_name);
		auto group_name2 = "Group #1000";
		auto group2 = category.find_group(group_name2);
		REQUIRE_FALSE(group2);

		// Case-insensitive search of groups
		auto search_str = "Group #2";
		auto results = category.find_groups(search_str);
		REQUIRE(results.size() == 11);
		for (const auto& current_group : results) {
			REQUIRE(current_group->get_name().find("Group #2") != string::npos);
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
		auto site = GroupFactory::make_site(site_name, site_url, site_description);
		REQUIRE(site->get_name() == site_name);
		REQUIRE(site->get_url() == site_url);
		REQUIRE(site->get_description() == site_description);
		REQUIRE(site->get_passwords().empty());
	}

	SECTION("Create Applications") {
		auto app_name = "App 0";
		auto app_url = "https://www.app.com";
		auto app_description = "lorem ipsum dolor senet";
		auto app = GroupFactory::make_application(app_name, app_url, app_description);
		REQUIRE(app->get_name() == app_name);
		REQUIRE(app->get_url() == app_url);
		REQUIRE(app->get_description() == app_description);
		REQUIRE(app->get_passwords().empty());
	}
}
