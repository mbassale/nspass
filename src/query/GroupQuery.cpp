//
// Created by Marco Bassaletti on 30-03-21.
//

#include "GroupNotFoundException.h"
#include "CategoryQuery.h"
#include "GroupQuery.h"

namespace NSPass::Query {

	GroupQueryItem GroupQuery::find(ObjectId group_id)
	{
		find_categories();
		results.clear();
		for (const auto& category : categories) {
			for (const auto& group : category->get_groups()) {
				if (group->get_id() == group_id) {
					results.emplace_back(category, group);
					return results.front();
				}
			}
		}
		std::ostringstream error_message;
		error_message << "Group not found: " << object_id_to_string(group_id);
		throw GroupNotFoundException{ error_message.str() };
	}

	std::vector<GroupQueryItem> GroupQuery::find()
	{
		find_categories();
		results.clear();
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

	GroupQueryItem GroupQuery::find_first()
	{
		find_categories();
		results.clear();
		for (const auto& category : categories) {
			if (args.search.empty()) {
				const auto& groups = category->get_groups();
				for (const auto& group : groups) {
					results.emplace_back(category, group);
					return results.front();
				}
			}
			else {
				const auto category_groups = category->find_groups(args.search);
				for (const auto& group : category_groups) {
					results.emplace_back(category, group);
					return results.front();
				}
			}
		}
		std::ostringstream error_message;
		error_message << "Group not found: " << args.search;
		throw GroupNotFoundException{ error_message.str() };
	}

	bool GroupQuery::empty()
	{
		return results.empty();
	}

	size_t GroupQuery::size()
	{
		return results.size();
	}
	void GroupQuery::find_categories()
	{
		CategoryQuery category_query{ storage, args.category_search };
		categories = category_query.find();
	}
}
