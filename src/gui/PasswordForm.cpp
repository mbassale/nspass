//
// Created by Marco Bassaletti on 08-04-21.
//
#include <wx/stdpaths.h>
#include <wx/clipbrd.h>
#include "../commands/CopyPasswordCommand.h"
#include "PasswordForm.h"

namespace NSPass::GUI {
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::CopyPasswordCommand;

	PasswordForm::PasswordForm(wxWindow* parent, PasswordPtr password)
			:BasePasswordForm(parent), password{ std::move(password) }
	{
		FillData();
		DisableEdition();
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
		try {
			wxString url{ password->get_url().data() };
			wxLaunchDefaultBrowser(url, wxBROWSER_NEW_WINDOW);
		}
		catch (...) {
			wxMessageBox("Error launching default browser.", "Error Opening URL", wxICON_ERROR);
		}
	}

	void PasswordForm::OnChangePassword(wxCommandEvent& event)
	{
		EnableEdition();
	}

	void PasswordForm::OnSave(wxCommandEvent& event)
	{

	}

	void PasswordForm::OnCancel(wxCommandEvent& event)
	{
		OnReset(event);
		DisableEdition();
	}

	void PasswordForm::OnReset(wxCommandEvent& event)
	{
		FillData();
	}

	void PasswordForm::OnUsernameCopy(wxCommandEvent& event)
	{
		if (wxTheClipboard->Open()) {
			wxString username = usernameText->GetValue();
			wxTheClipboard->SetData(new wxTextDataObject(username));
			wxTheClipboard->Close();
		}
	}

	void PasswordForm::OnUrlCopy(wxCommandEvent& event)
	{
		if (wxTheClipboard->Open()) {
			wxString url = urlText->GetValue();
			wxTheClipboard->SetData(new wxTextDataObject(url));
			wxTheClipboard->Close();
		}
	}

	void PasswordForm::OnDescriptionCopy(wxCommandEvent& event)
	{
		if (wxTheClipboard->Open()) {
			wxString description = descriptionText->GetValue();
			wxTheClipboard->SetData(new wxTextDataObject(description));
			wxTheClipboard->Close();
		}
	}

	void PasswordForm::OnPasswordCopy(wxCommandEvent& event)
	{
		OnCopy(event);
	}

	void PasswordForm::EnableEdition()
	{
		isUpdating = true;
		usernameText->SetEditable(true);
		urlText->SetEditable(true);
		descriptionText->SetEditable(true);
		passwordText->SetEditable(true);

		copyPasswordButton->Hide();
		openUrlButton->Hide();
		changePasswordButton->Hide();
		saveButton->Show();
		cancelButton->Show();
		resetButton->Show();

		this->Layout();
		boxSizer->Fit(this);
	}

	void PasswordForm::DisableEdition()
	{
		isUpdating = false;
		usernameText->SetEditable(false);
		urlText->SetEditable(false);
		descriptionText->SetEditable(false);
		passwordText->SetEditable(false);

		copyPasswordButton->Show();
		openUrlButton->Show();
		changePasswordButton->Show();
		saveButton->Hide();
		cancelButton->Hide();
		resetButton->Hide();

		this->Layout();
		boxSizer->Fit(this);
	}

}
