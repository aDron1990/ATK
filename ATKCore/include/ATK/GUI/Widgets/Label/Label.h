#pragma once

#include "../../../pch.h"

#include "../Widget.h"

namespace ATK
{
	class Label : public Widget
	{
	public:
		Label(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height);
		~Label();
	};
}
