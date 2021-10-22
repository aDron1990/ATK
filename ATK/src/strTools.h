#pragma once

#include <Windows.h>

int StrToInt(const wchar_t* value)
{
	return wcstol(value, 0, 10);
}

const wchar_t* IntToStr(int value)
{
	wchar_t result[1024];
	wsprintf(result, L"%d", value);
	return result;
}