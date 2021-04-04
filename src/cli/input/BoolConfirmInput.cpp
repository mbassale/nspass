//
// Created by Marco Bassaletti on 21-03-21.
//

#include "BoolConfirmInput.h"

namespace NSPass::CLI::Input {
	bool BoolConfirmInput::request()
	{
		return confirm;
	}
}
