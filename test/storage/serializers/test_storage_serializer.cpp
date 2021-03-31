//
// Created by Marco Bassaletti on 23-03-21.
//

#include "../../catch.hpp"
#include "../../../src/OwnPass.h"
#include "../../../src/storage/StorageHeader.h"
#include "../../../src/Category.h"
#include "../../../src/storage/serializer/StorageSerializer.h"
#include <iostream>

using namespace std;
using OwnPass::Storage::StorageHeader;
using OwnPass::Storage::StorageHeaderFactory;
using OwnPass::Category;
using OwnPass::CategoryPtr;
using OwnPass::CategoryFactory;
using OwnPass::Storage::Serializer::StorageTuple;
using OwnPass::Storage::Serializer::StorageSerializer;

class StorageSerializerFixture {
public:
	StorageSerializerFixture() = default;
};

TEST_CASE_METHOD(StorageSerializerFixture, "StorageSerializer - serialize/deserialize", "[storage serializer]")
{
	constexpr size_t categories_size = 10;
	auto storage_header = StorageHeaderFactory::make("test@test.com");
	vector<CategoryPtr> categories;
	categories.reserve(categories_size);
	for (auto i = 1; i <= categories_size; i++) {
		stringstream ss;
		ss << "Category #" << i;
		categories.push_back(CategoryFactory::make(ss.str()));
	}

	StorageSerializer storage_serializer{};
	auto serialized_storage = storage_serializer.serialize(StorageTuple{ storage_header, categories });
	auto[storage_header2, categories2] = storage_serializer.deserialize(serialized_storage);
	REQUIRE(storage_header.get_id() == storage_header2.get_id());
	REQUIRE(storage_header.get_email() == storage_header2.get_email());
	REQUIRE(storage_header.get_created_at() == storage_header2.get_created_at());
	REQUIRE(storage_header.get_updated_at() == storage_header2.get_updated_at());

	int index = 1;
	auto it = categories2.begin();
	while (it != categories2.end()) {
		stringstream ss;
		ss << "Category #" << index;
		REQUIRE((*it)->get_name() == ss.str());
		index++;
		it++;
	}
}
