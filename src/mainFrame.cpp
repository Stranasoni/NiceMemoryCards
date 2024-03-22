#include "mainFrame.h"



MainFrame::MainFrame(const wxString title)
	:wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(-1, -1))
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);

	//wxPanel* first_panel = new wxPanel(this, wxID_ANY);
	//wxPanel* second_panel = new wxPanel(this, wxID_ANY);

	btn1 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn2 = new wxButton(panel,wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn3 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn4 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);

	btn1->SetBackgroundColour(gray);
	btn2->SetBackgroundColour(gray);
	btn3->SetBackgroundColour(gray);
	btn4->SetBackgroundColour(gray);

	hbox1->Add(btn1,1,wxEXPAND | wxALL, 5);
	hbox1->Add(btn2, 1, wxEXPAND | wxALL, 5);
	hbox1->Add(btn3, 1, wxEXPAND | wxALL, 5);
	hbox1->Add(btn4, 1, wxEXPAND | wxALL, 5);

	btn5 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn6 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn7 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn8 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);

	btn5->SetBackgroundColour(gray);
	btn6->SetBackgroundColour(gray);
	btn7->SetBackgroundColour(gray);
	btn8->SetBackgroundColour(gray);

	hbox2->Add(btn5, 1, wxEXPAND | wxALL, 5);
	hbox2->Add(btn6, 1, wxEXPAND | wxALL, 5);
	hbox2->Add(btn7, 1, wxEXPAND | wxALL, 5);
	hbox2->Add(btn8, 1, wxEXPAND | wxALL, 5);
	
	vbox->Add(hbox1,1, wxEXPAND);
	vbox->Add(hbox2,1, wxEXPAND);

	Connect(btn1->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
	Connect(btn2->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
	Connect(btn3->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
	Connect(btn4->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
	Connect(btn5->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
	Connect(btn6->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
	Connect(btn7->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
	Connect(btn8->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
	

	panel->SetSizer(vbox);
}

void MainFrame::OnClickbtn1(wxCommandEvent& event) {

	switch (PUT_ID) {
	case -1:
		PUT_ID = event.GetId();
		wxButton* current_button = (wxButton*)FindWindowById(PUT_ID);
		

	}
	if (PUT_ID == -1) {
		PUT_ID = event.GetId();
	}
	else {
		wxButton* previos_button = (wxButton*)FindWindowById(PUT_ID);
		previos_button->SetBackgroundColour(wxColor("#000000"));
	}

}