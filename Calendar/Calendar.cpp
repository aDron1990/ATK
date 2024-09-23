#define ATK_PLUGIN

#include "ATK/ATK.h"

class Calendar : public ATK::Plugin
{
    ATK::Window* window;

public:

    Calendar(ATK::Application* app) : Plugin(app)
    {
        window = new ATK::Window(GetModuleHandle(0), L"Календарь", 400, 200);
        addWindow(window);
    }
    ~Calendar()
    {

    }
};

void initPlugin(ATK::Application* app)
{
    new Calendar(app);
}