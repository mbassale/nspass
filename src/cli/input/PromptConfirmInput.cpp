//
// Created by Marco Bassaletti on 21-03-21.
//

#include <iostream>
#include "PromptConfirmInput.h"

namespace NSPass::CLI::Input {

	bool PromptConfirmInput::request()
	{
		std::string confirm_text{};
		do {
			std::cout << "Please confirm (Y/N): " << std::flush;
			std::cin >> confirm_text;
			boost::algorithm::to_lower(confirm_text);
			boost::algorithm::trim(confirm_text);
		}
		while (confirm_text != "y" && confirm_text != "n");
		return confirm_text == "y";
	}
}
