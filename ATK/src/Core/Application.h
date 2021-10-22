#pragma 

#include "../Events/EventHandler/EventHandler.h"
#include "../GUI/Window.h"

#include <vector>

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