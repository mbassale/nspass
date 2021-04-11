//
// Created by Marco Bassaletti on 10-04-21.
//

#include "SelectCategoryState.h"

namespace NSPass::GUI::States {

	void SelectCategoryState::SelectCategory(const CategoryPtr& category)
	{
		context.SetCurrentState(StateName::SelectCategory);
		context.Notify(StateName::SelectCategory, category);
	}
}
