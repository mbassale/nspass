//
// Created by Marco Bassaletti on 08-04-21.
//

#ifndef NSPASS_GROUPFORM_H
#define NSPASS_GROUPFORM_H

#include "App.h"
#include "GeneratedUI.h"
#include "../Category.h"
#include "../Group.h"
#include "../signals/SignalContext.h"

namespace NSPass::GUI {
	class GroupForm : public BaseGroupForm {
	public:
		GroupForm(wxWindow* parent, CategoryPtr category, GroupPtr group);
		~GroupForm() override = default;

		bool Destroy() override;

	protected:
		CategoryPtr category;
		GroupPtr group;
		Signals::SignalConnection passwordCreatedConnection;
		Signals::SignalConnection passwordUpdatedConnection;
		Signals::SignalConnection passwordDeletedConnection;

		[[nodiscard]] static Signals::SignalContext& GetSignalContext()
		{
			return Application::instance().get_signal_context();
		}

		void OnItemSelected(wxListEvent& event) override;
		void OnEdit(wxCommandEvent& event) override;
		void OnSave(wxCommandEvent& event) override;
		void OnCancel(wxCommandEvent& event) override;
		void OnDelete(wxCommandEvent& event) override;
		void OnAddPassword(wxCommandEvent& event) override;
		void OnPasswordCreated(const PasswordPtr& password);
		void OnPasswordDeleted();

		void FillData();
		void FillPasswordsData();
		void EnableEdition();
		void DisableEdition();
		void RedrawForm();
	};
};

#endif //NSPASS_GROUPFORM_H
