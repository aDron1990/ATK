#include "GUI/Window.h"
#include "GUI/Widgets.h"

#include <Windows.h>
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	ATK::Window window(hInstance, L"Window", 1280, 720);
	
	ATK::Button btn(L"aga", 0, 0, 50, 50);

	window.addWidget(&btn);

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return EXIT_SUCCESS;
}