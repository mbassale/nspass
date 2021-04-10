//
// Created by Marco Bassaletti on 07-04-21.
//

#include "states/StateContext.h"
#include "TreeView.h"
#include "GlobalIds.h"

namespace NSPass::GUI {
	using States::StateName;

	wxBEGIN_EVENT_TABLE(TreeView, wxTreeCtrl)
					EVT_TREE_SEL_CHANGED(LeftTree_Ctrl, TreeView::OnSelChanged)
	wxEND_EVENT_TABLE()

	TreeView::TreeView(wxWindow* parent, wxWindowID id)
			:wxTreeCtrl(parent, id), app{ Application::instance() }
	{
		wxGetApp().GetStateContext().Subscribe(StateName::Open, [&]{
			this->FillStorageData();
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Close, [&]{
			this->DeleteAllItems();
		});
	}

	int TreeView::OnCompareItems(const wxTreeItemId& i1, const wxTreeItemId& i2)
	{
		return wxTreeCtrlBase::OnCompareItems(i1, i2);
	}

	void TreeView::OnSelChanged(wxTreeEvent& event)
	{
		wxTreeItemId selectedId = event.GetItem();
		auto* itemData = GetItemData(selectedId);
		auto* categoryItem = dynamic_cast<CategoryItemData*>(itemData);
		auto* groupItem = dynamic_cast<GroupItemData*>(itemData);
		if (categoryItem && categorySelectedCallback) {
			auto& category = categoryItem->get_category();
			categorySelectedCallback(category);
		}
		else if (groupItem && groupSelectedCallback) {
			auto& group = groupItem->get_group();
			groupSelectedCallback(group);
		}
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
}
