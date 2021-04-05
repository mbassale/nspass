//
// Created by Marco Bassaletti on 04-04-21.
//

#ifndef NSPASS_SETTINGS_H
#define NSPASS_SETTINGS_H

#include "../NSPass.h"

namespace NSPass::Config {
	class Settings {
	public:
		virtual std::string get_data_directory() = 0;
		virtual std::string get_temp_directory() = 0;
	};

	typedef std::unique_ptr<Settings> SettingsPtr;
}

#endif //NSPASS_SETTINGS_H
