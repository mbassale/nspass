//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_INITIALSTATE_H
#define NSPASS_INITIALSTATE_H

#include "State.h"
#include "StateContext.h"

namespace NSPass::GUI::States {
	class InitialState : public State {
	public:
		explicit InitialState(StateContext& context)
				:context{ context } { };
		void OpenDefault() override;
		void Open() override;
	protected:
		StateContext& context;
	};
}

#endif //NSPASS_INITIALSTATE_H
