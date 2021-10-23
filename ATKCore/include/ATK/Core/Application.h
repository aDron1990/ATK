#pragma 

#include "../pch.h"

#include "EventHandler.h"
#include "../GUI/Window.h"

namespace ATK
{
	class Application
	{
		Application* instance;
		EventHandler* e;

	public:
		Application();
		~Application();

		std::vector<Window*> _windowsList;

		void run();
		void addWindow(Window* window);
	};
}