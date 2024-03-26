#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "wx/wx.h"
#include <iterator>
#include <list>
#include <map>
//const struct MYColours {
//	const wxColor gray = wxT("#5F9EA0");
//	const wxColor brick = wxT("#B22222");
//	const wxColor gold = wxT("#FFD700");
//	const wxColor olive = wxT("#556B2F");
//	const wxColor blue = wxT("#4682B4");
//};
class MainFrame : public wxFrame
{
public://временно
	 int PUT_ID = -1;
	 std::list<int> random_nums{};
	 std::list<int>::iterator iter_r_nums; 
	 std::map<int, wxColor> btn_and_color;
	 const wxColor gray = wxT("#5F9EA0");
	 const wxColor my_colors[4]{wxT("#B22222"),wxT("#FFD700"),wxT("#556B2F"),wxT("#4682B4") };
	
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

//class MyButton : public wxButton
//{
//	wxColour color;
//public:
//	MyButton(wxWindow* parent,
//		wxWindowID id,
//		const wxString& label = wxEmptyString,
//		const wxPoint& pos = wxDefaultPosition,
//		const wxSize& size = wxDefaultSize,
//		long style = 0,
//		const wxValidator& validator = wxDefaultValidator,
//		const wxString& name = wxASCII_STR(wxButtonNameStr));
//
//};
 
#endif
