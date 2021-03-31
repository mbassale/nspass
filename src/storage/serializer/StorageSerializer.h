//
// Created by Marco Bassaletti on 23-03-21.
//

#ifndef OWNPASS_STORAGESERIALIZER_H
#define OWNPASS_STORAGESERIALIZER_H

#include "../../OwnPass.h"
#include "JsonSerializer.h"
#include "../../Category.h"
#include "../StorageHeader.h"

namespace OwnPass::Storage::Serializer {

	typedef std::tuple<OwnPass::Storage::StorageHeader, std::vector<OwnPass::CategoryPtr>> StorageTuple;

	class StorageSerializer : public JsonSerializer<StorageTuple> {
	public:
		StorageSerializer() = default;
		~StorageSerializer() = default;

		boost::json::object serialize(const StorageTuple& obj) override;
		boost::json::array serialize(const std::vector<StorageTuple>& objs) override;

		StorageTuple deserialize(boost::json::object& obj) override;
		std::vector<StorageTuple> deserialize(boost::json::array& objs) override;
	};
}

#endif //OWNPASS_STORAGESERIALIZER_H
