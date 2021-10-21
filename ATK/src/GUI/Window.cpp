#include "Window.h"
namespace ATK
{
	Window::Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height) : _hInstance(hInstance)
	{
		WNDCLASS wc = {};
		wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT
		{
			switch (uMsg)
			{
			case WM_DESTROY:
				PostQuitMessage(0);
			}
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		};
		wc.lpszClassName = CLASS_NAME;
		wc.hInstance = hInstance;

		if (!RegisterClass(&wc))
		{
			MessageBox(NULL, L"WndClass redistration failed!", L"Error", MB_OK);
		}

		_hWnd = CreateWindow(CLASS_NAME, name, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, hInstance, NULL);

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

	void Window::addWidget(Widget* widget)
	{
		_widgets.push_back(widget);
		(*widget).attachToWindow(this);
	}
}