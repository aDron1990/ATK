#include "../include/ATK/GUI/Widgets/ComboBox/ComboBox.h"

namespace ATK
{
	ComboBox::ComboBox(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height) : Widget(L"combobox", text, x, y, width, height)
	{

	}

	ComboBox::~ComboBox()
	{

	}

	void ComboBox::setOnSelect(void(*onSelect)(ATK::Widget* widget))
	{
		_onSelect = onSelect;
	}

	void ComboBox::OnSelect()
	{
		_selectedId = SendMessage(_hWnd, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
		SendMessage(_hWnd, (UINT)CB_GETLBTEXT, (WPARAM)_selectedId, (LPARAM)_selected);
		setText(_selected);
		MessageBox(NULL, (LPCWSTR)_selected, TEXT("Item Selected"), MB_OK);
		if (_onSelect) _onSelect(this);
	}

	void ComboBox::addString(LPCWSTR string)
	{
		TCHAR buff[256];

		wcscpy_s(buff, sizeof(buff) / sizeof(TCHAR), (TCHAR*)string);

		SendMessage(_hWnd, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)buff);
	}
}
