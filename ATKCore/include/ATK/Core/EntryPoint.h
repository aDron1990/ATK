#pragma once

#include "../pch.h"
#include "Application.h"

extern ATK::Application* ATK::GetApp(HINSTANCE hInstance);

#ifdef ATK_PLUGIN

BOOL WINAPI DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    HMODULE idGenerator = LoadLibrary(L"idGenerator.dll");
    ATK::Widget::GenerateId = (GetIdProc)GetProcAddress(idGenerator, "getId");
    switch (ul_reason_for_call)
    {

    case DLL_PROCESS_ATTACH:
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#endif