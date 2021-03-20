//
// Created by Marco Bassaletti on 19-03-21.
//

#include <string>
#include "../../catch.hpp"
#include "../../../src/cli/input/StringSecretInput.h"

using namespace std;
using OwnPass::CLI::Input::StringSecretInput;

class StringSecretInputFixture {
public:
	StringSecretInputFixture() = default;
protected:
	void assert_request(std::string_view secret)
	{
		StringSecretInput string_secret_input{ secret };
		REQUIRE(string_secret_input.request() == secret);
	}
};

TEST_CASE_METHOD(StringSecretInputFixture, "StringSecretInput - construct", "[secret input]")
{
	REQUIRE_NOTHROW(StringSecretInput{ "" });
	REQUIRE_NOTHROW(StringSecretInput{ "test1234" });
}

TEST_CASE_METHOD(StringSecretInputFixture, "StringSecretInput - request", "[secret input]")
{
	assert_request("");
	assert_request(" ");
	assert_request("test1234");
}
