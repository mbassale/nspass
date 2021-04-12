//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_SIGNALCONTEXT_H
#define NSPASS_SIGNALCONTEXT_H

#include "PasswordUpdateSignal.h"

namespace NSPass::Signals {

	class SignalContext {
	public:
		SignalContext() = default;

		PasswordUpdateSignal& get_password_update() { return password_update_signal; }

	protected:
		PasswordUpdateSignal password_update_signal;
	};

}

#endif //NSPASS_SIGNALCONTEXT_H
