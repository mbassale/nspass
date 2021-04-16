//
// Created by Marco Bassaletti on 14-04-21.
//
#include "../catch.hpp"
#include "../../src/config/UnixSettings.h"

using NSPass::Config::UnixSettings;

class UnixSettingsFixture {
public:
	static constexpr auto Tag = "[unix settings]";
	UnixSettingsFixture() = default;
};

TEST_CASE_METHOD(UnixSettingsFixture, "UnixSettings - create settings instance", UnixSettingsFixture::Tag)
{
	REQUIRE_NOTHROW(UnixSettings{});
}

TEST_CASE_METHOD(UnixSettingsFixture, "UnixSettings - get data directory", UnixSettingsFixture::Tag)
{
	UnixSettings unix_settings{};
	std::string data_directory = unix_settings.get_data_directory();
	std::cout << "Data Directory: " << data_directory << std::endl;
	REQUIRE_FALSE(data_directory.empty());
}

TEST_CASE_METHOD(UnixSettingsFixture, "UnixSettings - get temp directory", UnixSettingsFixture::Tag)
{
	UnixSettings unix_settings{};
	std::string temp_directory = unix_settings.get_temp_directory();
	std::cout << "Temp Directory: " << temp_directory << std::endl;
	REQUIRE_FALSE(temp_directory.empty());
}
