#include "mainFrame.h"
#include "../usefulClasses/myRandom.h"


MainFrame::MainFrame(int cards_count, wxWindow* parent, const wxString& title)
	: wxFrame(parent, wxID_ANY, title,parent->GetPosition(), parent->GetSize()), game_mode(cards_count), end_game(cards_count/2)
{
	
	panel = new wxPanel(this, wxID_ANY);
	vbox = new wxBoxSizer(wxVERTICAL);

	//все необходимые значения для графики мы получим из game_mode 
	std::pair<int, int> rw_cl = MatrixSize(cards_count);

	int temp_cards_count = cards_count /2;
	while (temp_cards_count-- > 0) {
		colors.push_back(RandomColour());
		colors.push_back(colors[colors.size()-1]);
	}

	RandomPermutation(colors);
	
	//панель с счетчиком игры
	vboxScore = new wxBoxSizer(wxVERTICAL);
	
	parting_words = new wxStaticText(panel, wxID_ANY, wxString("Откройте все карточки, потренируйте память, добейтесь успеха и получите приз."));
	score = new wxStaticText(panel, wxID_ANY, wxString("Очки: 0"));
	parting_words->SetFont(my_font);
	score->SetFont(my_font);
	
	vboxScore->Add(parting_words, 0, wxALIGN_CENTER| wxTOP, 15);
	vboxScore->Add(score, 0, wxALIGN_CENTER | wxTOP, 10);
	vbox->Add(vboxScore,0 , wxALIGN_CENTER | wxDOWN, 20);

	
	////что то здесь возможно вызывает утечки возможно это из за того что я теряю указатель хмм
	wxBoxSizer* cur_hbox;
	wxButton* cur_btn;

	for (size_t rows = 0; rows < rw_cl.first; ++rows)
	{
		cur_hbox = new wxBoxSizer(wxHORIZONTAL);
		for (size_t cols = 0; cols < rw_cl.second; ++cols, ++index_colors)
		{	
			cur_btn = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
			cur_btn->SetBackgroundColour(gray);
			Connect(cur_btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtns));

			cur_hbox->Add(cur_btn, 1, wxEXPAND | wxALL, 5);

			(*btn_and_colors)[cur_btn->GetId()] = colors[index_colors];
			
		}
		vbox->Add(cur_hbox, 1, wxEXPAND);
	}

	panel->SetSizer(vbox);
	Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(MainFrame::OnClose));
	
	
		

}





void MainFrame::OnClickbtns(wxCommandEvent& event)
{
	if (select_two_cards)
	{
		current_button->SetBackgroundColour(gray);
		previos_button->SetBackgroundColour(gray);
		select_two_cards = false;
	}
	
	bool alone = true;
	if (PUT_ID != NULL) 
	{ 
		alone = false;
		previos_button = (wxButton*)FindWindowById(PUT_ID);
	}

	PUT_ID = event.GetId();
	current_button = (wxButton*)FindWindowById(PUT_ID);
	current_button->SetBackgroundColour((*btn_and_colors)[PUT_ID]);

	if (alone || previos_button->GetId() == current_button->GetId()) return;

	if (current_button->GetBackgroundColour() != previos_button->GetBackgroundColour())
	{
		select_two_cards = true;	
		if (score_int > 2) score_int -= 4;
		

	}
	else {
		current_button->Enable(false); previos_button->Enable(false);	

		wxString new_label = std::to_string(wxAtoi(score->GetLabel().substr(6)) + score_int);
		score->SetLabelText(wxString("Очки: "+new_label));
		score_int = 10;
		//end game
		if (--end_game == 0) { PrintResult(); }
	}

	PUT_ID = NULL;
	
}

void MainFrame::PrintResult()
{
	int cur_score = wxAtoi(score->GetLabel().substr(6)) + score_int;
	if (cur_score < (game_mode * 4)) {
		parting_words->SetLabel(wxString("В этой игре вы не можете проиграть из-за неудачного расклада. Вы проиграли честно."));
	}
	else
	{
		wxImage::AddHandler(new wxPNGHandler);
		wxBitmapButton* win = new wxBitmapButton(panel, wxID_ANY, wxBitmap("../res/win.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(62, 54), wxBORDER_NONE);
		vboxScore->Replace(parting_words, win);
		parting_words->Destroy();
		
		//panel->Refresh();
		switch (game_mode)
		{
		case 4:
			score->SetLabel(wxString("Вы справились!(в этом режиме невозможно проиграть)"));
			break;
		case 8:
			score->SetLabel(wxString("Двигайтесь дальше"));
			break;
		case 16:
			score->SetLabel(wxString("ДА ПОЧЕМУ ВСЕ ЦВЕТА ОДИНАКОВЫЕ!?"));
			break;
		case 64:
			score->SetLabel(wxString("Я вас искренне поздравляю. Если в реальной жизни вы засомневаетесь в своих силах, ПОМНИТЕ,\n что здеесь вы навсегда остались героем игры, воплощением упорства и товарищем любопытству.\nНевозможно быть героем всегда, но именно такие моменты его и определяют. "));
			break;
		}	
	}
	panel->Layout();
}
void MainFrame::RandomPermutation(std::vector<wxColor>& colors)
{
	int fix = colors.size() ;
	int end = fix -1;
	int rand_index;
	while (end != 0)
	{
		rand_index = (rand())% fix;//чувствую надо вынести 
		wxColor temp_box = colors[end];
		colors[end] = colors[rand_index];
		colors[rand_index] = temp_box;
		--end;
	}
}

std::pair<int,int> MainFrame::MatrixSize(int count_cards) {
	//размер поля игры в зависимости от количества карточек

	int squart, rows,colums;
	if (count_cards % 10 == 4 || count_cards % 10 == 6) {
		squart = sqrt(count_cards);
		rows = squart, colums = squart;	
	}
	else
	{
		int pow_two = 0;
		while (count_cards != 1)
		{
			count_cards /= 2;
			++pow_two;
		}
		squart = sqrt(pow(2, pow_two));
		rows = squart;
		colums = squart * 2;

	}
	return std::pair<int, int>(rows, colums);
}

wxColor MainFrame::RandomColour() {
	int red = rand() % 256;
	int green = rand() % 256;
	int blue = rand() % 256;
	return wxColour(red, green, blue);
}

void MainFrame::OnClose(wxCloseEvent & event) {
	this->m_parent->SetPosition(this->GetPosition());
	this->m_parent->SetSize(this->GetSize());
	this->m_parent->Show(true);
	this->Destroy();


}