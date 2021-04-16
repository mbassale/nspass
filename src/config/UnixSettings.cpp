//
// Created by mbassale on 11-04-21.
//
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <filesystem>
#include "../NSPass.h"
#include "UnixSettings.h"

namespace NSPass::Config {
	namespace fs = std::filesystem;

	constexpr auto DataHome = ".local/share";

	constexpr auto DATA_DIRECTORY_NAME = "nspass";

	std::string get_home_directory()
	{
		const char* homedir = nullptr;
		if ((homedir = getenv("HOME")) == NULL) {
			homedir = getpwuid(getuid())->pw_dir;
		}
		return std::string(homedir);
	}

	std::string UnixSettings::get_data_directory()
	{
		fs::path home_dir = get_home_directory();
		fs::path local_share_dir(DataHome);
		fs::path full_data_directory = home_dir / local_share_dir / DATA_DIRECTORY_NAME;
		if (!fs::exists(full_data_directory))
			fs::create_directories(full_data_directory);
		return full_data_directory.string();
	}

	std::string UnixSettings::get_temp_directory()
	{
		return fs::temp_directory_path();
	}
}
