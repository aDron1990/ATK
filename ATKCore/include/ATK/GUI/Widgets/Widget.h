#pragma once

#include "../../pch.h"

typedef unsigned(*GetIdProc)();

namespace ATK
{
	class Window;
	class Widget
	{
	protected:
		friend class Window;

		unsigned _ID;
		unsigned _x;
		unsigned _y;
		unsigned _width;
		unsigned _height;

		HWND _hWnd;
		LPCWSTR _type;
		LPCWSTR _text;

		void updateSizePos();

		Widget(LPCWSTR type, LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height);

	public:
		
		static GetIdProc GenerateId;
//		HWND _hWnd;
		virtual ~Widget();

		void setText(const LPCWSTR text);
		void setSize(const std::vector<unsigned> size);
		void setPosition(const std::vector<unsigned> pos);
		void setPosition(unsigned x, unsigned y);

		unsigned getID();
		HWND getHWnd();
		LPCWSTR getText();
		std::vector<unsigned> getSize();
		std::vector<unsigned> getPosition();
	};
}

