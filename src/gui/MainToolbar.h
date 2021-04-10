//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_MAINTOOLBAR_H
#define NSPASS_MAINTOOLBAR_H

#include "GeneratedUI.h"

namespace NSPass::GUI {
	class MainToolbar : public BaseToolBar {
	public:
		explicit MainToolbar(wxWindow* parent);
		~MainToolbar() override = default;

		void OnOpenDefault(wxCommandEvent& event) override;
		void OnSave(wxCommandEvent& event) override;
		void OnOpen(wxCommandEvent& event) override;
		void OnCopy(wxCommandEvent& event) override;
	};
}

#endif //NSPASS_MAINTOOLBAR_H
