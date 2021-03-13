//
// Created by Marco Bassaletti on 12-03-21.
//

#include "catch.hpp"
#include <string>
#include "../Vault.h"

using namespace std;
using namespace OwnPass;

class VaultFixture {
public:
	VaultFixture()
	{
	}
protected:
	void assert_master_password(Vault& vault, const std::string& master_password)
	{
		REQUIRE(vault.set_master_password(master_password).get_master_password() == master_password);
	}
};

TEST_CASE_METHOD(VaultFixture, "get vault instance")
{
	REQUIRE_NOTHROW(Vault::instance());
}

TEST_CASE_METHOD(VaultFixture, "get/set password")
{
	auto& vault = Vault::instance();
	REQUIRE(vault.get_master_password().empty());
	assert_master_password(vault, "");
	assert_master_password(vault, " ");
	assert_master_password(vault, "    ");
	assert_master_password(vault, "test1234");
	assert_master_password(vault, "123456789 abcdefghijklmnopqrstuvwzyz ABCDEFGHIJKLMNOPQRSTUVWZYZ");
}

TEST_CASE_METHOD(VaultFixture, "get storage reference")
{
	Vault& vault = Vault::instance();
	REQUIRE_NOTHROW(vault.get_storage());
	auto& storage = vault.get_storage();
	REQUIRE_NOTHROW(storage.list_categories());
}
