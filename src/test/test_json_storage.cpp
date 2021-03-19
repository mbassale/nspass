//
// Created by Marco Bassaletti on 05-03-21.
//
#include "catch.hpp"
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <list>
#include <sstream>
#include "../crypto/SecureString.h"
#include "../storage/Storage.h"

using namespace std;
using namespace std::string_literals;
using namespace OwnPass;
using namespace OwnPass::Storage;

class JsonStorageFixture {
public:
	JsonStorageFixture()
			:storage{ StorageFactory::make() }, db{ *storage }
	{
		db.purge();
	}
private:
	std::unique_ptr<OwnPass::Storage::Storage> storage{};

protected:
	std::string_view master_password = "test1234";
	OwnPass::Storage::Storage& db;

	void save_category(const string& prefix, int index = 0)
	{
		stringstream category_name;
		category_name << prefix << index;
		Category category{ category_name.str() };
		db.save_category(category);
	}

	Group save_group(Category& category, const string& name, const string& url, const string& description)
	{
		Group group = GroupFactory::make_group(name, url, description);
		category.add_group(group);
		db.save_category(category);
		return group;
	}

	Group save_site(Category& category, const string& name, const string& url, const string& description)
	{
		Group site = GroupFactory::make_site(name, url, description);
		category.add_group(site);
		db.save_category(category);
		return site;
	}

	Group save_application(Category& category, const string& name, const string& url, const string& description)
	{
		Group application = GroupFactory::make_application(name, url, description);
		category.add_group(application);
		db.save_category(category);
		return application;
	}

	void save_category_and_group(Category& category, Group& group)
	{
		category.save_group(group);
		db.save_category(category);
	}

	void flush_and_reload()
	{
		db.flush();
		db.reload();
	}

	tuple<list<Category>&, Category&> initialize_db_with_category()
	{
		db.purge();
		Category category;
		db.save_category(category);
		db.flush();
		db.reload();
		auto& categories = db.list_categories();
		auto& first_category = categories.front();
		return tuple<list<Category>&, Category&>(categories, first_category);
	}

	tuple<Category&, Group&> get_first_category_and_group()
	{
		auto& first_category = db.list_categories().front();
		REQUIRE_FALSE(first_category.get_groups().empty());
		auto& first_group = first_category.get_groups().front();
		return tuple<Category&, Group&>(first_category, first_group);
	}

	void assert_equals(const Password& password1, const Password& password2)
	{
		REQUIRE(password1.get_id() == password2.get_id());
		REQUIRE(password1.get_username() == password2.get_username());
		REQUIRE(password1.get_password() == password2.get_password());
		REQUIRE(password1.get_url() == password2.get_url());
		REQUIRE(password1.get_description() == password2.get_description());
	}
};

TEST_CASE_METHOD(JsonStorageFixture, "make instance")
{
	REQUIRE_NOTHROW(StorageFactory::make());
}


TEST_CASE_METHOD(JsonStorageFixture, "open storage")
{
	db.open(master_password);
}

TEST_CASE_METHOD(JsonStorageFixture, "categories")
{
	SECTION("empty") {
		list<Category> categories = db.list_categories();
		REQUIRE(categories.empty());
	}

	SECTION("add 10 list again") {
		for (auto i = 0; i < 10; i++) {
			save_category("Category #", i);
		}
		list<Category> categories = db.list_categories();
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
		auto category = db.find_category(category_name);
		REQUIRE(category.get_name() == category_name);
		auto category_name2 = "category #5";
		auto category2 = db.find_category(category_name2);
		REQUIRE(boost::algorithm::icontains(category2.get_name(), category_name2));
	}
}

TEST_CASE_METHOD(JsonStorageFixture, "groups")
{
	auto[categories, first_category] = initialize_db_with_category();

	SECTION("new category with no group") {
		REQUIRE(first_category.get_groups().empty());
	}

	SECTION("add group to existing category")
	{
		auto group_name = "Group #1";
		auto group_url = "https://test.com";
		auto group_description = "lorem ipsum dolor senet";
		auto original_group = save_group(first_category, group_name, group_url, group_description);
		flush_and_reload();
		auto& first_category2 = db.list_categories().front();
		REQUIRE_FALSE(first_category2.get_groups().empty());
		auto& group = first_category2.get_groups().front();
		REQUIRE(group.get_id() == original_group.get_id());
		REQUIRE(group.get_type() == GroupType::Group);
		REQUIRE(group.get_name() == group_name);
		REQUIRE(group.get_url() == group_url);
		REQUIRE(group.get_description() == group_description);

		SECTION("modify a copy of existing category and group and then save it") {
			Category first_category_copy = db.list_categories().front();
			first_category_copy.set_name("Updated Category");
			first_category_copy.get_groups().front().set_name("Updated Group");
			db.save_category(first_category_copy);
			flush_and_reload();
			auto& updated_category = db.list_categories().front();
			REQUIRE(updated_category.get_name() == "Updated Category");
			auto& updated_group = updated_category.get_groups().front();
			REQUIRE(updated_group.get_name() == "Updated Group");
		}
	}

	SECTION("remove group from existing category") {
		auto first_group = save_group(first_category, "Group #1", "https://test.com", "lorem ipsum dolor senet");
		auto second_group = save_group(first_category, "Group #2", "https://test2.com", "senet dolor ipsum lorem");
		flush_and_reload();

		auto& first_category2 = db.list_categories().front();
		REQUIRE(first_category2.get_groups().size() == 2);
		first_category2.remove_group(first_group);
		flush_and_reload();

		auto& first_category3 = db.list_categories().front();
		REQUIRE(first_category3.get_groups().size() == 1);
		auto existing_group = first_category3.get_groups().front();
		REQUIRE(second_group.get_id() == existing_group.get_id());
	}
}

