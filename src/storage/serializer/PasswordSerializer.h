//
// Created by Marco Bassaletti on 10-03-21.
//

#ifndef OWNPASS_PASSWORDSERIALIZER_H
#define OWNPASS_PASSWORDSERIALIZER_H

#include "../../Password.h"
#include "JsonSerializer.h"

namespace OwnPass::Storage::Serializer {
	class PasswordSerializer : public JsonSerializer<PasswordPtr> {
	public:
		PasswordSerializer() = default;
		~PasswordSerializer() = default;

		boost::json::object serialize(const PasswordPtr& obj) override;
		boost::json::array serialize(const std::vector<PasswordPtr>& objs) override;
		PasswordPtr deserialize(boost::json::object& obj) override;
		std::vector<PasswordPtr> deserialize(boost::json::array& objs) override;
	};
}

#endif //OWNPASS_PASSWORDSERIALIZER_H
