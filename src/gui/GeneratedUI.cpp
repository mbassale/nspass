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


	boxSizer->Add( categorySizer, 1, wxEXPAND, 5 );


	boxSizer->Add( 0, 5, 0, wxEXPAND, 5 );

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


	boxSizer->Add( groupSizer, 1, wxEXPAND, 5 );


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
	wxBoxSizer* boxSizer;
	boxSizer = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* categorySizer;
	categorySizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Group") ), wxVERTICAL );

	wxFlexGridSizer* flexGridSizer1;
	flexGridSizer1 = new wxFlexGridSizer( 4, 2, 0, 0 );
	flexGridSizer1->SetFlexibleDirection( wxBOTH );
	flexGridSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	idLabel = new wxStaticText( categorySizer->GetStaticBox(), wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	idLabel->Wrap( -1 );
	flexGridSizer1->Add( idLabel, 0, wxALL, 5 );

	idText = new wxStaticText( categorySizer->GetStaticBox(), GroupIdText_Ctrl, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	idText->Wrap( -1 );
	flexGridSizer1->Add( idText, 0, wxALL, 5 );

	nameLabel = new wxStaticText( categorySizer->GetStaticBox(), wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	nameLabel->Wrap( -1 );
	flexGridSizer1->Add( nameLabel, 0, wxALL, 5 );

	nameText = new wxTextCtrl( categorySizer->GetStaticBox(), GroupNameText_Ctrl, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	nameText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer1->Add( nameText, 0, wxALL, 5 );

	urlLabel = new wxStaticText( categorySizer->GetStaticBox(), wxID_ANY, wxT("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	urlLabel->Wrap( -1 );
	flexGridSizer1->Add( urlLabel, 0, wxALL, 5 );

	urlText = new wxTextCtrl( categorySizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	urlText->SetMinSize( wxSize( 300,-1 ) );

	flexGridSizer1->Add( urlText, 0, wxALL, 5 );

	descriptionLabel = new wxStaticText( categorySizer->GetStaticBox(), wxID_ANY, wxT("Description"), wxDefaultPosition, wxDefaultSize, 0 );
	descriptionLabel->Wrap( -1 );
	flexGridSizer1->Add( descriptionLabel, 0, wxALL, 5 );

	descriptionText = new wxTextCtrl( categorySizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	descriptionText->SetMinSize( wxSize( 300,50 ) );

	flexGridSizer1->Add( descriptionText, 0, wxALL, 5 );


	categorySizer->Add( flexGridSizer1, 1, wxEXPAND, 5 );


	boxSizer->Add( categorySizer, 1, wxEXPAND, 5 );


	boxSizer->Add( 0, 5, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* passwordSizer;
	passwordSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Password Stats") ), wxVERTICAL );

	wxFlexGridSizer* flexGridSizer2;
	flexGridSizer2 = new wxFlexGridSizer( 1, 2, 0, 0 );
	flexGridSizer2->SetFlexibleDirection( wxBOTH );
	flexGridSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	passwordCountLabel = new wxStaticText( passwordSizer->GetStaticBox(), wxID_ANY, wxT("Password Count"), wxDefaultPosition, wxDefaultSize, 0 );
	passwordCountLabel->Wrap( -1 );
	flexGridSizer2->Add( passwordCountLabel, 0, wxALL, 5 );

	passwordCountText = new wxStaticText( passwordSizer->GetStaticBox(), GroupPasswordCountText_Ctrl, wxT("N/A"), wxDefaultPosition, wxDefaultSize, 0 );
	passwordCountText->Wrap( -1 );
	flexGridSizer2->Add( passwordCountText, 0, wxALL, 5 );


	passwordSizer->Add( flexGridSizer2, 1, wxEXPAND, 5 );


	boxSizer->Add( passwordSizer, 1, wxEXPAND, 5 );


	this->SetSizer( boxSizer );
	this->Layout();
	boxSizer->Fit( this );

	// Connect Events
	nameText->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BaseGroupForm::OnTextChanged ), NULL, this );
}

BaseGroupForm::~BaseGroupForm()
{
	// Disconnect Events
	nameText->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BaseGroupForm::OnTextChanged ), NULL, this );

}
