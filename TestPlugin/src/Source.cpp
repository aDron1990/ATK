#include <Windows.h>

#include "ATK/ATK.h"

void Wnd(HMODULE hModule);

BOOL WINAPI DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
 //       MessageBox(NULL, L"TestPlugin PROCESS_ATTACH", L"Plugin message", MB_OK);
        Wnd(hModule);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

void Wnd(HMODULE hModule)
{
    ATK::Window* w = new ATK::Window(hModule, L"TestPluginWnw", 200, 200);
}