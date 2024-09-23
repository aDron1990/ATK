#include "Core/EventHandler.h"
#include "Core/PluginInfo.h"
#include "Core/Application.h"
#include "Core/EntryPoint.h"

#include "GUI/Window.h"
#include "GUI/Widgets.h"

#include "atkTools.h"

#define LOAD "LoadPlugins"

typedef std::vector<ATK::PluginInfo>(*LoadPluginsFuncP)();