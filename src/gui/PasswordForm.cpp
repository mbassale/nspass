//
// Created by Marco Bassaletti on 08-04-21.
//

#include "../commands/CopyPasswordCommand.h"
#include "PasswordForm.h"

namespace NSPass::GUI {
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::CopyPasswordCommand;

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

	void PasswordForm::OnCopy(wxCommandEvent& event)
	{
		try {
			auto& commandRunner = wxGetApp().GetCommandRunner();
			CommandPtr copy_password_command{ new CopyPasswordCommand(Application::instance(), password->get_id()) };
			commandRunner.run_command(copy_password_command);
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error copying password", wxICON_ERROR);
		}
	}

	void PasswordForm::OnOpenUrl(wxCommandEvent& event)
	{

	}

	void PasswordForm::OnChangePassword(wxCommandEvent& event)
	{

	}
}
