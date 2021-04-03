//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../OwnPass.h"
#include "CategoryNotFoundException.h"
#include "CategoryQuery.h"

namespace OwnPass::Query {
	using OwnPass::CategoryRef;

	std::vector<CategoryPtr> CategoryQuery::find()
	{
		boost::algorithm::trim(search);
		results.clear();
		auto& categories = storage.get_categories();
		for (auto& category : categories) {
			if (search.empty() || boost::algorithm::icontains(category->get_name(), search))
				results.push_back(category);
		}
		return results;
	}

	OwnPass::CategoryPtr CategoryQuery::find_first()
	{
		boost::algorithm::trim(search);
		results.clear();
		auto& categories = storage.get_categories();
		for (auto& category : categories) {
			if (search.empty() || boost::algorithm::icontains(category->get_name(), search)) {
				results.push_back(category);
				return results.front();
			}
		}
		std::ostringstream error_message;
		error_message << "Category not found: " << search;
		throw CategoryNotFoundException(error_message.str());
	}

	bool CategoryQuery::empty()
	{
		return results.empty();
	}

	size_t CategoryQuery::size()
	{
		return results.size();
	}
}
