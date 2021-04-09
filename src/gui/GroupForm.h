//
// Created by Marco Bassaletti on 08-04-21.
//

#ifndef NSPASS_GROUPFORM_H
#define NSPASS_GROUPFORM_H

#include "App.h"
#include "GeneratedUI.h"
#include "../Category.h"
#include "../Group.h"

namespace NSPass::GUI {
	class GroupForm : public BaseGroupForm {
	public:
		GroupForm(wxWindow* parent, GroupPtr group);
		~GroupForm() override = default;
	protected:
		GroupPtr group;

		void FillData();
		void OnTextChanged(wxCommandEvent& event) override;
		void OnItemSelected(wxListEvent& event) override;
	};
};

#endif //NSPASS_GROUPFORM_H
