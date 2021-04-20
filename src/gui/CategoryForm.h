//
// Created by Marco Bassaletti on 08-04-21.
//

#ifndef NSPASS_CATEGORYFORM_H
#define NSPASS_CATEGORYFORM_H

#include "App.h"
#include "GeneratedUI.h"
#include "../signals/SignalContext.h"
#include "../Category.h"

namespace NSPass::GUI {
	class CategoryForm : public BaseCategoryForm {
	public:
		CategoryForm(wxWindow* parent, CategoryPtr category);
		~CategoryForm() override = default;

		bool Destroy() override;

	protected:
		CategoryPtr category;
		Signals::SignalConnection groupCreatedConnection;

		[[nodiscard]] static Signals::SignalContext& GetSignalContext()
		{
			return Application::instance().get_signal_context();
		}

		void OnEdit(wxCommandEvent& event) override;
		void OnSave(wxCommandEvent& event) override;
		void OnCancel(wxCommandEvent& event) override;
		void OnAddGroup(wxCommandEvent& event) override;
		void OnGroupCreated();

		void FillData();
		void EnableEdition();
		void DisableEdition();
		void RedrawForm();
	};
}

#endif //NSPASS_CATEGORYFORM_H
