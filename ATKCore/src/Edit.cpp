#include "../include/ATK/GUI/Widgets/Edit/Edit.h"

namespace ATK
{
	Edit::Edit(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height) : Widget(L"edit", text, x, y, width, height)
	{

	}

	Edit::~Edit()
	{

	}

	void Edit::setOnChange(void (*onChange)(ATK::Widget* widget))
	{
		_onChangeP = onChange;
	}

	void Edit::OnChange()
	{
		if (_onChangeP)
		{
			_onChangeP(this);
		}
	}
}
