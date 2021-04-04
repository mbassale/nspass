//
// Created by Marco Bassaletti on 21-03-21.
//

#include "../../catch.hpp"
#include "../../../src/cli/input/BoolConfirmInput.h"

using NSPass::CLI::Input::BoolConfirmInput;

class BoolConfirmInputFixture {
public:
	BoolConfirmInputFixture() = default;
protected:
	void assert_request(bool confirm)
	{
		BoolConfirmInput bool_confirm_input{ confirm };
		REQUIRE(bool_confirm_input.request() == confirm);
	}
};

TEST_CASE_METHOD(BoolConfirmInputFixture, "BoolConfirmInput - construct")
{
	REQUIRE_NOTHROW(BoolConfirmInput{ true });
	REQUIRE_NOTHROW(BoolConfirmInput{ false });
}

TEST_CASE_METHOD(BoolConfirmInputFixture, "BoolConfirmInput - request", "[secret input]")
{
	assert_request(true);
	assert_request(false);
}
