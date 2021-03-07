//
// Created by Marco Bassaletti on 07-03-21.
//

#include <fstream>
#include <string>
#include <boost/json.hpp>
#include "JsonParser.h"

namespace OwnPass::Storage {
	using namespace std;

	JsonParser::JsonParser(const char* filename)
			:filename{ filename }
	{
		load();
	}

	void JsonParser::load()
	{
		if (!std::filesystem::exists(filename))
			return create_empty();
		else
			return parse();
	}

	void JsonParser::create_empty()
	{
		root = boost::json::value(boost::json::array_kind);
	}

	void JsonParser::parse()
	{
		ifstream is{ "./ownpass.json", std::ios::in };
		if (!is.is_open()) throw std::runtime_error("Cannot open storage file.");
		boost::json::stream_parser p;
		std::string line;
		while (std::getline(is, line))
			p.write(line);
		p.finish();
		root = p.release();
	}
}
