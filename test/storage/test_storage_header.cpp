//
// Created by Marco Bassaletti on 23-03-21.
//

#include "../catch.hpp"
#include "../../src/OwnPass.h"
#include "../../src/storage/StorageHeader.h"

using OwnPass::IdGenerator;
using OwnPass::Storage::StorageHeaderFactory;

class StorageHeaderFixture {
public:
	StorageHeaderFixture() = default;
};

TEST_CASE_METHOD(StorageHeaderFixture, "StorageHeader - static factory", "[storage header]")
{
	REQUIRE_NOTHROW(StorageHeaderFactory::make());
	REQUIRE_NOTHROW(StorageHeaderFactory::make("test@test.com"));
	REQUIRE(StorageHeaderFactory::make("test@test.com").get_email() == "test@test.com");
	auto id = IdGenerator::make();
	auto email = "test@test.com";
	auto created_at = std::time(nullptr);
	auto updated_at = std::time(nullptr);
	auto storage_header = StorageHeaderFactory::make(id, email, created_at, updated_at);
	REQUIRE(storage_header.get_id() == id);
	REQUIRE(storage_header.get_email() == email);
	REQUIRE(storage_header.get_created_at() == created_at);
	REQUIRE(storage_header.get_updated_at() == updated_at);
}
