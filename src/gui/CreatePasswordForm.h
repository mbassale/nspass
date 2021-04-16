//
// Created by Marco Bassaletti on 15-04-21.
//

#ifndef NSPASS_CREATEPASSWORDFORM_H
#define NSPASS_CREATEPASSWORDFORM_H

#include "../NSPass.h"
#include "../Category.h"
#include "../Group.h"
#include "../Password.h"
#include "App.h"
#include "GeneratedUI.h"

namespace NSPass::GUI {
	class CreatePasswordForm : public BasePasswordForm {
	public:
		CreatePasswordForm(wxWindow* parent, CategoryPtr category, GroupPtr group);
		~CreatePasswordForm() override = default;

		void OnCopy(wxCommandEvent& event) override { event.Skip(); };
		void OnOpenUrl(wxCommandEvent& event) override { event.Skip(); };
		void OnEdit(wxCommandEvent& event) override { event.Skip(); };
		void OnSave(wxCommandEvent& event) override;
		void OnCancel(wxCommandEvent& event) override;
		void OnReset(wxCommandEvent& event) override;
		void OnDelete(wxCommandEvent& event) override { event.Skip(); };
		void OnUsernameCopy(wxCommandEvent& event) override { event.Skip(); };
		void OnUrlCopy(wxCommandEvent& event) override { event.Skip(); };
		void OnDescriptionCopy(wxCommandEvent& event) override { event.Skip(); };
		void OnPasswordCopy(wxCommandEvent& event) override { event.Skip(); };
		void OnPasswordShow(wxCommandEvent& event) override { event.Skip(); };
		void OnPasswordHide(wxCommandEvent& event) override { event.Skip(); };

	protected:
		CategoryPtr category;
		GroupPtr group;
		bool isShowingPassword = false;

		void EnableEdition();
		void ResetData();
	};
}

#endif //NSPASS_CREATEPASSWORDFORM_H
