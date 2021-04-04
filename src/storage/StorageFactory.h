//
// Created by Marco Bassaletti on 25-03-21.
//

#ifndef OWNPASS_STORAGEFACTORY_H
#define OWNPASS_STORAGEFACTORY_H

#include "Storage.h"

namespace NSPass::Storage {
	class StorageFactory {
	public:
		StorageFactory() = default;
		virtual ~StorageFactory() = default;
		virtual std::unique_ptr<Storage> make(std::string_view master_password, std::string_view storage_location) = 0;
	};
}

#endif //OWNPASS_STORAGEFACTORY_H
