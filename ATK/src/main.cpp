#include "Events/EventHandler/EventHandler.h"
#include "GUI/Window.h"
#include "GUI/widgets.h"

#include <Windows.h>
#include <iostream>

void b1OnClick(ATK::Widget* widget);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	ATK::Window window(hInstance, L"Window", 800, 600);
	
	ATK::Button b1(L"кнопка 1", 0, 0, 100, 30);
	ATK::Button b2(L"кнопка 2", 100, 0, 100, 30);

	window.addWidget(&b1);

	b1.setOnClick(b1OnClick);
	ATK::EventHandler* event = ATK::EventHandler::getInstance();
	while (event->getMessage())
	{
		event->pollEvents();
	}

	return EXIT_SUCCESS;
}

void b1OnClick(ATK::Widget* widget)
{
	widget->setPosition((widget->getPosition())[0] + 50, (widget->getPosition())[1] + 50);
}