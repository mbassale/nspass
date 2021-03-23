//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_JSONSERIALIZER_H
#define OWNPASS_JSONSERIALIZER_H

#include <list>
#include <boost/json.hpp>

namespace OwnPass::Storage::Serializer {
	template<typename T>
	class JsonSerializer {
	public:
		JsonSerializer() = default;
		~JsonSerializer() = default;

		virtual boost::json::object serialize(const T& obj) = 0;
		virtual boost::json::array serialize(const std::list<T>& objs) = 0;

		virtual T deserialize(boost::json::object& obj) = 0;
		virtual std::list<T> deserialize(boost::json::array& objs) = 0;
	};
}

#endif //OWNPASS_JSONSERIALIZER_H
