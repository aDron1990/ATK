#pragma once

#include "../../GUI/Window.h"
#include "../../GUI/Widgets/Widget.h"

#include <Windows.h>
#include "../../GUI/Widgets.h"

#include <vector>

namespace ATK
{
	class EventHandler
	{
		static EventHandler* _instance;
		friend class Window;
		friend class Widget;

		friend LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		std::vector<Window*> _windows;
		void addWindow(Window* window);
		void update();

		EventHandler();
		MSG msg = { };

	public:
		EventHandler(EventHandler& other) = delete;
		static EventHandler* getInstance();
		
		bool getMessage();
		void pollEvents();
	};

}

