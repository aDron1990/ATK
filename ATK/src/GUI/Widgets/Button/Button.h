#pragma once

#include "../Widget.h"

#include <Windows.h>

namespace ATK
{

	class Button : public Widget
	{
		void (*_onClickP)(ATK::Widget* widget) = NULL;
	public:
		Button(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height);
		~Button();

		void setOnClick(void (*onClick)(ATK::Widget* widget));
		void OnClick();
	};
}
