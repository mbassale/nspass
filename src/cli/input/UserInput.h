//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_USERINPUT_H
#define OWNPASS_USERINPUT_H

#include "../../OwnPass.h"

namespace OwnPass::CLI::Input {

	template<typename T>
	class UserInput {
	public:
		UserInput() = default;
		virtual ~UserInput() = default;

		virtual T request() = 0;
	};

}

#endif //OWNPASS_USERINPUT_H
