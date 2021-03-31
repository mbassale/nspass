//
// Created by Marco Bassaletti on 30-03-21.
//

#include "CategoryQuery.h"
#include "GroupQuery.h"

namespace OwnPass::Query {

	std::vector<GroupQueryItem> GroupQuery::execute()
	{
		find_categories();
		std::vector<GroupQueryItem> results;
		for (const auto& category : categories) {
			if (args.search.empty()) {
				const auto& groups = category->get_groups();
				for (const auto& group : groups) {
					results.emplace_back(category, group);
				}
			}
			else {
				const auto category_groups = category->find_groups(args.search);
				for (const auto& group : category_groups) {
					results.emplace_back(category, group);
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
