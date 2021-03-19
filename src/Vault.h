//
// Created by Marco Bassaletti on 12-03-21.
//

#ifndef OWNPASS_VAULT_H
#define OWNPASS_VAULT_H

#include <memory>
#include <string>
#include "./storage/Storage.h"

namespace OwnPass {
	using Storage::StorageFactory;
	using BaseStorage = Storage::Storage;

	class Vault {
	public:
		Vault() = default;
		Vault(Vault const&) = delete;
		Vault(Vault&&) = delete;

		[[nodiscard]] std::string_view get_master_password() const { return master_password; }

		Vault& set_master_password(std::string_view new_master_password)
		{
			master_password = new_master_password;
			return *this;
		}

		BaseStorage& get_storage() {
			if (!storage) {
				storage = StorageFactory::make();
				if (!master_password.empty() && !storage->is_open()) {
					storage->open(master_password);
				}
			}
			return *storage;
		}

	private:
		std::string master_password;
		std::unique_ptr<BaseStorage> storage{};
	};
}

#endif //OWNPASS_VAULT_H
