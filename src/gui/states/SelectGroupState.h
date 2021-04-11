//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_SELECTGROUPSTATE_H
#define NSPASS_SELECTGROUPSTATE_H

#include "State.h"
#include "StateContext.h"
#include "OpenState.h"

namespace NSPass::GUI::States {
	class SelectGroupState : public OpenState {
	public:
		explicit SelectGroupState(StateContext& context)
				:OpenState(context) { }
				
		void SelectGroup(const GroupPtr& group) override;
	};
}

#endif //NSPASS_SELECTGROUPSTATE_H
