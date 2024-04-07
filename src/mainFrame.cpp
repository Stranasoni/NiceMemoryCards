#include "mainFrame.h"
#include "../usefulClasses/myRandom.h"


MainFrame::MainFrame(int cards_count, wxWindow* parent, const wxString& title)
	: wxFrame(parent, wxID_ANY, title), game_mode(cards_count)
{


	

	wxPanel* panel = new wxPanel(this, wxID_ANY);
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

	/*btn1 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
	btn1->SetBackgroundColour(wxColour("#000000"));
	Connect(btn1->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));

	vbox->Add(btn1, 1, wxEXPAND | wxALL, 5);*/
	//все необходимые значени€ дл€ графики мы получим из game_mode 
	std::pair<int, int> rw_cl = MatrixSize(cards_count);

	int temp_cards_count = cards_count /2;
	while (temp_cards_count-- > 0) {
		colors.push_back(RandomColour());
		colors.push_back(colors[colors.size()-1]);
	}

	RandomPermutation(colors);

	wxBoxSizer* cur_hbox;
	wxButton* cur_btn;

	for (size_t rows = 0; rows < rw_cl.first; ++rows)
	{
		cur_hbox = new wxBoxSizer(wxHORIZONTAL);
		for (size_t cols = 0; cols < rw_cl.second; ++cols, ++index_colors)
		{	
			cur_btn = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
			cur_btn->SetBackgroundColour(wxColour("#000000"));
			Connect(cur_btn->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtns));

			cur_hbox->Add(cur_btn, 1, wxEXPAND | wxALL, 5);

			(*btn_and_colors)[cur_btn->GetId()] = colors[index_colors];
			
		}
		vbox->Add(cur_hbox, 1, wxEXPAND);
	}

	panel->SetSizer(vbox);
	Centre();
	//если оставить так то первые game_mode кнопок всегда будут разные , а не случайные поэтому хмм может быть просто создадим массив двойного размера и все
	

	//RandomPermutation(colors);
	
	

			//указатели можно перезаписывать поэтому создавай не временный обьект
			// будет случайнее если € буду назначать цвет в момент открыти€
			//потом когда будешь переворачивать карты прийдетс€ использовать метод find . ¬ целом если будет необходимость может заменить ключ в словаре
			//отрисовка кнопок и сайзеров дальше доброе утро 
		

}

















//MainFrame::MainFrame(const wxString title)
//	:wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(-1, -1))
//{
//	wxPanel* panel = new wxPanel(this, wxID_ANY);
//	
//	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
//	wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);
//	wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
//
//	//wxPanel* first_panel = new wxPanel(this, wxID_ANY);
//	//wxPanel* second_panel = new wxPanel(this, wxID_ANY);
//
//	btn1 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
//	btn2 = new wxButton(panel,wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
//	btn3 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
//	btn4 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
//
//	btn1->SetBackgroundColour(gray);
//	btn2->SetBackgroundColour(gray);
//	btn3->SetBackgroundColour(gray);
//	btn4->SetBackgroundColour(gray);
//
//	hbox1->Add(btn1,1,wxEXPAND | wxALL, 5);
//	hbox1->Add(btn2, 1, wxEXPAND | wxALL, 5);
//	hbox1->Add(btn3, 1, wxEXPAND | wxALL, 5);
//	hbox1->Add(btn4, 1, wxEXPAND | wxALL, 5);
//
//	btn5 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
//	btn6 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
//	btn7 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
//	btn8 = new wxButton(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
//
//	btn5->SetBackgroundColour(gray);
//	btn6->SetBackgroundColour(gray);
//	btn7->SetBackgroundColour(gray);
//	btn8->SetBackgroundColour(gray);
//
//	hbox2->Add(btn5, 1, wxEXPAND | wxALL, 5);
//	hbox2->Add(btn6, 1, wxEXPAND | wxALL, 5);
//	hbox2->Add(btn7, 1, wxEXPAND | wxALL, 5);
//	hbox2->Add(btn8, 1, wxEXPAND | wxALL, 5);
//	
//	vbox->Add(hbox1,1, wxEXPAND);
//	vbox->Add(hbox2,1, wxEXPAND);
//
//	Connect(btn1->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
//	Connect(btn2->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
//	Connect(btn3->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
//	Connect(btn4->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
//	Connect(btn5->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
//	Connect(btn6->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
//	Connect(btn7->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
//	Connect(btn8->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClickbtn1));
//	

	
//	MyRandom* rand = new MyRandom();
//	std::vector<int>& pofig = rand->GetRNums(4);
//	std::vector<int>& pofig2 = rand->GetRNums(4);
//	for (int i = 0; i < pofig.size(); ++i)
//	{
//		random_nums.push_back(pofig[i]);
//	}
//	for (int i = 0; i < pofig2.size(); ++i)
//	{
//		random_nums.push_back(pofig2[i]);
//	}
//	iter_r_nums = random_nums.begin();
// 
// 
//}




