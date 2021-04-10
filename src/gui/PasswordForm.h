//
// Created by Marco Bassaletti on 08-04-21.
//

#ifndef NSPASS_PASSWORDFORM_H
#define NSPASS_PASSWORDFORM_H

#include "../NSPass.h"
#include "../Password.h"
#include "App.h"
#include "GeneratedUI.h"

namespace NSPass::GUI {
	class PasswordForm : public BasePasswordForm {
	public:
		PasswordForm(wxWindow* parent, PasswordPtr password);
		~PasswordForm() override = default;

		void OnCopy(wxCommandEvent& event) override;
		void OnOpenUrl(wxCommandEvent& event) override;
		void OnEdit(wxCommandEvent& event) override;
		void OnSave(wxCommandEvent& event) override;
		void OnCancel(wxCommandEvent& event) override;
		void OnReset(wxCommandEvent& event) override;
		void OnUsernameCopy(wxCommandEvent& event) override;
		void OnUrlCopy(wxCommandEvent& event) override;
		void OnDescriptionCopy(wxCommandEvent& event) override;
		void OnPasswordCopy(wxCommandEvent& event) override;
		void OnPasswordShow(wxCommandEvent& event) override;
		void OnPasswordHide(wxCommandEvent& event) override;

	protected:
		bool isShowingPassword = false;
		PasswordPtr password;

		void FillData();
		void EnableEdition();
		void DisableEdition();
		void RedrawForm();
	};
}

#endif //NSPASS_PASSWORDFORM_H
