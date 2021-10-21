#pragma once

#include "../Widget.h"

#include <Windows.h>

namespace ATK
{

	class Button : public Widget
	{

	public:
		Button(LPCWSTR text, unsigned x, unsigned y, unsigned width, unsigned height);
		~Button();

		
	};
}
