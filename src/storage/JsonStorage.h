//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_JSONSTORAGE_H
#define OWNPASS_JSONSTORAGE_H

#include "../OwnPass.h"
#include "Storage.h"
#include "../Category.h"
#include "../Group.h"

namespace OwnPass::Storage {
	class JsonStorage : public Storage {
	public:
		JsonStorage(std::string_view master_password, std::string_view storage_filename);
		~JsonStorage() override;

		void flush() override;
		void reload() override;
		void purge() override;
		std::string dump() override;

		StorageHeader& get_header() override;
		std::vector<OwnPass::Category>& get_categories() override;
		Category& save_category(const Category& category) override;
		std::optional<CategoryRef> find_category(ObjectId category_id) override;
		std::optional<CategoryRef> find_category(std::string_view search) override;

	protected:
		StorageHeader storage_header;
		std::vector<Category> categories;

		void load();
		void save();
		void create_storage_file();
		void deserialize(std::string_view contents);
		void serialize();
		static void verify_file_header(std::string_view contents);
	};
}

#endif //OWNPASS_JSONSTORAGE_H
