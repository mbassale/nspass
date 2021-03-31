//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_QUERY_H
#define OWNPASS_QUERY_H

#include "../OwnPass.h"
#include "../storage/Storage.h"

namespace OwnPass::Query {
	template<typename T>
	class Query {
	public:
		explicit Query(OwnPass::Storage::Storage& storage) : storage{ storage } {}
		virtual std::vector<T> execute() = 0;
	protected:
		OwnPass::Storage::Storage& storage;
	};
}

#endif //OWNPASS_QUERY_H
