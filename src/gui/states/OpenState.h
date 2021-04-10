//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_OPENSTATE_H
#define NSPASS_OPENSTATE_H

#include "State.h"
#include "StateContext.h"

namespace NSPass::GUI::States {
	class OpenState : public State {
	public:
		explicit OpenState(StateContext& context);
		void OpenDefault() override;
		void Save() override;
		void Close() override;
	protected:
		StateContext& context;
	};
}

#endif //NSPASS_OPENSTATE_H
