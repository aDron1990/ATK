#pragma once

#include "../pch.h"

#include "EventHandler.h"
#include "../GUI/Window.h"

namespace ATK
{
	class Plugin;
	class Application
	{
		friend class Plugin;
	protected:

		HINSTANCE _hInstance;
		EventHandler* e;
		std::vector<Plugin*> _plugins;

	public:

		HINSTANCE getInstance();
		void setInstance(HINSTANCE hInstance);
		Application(HINSTANCE hInstance);
		virtual ~Application();
		virtual void run();
		unsigned addWindow(Window* window);
	};

	Application* GetApp(HINSTANCE hInstance);
}