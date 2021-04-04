//
// Created by Marco Bassaletti on 03-04-21.
//

#ifndef OWNPASS_CATEGORYNOTFOUNDEXCEPTION_H
#define OWNPASS_CATEGORYNOTFOUNDEXCEPTION_H

#include "../NSPass.h"
#include "RecordNotFoundException.h"

namespace NSPass::Query {
	class CategoryNotFoundException : public RecordNotFoundException {
	public:
		explicit CategoryNotFoundException(const std::string& message)
				:RecordNotFoundException(message) { }
	};
}

#endif //OWNPASS_CATEGORYNOTFOUNDEXCEPTION_H
