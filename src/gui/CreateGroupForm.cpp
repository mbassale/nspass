//
// Created by Marco Bassaletti on 16-04-21.
//

#include "../NSPass.h"
#include "../commands/CommandRunner.h"
#include "../commands/CreateGroupCommand.h"
#include "CreateGroupForm.h"

namespace NSPass::GUI {
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::CreateGroupCommand;

	CreateGroupForm::CreateGroupForm(wxWindow* parent, CategoryPtr category)
			:BaseCreateGroupForm(parent), category{ std::move(category) }
	{
	}

	void CreateGroupForm::OnSave(wxCommandEvent& event)
	{
		try {
			auto& commandRunner = wxGetApp().GetCommandRunner();
			CreateGroupCommand::CreateData create_data;
			create_data.category_id = category->get_id();
			create_data.name = nameText->GetValue();
			create_data.url = urlText->GetValue();
			create_data.description = descriptionText->GetValue();
			CommandPtr update_group_command{
					new CreateGroupCommand(Application::instance(), create_data) };
			commandRunner.run_command(update_group_command);
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error creating group", wxICON_ERROR);
		}
	}

	void CreateGroupForm::OnReset(wxCommandEvent& event)
	{

	}

	void CreateGroupForm::OnCancel(wxCommandEvent& event)
	{

	}
}
