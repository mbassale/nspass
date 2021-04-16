//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_STATECONTEXT_H
#define NSPASS_STATECONTEXT_H

#include <map>
#include <vector>
#include <functional>
#include <variant>
#include "State.h"

namespace NSPass::GUI::States {

	typedef std::function<void()> StateVoidCallback;

	typedef std::function<void(const CategoryPtr&)> StateCategoryCallback;

	typedef std::function<void(const CategoryPtr&, const GroupPtr&)> StateGroupCallback;

	typedef std::function<void(const PasswordPtr&)> StatePasswordCallback;

	typedef std::variant<StateVoidCallback,
						 StateCategoryCallback,
						 StateGroupCallback,
						 StatePasswordCallback> StateCallback;

	enum class StateName {
		Initial = 0,
		Open,
		Save,
		Close,
		SelectCategory,
		SelectGroup,
		SelectPassword
	};

	class StateContext {
	public:
		StateContext();

		void Subscribe(StateName state_name, const StateCallback& callback);

		[[nodiscard]] State& GetState(StateName stateName) { return *(states[stateName]); }
		[[nodiscard]] State& GetCurrentState() { return *currentState; }
		void SetCurrentState(StateName stateName) { currentState = states[stateName].get(); }

		void Init();
		void OpenDefault();
		void Open();
		void Save();
		void Close();
		void SelectCategory(const CategoryPtr& category);
		void SelectGroup(const CategoryPtr& category, const GroupPtr& group);

		void Notify(StateName state);
		void Notify(StateName stateName, const CategoryPtr& category);
		void Notify(StateName stateName, const CategoryPtr& category, const GroupPtr& group);

	protected:
		State* currentState{};
		std::map<StateName, StatePtr> states{};
		std::map<StateName, std::vector<StateCallback>> enterCallbacks{};

	};
}

#endif //NSPASS_STATECONTEXT_H
