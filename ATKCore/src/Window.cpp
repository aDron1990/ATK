#include "../include/ATK/GUI/Window.h"

namespace ATK
{
	extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	Window::Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height) : Widget(L"ATKWindow", name, CW_USEDEFAULT, CW_USEDEFAULT, width, height), _hInstance(hInstance)
	{
		EventHandler* e = EventHandler::getInstance();
		
		WNDCLASS wc = {};
		wc.lpfnWndProc = WndProc;
		wc.lpszClassName = CLASS_NAME;
		wc.hInstance = hInstance;

		RegisterClass(&wc);

		_hWnd = CreateWindow(CLASS_NAME, _text, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, _x, _y, _width, _height, nullptr, nullptr, _hInstance, NULL);
		e->_windows.push_back(this);

		ShowWindow(_hWnd, SW_SHOW);
	}

	Window::~Window()
	{
		for (int i = 0; i < _widgets.size(); i++)
		{
			delete _widgets[i];
		}
	}

	HINSTANCE Window::getInstance()
	{
		return _hInstance;
	}

	void Window::switchState()
	{
		if (_state == SW_SHOW)
		{
			_state = SW_HIDE;
		}
		else
		{
			_state = SW_SHOW;
		}
		ShowWindow(_hWnd, _state);
	}

	void Window::setState(unsigned state)
	{
		_state = state;
		ShowWindow(_hWnd, _state);
	}

	unsigned Window::getState()
	{
		return _state;
	}

	void Window::addWidget(Widget* widget)
	{
		_widgets.push_back(widget);
		if (dynamic_cast<Label*>(widget))
		{
			widget->_hWnd = CreateWindow(widget->_type, widget->_text, WS_VISIBLE | WS_CHILD, widget->_x, widget->_y, widget->_width, widget->_height, getHWnd(), (HMENU)widget->getID(), getInstance(), NULL);
			return;
		}
		widget->_hWnd = CreateWindow(widget->_type, widget->_text, WS_VISIBLE | WS_CHILD | WS_BORDER, widget->_x, widget->_y, widget->_width, widget->_height, getHWnd(), (HMENU)widget->getID(), getInstance(), NULL);
	}

	void Window::reDraw()
	{
		PAINTSTRUCT ps;
		HDC hDc = BeginPaint(_hWnd, &ps);
		FillRect(hDc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(_hWnd, &ps);
	}
}