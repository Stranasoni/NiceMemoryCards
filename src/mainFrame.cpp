#include "mainFrame.h"
#include "../usefulClasses/myRandom.h"

//MyButton::MyButton(wxWindow* parent,
//	wxWindowID id,
//	const wxString& label = wxEmptyString,
//	const wxPoint& pos = wxDefaultPosition,
//	const wxSize& size = wxDefaultSize,
//	long style = 0,
//	const wxValidator& validator = wxDefaultValidator,
//	const wxString& name = wxASCII_STR(wxButtonNameStr)) 
//	:wxButton(parent,id,label,pos,size,style,validator,name)
//{
//
//}


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

	btn1->SetBackgroundColour(my_colors[0]);
	btn2->SetBackgroundColour(my_colors[0]);
	btn3->SetBackgroundColour(my_colors[0]);
	btn4->SetBackgroundColour(my_colors[0]);

	hbox1->Add(btn1,1,wxEXPAND | wxALL, 5);
	hbox1->Add(btn2, 1, wxEXPAND | wxALL, 5);
	hbox1->Add(btn3, 1, wxEXPAND | wxALL, 5);
	hbox1->Add(btn4, 1, wxEXPAND | wxALL, 5);

	btn5 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn6 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn7 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn8 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);

	btn5->SetBackgroundColour(my_colors[0]);
	btn6->SetBackgroundColour(my_colors[0]);
	btn7->SetBackgroundColour(my_colors[0]);
	btn8->SetBackgroundColour(my_colors[0]);

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
	wxButton* current_button;
	wxButton* previos_button;
	switch (PUT_ID) {
		//кстати здесь не учтено выбранная карточка = предыдущей
	case -1:
		PUT_ID = event.GetId();
		current_button = (wxButton*)FindWindowById(PUT_ID);
		if (!btn_and_color.count(PUT_ID)) {
			MyRandom* rand = new MyRandom(5, 1);
			btn_and_color[PUT_ID] = my_colors[rand->GetRNums()[0]];//и это не гарантирует никаких паросочетаний но я устала в новой версии переделаю
		}
		//цвет определен - отобразить
		current_button->SetBackgroundColour(btn_and_color[PUT_ID]);
		break;
	default:		
		previos_button = (wxButton*)FindWindowById(PUT_ID);
		PUT_ID = event.GetId();
		current_button = (wxButton*)FindWindowById(PUT_ID);
		if (!btn_and_color.count(PUT_ID)) {
			MyRandom* rand = new MyRandom(5, 1);
			btn_and_color[PUT_ID] = my_colors[rand->GetRNums()[0]];
		}
		current_button->SetBackgroundColour(btn_and_color[PUT_ID]);
		//далле если цвета совпали осталяем, в идеале сделать некликабельными
		if (current_button->GetBackgroundColour() == previos_button->GetBackgroundColour()) { PUT_ID = -1; break; }
		
		current_button->SetBackgroundColour(my_colors[0]);
		previos_button->SetBackgroundColour(my_colors[0]);
		PUT_ID = -1;
		break;
		
		
	}
	

}