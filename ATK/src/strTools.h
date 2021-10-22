#pragma once

#include <Windows.h>
#include <string>
#include <sstream>
#include <tchar.h>

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

const wchar_t* FloatToStr(float value)
{
	std::wostringstream wss;
	wss << value;
	std::wstring ws = wss.str();
	wchar_t* result = _wcsdup(ws.c_str());
	return result;
}

float StrToFloat(LPCWSTR value)
{
	return wcstold(value, NULL);
}