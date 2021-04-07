//
// Created by Marco Bassaletti on 06-04-21.
//

#include "App.h"
#include "MainFrame.h"

namespace NSPass::GUI {

	bool App::OnInit()
	{
		if (!wxApp::OnInit())
			return false;
		auto* frame = new MainFrame("NSPass v0.1");
		frame->Show(true);
		return true;
	}
}

wxIMPLEMENT_APP(NSPass::GUI::App);
