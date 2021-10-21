#include "Window.h"
namespace ATK
{
	extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	Window::Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height) : Widget(L"ATKWindow", name, CW_USEDEFAULT, CW_USEDEFAULT, width, height), _hInstance(hInstance)
	{
		EventHandler* e = EventHandler::getInstance();
		e->addWindow(this);
		WNDCLASS wc = {};
		wc.lpfnWndProc = WndProc;
		wc.lpszClassName = CLASS_NAME;
		wc.hInstance = hInstance;

		RegisterClass(&wc);

		_hWnd = CreateWindow(CLASS_NAME, _text, WS_OVERLAPPEDWINDOW, _x, _y, _width, _height, nullptr, nullptr, _hInstance, NULL);

		ShowWindow(_hWnd, SW_SHOW);
	}

	Window::~Window()
	{

	}

	HINSTANCE Window::getInstance()
	{
		return _hInstance;
	}

	void Window::addWidget(Widget* widget)
	{
		_widgets.push_back(widget);
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