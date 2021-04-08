//
// Created by Marco Bassaletti on 07-04-21.
//

#include "App.h"
#include "CategoryForm.h"
#include "GroupForm.h"
#include "ContentPanel.h"

namespace NSPass::GUI {
	ContentPanel::ContentPanel(wxWindow* parent, wxWindowID id)
			:wxPanel(parent, id)
	{
		mainSizer = new wxBoxSizer(wxVERTICAL);
		SetSizer(mainSizer);
	}

	void ContentPanel::ShowCategory(const CategoryPtr& category)
	{
		auto* categoryForm = new CategoryForm(this, category);
		mainSizer->Clear(true);
		mainSizer->Add(categoryForm, wxSizerFlags().Expand().Border(wxALL, 10));
		mainSizer->Layout();
	}

	void ContentPanel::ShowGroup(const GroupPtr& group)
	{
		auto* groupForm = new GroupForm(this, group);
		mainSizer->Clear(true);
		mainSizer->Add(groupForm, wxSizerFlags().Expand().Border(wxALL, 10));
		mainSizer->Layout();
	}

	void ContentPanel::Clear()
	{
		mainSizer->Clear(true);
	}
}
