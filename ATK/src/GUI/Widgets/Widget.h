#pragma once

#include "../Window.h"

#include <Windows.h>
#include <vector>

namespace ATK
{

	class Widget
	{
		friend class Window;

	protected:
		unsigned _x;
		unsigned _y;
		unsigned _width;
		unsigned _height;
		HWND _hWnd;
		LPCWSTR _type;
		LPCWSTR _text;

		void attachToWindow(Window* window);

		Widget(LPCWSTR type, LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height);

	public:
		virtual ~Widget();

		void setText(const LPCWSTR text);
		void setSize(const std::vector<unsigned> size);
		void setPosition(const std::vector<unsigned> pos);

		LPCWSTR getText();
		std::vector<unsigned> getSize();
		std::vector<unsigned> getPosition();
	};
}