TEST_CASE_METHOD(JsonStorageFixture, "sites")
{
	auto[categories, first_category] = initialize_db_with_category();

	SECTION("add site to existing category") {
		auto site_name = "Site #1";
		auto site_url = "https://www.site.com";
		auto site_description = "lorem ipsum dolor senet";
		auto original_site = save_site(first_category, site_name, site_url, site_description);
		flush_and_reload();
		auto& first_category2 = db.list_categories().front();
		REQUIRE_FALSE(first_category2.get_groups().empty());
		auto& site = first_category2.get_groups().front();
		REQUIRE(site.get_id() == original_site.get_id());
		REQUIRE(GroupType::Site == site.get_type());
		REQUIRE(site.get_type() == GroupType::Site);
		REQUIRE(site.get_name() == site_name);
		REQUIRE(site.get_url() == site_url);
		REQUIRE(site.get_description() == site_description);
	}
}

TEST_CASE_METHOD(JsonStorageFixture, "applications")
{
	auto[categories, first_category] = initialize_db_with_category();

	SECTION("add application to existing category") {
		auto app_name = "App #1";
		auto app_url = "https://www.app.com";
		auto app_description = "lorem ipsum dolor senet";
		auto original_app = save_application(first_category, app_name, app_url, app_description);
		flush_and_reload();
		auto& first_category2 = db.list_categories().front();
		REQUIRE_FALSE(first_category2.get_groups().empty());
		auto& site = first_category2.get_groups().front();
		REQUIRE(original_app.get_id() == site.get_id());
		REQUIRE(GroupType::Application == site.get_type());
		REQUIRE(app_name == site.get_name());
		REQUIRE(app_url == site.get_url());
		REQUIRE(app_description == site.get_description());
	}
}

TEST_CASE_METHOD(JsonStorageFixture, "passwords")
{
	auto[categories, first_category] = initialize_db_with_category();
	auto group = save_group(first_category, "Group #1", "https://www.group.com", "lorem ipsum dolor senet");

	SECTION("add password to existing group") {
		auto password_username = "user@site.com";
		auto password_pass = SecureString::FromPlainText("test1234", "test1234");
		auto password_url = "https://site.com/login";
		auto password_description = "lorem ipsum dolor senet";
		Password password = PasswordFactory::make(group, password_username, password_pass, password_url,
				password_description);
		group.add_password(password);
		save_category_and_group(first_category, group);
		flush_and_reload();

		auto[first_category2, group2] = get_first_category_and_group();
		REQUIRE_FALSE(group2.get_passwords().empty());
		auto& saved_password = group2.get_passwords().front();
		assert_equals(password, saved_password);

		SECTION("add second password to existing group") {
			auto password2_username = "user2@site.com";
			auto password2_pass = SecureString::FromPlainText("test1234", "test1234");
			auto password2_url = "https://site.com/register";
			auto password2_description = "senet dolor ipsum lorem";
			Password password2 = PasswordFactory::make(group2, password2_username, password2_pass, password2_url,
					password2_description);
			group2.add_password(password2);
			save_category_and_group(first_category2, group2);
			flush_and_reload();

			auto[first_category3, group3] = get_first_category_and_group();
			REQUIRE(group3.get_passwords().size() == 2);
			auto it = group3.get_passwords().begin();
			assert_equals(password, *it); // first password
			assert_equals(password2, *(++it)); // second password

			SECTION("remove first password on existing group") {
				group3.remove_password(password);
				save_category_and_group(first_category3, group3);
				flush_and_reload();

				auto[first_category4, group4] = get_first_category_and_group();
				REQUIRE(group4.get_passwords().size() == 1);
				auto it2 = group4.get_passwords().begin();
				assert_equals(password2, *it2);
			}
		}
	}
}
