#include "../include/ATK/Core/Application.h"

namespace ATK
{
	Application::Application(HINSTANCE hInstance)
	{
		_hInstance = NULL;
		e = EventHandler::getInstance();
		_windows = e->getWindowList();
	}

	Application::~Application()
	{
		delete e;
	}

	HINSTANCE Application::getInstance()
	{
		return _hInstance;
	}

	void Application::setInstance(HINSTANCE hInstance)
	{
		_hInstance = hInstance;
	}

	unsigned Application::addWindow(Window* window)
	{
//		_windowsList.push_back(window);
		e->_windows.push_back(window);
		return e->_windows.size();
	}

	void Application::run()
	{
		while (1);
	}
}