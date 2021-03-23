//
// Created by Marco Bassaletti on 23-03-21.
//

#ifndef OWNPASS_STORAGEHEADER_H
#define OWNPASS_STORAGEHEADER_H

#include "../OwnPass.h"

namespace OwnPass::Storage {
	class StorageHeader {
	public:
		explicit StorageHeader(ObjectId id, std::string_view email, std::time_t created_at, std::time_t updated_at)
				:id{ id }, email{ email }, created_at{ created_at }, updated_at{ updated_at } { }

		[[nodiscard]] ObjectId get_id() const { return id; }
		[[nodiscard]] std::string_view get_email() const { return email; }
		[[nodiscard]] time_t get_created_at() const { return created_at; }
		[[nodiscard]] time_t get_updated_at() const { return updated_at; }

	protected:
		ObjectId id;
		std::string email{};
		std::time_t created_at{};
		std::time_t updated_at{};
	};

	class StorageHeaderFactory {
	public:
		static StorageHeader make(std::string_view email = "")
		{
			return StorageHeader{ IdGenerator::make(), email, std::time(nullptr), std::time(nullptr) };
		}

		static StorageHeader make(ObjectId id, std::string_view email, std::time_t created_at, std::time_t updated_at)
		{
			return StorageHeader{ id, email, created_at, updated_at };
		}
	};
}

#endif //OWNPASS_STORAGEHEADER_H
