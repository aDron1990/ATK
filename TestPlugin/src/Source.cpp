#include <Windows.h>

#include "ATK/ATK.h"

ATK::Plugin* GetPlugin(ATK::Application* app);

BOOL WINAPI DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
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



class TestPlugin : ATK::Plugin
{
public:
    TestPlugin(ATK::Application* app) : Plugin(app)
    {
        ATK::Window* window = new ATK::Window(app->getInstance(), L"TestPlugin Window", 300, 400);
        addWindow(window);
    }
    ~TestPlugin()
    {

    }
};

ATK::Plugin* GetPlugin(ATK::Application* app)
{
    return new TestPlugin(app);
}