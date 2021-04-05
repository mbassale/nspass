//
// Created by Marco Bassaletti on 04-04-21.
//

#ifndef NSPASS_SETTINGSFACTORY_H
#define NSPASS_SETTINGSFACTORY_H

#include "Settings.h"

namespace NSPass::Config {
	class SettingsFactory {
	public:
		static SettingsPtr make();
	};
}

#endif //NSPASS_SETTINGSFACTORY_H
