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
		wxGetApp().GetStateContext().Subscribe(StateName::Open, [&] {
			this->FillStorageData();
		});
		wxGetApp().GetStateContext().Subscribe(StateName::Close, [&] {
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
		const auto* itemData = GetItemData(selectedId);
		const auto* categoryItem = dynamic_cast<const CategoryItemData*>(itemData);
		const auto* groupItem = dynamic_cast<const GroupItemData*>(itemData);
		if (categoryItem) {
			const auto& category = categoryItem->get_category();
			wxGetApp().GetStateContext().SelectCategory(category);
		}
		else if (groupItem) {
			const auto& group = groupItem->get_group();
			wxGetApp().GetStateContext().SelectGroup(group);
		}
	}

	void TreeView::FillStorageData()
	{
		auto* rootNode = new StorageItemData(getStorage().get_header());
		rootId = AddRoot("Storage", -1, -1, rootNode);

		const auto& categories = app.get_storage().get_categories();
		for (const auto& category : categories) {
			auto* categoryNode = new CategoryItemData(category);
			wxTreeItemId categoryId = AppendItem(rootId, category->get_name().data(), -1, -1, categoryNode);
			for (const auto& group : category->get_groups()) {
				auto* groupNode = new GroupItemData(group);
				AppendItem(categoryId, group->get_name().data(), -1, -1, groupNode);
			}
		}

		ExpandAll();
	}
}
