//
// Created by Marco Bassaletti on 04-04-21.
//

#ifdef __APPLE__
#include "MacSettings.h"
#else
#include "UnixSettings.h"
#endif
#include "Settings.h"

namespace NSPass::Config {

	std::string Settings::get_data_directory()
	{
#ifdef __APPLE__
		return MacSettings::get_data_directory();
#else
		return UnixSettings::get_data_directory();
#endif

	}

	std::string Settings::get_temp_directory()
	{
#ifdef __APPLE__
		return MacSettings::get_temp_directory();
#else
		return UnixSettings::get_temp_directory();
#endif
	}
}
