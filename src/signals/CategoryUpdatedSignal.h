//
// Created by Marco Bassaletti on 13-04-21.
//

#ifndef NSPASS_CATEGORYUPDATEDSIGNAL_H
#define NSPASS_CATEGORYUPDATEDSIGNAL_H

#include "Signal.h"
#include "../Category.h"

namespace NSPass::Signals {

	typedef std::function<void(const CategoryPtr&)> CategorySlot;

	class CategoryUpdatedSignal : public Signal<CategorySlot, const CategoryPtr&> {
	};
}

#endif //NSPASS_CATEGORYUPDATEDSIGNAL_H
