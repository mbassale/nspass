//
// Created by Marco Bassaletti on 10-04-21.
//

#include "../App.h"
#include "CloseState.h"

namespace NSPass::GUI::States {

	void CloseState::OpenDefault()
	{
		context.GetState(StateName::Open).OpenDefault();
	}

	void CloseState::Open()
	{
		context.GetState(StateName::Open).Open();
	}
	void CloseState::Close()
	{
		auto& app = Application::instance();
		app.get_vault().close();
		context.SetCurrentState(StateName::Close);
	}
}