void MainFrame::OnClickbtns(wxCommandEvent& event)
{
	if (!first)
	{
		current_button->SetBackgroundColour(gray);
		previos_button->SetBackgroundColour(gray);
		
	}
	first = false;
	if (PUT_ID == -1) {
		PUT_ID = event.GetId();
		current_button = (wxButton*)FindWindowById(PUT_ID);
		current_button->SetBackgroundColour((*btn_and_colors)[PUT_ID]);
	}
	else
	{
		previos_button = (wxButton*)FindWindowById(PUT_ID);
		PUT_ID = event.GetId();
		current_button = (wxButton*)FindWindowById(PUT_ID);
		current_button->SetBackgroundColour((*btn_and_colors)[PUT_ID]);
		current_button->Refresh();
		
		if (current_button->GetBackgroundColour() == previos_button->GetBackgroundColour())
		{
			current_button->Enable(false); previos_button->Enable(false);
			PUT_ID = -1;			
		}
		else {
			
			//std::this_thread::sleep_for(std::chrono::seconds(2));
			/*current_button->SetBackgroundColour(gray);
			previos_button->SetBackgroundColour(gray);*/
			PUT_ID = -1;
		}
		
		
	}

	
}

//void MainFrame::OnClickbtns(wxCommandEvent& event) {
//	wxButton* current_button;
//	wxButton* previos_button;
//	if (index_colors == game_mode / 2) { RandomPermutation(colors); index_colors = 0; }
//	switch (PUT_ID) {
//	//	//кстати здесь не учтено выбранна€ карточка = предыдущей
//	case -1:
//		PUT_ID = event.GetId();
//		current_button = (wxButton*)FindWindowById(PUT_ID);
//		if (!(*btn_and_colors).count(PUT_ID)) {
//			
//			(*btn_and_colors)[PUT_ID] = colors[index_colors++];
//		}
//	//	//цвет определен - отобразить
//		current_button->SetBackgroundColour((*btn_and_colors)[PUT_ID]);
//		break;//
//	default:		
//		previos_button = (wxButton*)FindWindowById(PUT_ID);
//		PUT_ID = event.GetId();
//		current_button = (wxButton*)FindWindowById(PUT_ID);
//		if (!(*btn_and_colors).count(PUT_ID)) {
//			
//			(*btn_and_colors)[PUT_ID] = colors[index_colors++];
//		}
//		current_button->SetBackgroundColour((*btn_and_colors)[PUT_ID]);
//	//	//далле если цвета совпали остал€ем, в идеале сделать некликабельными
//		if (current_button->GetBackgroundColour() == previos_button->GetBackgroundColour()) 
//		{
//			current_button->Enable(false); previos_button->Enable(false);
//			PUT_ID = -1; 
//			break; 
//		}
//		Sleep(100);
//		current_button->SetBackgroundColour(gray);
//		previos_button->SetBackgroundColour(gray);
//		PUT_ID = -1;
//		break;
//	//	
//	//	
//	}
//	
//
//}

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
	//размер пол€ игры в зависимости от количества карточек

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