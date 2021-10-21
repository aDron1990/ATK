#include "EventHandler.h"


namespace ATK
{
	EventHandler* EventHandler::_instance = nullptr;

	EventHandler::EventHandler()
	{
		
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
		case WM_DESTROY:
			PostQuitMessage(0);
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
			for (int i = 0; i < e->_windows.size(); i++)
			{
				for (int j = 0; j < e->_windows[i]->_widgets.size(); j++)
				{
					if (wParam == e->_windows[i]->_widgets[j]->getID())
					{
						e->_windows[i]->_widgets[j]->OnClick();
					}
						
				}
			}
		}

		return DefWindowProc(hWnd, uMsg, wParam, lParam);
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

