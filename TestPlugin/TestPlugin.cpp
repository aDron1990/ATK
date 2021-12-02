#define ATK_PLUGIN

#include <Windows.h>

#include "ATK/ATK.h"

void OnClick(ATK::Widget* widget);

class Test : public ATK::Plugin
{
    ATK::Window* wnd;
    ATK::Button* bt;

public:

    Test(ATK::Application* app) : Plugin(app)
    {
        wnd = new ATK::Window(GetModuleHandle(0), L"test", 300, 150);
        addWindow(wnd);

        bt = new ATK::Button(L"Test", 0, 0, 50, 50);
        bt->setOnClick(OnClick);
        wnd->addWidget(bt);
    }
    ~Test()
    {

    }
};

void initPlugin(ATK::Application * app)
{
    new Test(app);
}

void OnClick(ATK::Widget* widget)
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    wchar_t buff[512];
    wsprintf(buff, _T("%d:%02d"), st.wHour, st.wMinute);
    MessageBox(NULL, buff, L"Test", MB_OK);
}