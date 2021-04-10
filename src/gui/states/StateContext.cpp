//
// Created by Marco Bassaletti on 10-04-21.
//

#include "../../NSPass.h"
#include "../App.h"
#include "State.h"
#include "StateContext.h"
#include "InitialState.h"
#include "OpenState.h"
#include "SaveState.h"
#include "CloseState.h"

namespace NSPass::GUI::States {

	StateContext::StateContext()
	{
		states[StateName::Initial] = StatePtr{ new InitialState(*this) };
		states[StateName::Open] = StatePtr{ new OpenState(*this) };
		states[StateName::Save] = StatePtr{ new SaveState{ *this }};
		states[StateName::Close] = StatePtr{ new CloseState{ *this }};
	}

	void StateContext::Subscribe(StateName state, const StateEnterCallback& callback)
	{
		enterCallbacks[state].push_back(callback);
	}

	void StateContext::Init()
	{
		currentState = states[StateName::Open].get();
		Notify(StateName::Initial);
	}

	void StateContext::OpenDefault()
	{
		currentState->OpenDefault();
	}

	void StateContext::Open()
	{
		currentState->Open();
	}

	void StateContext::Save()
	{
		currentState->Save();
	}

	void StateContext::Close()
	{
		currentState->Close();
	}

	void StateContext::Notify(StateName state)
	{
		if (enterCallbacks.count(state) > 0) {
			for (auto& callback : enterCallbacks[state]) {
				callback();
			}
		}
	}
}
