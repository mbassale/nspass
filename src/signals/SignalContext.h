//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_SIGNALCONTEXT_H
#define NSPASS_SIGNALCONTEXT_H

#include "CategoryUpdatedSignal.h"
#include "GroupUpdatedSignal.h"
#include "PasswordSignal.h"

namespace NSPass::Signals {

class SignalContext : private boost::noncopyable {
	public:
		SignalContext() = default;

		CategoryUpdatedSignal& get_category_updated() { return category_updated_signal; }
		GroupUpdatedSignal& get_group_updated() { return group_updated_signal; }
		PasswordSignal& get_password_updated() { return password_updated_signal; }
		PasswordSignal& get_password_deleted() { return password_deleted_signal; }

	protected:
		CategoryUpdatedSignal category_updated_signal{};
		GroupUpdatedSignal group_updated_signal{};
		PasswordSignal password_updated_signal{};
		PasswordSignal password_deleted_signal{};
	};

}

#endif //NSPASS_SIGNALCONTEXT_H
