///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GeneratedUI.h"

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

	wxBoxSizer* boxSizer;
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

	nameText = new wxTextCtrl( groupSizer->GetStaticBox(), GroupNameText_Ctrl, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	nameText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer1->Add( nameText, 0, wxALL, 5 );

	urlLabel = new wxStaticText( groupSizer->GetStaticBox(), wxID_ANY, wxT("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	urlLabel->Wrap( -1 );
	flexGridSizer1->Add( urlLabel, 0, wxALL, 5 );

	urlText = new wxTextCtrl( groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	urlText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer1->Add( urlText, 0, wxALL, 5 );

	descriptionLabel = new wxStaticText( groupSizer->GetStaticBox(), wxID_ANY, wxT("Description"), wxDefaultPosition, wxDefaultSize, 0 );
	descriptionLabel->Wrap( -1 );
	flexGridSizer1->Add( descriptionLabel, 0, wxALL, 5 );

	descriptionText = new wxTextCtrl( groupSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	descriptionText->SetMinSize( wxSize( 300,50 ) );

	flexGridSizer1->Add( descriptionText, 0, wxALL, 5 );


	groupSizer->Add( flexGridSizer1, 1, wxEXPAND, 5 );


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
	nameText->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BaseGroupForm::OnTextChanged ), NULL, this );
	passwordsList->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( BaseGroupForm::OnItemSelected ), NULL, this );
}

BaseGroupForm::~BaseGroupForm()
{
	// Disconnect Events
	nameText->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BaseGroupForm::OnTextChanged ), NULL, this );
	passwordsList->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( BaseGroupForm::OnItemSelected ), NULL, this );

}

BasePasswordForm::BasePasswordForm( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->SetMinSize( wxSize( 300,250 ) );

	wxBoxSizer* boxSizer;
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

	usernameText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	usernameText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer->Add( usernameText, 0, wxALL, 5 );

	urlLabel = new wxStaticText( this, wxID_ANY, wxT("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	urlLabel->Wrap( -1 );
	flexGridSizer->Add( urlLabel, 0, wxALL, 5 );

	urlText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	urlText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer->Add( urlText, 0, wxALL, 5 );

	descriptionLabel = new wxStaticText( this, wxID_ANY, wxT("Description"), wxDefaultPosition, wxDefaultSize, 0 );
	descriptionLabel->Wrap( -1 );
	flexGridSizer->Add( descriptionLabel, 0, wxALL, 5 );

	descriptionText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP );
	descriptionText->SetMinSize( wxSize( 300,50 ) );

	flexGridSizer->Add( descriptionText, 0, wxALL, 5 );

	passwordLabel = new wxStaticText( this, wxID_ANY, wxT("Password"), wxDefaultPosition, wxDefaultSize, 0 );
	passwordLabel->Wrap( -1 );
	flexGridSizer->Add( passwordLabel, 0, wxALL, 5 );

	passwordText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD|wxTE_READONLY );
	passwordText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer->Add( passwordText, 0, wxALL, 5 );


	boxSizer->Add( flexGridSizer, 1, wxBOTTOM|wxEXPAND, 5 );

	wxBoxSizer* buttonSizer;
	buttonSizer = new wxBoxSizer( wxHORIZONTAL );

	buttonSizer->SetMinSize( wxSize( -1,40 ) );
	copyPasswordButton = new wxButton( this, wxID_ANY, wxT("Copy Password"), wxDefaultPosition, wxDefaultSize, 0 );

	copyPasswordButton->SetDefault();
	buttonSizer->Add( copyPasswordButton, 0, wxALL, 5 );

	openUrlButton = new wxButton( this, wxID_ANY, wxT("Open URL"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( openUrlButton, 0, wxALL, 5 );

	changePasswordButton = new wxButton( this, wxID_ANY, wxT("Change Password"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonSizer->Add( changePasswordButton, 0, wxALL, 5 );


	boxSizer->Add( buttonSizer, 0, wxEXPAND|wxTOP, 5 );


	this->SetSizer( boxSizer );
	this->Layout();
	boxSizer->Fit( this );

	// Connect Events
	copyPasswordButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnCopy ), NULL, this );
	openUrlButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnOpenUrl ), NULL, this );
	changePasswordButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnChangePassword ), NULL, this );
}

BasePasswordForm::~BasePasswordForm()
{
	// Disconnect Events
	copyPasswordButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnCopy ), NULL, this );
	openUrlButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnOpenUrl ), NULL, this );
	changePasswordButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePasswordForm::OnChangePassword ), NULL, this );

}
