//
// Created by Marco Bassaletti on 05-04-21.
//

#ifndef NSPASS_MACSETTINGS_H
#define NSPASS_MACSETTINGS_H

#include "../NSPass.h"

namespace NSPass::Config {
	class MacSettings {
	public:
		static std::string get_data_directory();
		static std::string get_temp_directory();
	};
}

#endif //NSPASS_MACSETTINGS_H
