//
// Created by Marco Bassaletti on 07-04-21.
//

#include "App.h"
#include <wx/xrc/xmlres.h>
#include "ContentPanel.h"

namespace NSPass::GUI {
	ContentPanel::ContentPanel(wxWindow* parent, wxWindowID id)
			:wxPanel(parent, id)
	{
		wxXmlResource::Get()->InitAllHandlers();
		wxXmlResource::Get()->Load("resource.xrc");
		wxXmlResource::Get()->LoadAllFiles("rc");

		auto* mainSizer = new wxBoxSizer(wxVERTICAL);
		SetSizer(mainSizer);
	}

	void ContentPanel::ShowCategory(const CategoryPtr& category)
	{

	}

	void ContentPanel::ShowGroup(const GroupPtr& group)
	{

	}
}
