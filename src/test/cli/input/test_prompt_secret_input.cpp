//
// Created by Marco Bassaletti on 19-03-21.
//

#include "../../catch.hpp"
#include "../../../cli/input/PromptSecretInput.h"

using OwnPass::CLI::Input::PromptSecretInput;

class PromptSecretInputFixture {
public:
	PromptSecretInputFixture() = default;
};

TEST_CASE_METHOD(PromptSecretInputFixture, "PromptSecretInput - construct")
{
	REQUIRE_NOTHROW(PromptSecretInput{});
}
