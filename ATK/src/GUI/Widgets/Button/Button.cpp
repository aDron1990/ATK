#include "Button.h"

namespace ATK
{
	Button::Button(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height) : Widget(L"button", text,  x, y, width, height)
	{

	}
	Button::~Button()
	{

	}
}