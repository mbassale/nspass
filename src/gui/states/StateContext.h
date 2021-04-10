//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_STATECONTEXT_H
#define NSPASS_STATECONTEXT_H

#include <map>
#include <vector>
#include <functional>
#include "State.h"

namespace NSPass::GUI::States {

	typedef std::function<void()> StateEnterCallback;

	enum class StateName {
		Initial = 0,
		Open,
		Save,
		Close
	};

	class StateContext {
	public:
		StateContext();

		void Subscribe(StateName state_name, const StateEnterCallback& callback);

		[[nodiscard]] State& GetState(StateName stateName) { return *(states[stateName]); }
		[[nodiscard]] State& GetCurrentState() { return *currentState; }
		void SetCurrentState(StateName stateName)
		{
			currentState = states[stateName].get();
			Notify(stateName);
		}

		void Init();
		void OpenDefault();
		void Open();
		void Save();
		void Close();

		void Notify(StateName state);

	protected:
		State* currentState{};
		std::map<StateName, StatePtr> states{};
		std::map<StateName, std::vector<StateEnterCallback>> enterCallbacks{};
	};
}

#endif //NSPASS_STATECONTEXT_H
