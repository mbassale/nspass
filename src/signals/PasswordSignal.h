//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_PASSWORDSIGNAL_H
#define NSPASS_PASSWORDSIGNAL_H

#include <vector>
#include <functional>
#include "Signal.h"
#include "../Password.h"

namespace NSPass::Signals {

	typedef std::function<void(const PasswordPtr&)> PasswordSlot;

	class PasswordSignal : public Signal<PasswordSlot, const PasswordPtr&> {
	};

}

#endif //NSPASS_PASSWORDSIGNAL_H
