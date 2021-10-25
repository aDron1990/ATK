#include "pch.h"

#include "plugin_load.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MessageBox(NULL, L"TestPlugin PROCESS_ATTACH", L"Plugin message", MB_OK);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

std::vector<ATK::PluginInfo> LoadPlugins()
{
    loadPluginsDir();
    std::vector<ATK::PluginInfo> r;
    return r;
}