//
// Created by Marco Bassaletti on 22-02-21.
//
#include "OwnPass.h"
#include "Password.h"

namespace OwnPass {

	PasswordPtr PasswordFactory::make(std::string_view username, const SecureString& pass, std::string_view url,
			std::string_view description)
	{
		ObjectId password_id = IdGenerator::make();
		return std::make_shared<Password>(password_id, username, pass, url, description);
	}

	PasswordPtr PasswordFactory::make(ObjectId id, std::string_view username, const SecureString& pass,
			std::string_view url, std::string_view description)
	{
		return std::make_shared<Password>(id, username, pass, url, description);
	}

}
