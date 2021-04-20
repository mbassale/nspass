//
// Created by Marco Bassaletti on 07-04-21.
//

#include "App.h"
#include "CategoryForm.h"
#include "GroupForm.h"
#include "ContentPanel.h"
#include "states/StateContext.h"

namespace NSPass::GUI {
	using States::StateName;

	ContentPanel::ContentPanel(wxWindow* parent, wxWindowID id)
			:wxPanel(parent, id)
	{
		mainSizer = new wxBoxSizer(wxVERTICAL);
		SetSizer(mainSizer);

		wxGetApp().GetStateContext().Subscribe(StateName::Close, [&] {
			mainSizer->Clear(true);
		});
		wxGetApp().GetStateContext().Subscribe(StateName::SelectCategory, [&](const CategoryPtr& category) {
			ShowCategory(category);
		});
		wxGetApp().GetStateContext()
				.Subscribe(StateName::SelectGroup, [&](const CategoryPtr& category, const GroupPtr& group) {
					ShowGroup(category, group);
				});
		GetSignalContext().get_group_deleted().connect([&](const GroupPtr& group) {
			if (currentCategory)
				ShowCategory(currentCategory);
			else
				ClearPanel();
		});
	}

	void ContentPanel::ClearPanel()
	{
		mainSizer->Clear(true);
		mainSizer->Layout();
	}

	void ContentPanel::ShowCategory(const CategoryPtr& category)
	{
		currentCategory = category;
		auto* categoryForm = new CategoryForm(this, category);
		mainSizer->Clear(true);
		mainSizer->Add(categoryForm, wxSizerFlags().Expand().Border(wxALL, 10));
		mainSizer->Layout();
	}

	void ContentPanel::ShowGroup(const CategoryPtr& category, const GroupPtr& group)
	{
		currentCategory = category;
		currentGroup = group;
		auto* groupForm = new GroupForm(this, category, group);
		mainSizer->Clear(true);
		mainSizer->Add(groupForm, wxSizerFlags().Expand().Border(wxALL, 10));
		mainSizer->Layout();
	}
}
