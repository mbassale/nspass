//
// Created by Marco Bassaletti on 23-03-21.
//

#ifndef OWNPASS_INVALIDSTORAGEEXCEPTION_H
#define OWNPASS_INVALIDSTORAGEEXCEPTION_H

#include "../NSPass.h"
#include "StorageException.h"

namespace NSPass::Storage {
	class InvalidStorageException : public StorageException {
	public:
		explicit InvalidStorageException(const std::string& message)
				:StorageException(message) { }
	};
}

#endif //OWNPASS_INVALIDSTORAGEEXCEPTION_H
