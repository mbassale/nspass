//
// Created by Marco Bassaletti on 06-04-21.
//

#ifndef NSPASS_MAINFRAME_H
#define NSPASS_MAINFRAME_H

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

namespace NSPass::GUI {
	class MainFrame : public wxFrame {
	public:
		// ctor(s)
		MainFrame(const wxString& title);

		// event handlers (these functions should _not_ be virtual)
		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);

	private:
		// any class wishing to process wxWidgets events must use this macro
		wxDECLARE_EVENT_TABLE();
	};
}
#endif //NSPASS_MAINFRAME_H
