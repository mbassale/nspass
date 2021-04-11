//
// Created by mbassale on 11-04-21.
//
#include "../NSPass.h"
#include "UnixSettings.h"

namespace NSPass::Config {

	std::string UnixSettings::get_data_directory()
	{
		return std::string();
	}

	std::string UnixSettings::get_temp_directory()
	{
		return std::string();
	}
}
