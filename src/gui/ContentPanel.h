//
// Created by Marco Bassaletti on 07-04-21.
//

#ifndef NSPASS_CONTENTPANEL_H
#define NSPASS_CONTENTPANEL_H

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "App.h"
#include "../Application.h"
#include "../Category.h"
#include "../Group.h"

namespace NSPass::GUI {
	class ContentPanel : public wxPanel {
	public:
		ContentPanel(wxWindow* parent, wxWindowID id);

		void ShowCategory(const CategoryPtr& category);
		void ShowGroup(const GroupPtr& group);
	};
}

#endif //NSPASS_CONTENTPANEL_H
