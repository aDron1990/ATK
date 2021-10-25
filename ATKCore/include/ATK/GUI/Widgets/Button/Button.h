#pragma once

#include "../../../pch.h"

#include "../Widget.h"

namespace ATK
{

	class Button : public Widget
	{
		void (*_onClickP)(ATK::Widget*) = NULL;
	public:
		Button(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height);
		~Button();

		void setOnClick(void (*onClick)(ATK::Widget* widget));
		void OnClick();
	};
}
