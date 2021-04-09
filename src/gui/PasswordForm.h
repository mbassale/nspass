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
		void OnChangePassword(wxCommandEvent& event) override;

	protected:
		PasswordPtr password;

		void FillData();
	};
}

#endif //NSPASS_PASSWORDFORM_H
