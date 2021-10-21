#pragma once

#include "Widgets/Widget.h"

#include <Windows.h>
#include <string>
#include <vector>

#define CLASS_NAME L"ATKWindow"

namespace ATK
{
	class Window
	{
		friend class Widget;
		HWND _hWnd;
		HINSTANCE _hInstance;
		
		std::vector<Widget*> _widgets;
	public:
		HWND getHWND();
		HINSTANCE getInstance();
		Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height);
		void addWidget(Widget* widget);
//		~Window();
	};
}

