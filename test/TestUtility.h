//
// Created by Marco Bassaletti on 21-03-21.
//

#ifndef OWNPASS_TESTUTILITY_H
#define OWNPASS_TESTUTILITY_H

#include "catch.hpp"
#include <memory>
#include <typeinfo>
#include <string>
#include <vector>
#include <list>
#include <boost/json.hpp>

class TestUtility {
public:
	TestUtility() = delete;
	TestUtility(const TestUtility&) = delete;

	static int get_argc(const char* argv[]);
	static std::string convert_json_to_string(const boost::json::object& json);
	static boost::json::object convert_string_to_json(std::string_view str);
	static uint32_t random_integer(uint32_t min, uint32_t max);
	static std::string random_string(size_t length);
	static std::string get_random_filename();
	static std::string get_clipboard_text();
};

#endif //OWNPASS_TESTUTILITY_H
