//
// Created by Marco Bassaletti on 06-04-21.
//

#include "../Application.h"
#include "MainFrame.h"

#ifndef wxHAS_IMAGES_IN_RESOURCES
#include "../../assets/icons/sample.xpm"
#endif

namespace NSPass::GUI {
	enum {
		// menu items
		MainFrame_OpenDefault = 1,
		MainFrame_Open = wxID_OPEN,
		MainFrame_Save = wxID_SAVE,
		MainFrame_Close = wxID_CLOSE,
		MainFrame_Quit = wxID_EXIT,
		MainFrame_About = wxID_ABOUT
	};

	wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
					EVT_MENU(MainFrame_OpenDefault, MainFrame::OnOpenDefault)
					EVT_MENU(MainFrame_Open, MainFrame::OnOpen)
					EVT_MENU(MainFrame_Close, MainFrame::OnClose)
					EVT_MENU(MainFrame_Quit, MainFrame::OnQuit)
					EVT_MENU(MainFrame_About, MainFrame::OnAbout)
					EVT_WINDOW_CREATE(MainFrame::OnCreate)
	wxEND_EVENT_TABLE()

	MainFrame::MainFrame(const wxString& title)
			:wxFrame(NULL, wxID_ANY, title)
	{
		SetIcon(wxICON(sample));

#if wxUSE_MENUBAR
		// create a menu bar
		fileMenu = new wxMenu;
		fileMenu->Append(MainFrame_OpenDefault, "Open Default...", "Open default password storage file");
		fileMenu->Append(MainFrame_Open, "&Open\tCtrl-O", "Opens a password storage file");
		fileMenu->Append(MainFrame_Save, "&Save\tCtrl-S", "Saves current storage file");
		fileMenu->Append(MainFrame_Close, "&Close\tCtrl-W", "Closes current storage file");
		fileMenu->AppendSeparator();
		fileMenu->Append(MainFrame_Quit, "E&xit\tAlt-X", "Quit this program");

		// the "About" item should be in the help menu
		helpMenu = new wxMenu;
		helpMenu->Append(MainFrame_About, "&About\tF1", "Show about dialog");

		// now append the freshly created menu to the menu bar...
		menuBar = new wxMenuBar();
		menuBar->Append(fileMenu, "&File");
		menuBar->Append(helpMenu, "&Help");

		// ... and attach this menu bar to the frame
		SetMenuBar(menuBar);
#else // !wxUSE_MENUBAR
#endif // wxUSE_MENUBAR/!wxUSE_MENUBAR

#if wxUSE_STATUSBAR
		CreateStatusBar(2);
		SetStatusText("Welcome to NSPass!");
#endif // wxUSE_STATUSBAR
	}

	void MainFrame::OnCreate(wxWindowCreateEvent& event)
	{
		fileMenu->Enable(MainFrame_OpenDefault, true);
		fileMenu->Enable(MainFrame_Open, true);
		fileMenu->Enable(MainFrame_Save, false);
		fileMenu->Enable(MainFrame_Close, false);
		OpenDefaultStorage();
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
			auto masterPassword = wxGetPasswordFromUser("Please enter master password:", "Master Password Required",
					wxEmptyString, this);
			if (masterPassword.empty()) return;
			auto& app = Application::instance();
			auto& vault = app.get_vault();
			vault.set_master_password(std::string(masterPassword.c_str()));
			vault.set_storage_location(app.get_settings().get_data_directory()+"/nspass.db");
			vault.open();
			fileMenu->Enable(MainFrame_OpenDefault, false);
			fileMenu->Enable(MainFrame_Open, false);
			fileMenu->Enable(MainFrame_Save, true);
			fileMenu->Enable(MainFrame_Close, true);
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error opening storage.", wxOK | wxICON_ERROR);
		}
	}

	void MainFrame::OnSave(wxCommandEvent& event)
	{
		try {
			auto& app = Application::instance();
			app.get_vault().save();
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error saving storage.", wxOK | wxICON_ERROR);
		}
	}

	void MainFrame::CloseStorage()
	{
		try {
			auto& app = Application::instance();
			app.get_vault().close();
			fileMenu->Enable(MainFrame_OpenDefault, true);
			fileMenu->Enable(MainFrame_Open, true);
			fileMenu->Enable(MainFrame_Save, false);
			fileMenu->Enable(MainFrame_Close, false);
		}
		catch (ApplicationException& ex) {
			wxMessageBox(ex.what(), "Error closing storage.", wxOK | wxICON_ERROR);
		}
	}

}
