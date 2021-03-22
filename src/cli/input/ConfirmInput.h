//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_CONFIRMINPUT_H
#define OWNPASS_CONFIRMINPUT_H

#include "UserInput.h"

namespace OwnPass::CLI::Input {
	class ConfirmInput : public UserInput<bool> {
	};
}

#endif //OWNPASS_CONFIRMINPUT_H
