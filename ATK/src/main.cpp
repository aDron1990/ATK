#include "GUI/Window.h"
#include "GUI/widgets.h"

#include <Windows.h>
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	ATK::Window window(hInstance, L"Window", 800, 600);
	
	ATK::Button b1(L"кнопка 1", 0, 0, 100, 30);
	ATK::Button b2(L"кнопка 2", 100, 0, 100, 30);

	window.addWidget(&b1);
	window.addWidget(&b2);

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return EXIT_SUCCESS;
}