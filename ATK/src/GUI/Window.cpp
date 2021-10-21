#include "Window.h"
namespace ATK
{
	extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	Window::Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height) : _hInstance(hInstance), _text(name), _x(CW_USEDEFAULT), _y(CW_USEDEFAULT), _width(width), _height(height)
	{
		EventHandler* e = EventHandler::getInstance();
		e->addWindow(this);
		WNDCLASS wc = {};
		wc.lpfnWndProc = WndProc;
		wc.lpszClassName = CLASS_NAME;
		wc.hInstance = hInstance;

		RegisterClass(&wc);

		_hWnd = CreateWindow(CLASS_NAME, name, WS_OVERLAPPEDWINDOW, _x, _y, width, height, nullptr, nullptr, hInstance, NULL);

		ShowWindow(_hWnd, SW_SHOW);
	}

	HWND Window::getHWND()
	{
		return _hWnd;
	}

	HINSTANCE Window::getInstance()
	{
		return _hInstance;
	}

	void Window::handleCommand(WPARAM wParam, LPARAM lParam)
	{
		for (unsigned i = 0; i < _widgets.size(); i++)
		{
			if (_widgets[i]->getID() == wParam)
			{
				MessageBox(NULL, LPCWSTR(_widgets[i]->getID()), L"Кнопка нажата", MB_OK);
			}
		}
	}

	void Window::addWidget(Widget* widget)
	{
		_widgets.push_back(widget);
		(*widget).attachToWindow(this);
	}
}