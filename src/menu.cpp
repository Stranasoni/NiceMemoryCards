#include "menu.h"

Menu::Menu(const wxString title)
	:wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1024,768))
{
	wxImage::AddHandler(new wxJPEGHandler);
	image = wxImage(wxT("../res/geometry.jpg"), wxBITMAP_TYPE_JPEG);
	if (!image.IsOk()) {
		return;
	}

	panel = new wxPanel(this, wxID_ANY);
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	my_font = wxFont(18, wxFONTFAMILY_DEFAULT, wxSLANT, wxNORMAL);
	
		
	text_welcome = new wxStaticText(panel,wxID_ANY,"Не скучная игра в карточки на память");
	text_welcome->SetFont(my_font);
	text_welcome->SetBackgroundColour(wxColour("#303133"));
	text_welcome->SetForegroundColour(wxColour("#D6C91A"));

	btn_start = new wxButton(panel, wxID_ANY, wxString("Начать игру"),wxDefaultPosition,wxDefaultSize, wxNO_BORDER);
	btn_start->SetBackgroundColour(wxColour("#303133"));
	btn_start->SetForegroundColour(wxColour("#D6C91A"));
	btn_start->SetFont(my_font);

	vbox->Add(text_welcome,0, wxALIGN_CENTER| wxTOP,50);
	vbox->Add(btn_start,0,wxALIGN_CENTER| wxTOP,200);

	ScaledImage();

	panel->SetSizer(vbox );

	panel->Bind(wxEVT_PAINT, &Menu::OnImagePanelPaint, this);
	btn_start->Bind(wxEVT_ENTER_WINDOW, &Menu::Enter_btn, this);
	btn_start->Bind(wxEVT_LEAVE_WINDOW, &Menu::Leave_btn, this);
	btn_start->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Menu::Clicked_btn,this);
	Centre();

	
}
	
void Menu::OnImagePanelPaint(wxPaintEvent& event) {	
	if (panel->GetSize() != bitmap.GetSize()) {
		ScaledImage();
	}	
	wxPaintDC dc(panel);
	dc.DrawBitmap(bitmap, 0, 0);
}
void Menu::ScaledImage() {
	
	wxSize size = panel->GetSize();
	//gold strings
	bitmap = wxBitmap(image.Scale(size.GetWidth(), size.GetHeight(), wxIMAGE_QUALITY_NORMAL));//
	panel->Refresh();

}


void Menu::Clicked_btn(wxCommandEvent& event)
{
	wxImage::AddHandler(new wxJPEGHandler);
	image = wxImage(wxT("../res/post_geometry.jpg"), wxBITMAP_TYPE_JPEG);
	if (!image.IsOk()) {
		return;
	}
	ScaledImage();
	text_welcome->Hide();
	btn_start->Hide();

	//надо будет ощищать память при нажатии кнопки назад
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	//panel->DestroyChildren();
	btn_sclerosis = new wxButton(panel, ID_SCLEROSIS, wxString("Склероз"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn_sclerosis->SetBackgroundColour(wxColour("#303133"));
	btn_sclerosis->SetForegroundColour(wxColour("#D6C91A"));
	btn_sclerosis->SetFont(my_font);

	btn_easy = new wxButton(panel, ID_EASY, wxString("Релакс"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn_easy->SetBackgroundColour(wxColour("#303133"));
	btn_easy->SetForegroundColour(wxColour("#D6C91A"));
	btn_easy->SetFont(my_font);

	btn_medium = new wxButton(panel, ID_MEDIUM, wxString("Жизнь как она есть"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn_medium->SetBackgroundColour(wxColour("#303133"));
	btn_medium->SetForegroundColour(wxColour("#D6C91A"));
	btn_medium->SetFont(my_font);

	btn_hard = new wxButton(panel, ID_HARD, wxString("Фотографическая память"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn_hard->SetBackgroundColour(wxColour("#303133"));
	btn_hard->SetForegroundColour(wxColour("#D6C91A"));
	btn_hard->SetFont(my_font);

	vbox->Add(wxTop, 200);
	vbox->Add(btn_sclerosis, 0, wxALIGN_CENTER | wxALL , 10);
	vbox->Add(btn_easy, 0, wxALIGN_CENTER | wxALL, 10);
	vbox->Add(btn_medium, 0, wxALIGN_CENTER | wxALL, 10);
	vbox->Add(btn_hard, 0, wxALIGN_CENTER | wxALL, 10);
	vbox->Add(wxDOWN, 200);
	
	panel->SetSizer(NULL);

	panel->SetSizer(vbox);
	panel->Layout();

	
	btn_sclerosis->Bind(wxEVT_ENTER_WINDOW, &Menu::Enter_btn, this);
	btn_sclerosis->Bind(wxEVT_LEAVE_WINDOW, &Menu::Leave_btn, this);
	btn_sclerosis->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Menu::Clicked_btns, this);

	btn_easy->Bind(wxEVT_ENTER_WINDOW, &Menu::Enter_btn, this);
	btn_easy->Bind(wxEVT_LEAVE_WINDOW, &Menu::Leave_btn, this);
	btn_easy->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Menu::Clicked_btns, this);

	btn_medium->Bind(wxEVT_ENTER_WINDOW, &Menu::Enter_btn, this);
	btn_medium->Bind(wxEVT_LEAVE_WINDOW, &Menu::Leave_btn, this);
	btn_medium->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Menu::Clicked_btns, this);

	btn_medium->Bind(wxEVT_ENTER_WINDOW, &Menu::Enter_btn, this);
	btn_medium->Bind(wxEVT_LEAVE_WINDOW, &Menu::Leave_btn, this);
	btn_medium->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Menu::Clicked_btns, this);

	btn_hard->Bind(wxEVT_ENTER_WINDOW, &Menu::Enter_btn,this);
	btn_hard->Bind(wxEVT_LEAVE_WINDOW, &Menu::Leave_btn, this);
	btn_hard->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Menu::Clicked_btns, this);
	
}


void Menu::Clicked_btns(wxCommandEvent& event)
{
	switch (event.GetId()) {
		case 101:
			//создаем окно класса MainFrame 
			break;
		case 102:
			break;
		case 103:
			break;
		case 104:
			break;
	}
}


void Menu::Enter_btn(wxMouseEvent& event)
{
	wxButton* current_btn = (wxButton*)FindWindowById(event.GetId());

	current_btn->SetForegroundColour(wxColour("#807718"));	
}
void Menu::Leave_btn(wxMouseEvent& event)
{
	wxButton* current_btn = (wxButton*)FindWindowById(event.GetId());
	current_btn->SetForegroundColour(wxColour("#D6C91A"));
}