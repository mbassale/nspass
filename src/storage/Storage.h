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

		virtual void open(std::string_view master_password) = 0;
		virtual void close() = 0;
		virtual void flush() = 0;
		virtual void reload() = 0;
		virtual void purge() = 0;

		[[nodiscard]] virtual bool is_open() const = 0;

		virtual std::list<CategoryPtr>& list_categories() = 0;
		virtual void save_category(CategoryPtr& category) = 0;
		virtual std::optional<CategoryPtr> find_category(std::string_view search) = 0;
	};

	typedef std::unique_ptr<Storage> StoragePtr;

	class StorageFactory {
	public:
		static StoragePtr make();
	private:
		StorageFactory() = default;
	};
}

#endif //OWNPASS_STORAGE_H
