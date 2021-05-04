//
// Created by Marco Bassaletti on 10-04-21.
//

#include "App.h"
#include "states/StateContext.h"
#include "MainToolbar.h"

namespace NSPass::GUI {
	using States::StateContext;
	using States::StateName;

	MainToolbar::MainToolbar(wxWindow* parent)
			:BaseToolBar(parent)
	{
		wxGetApp().GetStateContext().Subscribe(StateName::Initial, [&] {
			openDefaultTool->Enable(true);
			openTool->Enable(true);
			saveTool->Enable(false);
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Open, [&] {
			openDefaultTool->Enable(false);
			openTool->Enable(false);
			saveTool->Enable(true);
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Save, [&] {
			saveTool->Enable(false);
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Close, [&] {
			openDefaultTool->Enable(true);
			openTool->Enable(true);
			saveTool->Enable(false);
		});
	}

	void MainToolbar::OnOpenDefault(wxCommandEvent& event)
	{
		try {
			wxGetApp().GetStateContext().OpenDefault();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error opening storage.", wxOK | wxICON_ERROR);
		}
	}

	void MainToolbar::OnOpen(wxCommandEvent& event)
	{
		try {
			wxGetApp().GetStateContext().Open();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error opening storage.", wxOK | wxICON_ERROR);
		}
	}

	void MainToolbar::OnSave(wxCommandEvent& event)
	{
		try {
			wxGetApp().GetStateContext().Save();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error saving storage.", wxOK | wxICON_ERROR);
		}
	}

}
