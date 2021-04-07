//
// Created by Marco Bassaletti on 06-04-21.
//

#include "MainFrame.h"

#ifndef wxHAS_IMAGES_IN_RESOURCES
#include "../../assets/icons/sample.xpm"
#endif

namespace NSPass::GUI {
	enum {
		// menu items
		Minimal_Quit = wxID_EXIT,
		Minimal_About = wxID_ABOUT
	};

	wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
					EVT_MENU(Minimal_Quit, MainFrame::OnQuit)
					EVT_MENU(Minimal_About, MainFrame::OnAbout)
	wxEND_EVENT_TABLE()

	MainFrame::MainFrame(const wxString& title)
			:wxFrame(NULL, wxID_ANY, title)
	{
		SetIcon(wxICON(sample));

#if wxUSE_MENUBAR
		// create a menu bar
		wxMenu* fileMenu = new wxMenu;

		// the "About" item should be in the help menu
		wxMenu* helpMenu = new wxMenu;
		helpMenu->Append(Minimal_About, "&About\tF1", "Show about dialog");

		fileMenu->Append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program");

		// now append the freshly created menu to the menu bar...
		wxMenuBar* menuBar = new wxMenuBar();
		menuBar->Append(fileMenu, "&File");
		menuBar->Append(helpMenu, "&Help");

		// ... and attach this menu bar to the frame
		SetMenuBar(menuBar);
#else // !wxUSE_MENUBAR
		// If menus are not available add a button to access the about box
	wxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	wxButton* aboutBtn = new wxButton(this, wxID_ANY, "About...");
	aboutBtn->Bind(wxEVT_BUTTON, &MyFrame::OnAbout, this);
	sizer->Add(aboutBtn, wxSizerFlags().Center());
	SetSizer(sizer);
#endif // wxUSE_MENUBAR/!wxUSE_MENUBAR

#if wxUSE_STATUSBAR
		CreateStatusBar(2);
		SetStatusText("Welcome to NSPass!");
#endif // wxUSE_STATUSBAR
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

}
