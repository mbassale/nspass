//
// Created by Marco Bassaletti on 08-04-21.
//

#ifndef NSPASS_CATEGORYFORM_H
#define NSPASS_CATEGORYFORM_H

#include "App.h"
#include "BaseCategoryForm.h"
#include "../Category.h"

namespace NSPass::GUI {
	class CategoryForm : public BaseCategoryForm {
	public:
		CategoryForm(wxWindow* parent, CategoryPtr category);
		~CategoryForm() override = default;
	protected:
		CategoryPtr category;

		void FillData();
		void OnTextChanged(wxCommandEvent& event) override;
	};
}

#endif //NSPASS_CATEGORYFORM_H
