//
// Created by Marco Bassaletti on 05-04-21.
//

#ifndef NSPASS_MACSETTINGS_H
#define NSPASS_MACSETTINGS_H

#include "../NSPass.h"
#include "Settings.h"

namespace NSPass::Config {
	class MacSettings : public Settings {
	public:
		MacSettings() = default;
		~MacSettings() override = default;

		std::string get_data_directory() override;
		std::string get_temp_directory() override;
	};
}

#endif //NSPASS_MACSETTINGS_H
