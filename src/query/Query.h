//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_QUERY_H
#define OWNPASS_QUERY_H

#include "../NSPass.h"
#include "../storage/Storage.h"

namespace NSPass::Query {
	template<typename T>
	class Query {
	public:
		explicit Query(NSPass::Storage::Storage& storage)
				:storage{ storage } { }
		virtual T find(ObjectId id) = 0;
		virtual std::vector<T> find() = 0;
		virtual T find_first() = 0;
		virtual bool empty() = 0;
		virtual size_t size() = 0;
	protected:
		NSPass::Storage::Storage& storage;
	};
}

#endif //OWNPASS_QUERY_H
