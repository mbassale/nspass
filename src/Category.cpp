//
// Created by Marco Bassaletti on 24-02-21.
//

#include "Category.h"
#include "Group.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/iterator/filter_iterator.hpp>

namespace OwnPass {
	using namespace std;

	Category& Category::add_group(GroupPtr& group)
	{
		groups.push_back(group);
		return *this;
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
			results.push_back(*filtered_iterator_begin);
			filtered_iterator_begin++;
		}
		return results;
	}

	Category& Category::save_group(GroupPtr& group)
	{
		auto it = find(groups.begin(), groups.end(), group);
		if (it == groups.end()) {
			groups.push_back(group);
		}
		return *this;
	}

	Category& Category::remove_group(GroupPtr& group)
	{
		groups.remove_if([&group](const GroupPtr& other) {
			return other->get_name() == group->get_name();
		});
		return *this;
	}

	Category& Category::remove_group(string_view group_name)
	{
		groups.remove_if([group_name](const GroupPtr& group) {
			return group->get_name() == group_name;
		});
		return *this;
	}
}
