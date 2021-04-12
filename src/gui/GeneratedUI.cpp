///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GeneratedUI.h"

#include "icons/Clear32x32.png.h"
#include "icons/Copy.png.h"
#include "icons/Copy32x32.png.h"
#include "icons/Cut32x32.png.h"
#include "icons/Delete32x32.png.h"
#include "icons/HidePassword.png.h"
#include "icons/Open32x32.png.h"
#include "icons/OpenDefault32x32.png.h"
#include "icons/Paste32x32.png.h"
#include "icons/Save32x32.png.h"
#include "icons/ShowPassword.png.h"

///////////////////////////////////////////////////////////////////////////
using namespace NSPass::GUI;

BaseCategoryForm::BaseCategoryForm( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* boxSizer;
	boxSizer = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* categorySizer;
	categorySizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Category") ), wxVERTICAL );

	wxFlexGridSizer* flexGridSizer1;
	flexGridSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	flexGridSizer1->SetFlexibleDirection( wxBOTH );
	flexGridSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	idLabel = new wxStaticText( categorySizer->GetStaticBox(), wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	idLabel->Wrap( -1 );
	flexGridSizer1->Add( idLabel, 0, wxALL, 5 );

	idText = new wxStaticText( categorySizer->GetStaticBox(), CategoryIdText_Ctrl, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	idText->Wrap( -1 );
	flexGridSizer1->Add( idText, 0, wxALL, 5 );

	nameLabel = new wxStaticText( categorySizer->GetStaticBox(), wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	nameLabel->Wrap( -1 );
	flexGridSizer1->Add( nameLabel, 0, wxALL, 5 );

	nameText = new wxTextCtrl( categorySizer->GetStaticBox(), CategoryNameText_Ctrl, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	nameText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer1->Add( nameText, 0, wxALL, 5 );


	categorySizer->Add( flexGridSizer1, 1, wxEXPAND, 5 );


	boxSizer->Add( categorySizer, 1, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	wxStaticBoxSizer* groupSizer;
	groupSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Group Stats") ), wxVERTICAL );

	wxFlexGridSizer* flexGridSizer2;
	flexGridSizer2 = new wxFlexGridSizer( 2, 2, 0, 0 );
	flexGridSizer2->SetFlexibleDirection( wxBOTH );
	flexGridSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	groupCountLabel = new wxStaticText( groupSizer->GetStaticBox(), wxID_ANY, wxT("Site Count"), wxDefaultPosition, wxDefaultSize, 0 );
	groupCountLabel->Wrap( -1 );
	flexGridSizer2->Add( groupCountLabel, 0, wxALL, 5 );

	groupCountText = new wxStaticText( groupSizer->GetStaticBox(), CategoryGroupCountText_Ctrl, wxT("N/A"), wxDefaultPosition, wxDefaultSize, 0 );
	groupCountText->Wrap( -1 );
	flexGridSizer2->Add( groupCountText, 0, wxALL, 5 );

	passwordCountLabel = new wxStaticText( groupSizer->GetStaticBox(), wxID_ANY, wxT("Password Count"), wxDefaultPosition, wxDefaultSize, 0 );
	passwordCountLabel->Wrap( -1 );
	flexGridSizer2->Add( passwordCountLabel, 0, wxALL, 5 );

	passwordCountText = new wxStaticText( groupSizer->GetStaticBox(), CategoryPasswordCountText_Ctrl, wxT("N/A"), wxDefaultPosition, wxDefaultSize, 0 );
	passwordCountText->Wrap( -1 );
	flexGridSizer2->Add( passwordCountText, 0, wxALL, 5 );


	groupSizer->Add( flexGridSizer2, 1, wxEXPAND, 5 );


	boxSizer->Add( groupSizer, 1, wxBOTTOM|wxEXPAND|wxTOP, 5 );


	this->SetSizer( boxSizer );
	this->Layout();
	boxSizer->Fit( this );

	// Connect Events
	nameText->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BaseCategoryForm::OnTextChanged ), NULL, this );
}

BaseCategoryForm::~BaseCategoryForm()
{
	// Disconnect Events
	nameText->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BaseCategoryForm::OnTextChanged ), NULL, this );

}

BaseGroupForm::BaseGroupForm( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->SetMinSize( wxSize( -1,650 ) );

	boxSizer = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* groupSizer;
	groupSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Group") ), wxVERTICAL );

	wxFlexGridSizer* flexGridSizer1;
	flexGridSizer1 = new wxFlexGridSizer( 4, 2, 0, 0 );
	flexGridSizer1->SetFlexibleDirection( wxBOTH );
	flexGridSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	flexGridSizer1->SetMinSize( wxSize( 300,160 ) );
	idLabel = new wxStaticText( groupSizer->GetStaticBox(), wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	idLabel->Wrap( -1 );
	flexGridSizer1->Add( idLabel, 0, wxALL, 5 );

	idText = new wxStaticText( groupSizer->GetStaticBox(), GroupIdText_Ctrl, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	idText->Wrap( -1 );
	flexGridSizer1->Add( idText, 0, wxALL, 5 );

	nameLabel = new wxStaticText( groupSizer->GetStaticBox(), wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	nameLabel->Wrap( -1 );
	flexGridSizer1->Add( nameLabel, 0, wxALL, 5 );

	nameText = new wxTextCtrl( groupSizer->GetStaticBox(), GroupNameText_Ctrl, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	nameText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer1->Add( nameText, 0, wxALL, 5 );

	urlLabel = new wxStaticText( groupSizer->GetStaticBox(), wxID_ANY, wxT("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	urlLabel->Wrap( -1 );
	flexGridSizer1->Add( urlLabel, 0, wxALL, 5 );

	urlText = new wxTextCtrl( groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	urlText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer1->Add( urlText, 0, wxALL, 5 );

	descriptionLabel = new wxStaticText( groupSizer->GetStaticBox(), wxID_ANY, wxT("Description"), wxDefaultPosition, wxDefaultSize, 0 );
	descriptionLabel->Wrap( -1 );
	flexGridSizer1->Add( descriptionLabel, 0, wxALL, 5 );

	descriptionText = new wxTextCtrl( groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	descriptionText->SetMinSize( wxSize( 300,50 ) );

	flexGridSizer1->Add( descriptionText, 0, wxALL, 5 );


	groupSizer->Add( flexGridSizer1, 1, wxEXPAND, 5 );

	wxBoxSizer* buttonSizer;
	buttonSizer = new wxBoxSizer( wxHORIZONTAL );

	editButton = new wxButton( groupSizer->GetStaticBox(), wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( editButton, 0, wxALL, 5 );

	saveButton = new wxButton( groupSizer->GetStaticBox(), wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	saveButton->Hide();

	buttonSizer->Add( saveButton, 0, wxALL, 5 );

	cancelButton = new wxButton( groupSizer->GetStaticBox(), wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	cancelButton->Hide();

	buttonSizer->Add( cancelButton, 0, wxALL, 5 );


	groupSizer->Add( buttonSizer, 0, wxEXPAND, 5 );


	boxSizer->Add( groupSizer, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	passwordSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Passwords") ), wxVERTICAL );

	wxFlexGridSizer* flexGridSizer2;
	flexGridSizer2 = new wxFlexGridSizer( 1, 1, 0, 0 );
	flexGridSizer2->AddGrowableCol( 0 );
	flexGridSizer2->AddGrowableRow( 0 );
	flexGridSizer2->SetFlexibleDirection( wxBOTH );
	flexGridSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	flexGridSizer2->SetMinSize( wxSize( 300,100 ) );
	passwordsList = new wxListCtrl( passwordSizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,50 ), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_VRULES );
	passwordsList->SetMinSize( wxSize( 300,50 ) );

	flexGridSizer2->Add( passwordsList, 0, wxALL|wxEXPAND, 5 );


	passwordSizer->Add( flexGridSizer2, 1, wxEXPAND, 5 );


	boxSizer->Add( passwordSizer, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	passwordDetailSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Password Detail") ), wxVERTICAL );

	passwordDetailSizer->SetMinSize( wxSize( 300,300 ) );

	boxSizer->Add( passwordDetailSizer, 1, wxBOTTOM|wxEXPAND|wxRESERVE_SPACE_EVEN_IF_HIDDEN|wxTOP, 5 );


	this->SetSizer( boxSizer );
	this->Layout();
	boxSizer->Fit( this );

	// Connect Events
	editButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseGroupForm::OnEdit ), NULL, this );
	saveButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseGroupForm::OnSave ), NULL, this );
	cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseGroupForm::OnCancel ), NULL, this );
	passwordsList->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( BaseGroupForm::OnItemSelected ), NULL, this );
}

BaseGroupForm::~BaseGroupForm()
{
	// Disconnect Events
	editButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseGroupForm::OnEdit ), NULL, this );
	saveButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseGroupForm::OnSave ), NULL, this );
	cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseGroupForm::OnCancel ), NULL, this );
	passwordsList->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( BaseGroupForm::OnItemSelected ), NULL, this );

}

