//
// Created by Marco Bassaletti on 23-03-21.
//
#include "../../catch.hpp"
#include "../../TestUtility.h"
#include "../../../src/NSPass.h"
#include "../../../src/storage/StorageHeader.h"
#include "../../../src/storage/serializer/StorageHeaderSerializer.h"

using namespace std;
using NSPass::ObjectId;
using NSPass::Storage::StorageHeader;
using NSPass::Storage::StorageHeaderFactory;
using NSPass::Storage::Serializer::StorageHeaderSerializer;

class StorageHeaderSerializerFixture {
public:
	StorageHeaderSerializerFixture() = default;
protected:
	static void assert_storage_header_serializer(string_view email)
	{
		auto created_at = std::time(nullptr);
		auto updated_at = std::time(nullptr);
		auto storage_header1 = StorageHeaderFactory::make(email, created_at, updated_at);
		StorageHeaderSerializer storage_header_serializer1;
		auto json_data1 = storage_header_serializer1.serialize(storage_header1);
		auto json_string = TestUtility::convert_json_to_string(json_data1);
		auto json_data2 = TestUtility::convert_string_to_json(json_string);
		StorageHeaderSerializer storage_header_serializer2;
		auto storage_header2 = storage_header_serializer2.deserialize(json_data2);
		REQUIRE(storage_header1.get_id() == storage_header2.get_id());
		REQUIRE(storage_header1.get_email() == storage_header2.get_email());
		REQUIRE(storage_header1.get_created_at() == storage_header2.get_created_at());
		REQUIRE(storage_header1.get_updated_at() == storage_header2.get_updated_at());
		REQUIRE(storage_header2.get_created_at() == created_at);
		REQUIRE(storage_header2.get_updated_at() == updated_at);
	}
};

TEST_CASE_METHOD(StorageHeaderSerializerFixture, "StorageHeaderSerializer - serialize/deserialize",
		"[storage header serializer]")
{
	assert_storage_header_serializer("");
	assert_storage_header_serializer(" ");
	assert_storage_header_serializer("    ");
	assert_storage_header_serializer("test");
	assert_storage_header_serializer("test@test.com");
}
