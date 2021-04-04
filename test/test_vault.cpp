//
// Created by Marco Bassaletti on 12-03-21.
//

#include "catch.hpp"
#include "TestUtility.h"
#include "../src/NSPass.h"
#include "../src/Application.h"

using namespace std;
using namespace NSPass;

class VaultFixture {
public:
	VaultFixture() = default;
protected:
	static Vault& get_vault(std::string_view master_password, std::string_view storage_location)
	{
		auto& vault = Application::instance().get_vault();
		vault.set_master_password(master_password);
		vault.set_storage_location(storage_location);
		return vault;
	}
};

TEST_CASE_METHOD(VaultFixture, "get vault instance")
{
	REQUIRE_NOTHROW(Application::instance().get_vault());
}

TEST_CASE_METHOD(VaultFixture, "get storage reference")
{
	auto master_password = TestUtility::random_string(16);
	auto storage_location = TestUtility::get_random_filename();
	auto& vault = get_vault(master_password, storage_location);
	REQUIRE_NOTHROW(vault.get_storage());
	auto& storage = vault.get_storage();
	REQUIRE_NOTHROW(storage.get_categories());
	std::filesystem::remove(storage_location);
}
