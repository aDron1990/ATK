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

	void EventHandler::pollEvents()
	{

	}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		EventHandler *e = EventHandler::getInstance();
		switch (uMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_COMMAND:
//			MessageBox(NULL, L"1", L"Нажата кнопка", MB_OK);
			for (int i = 0; i < e->_windows.size(); i++)
			{
				for (int j = 0; j < e->_windows[i]->_widgets.size(); j++)
				{
					if (wParam == e->_windows[i]->_widgets[j]->getID())
					{
						wchar_t buffer[256];
						wsprintfW(buffer, L"%d", e->_windows[i]->_widgets[j]->getID());
						MessageBox(NULL, buffer, L"Нажата кнопка", MB_OK);
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

