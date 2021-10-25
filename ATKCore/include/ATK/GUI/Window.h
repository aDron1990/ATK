#pragma once

#include "../pch.h"

#include "Widgets/Widget.h"
#include "../Core/EventHandler.h"
//#include "../Core/Application.h"

#define CLASS_NAME L"ATKWindow"

namespace ATK
{
	class Window : public Widget
	{	
		friend LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		
		HINSTANCE _hInstance;

		std::vector<Widget*> _widgets;
		unsigned _state = SW_SHOW;

	public:
		Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height);
		~Window();		

		HINSTANCE getInstance();

		void switchState();
		void setState(unsigned state);
		unsigned getState();
		
		void addWidget(Widget* widget);
		void reDraw();

	};
}

