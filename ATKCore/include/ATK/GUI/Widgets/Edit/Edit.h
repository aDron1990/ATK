#pragma once

#include "../../../pch.h"

#include "../Widget.h"

namespace ATK
{
	class Edit : public Widget
	{
		void (*_onChangeP)(ATK::Widget* widget) = NULL;

	public:
		Edit(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height);
		~Edit();

		void setOnChange(void (*onChange)(ATK::Widget* widget));
		void OnChange();
	};
}
