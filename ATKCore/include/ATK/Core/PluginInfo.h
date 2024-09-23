#pragma once

#include "../pch.h"

#include "../GUI/Window.h"

typedef ATK::Window* (__stdcall* initFP)();

namespace ATK
{
	class PluginInfo
	{
		static unsigned nextId;
		unsigned id;
	public:
		initFP initialize;
		__stdcall PluginInfo(HMODULE hModule_, Window* window_);
		__stdcall PluginInfo(PluginInfo&&) = delete;
		HMODULE hModule;
		Window* window;
		unsigned getId();
	};
}

namespace ATK
{
	initFP initialize = NULL;
	unsigned PluginInfo::nextId = 0;

	__stdcall PluginInfo::PluginInfo(HMODULE hModule_, Window* window_) : hModule(hModule_), window(window_)
	{
		id = nextId;
		nextId++;
	}

	unsigned PluginInfo::getId()
	{
		return id;
	}
}