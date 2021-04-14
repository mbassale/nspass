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
		categoryUpdatedSignalId = getSignalContext().get_category_updated().connect([&](const CategoryPtr& category) {
			this->OnCategoryUpdated(category);
		});
		groupUpdatedSignalId = getSignalContext().get_group_updated().connect([&](const GroupPtr& group) {
			this->OnGroupUpdated(group);
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

		const auto& categories = getStorage().get_categories();
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

	void TreeView::OnCategoryUpdated(const CategoryPtr& category)
	{
		auto categoryItemId = FindItemId(category);
		if (categoryItemId.IsOk()) {
			wxString newName{ category->get_name().data() };
			SetItemText(categoryItemId, newName);
		}
	}

	void TreeView::OnGroupUpdated(const GroupPtr& group)
	{
		auto groupItemId = FindItemId(group);
		if (groupItemId.IsOk()) {
			wxString newName{ group->get_name().data() };
			SetItemText(groupItemId, newName);
		}
	}

	wxTreeItemId TreeView::FindItemId(const CategoryPtr& category) const
	{
		wxTreeItemIdValue categoryCookie;
		wxTreeItemId categoryItemId = GetFirstChild(rootId, categoryCookie);
		while (categoryItemId.IsOk()) {
			const auto* categoryItemData = GetItemData(categoryItemId);
			const auto* categoryItem = dynamic_cast<const CategoryItemData*>(categoryItemData);
			if (categoryItem) {
				const auto& existing_category = categoryItem->get_category();
				if (existing_category->get_id() == category->get_id()) {
					return categoryItemId;
				}
			}
			categoryItemId = GetNextChild(rootId, categoryCookie);
		}
		return wxTreeItemId();
	}

	wxTreeItemId TreeView::FindItemId(const GroupPtr& group) const
	{
		wxTreeItemIdValue categoryCookie;
		wxTreeItemId categoryItemId = GetFirstChild(rootId, categoryCookie);
		while (categoryItemId.IsOk()) {
			wxTreeItemIdValue groupCookie;
			wxTreeItemId groupItemId = GetFirstChild(categoryItemId, groupCookie);
			while (groupItemId.IsOk()) {
				const auto* groupItemData = GetItemData(groupItemId);
				const auto* groupItem = dynamic_cast<const GroupItemData*>(groupItemData);
				if (groupItem) {
					const auto& existing_group = groupItem->get_group();
					if (existing_group->get_id() == group->get_id()) {
						return groupItemId;
					}
				}
				groupItemId = GetNextChild(categoryItemId, groupCookie);
			}
			categoryItemId = GetNextChild(rootId, categoryCookie);
		}
		return wxTreeItemId();
	}

	bool TreeView::Destroy()
	{
		getSignalContext().get_category_updated().disconnect(categoryUpdatedSignalId);
		getSignalContext().get_group_updated().disconnect(groupUpdatedSignalId);
		return wxWindowBase::Destroy();
	}
}
