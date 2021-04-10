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
			cutTool->Enable(false);
			copyTool->Enable(false);
			pasteTool->Enable(false);
			deleteTool->Enable(false);
			clearTool->Enable(false);
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Open, [&] {
			openDefaultTool->Enable(false);
			openTool->Enable(false);
			saveTool->Enable(true);
			cutTool->Enable(false);
			copyTool->Enable(false);
			pasteTool->Enable(false);
			deleteTool->Enable(false);
			clearTool->Enable(false);
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Save, [&] {
			saveTool->Enable(false);
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Close, [&] {
			openDefaultTool->Enable(true);
			openTool->Enable(true);
			saveTool->Enable(false);
			cutTool->Enable(false);
			copyTool->Enable(false);
			pasteTool->Enable(false);
			deleteTool->Enable(false);
			clearTool->Enable(false);
		});
	}

	void MainToolbar::OnOpenDefault(wxCommandEvent& event)
	{
		wxGetApp().GetStateContext().OpenDefault();
	}

	void MainToolbar::OnOpen(wxCommandEvent& event)
	{
		wxGetApp().GetStateContext().Open();
	}

	void MainToolbar::OnSave(wxCommandEvent& event)
	{
		wxGetApp().GetStateContext().Save();
	}

	void MainToolbar::OnCopy(wxCommandEvent& event)
	{
	}

	void MainToolbar::OnCut(wxCommandEvent& event)
	{

	}

	void MainToolbar::OnPaste(wxCommandEvent& event)
	{

	}

	void MainToolbar::OnDelete(wxCommandEvent& event)
	{

	}

	void MainToolbar::OnClear(wxCommandEvent& event)
	{

	}
}
