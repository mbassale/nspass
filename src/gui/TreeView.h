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

#include "../NSPass.h"
#include "../Application.h"
#include "../Category.h"
#include "../Group.h"
#include "../storage/StorageHeader.h"
#include <wx/treectrl.h>

#include <utility>

namespace NSPass::GUI {

	class StorageItemData : public wxTreeItemData {
	public:
		explicit StorageItemData(Storage::StorageHeader storageHeader)
				:storageHeader{ std::move(storageHeader) } { }
	protected:
		Storage::StorageHeader storageHeader;
	};

	class CategoryItemData : public wxTreeItemData {
	public:
		explicit CategoryItemData(CategoryPtr category)
				:category{ std::move(category) } { }

		[[nodiscard]] const CategoryPtr& get_category() const { return category; }
	private:
		CategoryPtr category;
	};

	class GroupItemData : public wxTreeItemData {
	public:
		explicit GroupItemData(GroupPtr group)
				:group{ std::move(group) } { }

		[[nodiscard]] const GroupPtr& get_group() const { return group; }
	private:
		GroupPtr group;
	};

	typedef std::function<void(const CategoryPtr&)> CategorySelectedCallback;

	typedef std::function<void(const GroupPtr&)> GroupSelectedCallback;

	class TreeView : public wxTreeCtrl {
	public:
		TreeView()
				:app{ Application::instance() } { };
		TreeView(wxWindow* parent, wxWindowID id);
		~TreeView() override = default;

		void OnSelChanged(wxTreeEvent& event);

		void FillStorageData();

	protected:
		Application& app;
		wxTreeItemId rootId;

		Storage::Storage& getStorage() { return app.get_storage(); }
		int OnCompareItems(const wxTreeItemId& i1, const wxTreeItemId& i2) override;

	private:
	wxDECLARE_EVENT_TABLE();
	};
}

#endif //NSPASS_TREEVIEW_H
