//
// Created by Marco Bassaletti on 19-03-21.
//

#ifndef OWNPASS_PROMPTSECRETINPUT_H
#define OWNPASS_PROMPTSECRETINPUT_H

#include "SecretInput.h"

namespace OwnPass::CLI::Input {
	class PromptSecretInput : public SecretInput {
	public:
		PromptSecretInput() = default;
		~PromptSecretInput() override = default;

		std::string request() override;
	};
}

#endif //OWNPASS_PROMPTSECRETINPUT_H
