//
// Created by Marco Bassaletti on 07-03-21.
//
#include <sstream>
#include <fstream>
#include <boost/json.hpp>
#include "JsonWriter.h"

namespace NSPass::Storage {
	using namespace std;

	JsonWriter::JsonWriter(boost::json::value& root) : root{ root }
	{
	}

	std::string JsonWriter::save()
	{
		ostringstream os;
		os << root;
		return os.str();
	}
}
