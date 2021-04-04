//
// Created by Marco Bassaletti on 23-03-21.
//

#ifndef OWNPASS_STORAGEHEADERSERIALIZER_H
#define OWNPASS_STORAGEHEADERSERIALIZER_H

#include "../../NSPass.h"
#include <boost/json.hpp>
#include "../StorageHeader.h"
#include "JsonSerializer.h"

namespace NSPass::Storage::Serializer {
	class StorageHeaderSerializer : public JsonSerializer<StorageHeader> {
	public:
		static constexpr auto Magic = "MOPM";
		StorageHeaderSerializer() = default;
		~StorageHeaderSerializer() = default;

		boost::json::object serialize(const StorageHeader& obj) override;
		boost::json::array serialize(const std::vector<StorageHeader>& objs) override;

		StorageHeader deserialize(boost::json::object& obj) override;
		std::vector<StorageHeader> deserialize(boost::json::array& objs) override;
	protected:
		static void check_magic(boost::json::object& obj);
	};
}

#endif //OWNPASS_STORAGEHEADERSERIALIZER_H
