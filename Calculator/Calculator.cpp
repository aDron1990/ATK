#define ATK_PLUGIN

#include <Windows.h>

#include "ATK/ATK.h"

void add(ATK::Widget* widget);
void sub(ATK::Widget* widget);
void mult(ATK::Widget* widget);
void div(ATK::Widget* widget);
void clear(ATK::Widget* widget);

ATK::Window* window;

ATK::Button* plus;
ATK::Button* minus;
ATK::Button* multiple;
ATK::Button* divide;
ATK::Button* clear_bt;

ATK::Edit* input1;
ATK::Edit* input2;
ATK::Edit* output;

class Calculator : public ATK::Plugin
{
public:

    Calculator(ATK::Application* app) : Plugin(app)
    {
        window = new ATK::Window(GetModuleHandle(0), L"Калькулятор", 310, 500);
        
        input1 = new ATK::Edit(NULL, 50, 100, 200, 30);
        input2 = new ATK::Edit(NULL, 50, 150, 200, 30);
        output = new ATK::Edit(NULL, 50, 300, 200, 30);

        plus     = new ATK::Button(L"+", 50, 200, 75, 30);
        minus    = new ATK::Button(L"-", 50, 250, 75, 30);
        multiple = new ATK::Button(L"*", 175, 200, 75, 30);
        divide   = new ATK::Button(L"/", 175, 250, 75, 30);
        clear_bt = new ATK::Button(L"C", 150, 350, 100, 30);

        plus->setOnClick(add);
        minus->setOnClick(sub);
        multiple->setOnClick(mult);
        divide->setOnClick(div);
        clear_bt->setOnClick(clear);

        addWindow(window);

        window->addWidget(input1);
        window->addWidget(input2);
        window->addWidget(output);

        window->addWidget(plus);
        window->addWidget(minus);
        window->addWidget(multiple);
        window->addWidget(divide);
        window->addWidget(clear_bt);
    }

    ~Calculator()
    {

    }
};

void initPlugin(ATK::Application* app)
{
    new Calculator(app);
}

void add(ATK::Widget* widget)
{
    float a, b, result;
    a = StrToFloat(input1->getText());
    b = StrToFloat(input2->getText());
    result = a + b;
    output->setText(FloatToStr(result));
}

void sub(ATK::Widget* widget)
{
    float a, b, result;
    a = StrToFloat(input1->getText());
    b = StrToFloat(input2->getText());
    result = a - b;
    output->setText(FloatToStr(result));
}

void mult(ATK::Widget* widget)
{
    float a, b, result;
    a = StrToFloat(input1->getText());
    b = StrToFloat(input2->getText());
    result = a * b;
    output->setText(FloatToStr(result));
}

void div(ATK::Widget* widget)
{
    float a, b, result;
    a = StrToFloat(input1->getText());
    b = StrToFloat(input2->getText());
    result = a / b;
    output->setText(FloatToStr(result));
}

void clear(ATK::Widget* widget)
{
    input1->setText(NULL);
    input2->setText(NULL);
    output->setText(NULL);
}