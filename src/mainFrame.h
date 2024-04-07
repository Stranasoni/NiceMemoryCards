#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "wx/wx.h"
#include <iterator>
#include <list>//delete
#include <map>
#include <random>
#include <vector>

#include <cmath>
#include <thread>
#include <chrono>


//const struct MYColours {
//	const wxColor gray = wxT("#5F9EA0");
//	const wxColor brick = wxT("#B22222");
//	const wxColor gold = wxT("#FFD700");
//	const wxColor olive = wxT("#556B2F");
//	const wxColor blue = wxT("#4682B4");
// 
//};
//!
//! 
//! std::vector<wxColor> colors = { wxColor("#b32727"), wxColor("#b32727"), wxColor("#b32727"), wxColor("#b32727"),
//wxColor("#b32727"), wxColor("#b32727"), wxColor("#b32727"), wxColor("#b32727") };

class MainFrame : public wxFrame
{

	int PUT_ID = -1;
	//!!smart point?
	std::map<int, wxColor>* btn_and_colors = new std::map<int, wxColor>();
	//std::map<wxButton*, wxColor>* btn_and_colors = new std::map<wxButton*, wxColor>;
	//!!здесь нужно будет реализовать с помощью рандомных побидовых сдвигов hex кода числа или rgb. интереснее будет с hex 
	//! это будет автоматически генерироваться в зависимости от выбранного режима 
	//! кстати наверное это лучше всего хранить в структуре? хотя зачем я же случайно цвета выбираю
	
	std::vector<wxColor> colors;
	const wxColor gray = wxT("#5F9EA0");
	size_t index_colors = 0;
	const int game_mode;


	wxButton* current_button;
	wxButton* previos_button;
	bool first = true;

public:
	MainFrame(int cards_count, wxWindow* parent, const wxString& title = "poher");
	
	//!!сдклать шаблонным? //пиздец этот array даже по ссылке передать нельзя
	void RandomPermutation(std::vector<wxColor>& colors);
	
	std::pair<int,int> MatrixSize(int count_cards);

	wxColor RandomColour();

	void check(wxButton& btn);



	

public://временно
	
	
	
	 
	
	 
	
public:
	
	MainFrame(const wxString title);
	void OnClickbtns(wxCommandEvent& event);
	

	wxButton* btn1;
	//wxButton* btn2;
	//wxButton* btn3;
	//wxButton* btn4;
	//wxButton* btn5;
	//wxButton* btn6;
	//wxButton* btn7;
	//wxButton* btn8;
	//
};

 
#endif
