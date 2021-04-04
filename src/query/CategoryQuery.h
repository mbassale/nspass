//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_CATEGORYQUERY_H
#define OWNPASS_CATEGORYQUERY_H

#include "../NSPass.h"
#include "../Category.h"
#include "Query.h"

namespace NSPass::Query {
	class CategoryQuery : public Query<NSPass::CategoryPtr> {
	public:
		CategoryQuery(Storage::Storage& storage, std::string_view search)
				:Query<NSPass::CategoryPtr>(storage), search{ search } { }
		std::vector<NSPass::CategoryPtr> find() override;
		NSPass::CategoryPtr find_first() override;
		bool empty() override;
		size_t size() override;
	protected:
		std::string search;
		std::vector<NSPass::CategoryPtr> results{};
	};
}

#endif //OWNPASS_CATEGORYQUERY_H
