//
// Created by Marco Bassaletti on 05-03-21.
//

#ifndef OWNPASS_STORAGE_H
#define OWNPASS_STORAGE_H

#include "../OwnPass.h"
#include "../Category.h"
#include "../Group.h"
#include "../Password.h"
#include "StorageHeader.h"

namespace OwnPass::Storage {

	class Storage {
	public:
		Storage() = default;
		virtual ~Storage() = default;

		virtual void open(std::string_view master_password) = 0;
		virtual void close() = 0;
		virtual void flush() = 0;
		virtual void reload() = 0;
		virtual void purge() = 0;

		[[nodiscard]] virtual bool is_open() const = 0;

		virtual StorageHeader& get_header() = 0;
		virtual std::list<OwnPass::Category>& list_categories() = 0;
		virtual Category& save_category(Category& category) = 0;
		virtual std::optional<CategoryRef> find_category(ObjectId category_id) = 0;
		virtual std::optional<CategoryRef> find_category(std::string_view search) = 0;
	};
}

#endif //OWNPASS_STORAGE_H
