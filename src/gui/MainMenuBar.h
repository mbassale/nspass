//
// Created by Marco Bassaletti on 07-04-21.
//

#ifndef NSPASS_MAINMENUBAR_H
#define NSPASS_MAINMENUBAR_H

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "GlobalIds.h"

namespace NSPass::GUI {
	class MainMenuBar : public wxMenuBar {
	public:
		MainMenuBar();

		void Reset();
		void OnOpen();
		void OnClose();
	protected:
		wxMenu* fileMenu;
		wxMenu* helpMenu;
	};
}

#endif //NSPASS_MAINMENUBAR_H
