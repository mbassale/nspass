//
// Created by Marco Bassaletti on 12-03-21.
//

#ifndef OWNPASS_VAULT_H
#define OWNPASS_VAULT_H

#include "OwnPass.h"
#include "./storage/StorageFactory.h"
#include "./storage/Storage.h"

namespace OwnPass {
	using BaseStorage = Storage::Storage;

	class Vault {
	public:
		explicit Vault(OwnPass::Storage::StorageFactory& storage_factory) : storage_factory{ storage_factory } {}
		Vault(Vault const&) = delete;
		Vault(Vault&&) = delete;

		[[nodiscard]] std::string_view get_master_password() const { return master_password; }
		Vault& set_master_password(std::string_view new_master_password);
		BaseStorage& get_storage();

	private:
		OwnPass::Storage::StorageFactory& storage_factory;
		std::string master_password;
		std::unique_ptr<BaseStorage> storage{};
	};
}

#endif //OWNPASS_VAULT_H
