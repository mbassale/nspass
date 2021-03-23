//
// Created by Marco Bassaletti on 23-03-21.
//

#ifndef OWNPASS_STORAGEHEADERSERIALIZER_H
#define OWNPASS_STORAGEHEADERSERIALIZER_H

#include "../../OwnPass.h"
#include <boost/json.hpp>
#include "../StorageHeader.h"
#include "JsonSerializer.h"

namespace OwnPass::Storage::Serializer {
	class StorageHeaderSerializer : public JsonSerializer<StorageHeader> {
	public:
		static constexpr auto Magic = "MOPM";
		StorageHeaderSerializer() = default;
		~StorageHeaderSerializer() = default;

		boost::json::object serialize(const StorageHeader& obj) override;
		boost::json::array serialize(const std::list<StorageHeader>& objs) override;

		StorageHeader deserialize(boost::json::object& obj) override;
		std::list<StorageHeader> deserialize(boost::json::array& objs) override;
	protected:
		void check_magic(boost::json::object& obj);
	};
}

#endif //OWNPASS_STORAGEHEADERSERIALIZER_H
