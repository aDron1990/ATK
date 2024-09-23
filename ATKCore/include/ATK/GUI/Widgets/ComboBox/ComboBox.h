#pragma once

#include "../../../pch.h"

#include "../Widget.h"

namespace ATK
{

	class ComboBox : public Widget
	{
		void (*_onSelect)(ATK::Widget* widget) = NULL;
		TCHAR _selected[256];
		unsigned _selectedId = 0;

	public:

		ComboBox(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height);
		~ComboBox();

		void setOnSelect(void(*onSelect)(ATK::Widget* widget));

		void OnSelect();

		void addString(LPCWSTR string);
//		void clear();
	};

}