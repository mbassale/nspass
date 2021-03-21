//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_GROUPSERIALIZER_H
#define OWNPASS_GROUPSERIALIZER_H

#include <list>
#include "../Group.h"
#include "JsonSerializer.h"

namespace OwnPass::Storage {
	class GroupSerializer : public JsonSerializer<Group> {
	public:
		GroupSerializer() = default;
		~GroupSerializer() = default;

		boost::json::object serialize(const Group& obj) override;
		boost::json::array serialize(const std::list<Group>& objs) override;

		Group deserialize(boost::json::object& obj) override;
		std::list<Group> deserialize(boost::json::array& objs) override;
	};
}

#endif //OWNPASS_GROUPSERIALIZER_H
