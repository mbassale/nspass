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
		void SelectCategory(const CategoryPtr& category) override;
		void SelectGroup(const CategoryPtr& category, const GroupPtr& group) override;
	protected:
		StateContext& context;
	};
}

#endif //NSPASS_OPENSTATE_H
