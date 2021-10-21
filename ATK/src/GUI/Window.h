#pragma once

#include "Widgets/Widget.h"
#include "../Events/EventHandler/EventHandler.h"

#include <Windows.h>
#include <string>
#include <vector>

#define CLASS_NAME L"ATKWindow"

namespace ATK
{
	class Window : public Widget
	{	
		friend LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		
		HINSTANCE _hInstance;

		std::vector<Widget*> _widgets;

	public:
		Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height);
		~Window();		

		HINSTANCE getInstance();
		
		void addWidget(Widget* widget);
		void reDraw();

	};
}

