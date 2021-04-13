//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_PASSWORDQUERY_H
#define OWNPASS_PASSWORDQUERY_H

#include "../NSPass.h"
#include "../Password.h"
#include "Query.h"

#include "PasswordNotFoundException.h"
#include "GroupQuery.h"

namespace NSPass::Query {
	struct PasswordQueryItem {
		CategoryPtr category;
		GroupPtr group;
		PasswordPtr password;
		PasswordQueryItem(CategoryPtr category, GroupPtr group, PasswordPtr password)
				:category{ std::move(category) }, group{ std::move(group) }, password{ std::move(password) } { }
	};

	class PasswordQuery : public Query<PasswordQueryItem> {
	public:
		struct QueryArguments {
			std::string category_search;
			std::string group_search;
			std::string username;
		};

		explicit PasswordQuery(Storage::Storage& storage)
				:Query<PasswordQueryItem>(storage) { }
		PasswordQuery(Storage::Storage& storage, QueryArguments args)
				:Query<PasswordQueryItem>(storage), args{ std::move(args) } { }
		PasswordQueryItem find(ObjectId password_id) override;
		std::vector<PasswordQueryItem> find() override;
		PasswordQueryItem find_first() override;
		bool empty() override;
		size_t size() override;
	protected:
		QueryArguments args;
		std::vector<NSPass::CategoryPtr> categories;
		std::vector<NSPass::Query::GroupQueryItem> groups;
		std::vector<PasswordQueryItem> results;

		void find_groups();
	};

}

#endif //OWNPASS_PASSWORDQUERY_H