BasePasswordForm::BasePasswordForm( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->SetMinSize( wxSize( 300,250 ) );

	boxSizer = new wxBoxSizer( wxVERTICAL );

	boxSizer->SetMinSize( wxSize( 300,250 ) );
	wxFlexGridSizer* flexGridSizer;
	flexGridSizer = new wxFlexGridSizer( 5, 2, 0, 0 );
	flexGridSizer->SetFlexibleDirection( wxBOTH );
	flexGridSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	flexGridSizer->SetMinSize( wxSize( 300,200 ) );
	idLabel = new wxStaticText( this, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	idLabel->Wrap( -1 );
	flexGridSizer->Add( idLabel, 0, wxALL, 5 );

	idText = new wxStaticText( this, wxID_ANY, wxT("N/A"), wxDefaultPosition, wxDefaultSize, 0 );
	idText->Wrap( -1 );
	flexGridSizer->Add( idText, 0, wxALL, 5 );

	usernameLabel = new wxStaticText( this, wxID_ANY, wxT("Username"), wxDefaultPosition, wxDefaultSize, 0 );
	usernameLabel->Wrap( -1 );
	flexGridSizer->Add( usernameLabel, 0, wxALL, 5 );

	wxBoxSizer* usernameSizer;
	usernameSizer = new wxBoxSizer( wxHORIZONTAL );

	usernameText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	usernameText->SetMinSize( wxSize( 300,-1 ) );

	usernameSizer->Add( usernameText, 0, wxALL, 5 );

	usernameCopyButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW|wxBORDER_NONE );

	usernameCopyButton->SetBitmap( Copy_png_to_wx_bitmap() );
	usernameCopyButton->SetBitmapMargins( wxSize( 2,2 ) );
	usernameCopyButton->SetToolTip( wxT("Copy Username") );
	usernameCopyButton->SetMinSize( wxSize( 22,22 ) );

	usernameSizer->Add( usernameCopyButton, 0, wxBOTTOM|wxTOP, 5 );


	flexGridSizer->Add( usernameSizer, 1, wxEXPAND, 5 );

	urlLabel = new wxStaticText( this, wxID_ANY, wxT("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	urlLabel->Wrap( -1 );
	flexGridSizer->Add( urlLabel, 0, wxALL, 5 );

	wxBoxSizer* urlSizer;
	urlSizer = new wxBoxSizer( wxHORIZONTAL );

	urlText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	urlText->SetMinSize( wxSize( 300,-1 ) );

	urlSizer->Add( urlText, 0, wxALL, 5 );

	urlCopyButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	urlCopyButton->SetBitmap( Copy_png_to_wx_bitmap() );
	urlCopyButton->SetBitmapMargins( wxSize( 2,2 ) );
	urlCopyButton->SetToolTip( wxT("Copy URL") );
	urlCopyButton->SetMinSize( wxSize( 22,22 ) );

	urlSizer->Add( urlCopyButton, 0, wxBOTTOM|wxTOP, 5 );


	flexGridSizer->Add( urlSizer, 1, wxEXPAND, 5 );

	descriptionLabel = new wxStaticText( this, wxID_ANY, wxT("Description"), wxDefaultPosition, wxDefaultSize, 0 );
	descriptionLabel->Wrap( -1 );
	flexGridSizer->Add( descriptionLabel, 0, wxALL, 5 );

	wxBoxSizer* descriptionSizer;
	descriptionSizer = new wxBoxSizer( wxHORIZONTAL );

	descriptionText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_WORDWRAP );
	descriptionText->SetMinSize( wxSize( 300,50 ) );

	descriptionSizer->Add( descriptionText, 0, wxALL, 5 );

	descriptionCopyButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	descriptionCopyButton->SetBitmap( Copy_png_to_wx_bitmap() );
	descriptionCopyButton->SetBitmapMargins( wxSize( 2,2 ) );
	descriptionCopyButton->SetToolTip( wxT("Copy Description") );
	descriptionCopyButton->SetMinSize( wxSize( 22,22 ) );

	descriptionSizer->Add( descriptionCopyButton, 0, wxBOTTOM|wxTOP, 5 );


	flexGridSizer->Add( descriptionSizer, 1, wxEXPAND, 5 );

	passwordLabel = new wxStaticText( this, wxID_ANY, wxT("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	passwordLabel->Wrap( -1 );
	flexGridSizer->Add( passwordLabel, 0, wxALL, 5 );

	wxBoxSizer* passwordSizer;
	passwordSizer = new wxBoxSizer( wxHORIZONTAL );

	passwordText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD|wxTE_READONLY );
	passwordText->SetMinSize( wxSize( 300,-1 ) );

	passwordSizer->Add( passwordText, 0, wxALL, 5 );

	passwordShownText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	passwordShownText->Hide();
	passwordShownText->SetMinSize( wxSize( 300,-1 ) );

	passwordSizer->Add( passwordShownText, 0, wxALL, 5 );

	passwordCopyButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	passwordCopyButton->SetBitmap( Copy_png_to_wx_bitmap() );
	passwordCopyButton->SetBitmapMargins( wxSize( 2,2 ) );
	passwordCopyButton->SetToolTip( wxT("Copy Password") );
	passwordCopyButton->SetMinSize( wxSize( 22,22 ) );

	passwordSizer->Add( passwordCopyButton, 0, wxBOTTOM|wxTOP, 5 );

	passwordShowButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	passwordShowButton->SetBitmap( ShowPassword_png_to_wx_bitmap() );
	passwordShowButton->SetBitmapMargins( wxSize( 2,2 ) );
	passwordShowButton->Hide();
	passwordShowButton->SetToolTip( wxT("Show Password") );
	passwordShowButton->SetMinSize( wxSize( 22,22 ) );

	passwordSizer->Add( passwordShowButton, 0, wxBOTTOM|wxTOP, 5 );

	passwordHideButton = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE );

	passwordHideButton->SetBitmap( HidePassword_png_to_wx_bitmap() );
	passwordHideButton->SetBitmapMargins( wxSize( 2,2 ) );
	passwordHideButton->Hide();
	passwordHideButton->SetMinSize( wxSize( 22,22 ) );

	passwordSizer->Add( passwordHideButton, 0, wxBOTTOM|wxTOP, 5 );


	flexGridSizer->Add( passwordSizer, 1, wxEXPAND, 5 );


	boxSizer->Add( flexGridSizer, 1, wxBOTTOM|wxEXPAND, 5 );

	wxBoxSizer* buttonSizer;
	buttonSizer = new wxBoxSizer( wxHORIZONTAL );

	buttonSizer->SetMinSize( wxSize( -1,40 ) );
	copyPasswordButton = new wxButton( this, wxID_ANY, wxT("Copy Password"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( copyPasswordButton, 0, wxALL, 5 );

	openUrlButton = new wxButton( this, wxID_ANY, wxT("Open URL"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( openUrlButton, 0, wxALL, 5 );

	editButton = new wxButton( this, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( editButton, 0, wxALL, 5 );

	saveButton = new wxButton( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	saveButton->Hide();

	buttonSizer->Add( saveButton, 0, wxALL, 5 );

	cancelButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	cancelButton->Hide();

	buttonSizer->Add( cancelButton, 0, wxALL, 5 );

	resetButton = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	resetButton->Hide();

	buttonSizer->Add( resetButton, 0, wxALL, 5 );


	boxSizer->Add( buttonSizer, 0, wxEXPAND|wxTOP, 5 );


	this->SetSizer( boxSizer );
	this->Layout();
	boxSizer->Fit( this );

	// Connect Events
	usernameCopyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnUsernameCopy ), NULL, this );
	urlCopyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnUrlCopy ), NULL, this );
	descriptionCopyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnDescriptionCopy ), NULL, this );
	passwordCopyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnPasswordCopy ), NULL, this );
	passwordShowButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnPasswordShow ), NULL, this );
	passwordHideButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnPasswordHide ), NULL, this );
	copyPasswordButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnCopy ), NULL, this );
	openUrlButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnOpenUrl ), NULL, this );
	editButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnEdit ), NULL, this );
	saveButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnSave ), NULL, this );
	cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnCancel ), NULL, this );
	resetButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnReset ), NULL, this );
}

