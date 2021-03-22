//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_PROMPTCONFIRMINPUT_H
#define OWNPASS_PROMPTCONFIRMINPUT_H

#include "../../OwnPass.h"
#include "ConfirmInput.h"

namespace OwnPass::CLI::Input {
	class PromptConfirmInput : public ConfirmInput {
	public:
		PromptConfirmInput() = default;
		~PromptConfirmInput() override = default;

		bool request() override;
	};
}

#endif //OWNPASS_PROMPTCONFIRMINPUT_H
