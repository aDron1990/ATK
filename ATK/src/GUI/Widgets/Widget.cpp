#include "Widget.h"

namespace ATK
{
	Widget::Widget(LPCWSTR type, LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height) : _type(type), _text(text), _x(x), _y(y), _width(width), _height(height)
	{

	}

	Widget::~Widget() {}

	void Widget::attachToWindow(Window* window)
	{
		_hWnd = CreateWindow(_type, _text, WS_VISIBLE | WS_CHILD | WS_BORDER, _x, _y, _width, _height, (*window).getHWND(), nullptr, (*window).getInstance(), NULL);
	}

	void Widget::setText(const LPCWSTR text)
	{
		_text = text;
	}

	void Widget::setSize(const std::vector<unsigned> size)
	{
		_x = size[0];
		_y = size[1];
	}

	void Widget::setPosition(const std::vector<unsigned> pos)
	{
		_width = pos[0];
		_height = pos[1];
	}

	LPCWSTR Widget::getText()
	{
		LPCWSTR text(_text);
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
