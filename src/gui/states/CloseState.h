//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_CLOSESTATE_H
#define NSPASS_CLOSESTATE_H

#include "State.h"
#include "StateContext.h"

namespace NSPass::GUI::States {
	class CloseState : public State {
	public:
		CloseState(StateContext& context)
				:context{ context } { }

		void OpenDefault() override;
		void Open() override;
		void Close() override;

	protected:
		StateContext& context;
	};
}

#endif //NSPASS_CLOSESTATE_H
