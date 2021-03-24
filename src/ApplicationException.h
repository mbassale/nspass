//
// Created by Marco Bassaletti on 19-03-21.
//

#ifndef OWNPASS_APPLICATIONEXCEPTION_H
#define OWNPASS_APPLICATIONEXCEPTION_H

#include <stdexcept>

namespace OwnPass {
	class ApplicationException : public std::runtime_error {
	public:
		explicit ApplicationException(const char* message)
				:std::runtime_error(message) { }
		explicit ApplicationException(const std::string& message)
				:runtime_error(message) { }
	};
}

#endif //OWNPASS_APPLICATIONEXCEPTION_H
