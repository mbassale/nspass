//
// Created by Marco Bassaletti on 07-04-21.
//

#include "MainMenuBar.h"
#include "states/StateContext.h"

namespace NSPass::GUI {
	using States::StateContext;
	using States::StateName;

	MainMenuBar::MainMenuBar()
	{
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

		Append(fileMenu, "&File");
		Append(helpMenu, "&Help");

		Reset();

		wxGetApp().GetStateContext().Subscribe(StateName::Initial, [&] {
			Reset();
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Open, [&] {
			OnOpen();
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Save, [&] {

		});
		wxGetApp().GetStateContext().Subscribe(StateName::Close, [&] {
			OnClose();
		});
	}

	void MainMenuBar::Reset()
	{
		OnClose();
	}

	void MainMenuBar::OnOpen()
	{
		fileMenu->Enable(MainFrame_OpenDefault, false);
		fileMenu->Enable(MainFrame_Open, false);
		fileMenu->Enable(MainFrame_Save, true);
		fileMenu->Enable(MainFrame_Close, true);
	}
	void MainMenuBar::OnClose()
	{
		fileMenu->Enable(MainFrame_OpenDefault, true);
		fileMenu->Enable(MainFrame_Open, true);
		fileMenu->Enable(MainFrame_Save, false);
		fileMenu->Enable(MainFrame_Close, false);
	}

}
