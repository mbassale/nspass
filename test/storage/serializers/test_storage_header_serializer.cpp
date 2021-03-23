//
// Created by Marco Bassaletti on 23-03-21.
//
#include "../../catch.hpp"
#include "../../../src/OwnPass.h"
#include "../../../src/storage/StorageHeader.h"
#include "../../../src/storage/serializer/StorageHeaderSerializer.h"

using namespace std;
using OwnPass::ObjectId;
using OwnPass::Storage::StorageHeader;
using OwnPass::Storage::StorageHeaderFactory;
using OwnPass::Storage::Serializer::StorageHeaderSerializer;

class StorageHeaderSerializerFixture {
public:
	StorageHeaderSerializerFixture() = default;
};

TEST_CASE_METHOD(StorageHeaderSerializerFixture, "StorageHeaderSerializer - serialize/deserialize", "[storage header serializer]")
{
	auto storage_header = StorageHeaderFactory::make("test@test.com");
	StorageHeaderSerializer storage_header_serializer{};
	auto json_data = storage_header_serializer.serialize(storage_header);
	stringstream ss;
	ss << json_data;
	boost::json::parser p;
	p.reset();
	p.write(ss.str().data());
	auto root = p.release();
	auto storage_header2 = storage_header_serializer.deserialize(root.as_object());
	REQUIRE(storage_header.get_id() == storage_header2.get_id());
	REQUIRE(storage_header.get_email() == storage_header2.get_email());
	REQUIRE(storage_header.get_created_at() == storage_header2.get_created_at());
	REQUIRE(storage_header.get_updated_at() == storage_header2.get_updated_at());
}
