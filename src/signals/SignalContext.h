//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_SIGNALCONTEXT_H
#define NSPASS_SIGNALCONTEXT_H

#include "CategoryUpdatedSignal.h"
#include "GroupUpdatedSignal.h"
#include "PasswordUpdateSignal.h"

namespace NSPass::Signals {

	class SignalContext {
	public:
		SignalContext() = default;

		CategoryUpdatedSignal& get_category_updated() { return category_updated_signal; }
		GroupUpdatedSignal& get_group_updated() { return group_updated_signal; }
		PasswordUpdateSignal& get_password_update() { return password_update_signal; }

	protected:
		CategoryUpdatedSignal category_updated_signal;
		GroupUpdatedSignal group_updated_signal;
		PasswordUpdateSignal password_update_signal;
	};

}

#endif //NSPASS_SIGNALCONTEXT_H
