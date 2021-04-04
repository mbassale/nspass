//
// Created by Marco Bassaletti on 07-03-21.
//

#include <sstream>
#include <string>
#include <boost/json.hpp>
#include "JsonParser.h"

namespace NSPass::Storage {
	using namespace std;

	JsonParser::JsonParser(std::string_view contents) : contents{ contents }
	{
		load();
	}

	void JsonParser::load()
	{
		if (contents.empty())
			return create_empty();
		return parse();
	}

	void JsonParser::create_empty()
	{
		root = boost::json::value(boost::json::array_kind);
	}

	void JsonParser::parse()
	{
		boost::json::parser p;
		p.reset();
		p.write(contents.data());
		root = p.release();
	}
}
