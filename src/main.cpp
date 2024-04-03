

#include "menu.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
	std::cout;
	Menu* mf = new Menu(wxT("Memory"));
	mf->Show();
	return true;
}
