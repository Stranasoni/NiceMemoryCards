#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "wx/wx.h"

class MainFrame : public wxFrame
{
	 int PUT_ID = -1;
	 const wxColor gray = wxT("#5F9EA0");
	 const wxColor brick = wxT("#B22222");
	 const wxColor gold = wxT("#FFD700");
	 const wxColor olive = wxT("#556B2F");
	 const wxColor blue = wxT("#4682B4");
public:
	
	MainFrame(const wxString title);
	void OnClickbtn1(wxCommandEvent& event);
	

	wxButton* btn1;
	wxButton* btn2;
	wxButton* btn3;
	wxButton* btn4;
	wxButton* btn5;
	wxButton* btn6;
	wxButton* btn7;
	wxButton* btn8;
	
};

#endif
