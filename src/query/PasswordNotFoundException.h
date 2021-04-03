//
// Created by Marco Bassaletti on 03-04-21.
//

#ifndef OWNPASS_PASSWORDNOTFOUNDEXCEPTION_H
#define OWNPASS_PASSWORDNOTFOUNDEXCEPTION_H

#include "../OwnPass.h"
#include "RecordNotFoundException.h"

namespace OwnPass::Query {
	class PasswordNotFoundException : public RecordNotFoundException {
	public:
		explicit PasswordNotFoundException(const std::string& password)
				:RecordNotFoundException(password) { }
	};
}

#endif //OWNPASS_PASSWORDNOTFOUNDEXCEPTION_H
