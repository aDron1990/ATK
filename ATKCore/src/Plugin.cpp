#include "../include/ATK/Plugin/Plugin.h"

namespace ATK
{
	Plugin::Plugin(Application* app)
	{
		this->app = app;
	}

	Plugin::~Plugin()
	{

	}

	void Plugin::addWindow(Window* window)
	{
		app->addWindow(window);
	}
}