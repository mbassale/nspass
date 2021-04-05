//
// Created by Marco Bassaletti on 05-04-21.
//
#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../../src/Application.h"
#include "../../src/config/Settings.h"

using namespace std;
using NSPass::Config::Settings;

class SettingsFixture {
public:
	static constexpr auto Tag = "[settings]";
	SettingsFixture() = default;
};

TEST_CASE_METHOD(SettingsFixture, "Settings - create settings instance", SettingsFixture::Tag)
{
	REQUIRE_NOTHROW(Settings{});
}

TEST_CASE_METHOD(SettingsFixture, "Settings - get data directory", SettingsFixture::Tag)
{
	REQUIRE_NOTHROW([&] {
		Settings settings;
		auto data_directory = settings.get_data_directory();
		REQUIRE_FALSE(data_directory.empty());
	});
}

TEST_CASE_METHOD(SettingsFixture, "Settings - get temp directory", SettingsFixture::Tag)
{
	REQUIRE_NOTHROW([&] {
		Settings settings;
		auto temp_directory = settings.get_temp_directory();
		REQUIRE_FALSE(temp_directory.empty());
	});
}
