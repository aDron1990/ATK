#pragma once

#include "../GUI/Window.h"
#include "../Core/Application.h"

namespace ATK
{

	class Plugin
	{
		Application* app;
		

	public:

		void addWindow(Window* window);
		Plugin(ATK::Application* app);
		virtual ~Plugin();
	};

}