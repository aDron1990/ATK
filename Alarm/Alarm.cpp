#define ATK_PLUGIN

#include <Windows.h>
#include <thread>

#include "ATK.h"

void OnClick(ATK::Widget* widget);

ATK::Window* window;

ATK::Edit* input1;
ATK::Edit* input2;

ATK::Button* btn;

class Alarm : public ATK::Plugin
{
public:
    Alarm(ATK::Application* app) : Plugin(app)
    {
        window = new ATK::Window(GetModuleHandle(0), L"Будильник", 360, 300);

        input1 = new ATK::Edit(L"0", 50, 50, 100, 30);
        input2 = new ATK::Edit(L"0", 200, 50, 100, 30);
        btn = new ATK::Button(L"Поставить будильник", 50, 200, 250, 30);

        btn->setOnClick(OnClick);

        addWindow(window);

        window->addWidget(btn);
        window->addWidget(input1);
        window->addWidget(input2);
    }
    ~Alarm()
    {

    }
};

void initPlugin(ATK::Application* app)
{
    new Alarm(app);
}

void setAlarm(int hour, int minute)
{
    SYSTEMTIME st;
    while (true)
    {
        GetLocalTime(&st);
        if (st.wHour == hour && st.wMinute == minute)
        {
            BOOL e = PlaySound(TEXT("Sounds/alarm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            if (MessageBox(NULL, L"", L"Будильник", MB_OK)) PlaySound(NULL, NULL, SND_NODEFAULT);
            break;
        }
        Sleep(5000);
    }
}

void OnClick(ATK::Widget* widget)
{
    int hour = StrToInt(input1->getText());
    int minute = StrToInt(input2->getText());
    wchar_t buff[256];
    wsprintf(buff, _T("Поставлен будильник на %d:%02d"), hour, minute);
    MessageBox(NULL, buff, L"Увeдомление", MB_OK);

    std::thread th(setAlarm, hour, minute);
    th.detach();
}