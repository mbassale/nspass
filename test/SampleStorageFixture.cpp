//
// Created by Marco Bassaletti on 30-03-21.
//

#include "../src/OwnPass.h"
#include "TestUtility.h"
#include "SampleStorageFixture.h"

using namespace std;
using OwnPass::Application;
using OwnPass::CategoryFactory;
using OwnPass::GroupFactory;
using OwnPass::PasswordFactory;
using OwnPass::Crypto::SecureString;

SampleStorageFixture::SampleStorageFixture()
		:app{ Application::instance() }
{
	auto& vault = app.get_vault();
	vault.set_master_password(get_master_password());
	vault.set_storage_location(get_storage_location());
}

SampleStorageFixture::~SampleStorageFixture()
{
	auto& vault = app.get_vault();
	std::filesystem::remove(vault.get_storage_location());
}

void SampleStorageFixture::reset_sample_storage()
{
	auto& storage = app.get_vault().get_storage();
	storage.purge();
	for (size_t i = 0; i < 10; i++) {
		ostringstream ss;
		ss << "Category #" << i;
		auto category = CategoryFactory::make(ss.str());

		for (size_t j = 0; j < 10; j++) {
			ostringstream ss2;
			ss2 << "Group #" << i << '_' << j;
			auto group = GroupFactory::make_site(ss2.str());

			for (size_t k = 0; k < 10; k++) {
				ostringstream username;
				username << "user" << i << '_' << j << '_' << k << "@test.com";
				ostringstream plain_pass;
				plain_pass << "test" << i << '_' << j << '_' << k;
				auto secure_pass = SecureString::FromPlainText(username.str(), plain_pass.str());
				auto password = PasswordFactory::make(username.str(), secure_pass);
				group.add_password(password);
			}
			category.save_group(group);
		}

		storage.save_category(category);
	}
	storage.flush();
}

std::string SampleStorageFixture::get_master_password()
{
	return DefaultMasterPassword;
}
std::string SampleStorageFixture::get_storage_location()
{
	return TestUtility::get_random_filename();
}
