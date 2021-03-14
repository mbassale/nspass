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
		JsonStorage();
		~JsonStorage() override;

		void flush() override;
		void reload() override;
		void purge() override;

		std::list<OwnPass::Category>& list_categories() override;
		Category& save_category(Category& category) override;
		Category& find_category(std::string_view search) override;

	private:
		static constexpr const char* StorageFile = "ownpass.json";
		std::list<Category> categories;

		void load();
		void save();
	};
}

#endif //OWNPASS_JSONSTORAGE_H
