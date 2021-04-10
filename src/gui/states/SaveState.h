//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_SAVESTATE_H
#define NSPASS_SAVESTATE_H

#include "State.h"
#include "StateContext.h"
#include "OpenState.h"

namespace NSPass::GUI::States {
	class SaveState : public OpenState {
	public:
		explicit SaveState(StateContext& context);

		void Save() override;
	};

}

#endif //NSPASS_SAVESTATE_H
