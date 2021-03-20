//
// Created by Marco Bassaletti on 19-03-21.
//

#include "StringSecretInput.h"

namespace OwnPass::CLI::Input {

	std::string StringSecretInput::request()
	{
		return secret;
	}
}
