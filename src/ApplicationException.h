//
// Created by Marco Bassaletti on 19-03-21.
//

#ifndef OWNPASS_APPLICATIONEXCEPTION_H
#define OWNPASS_APPLICATIONEXCEPTION_H

#include <stdexcept>

namespace OwnPass {
	class ApplicationException : public std::runtime_error {
	public:
		explicit ApplicationException(const std::string& string)
				:runtime_error(string) { }
	};
}

#endif //OWNPASS_APPLICATIONEXCEPTION_H
