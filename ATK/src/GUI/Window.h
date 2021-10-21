#pragma once

#include "Widgets/Widget.h"
#include "../Events/EventHandler/EventHandler.h"

#include <Windows.h>
#include <string>
#include <vector>

#define CLASS_NAME L"ATKWindow"

namespace ATK
{
	class Window
	{
		friend class Widget;
		
		friend LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		unsigned _x;
		unsigned _y;
		unsigned _width;
		unsigned _height;

		LPCWSTR _text;
		HWND _hWnd;
		HINSTANCE _hInstance;

		std::vector<Widget*> _widgets;

//		EventHandler _eventHandler;

		void handleCommand(WPARAM wParam,LPARAM lParam);

	public:
		Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height);
//		~Window();		

		HWND getHWND();
		HINSTANCE getInstance();
		
		void addWidget(Widget* widget);


	};
}

