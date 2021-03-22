//
// Created by Marco Bassaletti on 21-03-21.
//

#include "../../catch.hpp"
#include "../../../src/cli/input/PromptConfirmInput.h"

using OwnPass::CLI::Input::PromptConfirmInput;

class PromptConfirmInputFixture {
public:
	PromptConfirmInputFixture() = default;
};

TEST_CASE_METHOD(PromptConfirmInputFixture, "PromptConfirmInput - construct")
{
	REQUIRE_NOTHROW(PromptConfirmInput{});
}
