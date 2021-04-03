//
// Created by Marco Bassaletti on 03-04-21.
//

#ifndef OWNPASS_GROUPNOTFOUNDEXCEPTION_H
#define OWNPASS_GROUPNOTFOUNDEXCEPTION_H

#include "../OwnPass.h"
#include "RecordNotFoundException.h"

namespace OwnPass::Query {
	class GroupNotFoundException : public RecordNotFoundException {
	public:
		explicit GroupNotFoundException(const std::string& message)
				:RecordNotFoundException(message) { }
	};
}

#endif //OWNPASS_GROUPNOTFOUNDEXCEPTION_H
