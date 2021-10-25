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

//		void update();

		EventHandler();
		MSG msg = { };
		bool _appState = 1;

	public:
		~EventHandler();

		EventHandler(EventHandler& other) = delete;
		static EventHandler* getInstance();
		
		std::vector<Window*> _windows;
		BOOL getMessage();
		void pollEvents();
	};

}

