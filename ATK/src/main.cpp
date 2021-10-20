#include "Window/Window.h"

#include <Windows.h>
#include <iostream>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
/*	const wchar_t CLASS_NAME[] = L"ADKWindow";

	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, L"WndClass redistration failed!", L"Error", MB_OK);
		return 1;
	}

	HWND hWnd = CreateWindow(CLASS_NAME, L"Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, nullptr, nullptr, hInstance, nullptr);
	ShowWindow(hWnd, SW_SHOW);
*/

	ATK::Window window(hInstance, L"Wind", 1280, 720);
	ATK::Window window2(hInstance, L"Wind2", 1280, 720);
	
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return EXIT_SUCCESS;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HINSTANCE hInstance;
	static HWND bt_exit;
	static HWND bt_2;
	switch (uMsg)
	{
	case WM_CREATE:
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;

		bt_exit = CreateWindow(L"button", L"Exit", WS_VISIBLE | WS_CHILD | WS_BORDER, 0, 0, 100, 30, hWnd, nullptr, hInstance, nullptr);
		bt_2 = CreateWindow(L"button", L"2", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 0, 100, 30, hWnd, nullptr, hInstance, nullptr);

	case WM_COMMAND:
		if (lParam == (LPARAM)bt_exit)
		{
			PostQuitMessage(0);
		}
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			PostQuitMessage(0);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}