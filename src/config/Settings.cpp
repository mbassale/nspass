//
// Created by Marco Bassaletti on 04-04-21.
//

#include "MacSettings.h"
#include "Settings.h"

namespace NSPass::Config {

	std::string Settings::get_data_directory()
	{
		return MacSettings::get_data_directory();
	}

	std::string Settings::get_temp_directory()
	{
		return MacSettings::get_temp_directory();
	}
}
