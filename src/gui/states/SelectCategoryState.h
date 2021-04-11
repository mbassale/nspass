//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_SELECTCATEGORYSTATE_H
#define NSPASS_SELECTCATEGORYSTATE_H

#include "State.h"
#include "OpenState.h"
#include "StateContext.h"

namespace NSPass::GUI::States {
	class SelectCategoryState : public OpenState {
	public:
		explicit SelectCategoryState(StateContext& context)
				:OpenState(context) { }

		void SelectCategory(const CategoryPtr& category) override;
	};
}

#endif //NSPASS_SELECTCATEGORYSTATE_H
