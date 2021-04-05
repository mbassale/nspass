//
// Created by Marco Bassaletti on 05-04-21.
//
#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../../src/Application.h"
#include "../../src/config/MacSettings.h"

using namespace std;
using NSPass::Config::MacSettings;

class MacSettingsFixture {
public:
	static constexpr auto Tag = "[mac settings]";
	MacSettingsFixture() = default;
};

TEST_CASE_METHOD(MacSettingsFixture, "MacSettings - create settings instance.", MacSettingsFixture::Tag)
{
	REQUIRE_NOTHROW(MacSettings{});
}

TEST_CASE_METHOD(MacSettingsFixture, "MacSettings - get data directory")
{
	MacSettings mac_settings{};
	string data_directory = mac_settings.get_data_directory();
	std::cout << "Data Directory: " << data_directory << std::endl;
	REQUIRE_FALSE(data_directory.empty());
}

TEST_CASE_METHOD(MacSettingsFixture, "MacSettings - get temp directory") {
	MacSettings mac_settings{};
	string temp_directory = mac_settings.get_temp_directory();
	std::cout << "Temp Directory: " << temp_directory << std::endl;
	REQUIRE_FALSE(temp_directory.empty());
}
