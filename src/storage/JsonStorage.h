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
		JsonStorage(std::string_view master_password, std::string_view storage_filename);
		~JsonStorage() override;

		void flush() override;
		void reload() override;
		void purge() override;

		StorageHeader& get_header() override;
		std::list<OwnPass::Category>& list_categories() override;
		Category& save_category(Category& category) override;
		std::optional<CategoryRef> find_category(ObjectId category_id) override;
		std::optional<CategoryRef> find_category(std::string_view search) override;

	protected:
		StorageHeader storage_header;
		std::list<Category> categories;

		void load();
		void save();
		void create_storage_file();
		void deserialize(std::string_view contents);
		void serialize();
	};
}

#endif //OWNPASS_JSONSTORAGE_H
