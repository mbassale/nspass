//
// Created by Marco Bassaletti on 08-04-21.
//

#include "PasswordForm.h"
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

		passwordsList->ClearAll();
		wxListItem urlColumn;
		urlColumn.SetText("URL");
		urlColumn.SetAlign(wxLIST_FORMAT_LEFT);
		passwordsList->InsertColumn(0, urlColumn);

		wxListItem usernameColumn;
		usernameColumn.SetText("Username");
		usernameColumn.SetAlign(wxLIST_FORMAT_LEFT);
		passwordsList->InsertColumn(1, usernameColumn);

		int row = 0;
		for (auto& password : group->get_passwords()) {
			wxString password_id{ object_id_to_string(password->get_id()) };
			wxString password_url{ password->get_url().data() };
			wxString username{ password->get_username().data() };
			if (password_url.length() > 32) {
				password_url = password_url.substr(0, 30)+"..";
			}
			long itemId = passwordsList->InsertItem(row, password_id, 0);
			passwordsList->SetItemData(itemId, row);
			passwordsList->SetItemPtrData(itemId, reinterpret_cast<wxUIntPtr>(&password));
			passwordsList->SetItem(itemId, 0, password_url);
			passwordsList->SetItem(itemId, 1, username);
			row++;
		}
		passwordsList->SetColumnWidth(0, wxLIST_AUTOSIZE);
		passwordsList->SetColumnWidth(1, wxLIST_AUTOSIZE);
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

	void GroupForm::OnItemSelected(wxListEvent& event)
	{
		auto& password = *(reinterpret_cast<PasswordPtr*>(event.GetData()));
		auto* passwordForm = new PasswordForm(this, password);
		passwordDetailSizer->Clear(true);
		passwordDetailSizer->Add(passwordForm, wxSizerFlags().Expand().Border(wxALL, 0));
		Layout();
	}
}
