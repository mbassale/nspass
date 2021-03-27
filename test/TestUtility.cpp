//
// Created by Marco Bassaletti on 21-03-21.
//

#include "TestUtility.h"

int TestUtility::get_argc(const char* argv[])
{
	int count = 0;
	for (char** ptr = const_cast<char**>(argv); *ptr != nullptr; ptr++) count++;
	return count;
}

std::string TestUtility::convert_json_to_string(const boost::json::object& json) {
	std::stringstream ss;
	ss << json;
	return ss.str();
}

boost::json::object TestUtility::convert_string_to_json(std::string_view str) {
	boost::json::parser p;
	p.reset();
	p.write(str.data());
	auto root = p.release();
	return root.as_object();
}
