//
// Created by mbassale on 11-04-21.
//

#ifndef NSPASS_UNIXSETTINGS_H
#define NSPASS_UNIXSETTINGS_H

#include "../NSPass.h"

namespace NSPass::Config {
	class UnixSettings {
	public:
		static std::string get_data_directory();
		static std::string get_temp_directory();
	};
}

#endif //NSPASS_UNIXSETTINGS_H
