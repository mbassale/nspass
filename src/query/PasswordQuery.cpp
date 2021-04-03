//
// Created by Marco Bassaletti on 30-03-21.
//
#include "PasswordNotFoundException.h"
#include "CategoryQuery.h"
#include "GroupQuery.h"
#include "PasswordQuery.h"

namespace OwnPass::Query {
	using OwnPass::Category;
	using OwnPass::PasswordRef;

	std::vector<PasswordQueryItem> PasswordQuery::find()
	{
		find_groups();
		results.clear();
		for (const auto& group_item : groups) {
			const auto& passwords = group_item.group->get_passwords();
			for (const auto& password : passwords) {
				if (args.username.empty() || boost::algorithm::icontains(password->get_username(), args.username))
					results.emplace_back(group_item.category, group_item.group, password);
			}
		}
		return results;
	}

	PasswordQueryItem PasswordQuery::find_first()
	{
		find_groups();
		results.clear();
		for (const auto& group_item : groups) {
			const auto& passwords = group_item.group->get_passwords();
			for (const auto& password : passwords) {
				if (args.username.empty() || boost::algorithm::icontains(password->get_username(), args.username)) {
					results.emplace_back(group_item.category, group_item.group, password);
					return results.front();
				}
			}
		}
		std::ostringstream error_message;
		error_message << "Password not found: " << args.username;
		throw PasswordNotFoundException{ error_message.str() };
	}

	bool PasswordQuery::empty()
	{
		return results.empty();
	}

	size_t PasswordQuery::size()
	{
		return results.size();
	}

	void PasswordQuery::find_groups()
	{
		GroupQuery::QueryArguments group_query_args;
		group_query_args.category_search = args.category_search;
		group_query_args.search = args.group_search;
		GroupQuery group_query{ storage, group_query_args };
		groups = group_query.find();
	}
}
