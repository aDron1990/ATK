#include "Label.h"

namespace ATK
{
	Label::Label(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height) : Widget(L"static", text, x, y, width, height)
	{

	}

	Label::~Label()
	{

	}
}