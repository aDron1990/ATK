#include "../include/ATK/GUI/Widgets/Widget.h"

namespace ATK
{
	Widget::Widget(LPCWSTR type, LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height) : _type(type), _text(text), _x(x), _y(y), _width(width), _height(height)
	{
		static unsigned _widgetsCount = 0;
		_ID = _widgetsCount;
		_widgetsCount++;
	}

	Widget::~Widget() {}

	void Widget::updateSizePos()
	{
		SetWindowPos(_hWnd, NULL, _x, _y, _width, _height, NULL);
	}

	void Widget::setText(const LPCWSTR text)
	{
		_text = text;
		SendMessage(_hWnd, WM_SETTEXT, 0, (LPARAM)_text);
	}

	void Widget::setSize(const std::vector<unsigned> size)
	{
		_width = size[0];
		_height = size[1];
		updateSizePos();
	}

	void Widget::setPosition(const std::vector<unsigned> pos)
	{
		_x = pos[0];
		_y = pos[1];
		updateSizePos();
	}

	void Widget::setPosition(unsigned x, unsigned y)
	{
		_x = x;
		_y = y;
		updateSizePos();
	}

	unsigned Widget::getID()
	{
		return _ID;
	}

	HWND Widget::getHWnd()
	{
		return _hWnd;
	}

	LPCWSTR Widget::getText()
	{
		int len = GetWindowTextLength(_hWnd) + 1;
		TCHAR* text = new TCHAR[len];
		len = GetWindowText(_hWnd, text, len);
		_text = text;
		return text;
	}

	std::vector<unsigned> Widget::getSize()
	{
		std::vector<unsigned> size{ _width, _height };
		return size;
	}

	std::vector<unsigned> Widget::getPosition()
	{
		std::vector<unsigned> position{ _x, _y };
		return position;
	}
}
