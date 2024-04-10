#include "wx/wx.h"
#include "mainFrame.h"

class Menu : public wxFrame
{
	int ID_SCLEROSIS = 4;
	int ID_EASY = 8;
	int ID_MEDIUM = 16;
	int ID_HARD = 64;

public:
	Menu(const wxString title);
	
	wxButton* btn_start;
	wxStaticText* text_welcome;
	//set backroundImage? нет все не так просто
	wxPanel* panel;
	wxBitmap bitmap;
	wxImage image;
	wxFont my_font= wxFont(18, wxFONTFAMILY_DEFAULT, wxBOLD, wxNORMAL);;

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
	void OnClose(wxCloseEvent& event) {
		
	}
	

};