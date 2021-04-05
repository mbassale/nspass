//
// Created by Marco Bassaletti on 04-04-21.
//

#include "MacSettings.h"
#include "SettingsFactory.h"

namespace NSPass::Config {
	SettingsPtr SettingsFactory::make()
	{
		return std::make_unique<MacSettings>();
	}
}
