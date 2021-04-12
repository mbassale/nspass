//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_PASSWORDUPDATESIGNAL_H
#define NSPASS_PASSWORDUPDATESIGNAL_H

#include <vector>
#include <functional>
#include "Signal.h"
#include "../../Password.h"

namespace NSPass::GUI::Signals {

	typedef std::function<void(const PasswordPtr&)> PasswordSlot;

	class PasswordUpdateSignal : public Signal<PasswordSlot, const PasswordPtr&> {
	};

}

#endif //NSPASS_PASSWORDUPDATESIGNAL_H
