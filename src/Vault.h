//
// Created by Marco Bassaletti on 12-03-21.
//

#ifndef OWNPASS_VAULT_H
#define OWNPASS_VAULT_H

#include "NSPass.h"
#include "./storage/StorageFactory.h"
#include "./storage/Storage.h"

namespace NSPass {
	using BaseStorage = Storage::Storage;

	class Vault {
	public:
		explicit Vault(NSPass::Storage::StorageFactory& storage_factory) : storage_factory{ storage_factory } {}
		Vault(Vault const&) = delete;
		Vault(Vault&&) = delete;

		[[nodiscard]] std::string_view get_master_password() const { return master_password; }
		Vault& set_master_password(std::string_view new_master_password);

		[[nodiscard]] std::string_view get_storage_location() const { return storage_location; }
		Vault& set_storage_location(std::string_view new_storage_location);

		BaseStorage& get_storage();

	private:
		NSPass::Storage::StorageFactory& storage_factory;
		std::string master_password;
		std::string storage_location;
		std::unique_ptr<BaseStorage> storage{};
	};
}

#endif //OWNPASS_VAULT_H
