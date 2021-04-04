//
// Created by Marco Bassaletti on 05-03-21.
//

#ifndef OWNPASS_STORAGE_H
#define OWNPASS_STORAGE_H

#include "../NSPass.h"
#include "../Category.h"
#include "../Group.h"
#include "../Password.h"
#include "StorageHeader.h"

namespace NSPass::Storage {

	class Storage {
	public:
		Storage() = delete;
		Storage(std::string_view master_password, std::string_view storage_location)
				:master_password{ master_password }, storage_location{ storage_location } { }
		virtual ~Storage() = default;

		virtual void flush() = 0;
		virtual void reload() = 0;
		virtual void purge() = 0;
		virtual std::string dump() = 0;

		virtual StorageHeader& get_header() = 0;
		virtual std::vector<NSPass::CategoryPtr>& get_categories() = 0;
		virtual void save_category(const CategoryPtr& category) = 0;
		virtual CategoryPtr find_category(ObjectId category_id) = 0;
		virtual CategoryPtr find_category(std::string_view search) = 0;

	protected:
		std::string_view master_password;
		std::string_view storage_location;
	};
}

#endif //OWNPASS_STORAGE_H
