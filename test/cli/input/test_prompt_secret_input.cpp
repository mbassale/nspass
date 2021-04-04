//
// Created by Marco Bassaletti on 19-03-21.
//

#include "../../catch.hpp"
#include "../../../src/cli/input/PromptSecretInput.h"

using NSPass::CLI::Input::PromptSecretInput;

class PromptSecretInputFixture {
public:
	PromptSecretInputFixture() = default;
};

TEST_CASE_METHOD(PromptSecretInputFixture, "PromptSecretInput - construct")
{
	REQUIRE_NOTHROW(PromptSecretInput{});
}
