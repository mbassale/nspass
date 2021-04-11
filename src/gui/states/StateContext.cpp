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
#include "SelectCategoryState.h"
#include "SelectGroupState.h"

namespace NSPass::GUI::States {

	StateContext::StateContext()
	{
		states[StateName::Initial] = StatePtr{ new InitialState(*this) };
		states[StateName::Open] = StatePtr{ new OpenState(*this) };
		states[StateName::Save] = StatePtr{ new SaveState{ *this }};
		states[StateName::Close] = StatePtr{ new CloseState{ *this }};
		states[StateName::SelectCategory] = StatePtr{ new SelectCategoryState{ *this }};
		states[StateName::SelectGroup] = StatePtr{ new SelectGroupState{ *this }};
	}

	void StateContext::Subscribe(StateName state, const StateCallback& callback)
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

	void StateContext::SelectCategory(const CategoryPtr& category)
	{
		currentState->SelectCategory(category);
	}

	void StateContext::SelectGroup(const GroupPtr& group)
	{
		currentState->SelectGroup(group);
	}

	void StateContext::Notify(StateName state)
	{
		if (enterCallbacks.count(state) > 0) {
			for (const auto& callback : enterCallbacks[state]) {
				if (callback.index() == 0) {
					const auto* callback_ptr = std::get_if<0>(&callback);
					if (callback_ptr) {
						(*callback_ptr)();
					}
				}
			}
		}
	}
	void StateContext::Notify(StateName stateName, const CategoryPtr& category)
	{
		if (enterCallbacks.count(stateName) > 0) {
			for (const auto& callback : enterCallbacks[stateName]) {
				if (callback.index() == 1) {
					const auto* callback_ptr = std::get_if<1>(&callback);
					if (callback_ptr) {
						(*callback_ptr)(category);
					}
				}
			}
		}
	}

	void StateContext::Notify(StateName stateName, const GroupPtr& group)
	{
		if (enterCallbacks.count(stateName) > 0) {
			for (const auto& callback : enterCallbacks[stateName]) {
				if (callback.index() == 2) {
					const auto* callback_ptr = std::get_if<2>(&callback);
					if (callback_ptr) {
						(*callback_ptr)(group);
					}
				}
			}
		}
	}
}
