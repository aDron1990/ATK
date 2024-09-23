#pragma once

#include "../Core/Application.h"
#include "../GUI/Window.h"

namespace ATK
{
	class Plugin
	{
		std::vector<Window*> _windows;
	protected:
		Application* _app;
	public:
		Plugin(Application* app);
		virtual ~Plugin();

		void init();
		void addWindow(Window* window);
	};
}
