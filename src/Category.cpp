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

	Category& Category::add_group(Group& group)
	{
		groups.push_back(group);
		return *this;
	}

	optional<Group> Category::find_group(const string& group_name)
	{
		const auto match_group = [group_name](const Group& group) {
			return boost::iequals(group.get_name(), group_name);
		};
		auto filtered_iterator_begin = boost::make_filter_iterator(match_group, groups.cbegin(), groups.cend());
		auto filtered_iterator_end = boost::make_filter_iterator(match_group, groups.cend(), groups.cend());
		if (filtered_iterator_begin == filtered_iterator_end) return nullopt;
		return *filtered_iterator_begin;
	}

	list<reference_wrapper<Group>> Category::find_groups(const string& search)
	{
		list<reference_wrapper<Group>> results;
		const auto match_group = [search](const Group& group) {
			return boost::icontains(group.get_name(), search);
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

	Category& Category::remove_group(Group& group)
	{
		groups.remove_if([&group](const Group& other) {
			return other.get_name() == group.get_name();
		});
		return *this;
	}

	Category& Category::remove_group(const string& group_name)
	{
		groups.remove_if([group_name](const Group& group) {
			return group.get_name() == group_name;
		});
		return *this;
	}
}
