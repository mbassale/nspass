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
	class GroupQuery : public Query<OwnPass::GroupPtr> {
	public:
		struct QueryArguments {
			std::string category_search;
			std::string search;
		};

		GroupQuery(Storage::Storage& storage, QueryArguments args)
				:Query<OwnPass::GroupPtr>(storage), args{ std::move(args) } { }
		std::vector<OwnPass::GroupPtr> execute() override;
	protected:
		QueryArguments args;
		std::vector<OwnPass::CategoryPtr> categories;
		void find_categories();
	};
}

#endif //OWNPASS_GROUPQUERY_H
