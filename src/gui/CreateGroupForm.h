//
// Created by Marco Bassaletti on 16-04-21.
//

#ifndef NSPASS_CREATEGROUPFORM_H
#define NSPASS_CREATEGROUPFORM_H

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "App.h"
#include "GeneratedUI.h"

namespace NSPass::GUI {
	class CreateGroupForm : public BaseCreateGroupForm {
	public:
		explicit CreateGroupForm(wxWindow* parent, CategoryPtr category);
	protected:
		CategoryPtr category;

		void OnSave(wxCommandEvent& event);
		void OnReset(wxCommandEvent& event);
		void OnCancel(wxCommandEvent& event);
	};
}

#endif //NSPASS_CREATEGROUPFORM_H
