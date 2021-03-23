//
// Created by Marco Bassaletti on 10-03-21.
//

#ifndef OWNPASS_PASSWORDSERIALIZER_H
#define OWNPASS_PASSWORDSERIALIZER_H

#include "../../Password.h"
#include "JsonSerializer.h"

namespace OwnPass::Storage::Serializer {
	class PasswordSerializer : public JsonSerializer<Password> {
	public:
		PasswordSerializer() = default;
		~PasswordSerializer() = default;

		boost::json::object serialize(const Password& obj) override;
		boost::json::array serialize(const std::list<Password>& objs) override;
		Password deserialize(boost::json::object& obj) override;
		std::list<Password> deserialize(boost::json::array& objs) override;
	};
}

#endif //OWNPASS_PASSWORDSERIALIZER_H
