//
// Created by Marco Bassaletti on 24-02-21.
//

#include "Category.h"
#include "Group.h"
#include <boost/algorithm/string.hpp>
#include <boost/iterator/filter_iterator.hpp>

namespace NSPass {
	using namespace std;

	Category& Category::add_group(const GroupPtr& group)
	{
		groups.push_back(group);
		std::sort(groups.begin(), groups.end(),
				[](const GroupPtr& group1, const GroupPtr& group2) -> bool {
					return group1->get_name() < group2->get_name();
				});
		return *this;
	}

	GroupPtr Category::find_group(ObjectId group_id)
	{
		auto match_group = [group_id](const GroupPtr& group) {
			return group_id == group->get_id();
		};
		auto filtered_iterator_begin = boost::make_filter_iterator(match_group, groups.begin(), groups.end());
		auto filtered_iterator_end = boost::make_filter_iterator(match_group, groups.end(), groups.end());
		if (filtered_iterator_begin == filtered_iterator_end) return nullptr;
		return *filtered_iterator_begin;
	}

	GroupPtr Category::find_group(string_view group_name)
	{
		auto match_group = [group_name](const GroupPtr& group) {
			return boost::iequals(group->get_name(), group_name);
		};
		auto filtered_iterator_begin = boost::make_filter_iterator(match_group, groups.begin(), groups.end());
		auto filtered_iterator_end = boost::make_filter_iterator(match_group, groups.end(), groups.end());
		if (filtered_iterator_begin == filtered_iterator_end) return nullptr;
		return *filtered_iterator_begin;
	}

	list<GroupPtr> Category::find_groups(string_view search)
	{
		list<GroupPtr> results;
		const auto match_group = [search](const GroupPtr& group) {
			return boost::icontains(group->get_name(), search);
		};
		auto filtered_iterator_begin = boost::make_filter_iterator(match_group, groups.begin(), groups.end());
		auto filtered_iterator_end = boost::make_filter_iterator(match_group, groups.end(), groups.end());
		if (filtered_iterator_begin == filtered_iterator_end) return results;
		while (filtered_iterator_begin != filtered_iterator_end) {
			results.push_back(std::ref(*filtered_iterator_begin));
			filtered_iterator_begin++;
		}
		return results;
	}

	Category& Category::save_group(const GroupPtr& group)
	{
		auto it = find(groups.begin(), groups.end(), group);
		if (it == groups.end()) {
			groups.push_back(group);
		}
		else {
			*it = group;
		}
		std::sort(groups.begin(), groups.end(),
				[](const GroupPtr& group1, const GroupPtr& group2) -> bool {
					return group1->get_name() < group2->get_name();
				});
		return *this;
	}

	Category& Category::remove_group(const GroupPtr& group)
	{
		for (auto it = groups.begin(); it != groups.end(); it++) {
			if ((*it)->get_id() == group->get_id()) {
				groups.erase(it);
				break;
			}
		}
		return *this;
	}

	Category& Category::remove_group(string_view group_name)
	{
		for (auto it = groups.begin(); it != groups.end(); it++) {
			if ((*it)->get_name() == group_name) {
				groups.erase(it);
				break;
			}
		}
		return *this;
	}
}
