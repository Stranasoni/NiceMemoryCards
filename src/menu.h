#include "wx/wx.h"

class Menu : public wxFrame
{
public:
	Menu(const wxString title);
	
	wxButton* btn_start;
	wxStaticText* text_welcome;
	//set backroundImage? ��� ��� �� ��� ������
	wxPanel* panel;
	//wxImage squard;
	wxBitmap bitmap;
	wxImage image;

	void OnImagePanelPaint(wxPaintEvent&);
	

};