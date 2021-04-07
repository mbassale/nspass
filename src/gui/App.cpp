//
// Created by Marco Bassaletti on 06-04-21.
//

#include "App.h"
#include "MainFrame.h"
#include <wx/sysopt.h>

namespace NSPass::GUI {

	bool App::OnInit()
	{
		if (!wxApp::OnInit())
			return false;

		// On Mac, activate spell checker for text inputs.
#ifdef __WXMAC__
		wxSystemOptions::SetOption(wxMAC_TEXTCONTROL_USE_SPELL_CHECKER, 1);
#endif // __WXMAC__

		auto* frame = new MainFrame("NSPass v0.1");
		frame->Show(true);
		return true;
	}
}

wxIMPLEMENT_APP(NSPass::GUI::App);
