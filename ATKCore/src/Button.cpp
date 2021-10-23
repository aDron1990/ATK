#include "../include/ATK/GUI/Widgets/Button/Button.h"

namespace ATK
{
	Button::Button(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height) : Widget(L"button", text,  x, y, width, height)
	{

	}
	Button::~Button()
	{

	}

	void Button::setOnClick(void (*onClick)(ATK::Widget* widget))
	{
		_onClickP = onClick;
	}

	void Button::OnClick()
	{
		if (_onClickP)
		{
			_onClickP(this);
		}
	}
}