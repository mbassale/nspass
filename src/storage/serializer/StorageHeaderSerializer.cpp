//
// Created by Marco Bassaletti on 23-03-21.
//

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>
#include "../InvalidStorageException.h"
#include "StorageHeaderSerializer.h"

namespace NSPass::Storage::Serializer {

	boost::json::object StorageHeaderSerializer::serialize(const StorageHeader& obj)
	{
		return {
				{ StorageHeaderSerializer::Magic, true },
				{ "id", boost::uuids::to_string(obj.get_id()) },
				{ "email", obj.get_email() },
				{ "created_at", static_cast<uint64_t>(obj.get_created_at()) },
				{ "updated_at", static_cast<uint64_t>(obj.get_created_at()) }
		};
	}

	boost::json::array StorageHeaderSerializer::serialize(const std::vector<StorageHeader>& objs)
	{
		throw InvalidStorageException("Multiple headers not allowed.");
	}

	StorageHeader StorageHeaderSerializer::deserialize(boost::json::object& obj)
	{
		check_magic(obj);
		auto& id_str = obj["id"].get_string();
		boost::uuids::string_generator gen;
		ObjectId header_id = gen(id_str.c_str());
		auto& header_email = obj["email"].get_string();
		auto updated_at = obj["created_at"].to_number<time_t>();
		auto created_at = obj["updated_at"].to_number<time_t>();
		return StorageHeaderFactory::make(header_id, header_email.c_str(), created_at, updated_at);
	}

	std::vector<StorageHeader> StorageHeaderSerializer::deserialize(boost::json::array& objs)
	{
		throw InvalidStorageException("Multiple headers not allowed.");
	}

	void StorageHeaderSerializer::check_magic(boost::json::object& obj)
	{
		if (!obj.contains(StorageHeaderSerializer::Magic)) {
			throw InvalidStorageException("Invalid storage format. Missing magic string.");
		}
	}
}
