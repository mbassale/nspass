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
