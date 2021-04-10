//
// Created by Marco Bassaletti on 08-04-21.
//
#include <wx/stdpaths.h>
#include <wx/clipbrd.h>
#include "../commands/UpdatePasswordCommand.h"
#include "../commands/CopyPasswordCommand.h"
#include "PasswordForm.h"

namespace NSPass::GUI {
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::CopyPasswordCommand;
	using NSPass::Commands::UpdatePasswordCommand;

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
		descriptionText->SetValue(description);
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

	void PasswordForm::OnEdit(wxCommandEvent& event)
	{
		EnableEdition();
	}

	void PasswordForm::OnSave(wxCommandEvent& event)
	{
		try {
			auto& commandRunner = wxGetApp().GetCommandRunner();
			UpdatePasswordCommand::UpdateData update_data;
			update_data.username = usernameText->GetValue();
			update_data.url = urlText->GetValue();
			update_data.description = descriptionText->GetValue();
			update_data.password = isShowingPassword ? passwordShownText->GetValue() : passwordText->GetValue();
			CommandPtr save_password_command{
					new UpdatePasswordCommand(Application::instance(), password->get_id(), update_data) };
			commandRunner.run_command(save_password_command);
			FillData();
			OnPasswordHide(event);
			DisableEdition();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error saving password", wxICON_ERROR);
		}
	}

	void PasswordForm::OnCancel(wxCommandEvent& event)
	{
		OnReset(event);
		OnPasswordHide(event);
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

	void PasswordForm::OnPasswordShow(wxCommandEvent& event)
	{
		isShowingPassword = true;
		passwordShownText->SetValue(passwordText->GetValue());
		passwordText->Hide();
		passwordShownText->Show();
		passwordShowButton->Hide();
		passwordHideButton->Show();
		RedrawForm();
	}

	void PasswordForm::OnPasswordHide(wxCommandEvent& event)
	{
		isShowingPassword = false;
		passwordShownText->SetValue("");
		passwordShownText->Hide();
		passwordText->Show();
		passwordHideButton->Hide();
		passwordShowButton->Show();
		RedrawForm();
	}

	void PasswordForm::EnableEdition()
	{
		usernameText->SetEditable(true);
		urlText->SetEditable(true);
		descriptionText->SetEditable(true);

		auto passwordStr = password->get_password().get_plain_text(password->get_username());
		passwordText->SetValue(passwordStr);
		passwordText->SetEditable(true);
		passwordCopyButton->Hide();
		passwordHideButton->Hide();
		passwordShowButton->Show();

		copyPasswordButton->Hide();
		openUrlButton->Hide();
		editButton->Hide();
		saveButton->Show();
		cancelButton->Show();
		resetButton->Show();

		RedrawForm();
	}

	void PasswordForm::DisableEdition()
	{
		usernameText->SetEditable(false);
		urlText->SetEditable(false);
		descriptionText->SetEditable(false);

		passwordText->SetValue("******");
		passwordText->SetEditable(false);
		passwordCopyButton->Show();
		passwordShowButton->Hide();
		passwordHideButton->Hide();

		copyPasswordButton->Show();
		openUrlButton->Show();
		editButton->Show();
		saveButton->Hide();
		cancelButton->Hide();
		resetButton->Hide();

		RedrawForm();
	}

	void PasswordForm::RedrawForm()
	{
		this->Layout();
		boxSizer->Fit(this);
	}

}
