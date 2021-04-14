//
// Created by Marco Bassaletti on 08-04-21.
//

#include "PasswordForm.h"
#include "GroupForm.h"
#include "../commands/UpdateGroupCommand.h"

namespace NSPass::GUI {
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::UpdateGroupCommand;

	GroupForm::GroupForm(wxWindow* parent, GroupPtr group)
			:BaseGroupForm(parent), group{ std::move(group) }
	{
		FillData();
		passwordUpdatedConnection = GetSignalContext().get_password_updated().connect([&](const PasswordPtr& password) {
			FillPasswordsData();
		});
		passwordDeletedConnection = GetSignalContext().get_password_deleted().connect([&](const PasswordPtr& password) {
			OnPasswordDeleted();
		});
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
		descriptionText->SetValue(description);

		FillPasswordsData();
	}

	void GroupForm::FillPasswordsData()
	{
		passwordsList->Hide();
		passwordsList->DeleteAllItems();
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
		passwordsList->Show();
	}

	void GroupForm::OnItemSelected(wxListEvent& event)
	{
		auto& password = *(reinterpret_cast<PasswordPtr*>(event.GetData()));
		auto* passwordForm = new PasswordForm(this, password);
		passwordDetailSizer->Clear(true);
		passwordDetailSizer->Add(passwordForm, wxSizerFlags().Expand().Border(wxALL, 0));
		Layout();
	}

	void GroupForm::OnEdit(wxCommandEvent& event)
	{
		EnableEdition();
	}

	void GroupForm::OnSave(wxCommandEvent& event)
	{
		try {
			auto& commandRunner = wxGetApp().GetCommandRunner();
			UpdateGroupCommand::UpdateData update_data;
			update_data.name = nameText->GetValue();
			update_data.url = urlText->GetValue();
			update_data.description = descriptionText->GetValue();
			CommandPtr update_group_command{
					new UpdateGroupCommand(Application::instance(), group->get_id(), update_data) };
			commandRunner.run_command(update_group_command);
			FillData();
			DisableEdition();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error saving group", wxICON_ERROR);
		}
	}

	void GroupForm::OnCancel(wxCommandEvent& event)
	{
		FillData();
		DisableEdition();
	}

	void GroupForm::OnPasswordDeleted()
	{
		passwordDetailSizer->Clear(true);
		FillPasswordsData();
	}

	void GroupForm::EnableEdition()
	{
		nameText->SetEditable(true);
		urlText->SetEditable(true);
		descriptionText->SetEditable(true);

		editButton->Hide();
		saveButton->Show();
		cancelButton->Show();

		RedrawForm();
	}

	void GroupForm::DisableEdition()
	{
		nameText->SetEditable(false);
		urlText->SetEditable(false);
		descriptionText->SetEditable(false);

		editButton->Show();
		saveButton->Hide();
		cancelButton->Hide();

		RedrawForm();
	}

	void GroupForm::RedrawForm()
	{
		this->Layout();
	}

	bool GroupForm::Destroy()
	{
		passwordUpdatedConnection.disconnect();
		passwordDeletedConnection.disconnect();
		return wxWindowBase::Destroy();
	}
}
