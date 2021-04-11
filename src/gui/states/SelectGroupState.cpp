//
// Created by Marco Bassaletti on 10-04-21.
//

#include "SelectGroupState.h"

namespace NSPass::GUI::States {

	void SelectGroupState::SelectGroup(const GroupPtr& group)
	{
		context.SetCurrentState(StateName::SelectGroup);
		context.Notify(StateName::SelectGroup, group);
	}
}
