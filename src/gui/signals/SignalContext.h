//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_SIGNALCONTEXT_H
#define NSPASS_SIGNALCONTEXT_H

#include "PasswordUpdateSignal.h"

namespace NSPass::GUI::Signals {

	class SignalContext {
	public:
		SignalContext() = default;

		PasswordUpdateSignal& GetPasswordUpdate() { return passwordUpdateSignal; }

	protected:
		PasswordUpdateSignal passwordUpdateSignal;
	};

}

#endif //NSPASS_SIGNALCONTEXT_H
