//
// Created by Marco Bassaletti on 30-03-21.
//

#include <boost/algorithm/string.hpp>
#include "CategoryQuery.h"

namespace OwnPass::Query {
	using OwnPass::CategoryRef;

	std::list<CategoryRef> CategoryQuery::execute()
	{
		boost::algorithm::trim(search);
		std::list<CategoryRef> results;
		auto& categories = storage.get_categories();
		for (auto& category : categories) {
			if (search.empty() || boost::algorithm::icontains(category.get_name(), search))
				results.emplace_back(category);
		}
		return results;
	}
}
