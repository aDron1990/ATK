#pragma once

#include "../pch.h"
#include "Application.h"

extern ATK::Application* ATK::GetApp(HINSTANCE hInstance);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	
	auto app = ATK::GetApp(hInstance);
//	delete app;
	app->run();
	return EXIT_SUCCESS;
}