//
// Created by Marco Bassaletti on 08-04-21.
//

#include "GroupForm.h"

namespace NSPass::GUI {

	GroupForm::GroupForm(wxWindow* parent, GroupPtr group)
			:BaseGroupForm(parent), group{ std::move(group) }
	{
		FillData();
	}

	void GroupForm::FillData()
	{
		wxString id{ object_id_to_string(group->get_id()) };
		idText->SetLabel(id);
		wxString name{ group->get_name().data() };
		nameText->SetValue(name);
		wxString url{ group->get_url().data() };
		urlText->SetValue(url);
		wxString description{ group->get_description().data() };
		urlText->SetValue(description);
		wxString passwordCount{ std::to_string(group->get_passwords().size()) };
		passwordCountText->SetLabel(passwordCount);
	}

	void GroupForm::OnTextChanged(wxCommandEvent& event)
	{
		switch (event.GetId()) {
		case GroupNameText_Ctrl:
			wxString existingGroupName{ group->get_name().data() };
			auto newGroupName = nameText->GetValue();
			if (existingGroupName != newGroupName) {
				group->set_name(static_cast<const char*>(newGroupName.c_str()));
			}
			break;
		}
	}
}
