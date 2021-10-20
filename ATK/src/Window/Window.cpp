#include "Window.h"
namespace ATK
{
	Window::Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height)
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

		
		_WindowDescriptor = CreateWindow(CLASS_NAME, name, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, hInstance, nullptr);
		ShowWindow(_WindowDescriptor, SW_SHOW);
	}
}