BasePasswordForm::~BasePasswordForm()
{
	// Disconnect Events
	usernameCopyButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnUsernameCopy ), NULL, this );
	urlCopyButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnUrlCopy ), NULL, this );
	descriptionCopyButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnDescriptionCopy ), NULL, this );
	passwordCopyButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnPasswordCopy ), NULL, this );
	passwordShowButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnPasswordShow ), NULL, this );
	passwordHideButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnPasswordHide ), NULL, this );
	copyPasswordButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnCopy ), NULL, this );
	openUrlButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnOpenUrl ), NULL, this );
	editButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnEdit ), NULL, this );
	saveButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnSave ), NULL, this );
	cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnCancel ), NULL, this );
	resetButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnReset ), NULL, this );

}

BaseToolBar::BaseToolBar( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxToolBar( parent, id, pos, size, style )
{
	SetToolBitmapSize( wxSize( 32,32 ) );

	openDefaultTool = AddTool( wxID_ANY, wxT("Open Default"), OpenDefault32x32_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxT("Open default storage."), wxT("Open default storage."), NULL );

	openTool = AddTool( wxID_ANY, wxT("Open"), Open32x32_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Open a Storage File."), NULL );

	saveTool = AddTool( wxID_ANY, wxT("Save"), Save32x32_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxT("Save changes to storage."), wxT("Save changes to storage."), NULL );

	AddSeparator();

	cutTool = AddTool( wxID_ANY, wxT("tool"), Cut32x32_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	copyTool = AddTool( wxID_ANY, wxT("Copy"), Copy32x32_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxT("Copy selected password."), wxT("Copy selected password."), NULL );

	pasteTool = AddTool( wxID_ANY, wxT("tool"), Paste32x32_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	deleteTool = AddTool( wxID_ANY, wxT("tool"), Delete32x32_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );

	AddSeparator();

	clearTool = AddTool( wxID_ANY, wxT("tool"), Clear32x32_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL );


	Realize();

	// Connect Events
	this->Connect( openDefaultTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnOpenDefault ) );
	this->Connect( openTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnOpen ) );
	this->Connect( saveTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnSave ) );
	this->Connect( cutTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnCut ) );
	this->Connect( copyTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnCopy ) );
	this->Connect( pasteTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnPaste ) );
	this->Connect( deleteTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnDelete ) );
	this->Connect( clearTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnClear ) );
}

BaseToolBar::~BaseToolBar()
{
	// Disconnect Events
	this->Disconnect( openDefaultTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnOpenDefault ) );
	this->Disconnect( openTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnOpen ) );
	this->Disconnect( saveTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnSave ) );
	this->Disconnect( cutTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnCut ) );
	this->Disconnect( copyTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnCopy ) );
	this->Disconnect( pasteTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnPaste ) );
	this->Disconnect( deleteTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnDelete ) );
	this->Disconnect( clearTool->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( BaseToolBar::OnClear ) );

}
