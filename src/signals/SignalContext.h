//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_SIGNALCONTEXT_H
#define NSPASS_SIGNALCONTEXT_H

#include "GroupUpdatedSignal.h"
#include "PasswordUpdateSignal.h"

namespace NSPass::Signals {

	class SignalContext {
	public:
		SignalContext() = default;

		GroupUpdatedSignal& get_group_updated() { return group_updated_signal; }
		PasswordUpdateSignal& get_password_update() { return password_update_signal; }

	protected:
		GroupUpdatedSignal group_updated_signal;
		PasswordUpdateSignal password_update_signal;
	};

}

#endif //NSPASS_SIGNALCONTEXT_H
