//
// Created by Marco Bassaletti on 10-03-21.
//

#include <list>
#include <boost/json.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>
#include "../../crypto/SecureString.h"
#include "../../Password.h"
#include "PasswordSerializer.h"

namespace OwnPass::Storage::Serializer {
	using namespace std;
	using namespace OwnPass;
	using namespace OwnPass::Crypto;

	boost::json::object PasswordSerializer::serialize(const Password& obj)
	{
		return {
				{ "id", boost::uuids::to_string(obj.get_id()) },
				{ "username", obj.get_username() },
				{ "password", obj.get_password().get_cipher_text() },
				{ "url", obj.get_url() },
				{ "description", obj.get_description() }
		};
	}
	boost::json::array PasswordSerializer::serialize(const std::list<Password>& objs)
	{
		boost::json::array password_data;
		for (auto& password : objs) {
			boost::json::object password_datum = serialize(password);
			password_data.push_back(password_datum);
		}
		return password_data;
	}
	Password PasswordSerializer::deserialize(boost::json::object& obj)
	{
		auto& id_str = obj["id"].as_string();
		boost::uuids::string_generator gen;
		boost::uuids::uuid id = gen(id_str.c_str());
		auto& username = obj["username"].as_string();
		auto& password_s = obj["password"].as_string();
		auto& url = obj["url"].as_string();
		auto& description = obj["description"].as_string();
		return PasswordFactory::make(id, username.c_str(), SecureString::FromCipherText(password_s.c_str()),
				url.c_str(), description.c_str());
	}
	std::list<Password> PasswordSerializer::deserialize(boost::json::array& objs)
	{
		std::list<Password> passwords;
		for (auto val : objs) {
			boost::json::object obj = val.as_object();
			passwords.push_back(deserialize(obj));
		}
		return passwords;
	}
}
