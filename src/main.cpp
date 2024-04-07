

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "menu.h"
#include "mainFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
	std::cout;
	//MainFrame* h = new MainFrame(4, NULL);
	//h->Show();
	Menu* mf = new Menu(wxT("Memory"));
	mf->Show();
	_CrtDumpMemoryLeaks();
	return true;
}
