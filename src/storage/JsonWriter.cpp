//
// Created by Marco Bassaletti on 07-03-21.
//
#include <sstream>
#include <fstream>
#include <boost/json.hpp>
#include "JsonWriter.h"

namespace OwnPass::Storage {
	using namespace std;

	JsonWriter::JsonWriter(boost::json::value& root, const char* filename)
			:root{ root }, filename{ filename }
	{
	}

	void JsonWriter::save()
	{
		ofstream os{ filename, ios::out };
		if (!os.is_open()) {
			ostringstream error_message;
			error_message << "Cannot open file: " << filename;
			throw std::runtime_error(error_message.str());
		}
		os << root;
	}
}
