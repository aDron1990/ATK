#pragma once

#include "pch.h"

int StrToInt(const wchar_t* value)
{
	return wcstol(value, 0, 10);
}

const wchar_t* IntToStr(int value)
{
	std::wostringstream wss;
	wss << value;
	std::wstring ws = wss.str();
	wchar_t* result = _wcsdup(ws.c_str());
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