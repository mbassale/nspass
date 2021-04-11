//
// Created by Marco Bassaletti on 06-04-21.
//

#include "../Application.h"
#include "App.h"
#include "states/StateContext.h"
#include "MainFrame.h"

#ifndef wxHAS_IMAGES_IN_RESOURCES
#include "../../assets/icons/sample.xpm"
#endif

namespace NSPass::GUI {
	using States::StateName;

	wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
					EVT_SIZE(MainFrame::OnSize)
					EVT_MENU(MainFrame_OpenDefault, MainFrame::OnOpenDefault)
					EVT_MENU(MainFrame_Open, MainFrame::OnOpen)
					EVT_MENU(MainFrame_Save, MainFrame::OnSave)
					EVT_MENU(MainFrame_Close, MainFrame::OnClose)
					EVT_MENU(MainFrame_Quit, MainFrame::OnQuit)
					EVT_MENU(MainFrame_About, MainFrame::OnAbout)
	wxEND_EVENT_TABLE()

	MainFrame::MainFrame(const wxString& title)
			:wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 800))
	{
		SetIcon(wxICON(sample));

#if wxUSE_MENUBAR
		// now append the freshly created menu to the menu bar...
		menuBar = new MainMenuBar();
		SetMenuBar(menuBar);

#else // !wxUSE_MENUBAR
#endif // wxUSE_MENUBAR/!wxUSE_MENUBAR

		mainSizer = new wxBoxSizer(wxVERTICAL);

		toolbar = new MainToolbar(this);
		mainSizer->Add(toolbar, wxSizerFlags(0).Expand().Border(wxALL, 0));

		splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D);
		splitter->SetSize(GetClientSize());
		splitter->SetSashGravity(1.0);

		treeView = new TreeView(splitter, LeftTree_Ctrl);
		contentPanel = new ContentPanel(splitter, ContentPanel_Ctrl);

		splitter->SplitVertically(treeView, contentPanel, 300);
		mainSizer->Add(splitter, wxSizerFlags(1).Expand().Border(wxALL, 0));

#if wxUSE_STATUSBAR
		CreateStatusBar(2);
		SetStatusText("Welcome to NSPass!");
#endif // wxUSE_STATUSBAR

		SetSizer(mainSizer);
		this->Layout();

		treeView->SetGroupSelectedCallback([&](const GroupPtr& group) {
			contentPanel->ShowGroup(group);
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Initial, [&] {
			// empty for now
		});
	}

	void MainFrame::OnOpen(wxCommandEvent& WXUNUSED(event))
	{

	}

	void MainFrame::OnOpenDefault(wxCommandEvent& WXUNUSED(event))
	{
		OpenDefaultStorage();
	}

	void MainFrame::OnClose(wxCommandEvent& event)
	{
		CloseStorage();
	}

	void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
	{
		Close(true);
	}

	void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
	{
		auto message = wxString::Format("Welcome to NSPass v0.1!\n\n"
										"Copyright (c) %d Marco Bassaletti.\n"
										"NSPass is licensed under the MIT License.\n"
										"Running under %s.",
				wxDateTime::Now().GetYear(),
				wxGetOsDescription()
		);
		wxMessageBox(message, "About NSPass", wxOK | wxICON_INFORMATION, this);
	}

	void MainFrame::OpenDefaultStorage()
	{
		try {
			wxGetApp().GetStateContext().OpenDefault();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error opening storage.", wxOK | wxICON_ERROR);
		}
	}

	void MainFrame::OnSave(wxCommandEvent& event)
	{
		try {
			wxGetApp().GetStateContext().Save();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error saving storage.", wxOK | wxICON_ERROR);
		}
	}

	void MainFrame::CloseStorage()
	{
		try {
			wxGetApp().GetStateContext().Close();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error closing storage.", wxOK | wxICON_ERROR);
		}
	}

}
