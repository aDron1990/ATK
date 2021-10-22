#include "Events/EventHandler/EventHandler.h"
#include "GUI/Window.h"
#include "GUI/widgets.h"
#include "strTools.h"

#include <Windows.h>
#include <iostream>

ATK::Window* window;
ATK::Button* bt_plus;
ATK::Button* bt_minus;
ATK::Button* bt_mult;
ATK::Button* bt_div;
ATK::Edit* e1;
ATK::Edit* e2;
ATK::Edit* e3;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	window = new ATK::Window(hInstance, L"Калькулятор", 400, 550);
	
	e1 = new ATK::Edit(nullptr, 50, 100, 125, 20);
	e2 = new ATK::Edit(nullptr, 225, 100, 125, 50);
	e3 = new ATK::Edit(nullptr, 100, 220, 200, 50);
	bt_plus = new ATK::Button(L"=", 50, 160, 300, 30);

	window->addWidget(e1);
	window->addWidget(e2);
	window->addWidget(e3);

	ATK::EventHandler* event = ATK::EventHandler::getInstance();
	while (event->getMessage())
	{
		event->pollEvents();
	}

	delete event;

	return EXIT_SUCCESS;
}