//
// Created by Marco Bassaletti on 23-03-21.
//

#ifndef OWNPASS_STORAGEEXCEPTION_H
#define OWNPASS_STORAGEEXCEPTION_H

#include "../OwnPass.h"

namespace OwnPass::Storage {
	class StorageException : public std::runtime_error {
	public:
		explicit StorageException(const std::string& message)
				:std::runtime_error(message) { }
	};
}

#endif //OWNPASS_STORAGEEXCEPTION_H
