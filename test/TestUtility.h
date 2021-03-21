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

class TestUtility {
public:
	TestUtility() = delete;
	TestUtility(const TestUtility&) = delete;

	static int get_argc(const char* argv[]);
};

#endif //OWNPASS_TESTUTILITY_H
