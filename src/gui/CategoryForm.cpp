//
// Created by Marco Bassaletti on 08-04-21.
//

#include "CategoryForm.h"

namespace NSPass::GUI {

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

	void CategoryForm::OnTextChanged(wxCommandEvent& event)
	{
		switch (event.GetId()) {
		case CategoryNameText_Ctrl:
			auto newCategoryName = nameText->GetValue();
			category->set_name(static_cast<const char*>(newCategoryName.c_str()));
			break;
		}
	}
}
