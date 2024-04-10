#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "wx/wx.h"
#include <iterator>
#include <list>//delete

#include <random>
#include <vector>

#include <cmath>
#include <map>


class MainFrame : public wxFrame
{
	const wxColor gray = wxT("#5F9EA0");
	const int game_mode;

	//!!smart point?(генерация цветов)
	std::map<int, wxColor>* btn_and_colors = new std::map<int, wxColor>();
	std::vector<wxColor> colors;	
	size_t index_colors = 0;
	

	//игра
	int PUT_ID = NULL;
	wxButton* current_button;
	wxButton* previos_button;
	bool select_two_cards = false;

	//счетчик и сопутсвующее
	wxFont my_font = wxFont(18, wxFONTFAMILY_DEFAULT, wxBOLD, wxNORMAL);
	wxStaticText* score;
	int score_int = 10;
	void PrintResult();


	
	void OnClickbtns(wxCommandEvent& event);

	void RandomPermutation(std::vector<wxColor>& colors);
	std::pair<int,int> MatrixSize(int count_cards);
	wxColor RandomColour();
	
public:
	MainFrame(int cards_count, wxWindow* parent, const wxString& title = "poher");
};

 
#endif
