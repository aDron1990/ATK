#pragma once

#include "pch.h"
#include  "ATK/ATK.h"

#define INITPROC "ADKPluginInitProc"

bool isDll(LPCWSTR name)
{
    std::wstring ws = name;
    if (ws.size() > 3)
    {
        if ((ws[ws.size() - 4] == '.' && ws[ws.size() - 3] == 'd') && (ws[ws.size() - 2] == 'l' && ws[ws.size() - 1] == 'l'))
            return true;
    }
    return false;
}

ATK::PluginInfo* loadPlugin(LPCWSTR dllName)
{
    HMODULE hModule = LoadLibrary(dllName);
    if (hModule)
    {
        if (GetProcAddress(hModule, INITPROC))
        {
            initFP tIFP = (initFP)GetProcAddress(hModule, INITPROC);
            ATK::PluginInfo* pI = new ATK::PluginInfo(hModule, tIFP());
            pI->initialize = tIFP;
            return pI;
        }
    }
    return NULL;
}

std::vector<ATK::PluginInfo*> sortDlls(LPCWSTR pluginsDirPath)
{
    std::vector<ATK::PluginInfo*> result;
    WIN32_FIND_DATA data;  
    HANDLE hFind = FindFirstFile(pluginsDirPath, &data);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (isDll(data.cFileName))
            {
                std::wostringstream _t;
                _t << L".\\Plugins\\" << data.cFileName;
                result.push_back(loadPlugin(_t.str().c_str()));
            }
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }
    return result;
}

std::vector<ATK::PluginInfo*> loadPluginsDir()
{
    std::vector<ATK::PluginInfo*> r;
    WCHAR selfPath[256];
    TCHAR Buffer[MAX_PATH];
    DWORD dwRet;
    GetCurrentDirectory(MAX_PATH, Buffer);
    sortDlls(L".\\Plugins\\*");
    return r;
}