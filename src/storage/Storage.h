//
// Created by Marco Bassaletti on 05-03-21.
//

#ifndef OWNPASS_STORAGE_H
#define OWNPASS_STORAGE_H

#include <memory>
#include <string>
#include <list>
#include "../Category.h"
#include "../Group.h"
#include "../Password.h"

namespace OwnPass::Storage {

	class Storage {
	public:
		Storage() = default;
		virtual ~Storage() = 0;

		virtual void flush() = 0;
		virtual void reload() = 0;
		virtual void purge() = 0;

		virtual std::list<OwnPass::Category>& list_categories() = 0;
		virtual Category& save_category(Category& category) = 0;
		virtual Category& find_category(std::string_view search) = 0;
	};

	class StorageFactory {
	public:
		static Storage& make();
	private:
		StorageFactory() = default;
	};
}

#endif //OWNPASS_STORAGE_H
