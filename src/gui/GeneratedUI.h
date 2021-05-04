///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/listctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/toolbar.h>

///////////////////////////////////////////////////////////////////////////

namespace NSPass::GUI
{
	///////////////////////////////////////////////////////////////////////////////
	/// Class BaseCategoryForm
	///////////////////////////////////////////////////////////////////////////////
	class BaseCategoryForm : public wxPanel
	{
		private:

		protected:
			enum
			{
				CategoryIdText_Ctrl = 1000,
				CategoryNameText_Ctrl,
				CategoryGroupCountText_Ctrl,
				CategoryPasswordCountText_Ctrl
			};

			wxStaticText* idLabel;
			wxStaticText* idText;
			wxStaticText* nameLabel;
			wxTextCtrl* nameText;
			wxButton* editButton;
			wxButton* saveButton;
			wxButton* cancelButton;
			wxButton* addGroupButton;
			wxStaticText* groupCountLabel;
			wxStaticText* groupCountText;
			wxStaticText* passwordCountLabel;
			wxStaticText* passwordCountText;
			wxStaticBoxSizer* createGroupSizer;

			// Virtual event handlers, overide them in your derived class
			virtual void OnEdit( wxCommandEvent& event ) = 0;
			virtual void OnSave( wxCommandEvent& event ) = 0;
			virtual void OnCancel( wxCommandEvent& event ) = 0;
			virtual void OnAddGroup( wxCommandEvent& event ) = 0;


		public:

			BaseCategoryForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
			~BaseCategoryForm();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class BaseGroupForm
	///////////////////////////////////////////////////////////////////////////////
	class BaseGroupForm : public wxPanel
	{
		private:

		protected:
			enum
			{
				GroupIdText_Ctrl = 1000,
				GroupNameText_Ctrl
			};

			wxBoxSizer* boxSizer;
			wxStaticText* idLabel;
			wxStaticText* idText;
			wxStaticText* nameLabel;
			wxTextCtrl* nameText;
			wxStaticText* urlLabel;
			wxTextCtrl* urlText;
			wxStaticText* descriptionLabel;
			wxTextCtrl* descriptionText;
			wxButton* editButton;
			wxButton* saveButton;
			wxButton* cancelButton;
			wxButton* addPasswordButton;
			wxButton* deleteButton;
			wxStaticBoxSizer* passwordSizer;
			wxListCtrl* passwordsList;
			wxStaticBoxSizer* passwordDetailSizer;

			// Virtual event handlers, overide them in your derived class
			virtual void OnEdit( wxCommandEvent& event ) = 0;
			virtual void OnSave( wxCommandEvent& event ) = 0;
			virtual void OnCancel( wxCommandEvent& event ) = 0;
			virtual void OnAddPassword( wxCommandEvent& event ) = 0;
			virtual void OnDelete( wxCommandEvent& event ) = 0;
			virtual void OnItemSelected( wxListEvent& event ) = 0;


		public:

			BaseGroupForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
			~BaseGroupForm();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class BasePasswordForm
	///////////////////////////////////////////////////////////////////////////////
	class BasePasswordForm : public wxPanel
	{
		private:

		protected:
			wxBoxSizer* boxSizer;
			wxStaticText* idLabel;
			wxStaticText* idText;
			wxStaticText* usernameLabel;
			wxTextCtrl* usernameText;
			wxBitmapButton* usernameCopyButton;
			wxStaticText* urlLabel;
			wxTextCtrl* urlText;
			wxBitmapButton* urlCopyButton;
			wxStaticText* descriptionLabel;
			wxTextCtrl* descriptionText;
			wxBitmapButton* descriptionCopyButton;
			wxStaticText* passwordLabel;
			wxTextCtrl* passwordText;
			wxTextCtrl* passwordShownText;
			wxBitmapButton* passwordCopyButton;
			wxBitmapButton* passwordShowButton;
			wxBitmapButton* passwordHideButton;
			wxButton* copyPasswordButton;
			wxButton* openUrlButton;
			wxButton* editButton;
			wxButton* saveButton;
			wxButton* cancelButton;
			wxButton* resetButton;
			wxButton* deleteButton;

			// Virtual event handlers, overide them in your derived class
			virtual void OnUsernameCopy( wxCommandEvent& event ) = 0;
			virtual void OnUrlCopy( wxCommandEvent& event ) = 0;
			virtual void OnDescriptionCopy( wxCommandEvent& event ) = 0;
			virtual void OnPasswordCopy( wxCommandEvent& event ) = 0;
			virtual void OnPasswordShow( wxCommandEvent& event ) = 0;
			virtual void OnPasswordHide( wxCommandEvent& event ) = 0;
			virtual void OnCopy( wxCommandEvent& event ) = 0;
			virtual void OnOpenUrl( wxCommandEvent& event ) = 0;
			virtual void OnEdit( wxCommandEvent& event ) = 0;
			virtual void OnSave( wxCommandEvent& event ) = 0;
			virtual void OnCancel( wxCommandEvent& event ) = 0;
			virtual void OnReset( wxCommandEvent& event ) = 0;
			virtual void OnDelete( wxCommandEvent& event ) = 0;


		public:

			BasePasswordForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
			~BasePasswordForm();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class BaseToolBar
	///////////////////////////////////////////////////////////////////////////////
	class BaseToolBar : public wxToolBar
	{
		private:

		protected:
			wxToolBarToolBase* openDefaultTool;
			wxToolBarToolBase* openTool;
			wxToolBarToolBase* saveTool;

			// Virtual event handlers, overide them in your derived class
			virtual void OnOpenDefault( wxCommandEvent& event ) { event.Skip(); }
			virtual void OnOpen( wxCommandEvent& event ) { event.Skip(); }
			virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }


		public:

			BaseToolBar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0 );
			~BaseToolBar();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class BaseCreateGroupForm
	///////////////////////////////////////////////////////////////////////////////
	class BaseCreateGroupForm : public wxPanel
	{
		private:

		protected:
			wxBoxSizer* mainSizer;
			wxFlexGridSizer* formSizer;
			wxStaticText* nameLabel;
			wxTextCtrl* nameText;
			wxStaticText* urlLabel;
			wxTextCtrl* urlText;
			wxStaticText* descriptionLabel;
			wxTextCtrl* descriptionText;
			wxButton* saveButton;
			wxButton* resetButton;
			wxButton* cancelButton;

			// Virtual event handlers, overide them in your derived class
			virtual void OnSave( wxCommandEvent& event ) = 0;
			virtual void OnReset( wxCommandEvent& event ) = 0;
			virtual void OnCancel( wxCommandEvent& event ) = 0;


		public:

			BaseCreateGroupForm( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,250 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
			~BaseCreateGroupForm();

	};

} // namespace NSPass::GUI

