#include "../include/ATK/Plugin/Plugin.h"

namespace ATK
{
	Plugin::Plugin(Application* app) : _app(app)
	{

	}

	Plugin::~Plugin()
	{

	}

	void Plugin::init()
	{
		_app->_plugins.push_back(this);
		for (unsigned i = 0; i < _windows.size(); i++)
		{
			_app->addWindow(_windows[i]);
		}
	}

	void Plugin::addWindow(Window* window)
	{
		_windows.push_back(window);
		_app->addWindow(window);
	}
}