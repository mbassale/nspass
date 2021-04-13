//
// Created by Marco Bassaletti on 08-04-21.
//

#ifndef NSPASS_CATEGORYFORM_H
#define NSPASS_CATEGORYFORM_H

#include "App.h"
#include "GeneratedUI.h"
#include "../Category.h"

namespace NSPass::GUI {
	class CategoryForm : public BaseCategoryForm {
	public:
		CategoryForm(wxWindow* parent, CategoryPtr category);
		~CategoryForm() override = default;
	protected:
		CategoryPtr category;

		void OnEdit(wxCommandEvent& event) override;
		void OnSave(wxCommandEvent& event) override;
		void OnCancel(wxCommandEvent& event) override;

		void FillData();
		void EnableEdition();
		void DisableEdition();
		void RedrawForm();
	};
}

#endif //NSPASS_CATEGORYFORM_H
