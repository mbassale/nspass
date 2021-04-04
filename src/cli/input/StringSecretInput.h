//
// Created by Marco Bassaletti on 19-03-21.
//

#ifndef OWNPASS_STRINGSECRETINPUT_H
#define OWNPASS_STRINGSECRETINPUT_H

#include <string>
#include "SecretInput.h"

namespace NSPass::CLI::Input {
	class StringSecretInput : public SecretInput {
	public:
		explicit StringSecretInput(std::string_view secret)
				:secret{ secret } { }
		~StringSecretInput() override = default;
		std::string request() override;
	protected:
		std::string secret;
	};
}

#endif //OWNPASS_STRINGSECRETINPUT_H
