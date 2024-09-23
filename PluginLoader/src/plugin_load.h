#pragma once

#include "pch.h"
#include  "ATK/ATK.h"

#define INITPROC "initPlugin"

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

void loadPlugin(LPCWSTR dllName, ATK::Application* app)
{
    HMODULE hModule = LoadLibrary(dllName);
    if (hModule)
    {
        if (GetProcAddress(hModule, INITPROC))
        {
            initFP tIFP = (initFP)GetProcAddress(hModule, INITPROC);
            tIFP(app);
        }
    }
}

void sortDlls(LPCWSTR pluginsDirPath, ATK::Application* app)
{
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
                loadPlugin(_t.str().c_str(), app);
            }
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }
}

void loadPluginsDir(ATK::Application* app)
{
    WCHAR selfPath[256];
    TCHAR Buffer[MAX_PATH];
    DWORD dwRet;
    GetCurrentDirectory(MAX_PATH, Buffer);
    sortDlls(L".\\Plugins\\*", app);
}