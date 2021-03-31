//
// Created by Marco Bassaletti on 30-03-21.
//

#include "CategoryQuery.h"
#include "GroupQuery.h"

namespace OwnPass::Query {

	std::vector<OwnPass::GroupRef> GroupQuery::execute()
	{
		find_categories();
		std::vector<GroupRef> results;
		for (auto& category : categories) {
			if (args.search.empty()) {
				auto& groups = category->get_groups();
				for (auto& group : groups) {
					results.push_back(std::ref(*group));
				}
			}
			else {
				auto category_groups = category->find_groups(args.search);
				for (auto group_ref : category_groups) {
					results.push_back(*group_ref);
				}
			}
		}
		return results;
	}

	void GroupQuery::find_categories()
	{
		CategoryQuery category_query{ storage, args.category_search };
		categories = category_query.execute();
	}
}
