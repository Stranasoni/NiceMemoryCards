

#include "mainFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
	std::cout;
	MainFrame* mf = new MainFrame(wxT("Memory"));
	mf->Show();
	return true;
}
