//
// Created by Marco Bassaletti on 06-04-21.
//

#ifndef NSPASS_APP_H
#define NSPASS_APP_H

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


namespace NSPass::GUI {
	class App : public wxApp
	{
	public:
		// override base class virtuals
		// ----------------------------

		// this one is called on application startup and is a good place for the app
		// initialization (doing it here and not in the ctor allows to have an error
		// return: if OnInit() returns false, the application terminates)
		virtual bool OnInit() wxOVERRIDE;
	};
}

#endif //NSPASS_APP_H
