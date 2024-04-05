#include "wx/wx.h"

class Menu : public wxFrame
{
	int ID_SCLEROSIS = 101;
	int ID_EASY = 102;
	int ID_MEDIUM = 103;
	int ID_HARD = 104;

public:
	Menu(const wxString title);
	
	wxButton* btn_start;
	wxStaticText* text_welcome;
	//set backroundImage? нет все не так просто
	wxPanel* panel;
	wxBitmap bitmap;
	wxImage image;
	wxFont my_font;

	//подменю выбора режима
	wxButton* btn_sclerosis;
	wxButton* btn_easy;
	wxButton* btn_medium;
	wxButton* btn_hard;
	wxButton* btn_back;

	void OnImagePanelPaint(wxPaintEvent& event);
	void ScaledImage();
	void Enter_btn(wxMouseEvent& event);
	void Leave_btn(wxMouseEvent& event);
	void Clicked_btn(wxCommandEvent& event);
	void Clicked_btns(wxCommandEvent& event);
	

};