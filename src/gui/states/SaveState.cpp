//
// Created by Marco Bassaletti on 10-04-21.
//
#include "../App.h"
#include "SaveState.h"

namespace NSPass::GUI::States {
	SaveState::SaveState(StateContext& context)
			:OpenState(context)
	{
	}

	void SaveState::Save()
	{
		const auto& app = Application::instance();
		app.get_vault().save();
		context.SetCurrentState(StateName::Save);
		context.Notify(StateName::Save);
	}
}
