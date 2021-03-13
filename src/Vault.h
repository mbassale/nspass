//
// Created by Marco Bassaletti on 12-03-21.
//

#ifndef OWNPASS_VAULT_H
#define OWNPASS_VAULT_H

#include <memory>
#include <string>
#include "./storage/Storage.h"

namespace OwnPass {

	class Vault {
	private:
		Vault() = default;
		std::string master_password;
		std::shared_ptr<OwnPass::Storage::Storage> storage;

	public:
		static Vault& instance()
		{
			static Vault INSTANCE;
			return INSTANCE;
		}

		Vault(Vault const&) = delete;
		void operator=(Vault const&) = delete;

		[[nodiscard]] const std::string& get_master_password() const { return master_password; }
		Vault& set_master_password(const std::string& new_master_password)
		{
			master_password = new_master_password;
			return *this;
		}

		OwnPass::Storage::Storage& get_storage() {
			if (!storage) {
				storage = Storage::StorageFactory::make();
			}
			return *storage;
		}
	};
}

#endif //OWNPASS_VAULT_H
