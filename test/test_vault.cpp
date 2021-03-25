//
// Created by Marco Bassaletti on 12-03-21.
//

#include "catch.hpp"
#include <string>
#include "../src/Application.h"

using namespace std;
using namespace OwnPass;

class VaultFixture {
public:
	VaultFixture()
	{
	}
protected:
	Vault& get_vault()
	{
		auto& vault = Application::instance().get_vault();
		vault.set_master_password("test1234");
		return vault;
	}

	void assert_master_password(Vault& vault, const std::string& master_password)
	{
		REQUIRE(vault.set_master_password(master_password).get_master_password() == master_password);
	}
};

TEST_CASE_METHOD(VaultFixture, "get vault instance")
{
	REQUIRE_NOTHROW(Application::instance().get_vault());
}

TEST_CASE_METHOD(VaultFixture, "get/set password")
{
	auto& vault = get_vault();
	assert_master_password(vault, "");
	assert_master_password(vault, " ");
	assert_master_password(vault, "    ");
	assert_master_password(vault, "test1234");
	assert_master_password(vault, "123456789 abcdefghijklmnopqrstuvwzyz ABCDEFGHIJKLMNOPQRSTUVWZYZ");
}

TEST_CASE_METHOD(VaultFixture, "get storage reference")
{
	auto& vault = get_vault();
	REQUIRE_NOTHROW(vault.get_storage());
	auto& storage = vault.get_storage();
	REQUIRE_NOTHROW(storage.list_categories());
}
