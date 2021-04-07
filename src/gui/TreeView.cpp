//
// Created by Marco Bassaletti on 07-04-21.
//

#include "TreeView.h"

namespace NSPass::GUI {

	wxBEGIN_EVENT_TABLE(TreeView, wxTreeCtrl)
	wxEND_EVENT_TABLE()

	TreeView::TreeView(wxWindow* parent, wxWindowID id)
			:wxTreeCtrl(parent, id), app{ Application::instance() }
	{

	}

	int TreeView::OnCompareItems(const wxTreeItemId& i1, const wxTreeItemId& i2)
	{
		return wxTreeCtrlBase::OnCompareItems(i1, i2);
	}

	void TreeView::FillStorageData()
	{
		auto* rootNode = new StorageItemData(getStorage().get_header());
		rootId = AddRoot("Storage", -1, -1, rootNode);

		auto& categories = app.get_storage().get_categories();
		for (auto& category : categories) {
			auto* categoryNode = new CategoryItemData(category);
			wxTreeItemId categoryId = AppendItem(rootId, category->get_name().data(), -1, -1, categoryNode);
			for (auto& group : category->get_groups()) {
				auto* groupNode = new GroupItemData(group);
				AppendItem(categoryId, group->get_name().data(), -1, -1, groupNode);
			}
		}

		ExpandAll();
	}

	void TreeView::DeleteStorageData()
	{
		DeleteAllItems();
	}
}
