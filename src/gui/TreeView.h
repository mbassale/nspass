//
// Created by Marco Bassaletti on 07-04-21.
//

#ifndef NSPASS_TREEVIEW_H
#define NSPASS_TREEVIEW_H

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/treectrl.h>

namespace NSPass::GUI {
	class TreeView : public wxTreeCtrl {
	public:
		TreeView() = default;
		TreeView(wxWindow* parent, wxWindowID id);
		~TreeView() override = default;

	protected:
		int OnCompareItems(const wxTreeItemId& i1, const wxTreeItemId& i2) wxOVERRIDE;

	private:
	wxDECLARE_EVENT_TABLE();
	};
}

#endif //NSPASS_TREEVIEW_H
