#pragma once

#include "../pch.h"

#include "../GUI/Window.h"
#include "../GUI/Widgets/Widget.h"
#include "../GUI/Widgets.h"

namespace ATK
{
	class EventHandler
	{
		static EventHandler* _instance;
		friend class Window;
		friend class Widget;
		friend class Application;

		friend LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		std::vector<Window*> _windows;
		void addWindow(Window* window);
		void update();

		EventHandler();
		MSG msg = { };

	public:
		~EventHandler();

		EventHandler(EventHandler& other) = delete;
		static EventHandler* getInstance();
		
		std::vector<Window*> getWindowList();
		bool getMessage();
		void pollEvents();
	};

}

