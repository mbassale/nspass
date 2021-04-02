//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_PASSWORDQUERY_H
#define OWNPASS_PASSWORDQUERY_H

#include "../OwnPass.h"
#include "../Password.h"
#include "Query.h"

#include <utility>
#include "GroupQuery.h"

namespace OwnPass::Query {
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

		PasswordQuery(Storage::Storage& storage, QueryArguments args)
				:Query<PasswordQueryItem>(storage), args{ std::move(args) } { }
		std::vector<PasswordQueryItem> execute() override;
	protected:
		QueryArguments args;
		std::vector<OwnPass::CategoryPtr> categories;
		std::vector<OwnPass::Query::GroupQueryItem> groups;

		void find_categories();
		void find_groups();
	};

}

#endif //OWNPASS_PASSWORDQUERY_H
