//
// Created by Marco Bassaletti on 10-03-21.
//

#ifndef OWNPASS_PASSWORDSERIALIZER_H
#define OWNPASS_PASSWORDSERIALIZER_H

#include "../Password.h"
#include "JsonSerializer.h"

namespace OwnPass::Storage {
	class PasswordSerializer : public JsonSerializer<Password> {
	public:
		explicit PasswordSerializer(const Group& group) : group{ group } {}
		~PasswordSerializer() = default;

		boost::json::object serialize(const Password& obj) override;
		boost::json::array serialize(const std::list<Password>& objs) override;
		Password deserialize(boost::json::object& obj) override;
		std::list<Password> deserialize(boost::json::array& objs) override;

	private:
		const Group& group;
	};
}

#endif //OWNPASS_PASSWORDSERIALIZER_H
