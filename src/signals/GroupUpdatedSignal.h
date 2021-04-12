//
// Created by Marco Bassaletti on 12-04-21.
//

#ifndef NSPASS_GROUPUPDATEDSIGNAL_H
#define NSPASS_GROUPUPDATEDSIGNAL_H

#include "Signal.h"
#include "../Group.h"

namespace NSPass::Signals {

	typedef std::function<void(const GroupPtr&)> GroupSlot;

	class GroupUpdatedSignal : public Signal<GroupSlot, const GroupPtr&> {
	};
}

#endif //NSPASS_GROUPUPDATEDSIGNAL_H
