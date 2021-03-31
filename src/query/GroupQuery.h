//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_GROUPQUERY_H
#define OWNPASS_GROUPQUERY_H

#include "../OwnPass.h"
#include "../Group.h"
#include "Query.h"

#include <utility>

namespace OwnPass::Query {
	struct GroupQueryItem {
		CategoryPtr category;
		GroupPtr group;
		GroupQueryItem(CategoryPtr category, GroupPtr group)
				:category{ std::move(category) }, group{ std::move(group) } { }
	};

	class GroupQuery : public Query<GroupQueryItem> {
	public:
		struct QueryArguments {
			std::string category_search;
			std::string search;
		};

		GroupQuery(Storage::Storage& storage, QueryArguments args)
				:Query<GroupQueryItem>(storage), args{ std::move(args) } { }
		std::vector<GroupQueryItem> execute() override;
	protected:
		QueryArguments args;
		std::vector<OwnPass::CategoryPtr> categories;
		void find_categories();
	};
}

#endif //OWNPASS_GROUPQUERY_H
