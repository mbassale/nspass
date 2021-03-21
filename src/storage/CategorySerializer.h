//
// Created by Marco Bassaletti on 07-03-21.
//

#ifndef OWNPASS_CATEGORYSERIALIZER_H
#define OWNPASS_CATEGORYSERIALIZER_H

#include "JsonSerializer.h"
#include "../Category.h"
#include <list>
#include <boost/json.hpp>

namespace OwnPass::Storage {
	class CategorySerializer : public JsonSerializer<CategoryPtr> {
	public:
		CategorySerializer() = default;
		~CategorySerializer() = default;

		boost::json::object serialize(const CategoryPtr& obj) override;
		boost::json::array serialize(const std::list<CategoryPtr>& objs) override;

		CategoryPtr deserialize(boost::json::object& obj) override;
		std::list<CategoryPtr> deserialize(boost::json::array& objs) override;
	private:
		std::list<CategoryPtr> make_default();
	};
}

#endif //OWNPASS_CATEGORYSERIALIZER_H
