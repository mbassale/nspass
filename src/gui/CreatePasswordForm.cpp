//
// Created by Marco Bassaletti on 15-04-21.
//

#include "../commands/Command.h"
#include "../commands/CreatePasswordCommand.h"
#include "CreatePasswordForm.h"

namespace NSPass::GUI {
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::CreatePasswordCommand;

	CreatePasswordForm::CreatePasswordForm(wxWindow* parent, CategoryPtr category, GroupPtr group)
			:BasePasswordForm(parent), category{ std::move(category) }, group{ std::move(group) }
	{
		EnableEdition();
	}

	void CreatePasswordForm::EnableEdition()
	{
		idLabel->Hide();
		idText->Hide();
		usernameText->SetEditable(true);
		urlText->SetEditable(true);
		descriptionText->SetEditable(true);
		passwordText->SetEditable(true);

		copyPasswordButton->Hide();
		openUrlButton->Hide();
		editButton->Hide();
		deleteButton->Hide();
		saveButton->Show();
		cancelButton->Show();
		resetButton->Show();
	}

	void CreatePasswordForm::OnSave(wxCommandEvent& event)
	{
		try {
			auto& commandRunner = wxGetApp().GetCommandRunner();
			CreatePasswordCommand::CreateData create_data;
			create_data.category_id = category->get_id();
			create_data.group_id = group->get_id();
			create_data.username = usernameText->GetValue();
			create_data.url = urlText->GetValue();
			create_data.description = descriptionText->GetValue();
			create_data.password = isShowingPassword ? passwordShownText->GetValue() : passwordText->GetValue();
			CommandPtr create_password_command{
					new CreatePasswordCommand(Application::instance(), create_data) };
			commandRunner.run_command(create_password_command);
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error creating password", wxICON_ERROR);
		}
	}

	void CreatePasswordForm::OnCancel(wxCommandEvent& event)
	{

	}

	void CreatePasswordForm::OnReset(wxCommandEvent& event)
	{
		ResetData();
	}

	void CreatePasswordForm::ResetData()
	{
		usernameText->Clear();
		urlText->Clear();
		descriptionText->Clear();
		passwordText->Clear();
	}
}
