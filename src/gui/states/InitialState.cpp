//
// Created by Marco Bassaletti on 10-04-21.
//

#include "InitialState.h"
#include "OpenState.h"

namespace NSPass::GUI::States {

	void InitialState::OpenDefault()
	{
		context.GetState(StateName::Open).OpenDefault();
	}

	void InitialState::Open()
	{
		context.GetState(StateName::Open).Open();
	}
}
