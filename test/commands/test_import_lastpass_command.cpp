//
// Created by Marco Bassaletti on 01-04-21.
//
#include "../catch.hpp"
#include "../../src/OwnPass.h"
#include "../SampleStorageFixture.h"
#include "../../src/commands/ImportLastPassCommand.h"

using namespace std;
using OwnPass::Application;
using OwnPass::ApplicationException;
using OwnPass::Commands::ImportLastPassCommand;

class ImportLastPassCommandFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[import lastpass command]";
	static constexpr int MinCategoryNumber = 1;
	static constexpr int MaxCategoryNumber = 10;
	static constexpr int MinGroupNumber = 1;
	static constexpr int MaxGroupNumber = 10;
	static constexpr int MinPasswordNumber = 1;
	static constexpr int MaxPasswordNumber = 10;

	ImportLastPassCommandFixture()
	{
		ofstream fout{ filename };
		fout << "url,username,password,extra,name,grouping,fav" << std::endl;
		for (size_t i = MinCategoryNumber; i <= MaxCategoryNumber; i++) {
			ostringstream category;
			category << "Category #" << i;
			for (size_t j = MinGroupNumber; j <= MaxGroupNumber; j++) {
				ostringstream group;
				group << "Group #" << i << "_" << j;
				for (size_t k = MinPasswordNumber; k <= MaxPasswordNumber; k++) {
					ostringstream username, url, password;
					username << "user" << i << "_" << j << "_" << k << "@test.com";
					url << "https://test" << i << "-" << j << "-" << k << ".com";
					fout << url.str() << "," << username.str() << "," << password.str() << ",," << group.str() << ","
						 << category.str() << ",0" << std::endl;
				}
			}
		}
		fout.close();
	};
protected:
	std::string filename = "../data/test-lastpass-data.csv";
};

TEST_CASE_METHOD(ImportLastPassCommandFixture, "ImportLastPassCommand - Construct", ImportLastPassCommandFixture::Tag)
{
	REQUIRE_NOTHROW(ImportLastPassCommand{ Application::instance(), filename });
}

TEST_CASE_METHOD(ImportLastPassCommandFixture, "ImportLastPassCommand - Import", ImportLastPassCommandFixture::Tag)
{
	auto& storage = get_storage();
	storage.purge();
	REQUIRE(storage.get_categories().empty());
	ImportLastPassCommand import_last_pass{ Application::instance(), filename };
	import_last_pass.execute();
	REQUIRE_FALSE(storage.get_categories().empty());
	const auto& categories = storage.get_categories();
	std::regex category_regex{ R"(Category #(\d+))" };
	std::regex group_regex{ R"(Group #(\d+)_(\d+))" };
	std::regex password_regex{ R"(user(\d+)_(\d+)_(\d+)@test.com)" };
	for (const auto& category : categories) {
		std::string category_name{ category->get_name() };
		std::smatch category_matches;
		REQUIRE(std::regex_match(category_name, category_matches, category_regex));
		REQUIRE(category_matches.size() == 2);
		REQUIRE(category_matches[0] == category_name);
		const auto category_number = std::stoi(category_matches[1]);
		REQUIRE(category_number >= MinCategoryNumber);
		REQUIRE(category_number <= MaxCategoryNumber);

		REQUIRE_FALSE(category->get_groups().empty());
		const auto& groups = category->get_groups();
		for (const auto& group : groups) {
			std::string group_name{ group->get_name() };
			std::smatch group_matches;
			REQUIRE(std::regex_match(group_name, group_matches, group_regex));
			REQUIRE(group_matches.size() == 3);
			REQUIRE(group_matches[0] == group_name);
			const auto group_number = std::stoi(group_matches[2]);
			REQUIRE(group_number >= MinGroupNumber);
			REQUIRE(group_number <= MaxGroupNumber);

			REQUIRE_FALSE(group->get_passwords().empty());
			const auto& passwords = group->get_passwords();
			for (const auto& password : passwords) {
				std::string username{ password->get_username() };
				std::smatch password_matches;
				REQUIRE(std::regex_match(username, password_matches, password_regex));
				REQUIRE(password_matches.size() == 4);
				REQUIRE(password_matches[0] == username);
				const auto username_number = std::stoi(password_matches[3]);
				REQUIRE(username_number >= MinPasswordNumber);
				REQUIRE(username_number <= MaxPasswordNumber);
			}
		}
	}
}
