#include "Events/EventHandler/EventHandler.h"
#include "GUI/Window.h"
#include "GUI/widgets.h"

#include <Windows.h>
#include <iostream>

void b1OnClick(ATK::Widget* widget);

ATK::Edit* e1;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	ATK::Window window(hInstance, L"Window", 800, 600);
	
	ATK::Button b1(L"кнопка 1", 0, 0, 100, 30);
	e1 = new ATK::Edit(L"", 0, 30, 100, 30);

	window.addWidget(&b1);
	window.addWidget(e1);

	b1.setOnClick(b1OnClick);
	ATK::EventHandler* event = ATK::EventHandler::getInstance();
	while (event->getMessage())
	{
		event->pollEvents();
	}

	delete e1;
	delete event;
	return EXIT_SUCCESS;
}

void b1OnClick(ATK::Widget* widget)
{
	MessageBox(NULL, e1->getText(), L"2", MB_OK);
}