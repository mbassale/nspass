//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_CATEGORYQUERY_H
#define OWNPASS_CATEGORYQUERY_H

#include "../OwnPass.h"
#include "../Category.h"
#include "Query.h"

namespace OwnPass::Query {
	class CategoryQuery : public Query<OwnPass::CategoryRef> {
	public:
		CategoryQuery(Storage::Storage& storage, std::string_view search)
				:Query<OwnPass::CategoryRef>(storage), search{ search } { }
		std::list<OwnPass::CategoryRef> execute() override;
	protected:
		std::string search;
	};
}

#endif //OWNPASS_CATEGORYQUERY_H
