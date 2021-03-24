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

		StorageHeader& get_header() override;
		std::list<OwnPass::Category>& list_categories() override;
		Category& save_category(Category& category) override;
		std::optional<CategoryRef> find_category(ObjectId category_id) override;
		std::optional<CategoryRef> find_category(std::string_view search) override;

	private:
		static constexpr const char* StorageFile = "ownpass.dat";
		bool is_opened{ false };
		std::string_view master_password;
		StorageHeader storage_header;
		std::list<Category> categories;

		void load();
		void save();
		void save_and_close();
		void create_storage_file();
		void deserialize(std::string_view contents);
		void serialize();
	};
}

#endif //OWNPASS_JSONSTORAGE_H
