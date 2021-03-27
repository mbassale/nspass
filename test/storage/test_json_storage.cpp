//
// Created by Marco Bassaletti on 05-03-21.
//
#include "../catch.hpp"
#include "../TestUtility.h"
#include "../../src/OwnPass.h"
#include "../../src/storage/Storage.h"
#include "../../src/storage/JsonStorage.h"
#include "../../src/storage/JsonStorageFactory.h"

using namespace std;
using OwnPass::Storage::JsonStorage;
using OwnPass::Storage::JsonStorageFactory;

class JsonStorageFixture {
public:
	static constexpr auto Tag = "[json storage]";
	JsonStorageFixture() = default;
};

TEST_CASE_METHOD(JsonStorageFixture, "JsonStorage - factory", JsonStorageFixture::Tag)
{
	JsonStorageFactory storage_factory;
	auto storage_filename = TestUtility::get_random_filename();
	REQUIRE_NOTHROW(storage_factory.make("test1234", storage_filename));
	std::filesystem::remove(storage_filename);
}

TEST_CASE_METHOD(JsonStorageFixture, "JsonStorage - open with wrong password", JsonStorageFixture::Tag)
{
	JsonStorageFactory storage_factory;
	auto storage_filename = TestUtility::get_random_filename();
	REQUIRE_NOTHROW(storage_factory.make("test1234", storage_filename));
	REQUIRE_NOTHROW(storage_factory.make("test1234", storage_filename));
	REQUIRE_THROWS(storage_factory.make("test", storage_filename));
	std::filesystem::remove(storage_filename);
}
