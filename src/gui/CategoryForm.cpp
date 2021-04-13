//
// Created by Marco Bassaletti on 08-04-21.
//

#include "../NSPass.h"
#include "../commands/CommandRunner.h"
#include "../commands/Command.h"
#include "../commands/UpdateCategoryCommand.h"
#include "CategoryForm.h"

namespace NSPass::GUI {
	using NSPass::Commands::CommandPtr;
	using NSPass::Commands::UpdateCategoryCommand;

	CategoryForm::CategoryForm(wxWindow* parent, CategoryPtr category)
			:BaseCategoryForm{ parent }, category{ std::move(category) }
	{
		FillData();
	}

	void CategoryForm::FillData()
	{
		wxString id{ object_id_to_string(category->get_id()) };
		idText->SetLabel(id);
		wxString name{ category->get_name().data() };
		nameText->SetValue(name);
		wxString groupCount{ std::to_string(category->get_groups().size()) };
		groupCountText->SetLabel(groupCount);

		size_t passwordCount = 0;
		for (auto& group : category->get_groups()) {
			passwordCount += group->get_passwords().size();
		}
		wxString passwordCountStr{ std::to_string(passwordCount) };
		passwordCountText->SetLabel(passwordCountStr);
	}

	void CategoryForm::OnEdit(wxCommandEvent& event)
	{
		EnableEdition();
	}

	void CategoryForm::OnSave(wxCommandEvent& event)
	{
		try {
			auto& commandRunner = wxGetApp().GetCommandRunner();
			UpdateCategoryCommand::UpdateData update_data;
			update_data.name = nameText->GetValue();
			CommandPtr update_category_command{
					new UpdateCategoryCommand(Application::instance(), category->get_id(), update_data) };
			commandRunner.run_command(update_category_command);
			FillData();
			DisableEdition();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error saving category", wxICON_ERROR);
		}
	}

	void CategoryForm::OnCancel(wxCommandEvent& event)
	{
		FillData();
		DisableEdition();
	}

	void CategoryForm::EnableEdition()
	{
		nameText->SetEditable(true);

		editButton->Hide();
		saveButton->Show();
		cancelButton->Show();

		RedrawForm();
	}

	void CategoryForm::DisableEdition()
	{
		nameText->SetEditable(false);

		editButton->Show();
		saveButton->Hide();
		cancelButton->Hide();

		RedrawForm();
	}

	void CategoryForm::RedrawForm()
	{
		this->Layout();
	}
}
