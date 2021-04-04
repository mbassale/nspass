//
// Created by Marco Bassaletti on 18-03-21.
//

#ifndef OWNPASS_INVALIDCOMMANDSYNTAXEXCEPTION_H
#define OWNPASS_INVALIDCOMMANDSYNTAXEXCEPTION_H

#include <stdexcept>
#include <string>

namespace NSPass::CLI {
	class InvalidCommandSyntaxException : public std::runtime_error {
	public:
		explicit InvalidCommandSyntaxException(const std::string& message) : std::runtime_error(message) {}
	};
}

#endif //OWNPASS_INVALIDCOMMANDSYNTAXEXCEPTION_H
