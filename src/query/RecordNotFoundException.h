//
// Created by Marco Bassaletti on 03-04-21.
//

#ifndef OWNPASS_RECORDNOTFOUNDEXCEPTION_H
#define OWNPASS_RECORDNOTFOUNDEXCEPTION_H

#include "../ApplicationException.h"

namespace NSPass::Query {
	class RecordNotFoundException : public ApplicationException {
	public:
		explicit RecordNotFoundException(const char* message)
				:ApplicationException(message) { }
		explicit RecordNotFoundException(const std::string& message)
				:ApplicationException(message) { }
	};
}

#endif //OWNPASS_RECORDNOTFOUNDEXCEPTION_H
