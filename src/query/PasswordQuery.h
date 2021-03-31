//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_PASSWORDQUERY_H
#define OWNPASS_PASSWORDQUERY_H

#include "../OwnPass.h"
#include "../Password.h"
#include "Query.h"

namespace OwnPass::Query {

	class PasswordQuery : public Query<OwnPass::PasswordPtr> {
	public:
		struct QueryArguments {
			std::string category_search;
			std::string group_search;
			std::string username;
		};

		PasswordQuery(Storage::Storage& storage, QueryArguments args)
				:Query<OwnPass::PasswordPtr>(storage), args{ std::move(args) } { }
		std::list<OwnPass::PasswordPtr> execute() override;
	protected:
		QueryArguments args;
		std::list<OwnPass::CategoryRef> categories;
		std::list<OwnPass::GroupRef> groups;

		void find_categories();
		void find_groups();
	};

}

#endif //OWNPASS_PASSWORDQUERY_H
