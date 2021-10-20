#pragma once

#include <Windows.h>
#include <string>

#define CLASS_NAME L"ATKWindow"

namespace ATK
{
	class Window
	{
		HWND _WindowDescriptor;
	public:
		Window(HINSTANCE hInstance, LPCWSTR name, unsigned width, unsigned height);
//		~Window();
	};
}

