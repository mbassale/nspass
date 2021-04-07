//
// Created by Marco Bassaletti on 23-03-21.
//

#ifndef OWNPASS_STORAGEEXCEPTION_H
#define OWNPASS_STORAGEEXCEPTION_H

#include "../NSPass.h"

namespace NSPass::Storage {
	class StorageException : public ApplicationException {
	public:
		explicit StorageException(const std::string& message)
				:ApplicationException(message) { }
	};
}

#endif //OWNPASS_STORAGEEXCEPTION_H
