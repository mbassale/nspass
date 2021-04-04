//
// Created by Marco Bassaletti on 23-03-21.
//

#include "../InvalidStorageException.h"
#include "StorageHeaderSerializer.h"
#include "CategorySerializer.h"
#include "StorageSerializer.h"

namespace NSPass::Storage::Serializer {
	boost::json::object StorageSerializer::serialize(const StorageTuple& obj)
	{
		const auto&[storage_header, categories] = obj;
		StorageHeaderSerializer storage_header_serializer;
		boost::json::object header_obj = storage_header_serializer.serialize(storage_header);
		CategorySerializer categories_serializer;
		boost::json::array categories_obj = categories_serializer.serialize(categories);
		return {
				{ "header", header_obj },
				{ "categories", categories_obj }
		};
	}

	boost::json::array StorageSerializer::serialize(const std::vector<StorageTuple>& objs)
	{
		throw InvalidStorageException("Multiple storage objects not allowed.");
	}

	StorageTuple StorageSerializer::deserialize(boost::json::object& obj)
	{
		if (!obj.contains("header"))
			throw InvalidStorageException("Missing header record.");
		auto header_obj = obj["header"].as_object();
		StorageHeaderSerializer storage_header_serializer;
		auto storage_header = storage_header_serializer.deserialize(header_obj);
		if (!obj.contains("categories"))
			throw InvalidStorageException("Missing categories record.");
		auto categories_array = obj["categories"].as_array();
		CategorySerializer categories_serializer;
		auto categories = categories_serializer.deserialize(categories_array);
		return StorageTuple{ storage_header, categories };
	}

	std::vector<StorageTuple> StorageSerializer::deserialize(boost::json::array& objs)
	{
		throw InvalidStorageException("Multiple storage objects not allowed.");
	}
}
