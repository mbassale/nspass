//
// Created by Marco Bassaletti on 19-03-21.
//

#ifndef OWNPASS_SECRETINPUT_H
#define OWNPASS_SECRETINPUT_H

#include <string>

namespace OwnPass::CLI::Input {
	class SecretInput {
	public:
		SecretInput() = default;
		virtual ~SecretInput() = default;

		virtual std::string request() = 0;
	};
}

#endif //OWNPASS_SECRETINPUT_H
