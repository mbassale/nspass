//
// Created by Marco Bassaletti on 07-04-21.
//

#include "TreeView.h"

namespace NSPass::GUI {

	wxBEGIN_EVENT_TABLE(TreeView, wxTreeCtrl)
	wxEND_EVENT_TABLE()

	TreeView::TreeView(wxWindow* parent, wxWindowID id)
			:wxTreeCtrl(parent, id)
	{

	}

	int TreeView::OnCompareItems(const wxTreeItemId& i1, const wxTreeItemId& i2)
	{
		return wxTreeCtrlBase::OnCompareItems(i1, i2);
	}
}
