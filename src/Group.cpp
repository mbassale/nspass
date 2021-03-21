//
// Created by Marco Bassaletti on 22-02-21.
//

#include "Group.h"
#include <boost/algorithm/string.hpp>
#include <boost/iterator/filter_iterator.hpp>

namespace OwnPass {
	using namespace std;

	std::optional<PasswordRef> Group::find_password(ObjectId password_id) {
		auto match_group = [password_id](const Password& password) {
			return password_id == password.get_id();
		};
		auto filtered_iterator_begin = boost::make_filter_iterator(match_group, passwords.begin(), passwords.end());
		auto filtered_iterator_end = boost::make_filter_iterator(match_group, passwords.end(), passwords.end());
		if (filtered_iterator_begin == filtered_iterator_end) return nullopt;
		return *filtered_iterator_begin;
	}

	std::optional<PasswordRef> Group::find_password(std::string_view username) {
		auto match_group = [username](const Password& password) {
			return boost::iequals(password.get_username(), username);
		};
		auto filtered_iterator_begin = boost::make_filter_iterator(match_group, passwords.begin(), passwords.end());
		auto filtered_iterator_end = boost::make_filter_iterator(match_group, passwords.end(), passwords.end());
		if (filtered_iterator_begin == filtered_iterator_end) return nullopt;
		return *filtered_iterator_begin;
	}
}
