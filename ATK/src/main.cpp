#include <Windows.h>
#include "ATK/ATK.h"

static std::vector<std::pair<ATK::Widget*, ATK::Window*>*> x;
void Onclick(ATK::Widget* widget);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{

	auto app = ATK::GetApp(hInstance);
//	delete app;
	app->run();
	return EXIT_SUCCESS;
}

class TestApp : public ATK::Application
{
	ATK::Window* MainWindow;
//	ATK::Window* wnd1;

public:

	TestApp(HINSTANCE hInstance) : Application(hInstance)
	{
		HMODULE idGenerator = LoadLibrary(L"idGenerator.dll");
		ATK::Widget::GenerateId = (GetIdProc)GetProcAddress(idGenerator, "getId");

		MainWindow = new ATK::Window(hInstance, L"Advanced ToolKit", 300, 300);
//		wnd1 = new ATK::Window(hInstance, L"wnd1", 100, 100);

		HMODULE PluginLoader = LoadLibrary(L"PluginLoader.dll");
		LoadPluginsFuncP Load = (LoadPluginsFuncP)GetProcAddress(PluginLoader, "LoadPlugins");
		
		Load(this);
	}

	void run()
	{	
		for (int i = 1; i < e->_windows.size(); i++)
		{
			ATK::Button* btn = new ATK::Button(e->_windows[i]->getText(), 0, 0 - 30 + 30 * i, 100, 30);
			x.push_back(new std::pair<ATK::Widget*, ATK::Window*>(btn, e->_windows[i]));
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