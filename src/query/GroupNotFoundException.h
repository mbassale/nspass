//
// Created by Marco Bassaletti on 03-04-21.
//

#ifndef OWNPASS_GROUPNOTFOUNDEXCEPTION_H
#define OWNPASS_GROUPNOTFOUNDEXCEPTION_H

#include "../NSPass.h"
#include "RecordNotFoundException.h"

namespace NSPass::Query {
	class GroupNotFoundException : public RecordNotFoundException {
	public:
		explicit GroupNotFoundException(const std::string& message)
				:RecordNotFoundException(message) { }
	};
}

#endif //OWNPASS_GROUPNOTFOUNDEXCEPTION_H
