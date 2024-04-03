#include "menu.h"

Menu::Menu(const wxString title)
	:wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1024,768))
{
	panel = new wxPanel(this, wxID_ANY);
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	wxFont my_font = wxFont(16, wxFONTFAMILY_SWISS, wxSLANT, wxNORMAL);
	wxImage::AddHandler(new wxJPEGHandler);
	image = wxImage(wxT("../res/menu.jpg"),wxBITMAP_TYPE_JPEG);
	if (!image.IsOk()) {
		return;//сборщик мусора автоматически?
	}
	wxSize size = panel->GetSize();
	bitmap = wxBitmap(image.Scale(size.GetWidth(), size.GetHeight(), wxIMAGE_QUALITY_NORMAL));
	//wxPaintDC dc(panel);
	//dc.DrawBitmap(bitmap, 0, 0);



	text_welcome = new wxStaticText(panel,wxID_ANY,"Не скучная игра в карточки на память");
	text_welcome->SetFont(my_font);

	btn_start = new wxButton(panel, wxID_ANY, wxString("Начать игру"),wxDefaultPosition,wxDefaultSize, wxNO_BORDER);
	btn_start->SetBackgroundColour(wxColour("#000000"));
	btn_start->SetFont(my_font);

	vbox->Add(text_welcome,0, wxALIGN_CENTER| wxTOP,50);
	vbox->Add(btn_start,0,wxALIGN_CENTER| wxTOP,200);
	panel->SetSizer(vbox );
	Centre();

	panel->Bind(wxEVT_PAINT, &Menu::OnImagePanelPaint, this);
}
	
void Menu::OnImagePanelPaint(wxPaintEvent&) {
	if (panel->GetSize() != bitmap.GetSize()) {
		wxSize size = panel->GetSize();
		bitmap = wxBitmap(image.Scale(size.GetWidth(), size.GetHeight(), wxIMAGE_QUALITY_NORMAL));
	}
	
	wxPaintDC dc(panel);
	dc.DrawBitmap(bitmap, 0, 0);
}