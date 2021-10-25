#include <Windows.h>
#include "ATK/ATK.h"

static std::vector<std::pair<ATK::Widget*, ATK::Window*>*> x;
void Onclick(ATK::Widget* widget);

class TestApp : public ATK::Application
{
	ATK::Window* MainWindow;
	ATK::Window* wnd1;
	ATK::Window* wnd2;

public:

	TestApp(HINSTANCE hInstance) : Application(hInstance)
	{
		MainWindow = new ATK::Window(getInstance(), L"MainWindow", 300, 300);
		wnd1 = new ATK::Window(getInstance(), L"wnd1", 100, 100);
		wnd2 = new ATK::Window(getInstance(), L"wnd2", 100, 100);
	}

	void run()
	{	
		for (int i = 0; i < _windows.size() - 1; i++)
		{
			ATK::Button* btn = new ATK::Button(IntToStr(i), 0, 0 + 30 * i, 100, 30);
			x.push_back(new std::pair<ATK::Widget*, ATK::Window*>(btn, _windows[i + 1]));
			MainWindow->addWidget(btn);
			btn->setOnClick(Onclick);
		}
		while (e->getMessage())
		{
			e->pollEvents();
		}
	}

	~TestApp()
	{

	}
};

void Onclick(ATK::Widget* widget)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i]->first->getID() == widget->getID())
		{
			x[i]->second->switchState();
		}
	}
}

ATK::Application* ATK::GetApp(HINSTANCE hInstance)
{
	return new TestApp(hInstance);
}