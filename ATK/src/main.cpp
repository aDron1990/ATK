#include <Windows.h>
#include "ATK/ATK.h"

ATK::Button* b;

void gfeqwertf(ATK::Widget* widget)
{
	widget->setPosition(widget->getPosition()[0] + 10, widget->getPosition()[1] + 10);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	ATK::Window* window = new ATK::Window(hInstance, L"win", 800, 600);
	ATK::EventHandler* e = ATK::EventHandler::getInstance();

	HMODULE hM = LoadLibrary(L"PluginManager");
	void(*init)() = (void(*)())GetProcAddress(hM, "Init");

	b = new ATK::Button(L"Êíîïêà", 0, 0, 100, 30);
	b->setOnClick(gfeqwertf);
	window->addWidget(b);

	while (e->getMessage())
	{
		e->pollEvents();
	}
	return EXIT_SUCCESS;
}