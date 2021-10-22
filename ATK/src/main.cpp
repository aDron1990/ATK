#include "Events/EventHandler/EventHandler.h"
#include "GUI/Window.h"
#include "GUI/widgets.h"
#include "strTools.h"

#include <Windows.h>
#include <iostream>

void OnClick(ATK::Widget* widget);

ATK::Edit* e1;
ATK::Edit* e2;
ATK::Edit* e3;

ATK::Button* equal;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	ATK::Window window(hInstance, L"Window", 400, 400);
	
	e1 = new ATK::Edit(nullptr, 50, 100, 125, 30);
	e2 = new ATK::Edit(nullptr, 225, 100, 125, 30);
	e3 = new ATK::Edit(nullptr, 100, 220, 200, 30);

	equal = new ATK::Button(L"=", 50, 160, 300, 30);

	window.addWidget(e1);
	window.addWidget(e2);
	window.addWidget(e3);
	window.addWidget(equal);

	equal->setOnClick(OnClick);

	ATK::EventHandler* event = ATK::EventHandler::getInstance();
	while (event->getMessage())
	{
		event->pollEvents();
	}

	delete e1;
	delete e2;
	delete e3;
	delete equal;
	delete event;

	return EXIT_SUCCESS;
}

void OnClick(ATK::Widget* widget)
{
	e3->setText(IntToStr(StrToInt(e1->getText()) + StrToInt(e2->getText())));
}