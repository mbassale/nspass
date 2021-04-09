//
// Created by Marco Bassaletti on 08-04-21.
//

#include "PasswordForm.h"

namespace NSPass::GUI {
	PasswordForm::PasswordForm(wxWindow* parent, PasswordPtr password)
			:BasePasswordForm(parent), password{ std::move(password) }
	{
		FillData();
	}

	void PasswordForm::FillData()
	{
		wxString id{ object_id_to_string(password->get_id()) };
		idText->SetLabel(id);
		wxString username{ password->get_username().data() };
		usernameText->SetValue(username);
		wxString url{ password->get_url().data() };
		urlText->SetValue(url);
		wxString description{ password->get_description().data() };
		urlText->SetValue(description);
		passwordText->SetValue("******");
	}
}
