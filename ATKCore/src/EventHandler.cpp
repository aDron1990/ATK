#include "../include/ATK/Core/EventHandler.h"


namespace ATK
{
	EventHandler* EventHandler::_instance = nullptr;

	EventHandler::EventHandler()
	{
		
	}

	EventHandler::~EventHandler()
	{
		for (int i = 0; i < _windows.size(); i++)
		{
			delete &_windows[i];
		}
	}

	void EventHandler::addWindow(Window* window)
	{
		_windows.push_back(window);
	}

	bool EventHandler::getMessage()
	{
		return GetMessage(&msg, NULL, 0, 0) > 0;
	}

	void EventHandler::pollEvents()
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		EventHandler *e = EventHandler::getInstance();
		switch (uMsg)
		{
		case WM_SYSCOMMAND:
			switch (wParam)
			{
			case SC_CLOSE:
				if (hWnd == e->_windows[0]->getHWnd()) PostQuitMessage(0);
				else
				{
					if (hWnd == e->_windows[0]->getHWnd()) PostQuitMessage(0);
					else
					{
						for (unsigned i = 1; i < e->_windows.size(); i++)
						{
							if (hWnd == e->_windows[i]->getHWnd())
							{
								e->_windows[i]->switchState();
								return false;
							}
						}
					}
				}
				break;
			}
			break;
		case WM_DESTROY:
//			PostQuitMessage(0);
			break;
		case WM_PAINT:
			for (int i = 0; i < e->_windows.size(); i++)
			{
				if (wParam == e->_windows[i]->getID())
				{
					e->_windows[i]->reDraw();
				}
			}
			break;
		case WM_COMMAND:
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
				for (int i = 0; i < e->_windows.size(); i++)
				{
					for (int j = 0; j < e->_windows[i]->_widgets.size(); j++)
					{
						if (LOWORD(wParam) == e->_windows[i]->_widgets[j]->getID())
						{
							(dynamic_cast<Edit*>(e->_windows[i]->_widgets[j]))->OnChange();
						}

					}
				}
				break;
			case EN_MAXTEXT:
				for (int i = 0; i < e->_windows.size(); i++)
				{
					for (int j = 0; j < e->_windows[i]->_widgets.size(); j++)
					{
						if (LOWORD(wParam) == e->_windows[i]->_widgets[j]->getID())
						{
							(dynamic_cast<Edit*>(e->_windows[i]->_widgets[j]))->OnChange();
						}

					}
				}
				break;
			}
			for (int i = 0; i < e->_windows.size(); i++)
			{
				for (int j = 0; j < e->_windows[i]->_widgets.size(); j++)
				{
					if (wParam == e->_windows[i]->_widgets[j]->getID())
					{
						(dynamic_cast<Button*>(e->_windows[i]->_widgets[j]))->OnClick();
					}
						
				}
			}
		}

		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	std::vector<Window*> EventHandler::getWindowList()
	{
		return _windows;
	}

	EventHandler* EventHandler::getInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new EventHandler();
		}
		return _instance;
	}
}

