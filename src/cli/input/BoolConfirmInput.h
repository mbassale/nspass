//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_BOOLCONFIRMINPUT_H
#define OWNPASS_BOOLCONFIRMINPUT_H

#include "../../OwnPass.h"
#include "ConfirmInput.h"

namespace OwnPass::CLI::Input {
	class BoolConfirmInput : public ConfirmInput {
	public:
		explicit BoolConfirmInput(bool confirm)
				:confirm{ confirm } { }
		~BoolConfirmInput() override = default;
		bool request() override;
	protected:
		bool confirm = false;
	};
}

#endif //OWNPASS_BOOLCONFIRMINPUT_H
