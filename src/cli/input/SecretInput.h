//
// Created by Marco Bassaletti on 19-03-21.
//

#ifndef OWNPASS_SECRETINPUT_H
#define OWNPASS_SECRETINPUT_H

#include "../../OwnPass.h"
#include "UserInput.h"

namespace OwnPass::CLI::Input {
	class SecretInput : public UserInput<std::string> {
	};
}

#endif //OWNPASS_SECRETINPUT_H
