//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_JSONSTORAGE_H
#define OWNPASS_JSONSTORAGE_H

#include "Storage.h"
#include <list>
#include "../Category.h"
#include "../Group.h"

namespace OwnPass::Storage {
	class JsonStorage : public Storage {
	public:
		JsonStorage() = default;
		~JsonStorage() override;

		void open(std::string_view new_master_password) override;
		void close() override;
		void flush() override;
		void reload() override;
		void purge() override;

		[[nodiscard]] bool is_open() const override { return is_opened; }

		std::list<CategoryPtr>& list_categories() override;
		void save_category(CategoryPtr& category) override;
		std::optional<CategoryPtr> find_category(std::string_view search) override;

	private:
		static constexpr const char* StorageFile = "ownpass.dat";
		bool is_opened{ false };
		std::string_view master_password;
		std::list<CategoryPtr> categories;

		void load();
		void save();
		void save_and_close();
		void create_storage_file();
	};
}

#endif //OWNPASS_JSONSTORAGE_H
