//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../catch.hpp"
#include "../../src/OwnPass.h"
#include "../../src/Application.h"
#include "../../src/commands/CopyPasswordCommand.h"

using OwnPass::Application;
using OwnPass::Commands::CopyPasswordCommand;

class CopyPasswordCommandFixture {
public:
	static constexpr auto Tag = "[copy command]";
	CopyPasswordCommandFixture() = default;
};

TEST_CASE_METHOD(CopyPasswordCommandFixture, "CopyPasswordCommand - Construct", CopyPasswordCommandFixture::Tag)
{
	REQUIRE_NOTHROW(CopyPasswordCommand{ Application::instance() });
}

TEST_CASE_METHOD(CopyPasswordCommandFixture, "CopyPasswordCommand - Execute", CopyPasswordCommandFixture::Tag)
{
	CopyPasswordCommand copy_password_command{ Application::instance() };
	copy_password_command.execute();
}
