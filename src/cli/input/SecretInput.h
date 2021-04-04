//
// Created by Marco Bassaletti on 19-03-21.
//

#ifndef OWNPASS_SECRETINPUT_H
#define OWNPASS_SECRETINPUT_H

#include "../../NSPass.h"
#include "UserInput.h"

namespace NSPass::CLI::Input {
	class SecretInput : public UserInput<std::string> {
	};
}

#endif //OWNPASS_SECRETINPUT_H
