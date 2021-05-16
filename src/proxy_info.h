#pragma once
#include "dllincludes.h"
#include "io.h"

enum class LEGameVersion
{
    LE1 = 1,
    LE2 = 2,
    LE3 = 3,
    Unsupported = 4
};

struct AppProxyInfo
{
public:
    wchar_t ExePath[MAX_PATH];
    wchar_t ExeName[MAX_PATH];
    wchar_t WinTitle[MAX_PATH];

    bool DRMCompletedWait = false;
    LEGameVersion Game;

private:
    void StripPathFromFileName(wchar_t* path, wchar_t* newPath)
    {
        auto selectionStart = path;
        while (*path != L'\0')
        {
            if (*path == L'\\')
            {
                //IO::GLogger.writeFormatLine(L"   %s", path);
                selectionStart = path;
            }
            path++;
        }

        wcscpy(newPath, selectionStart + 1);
    }

    void AssociateWindowTitle(wchar_t* exeName, wchar_t* winTitle)
    {
        if (0 == wcscmp(exeName, LE1_ExecutableName))
        {
            wcscpy(winTitle, LE1_WindowTitle);
            Game = LEGameVersion::LE1;
        }
        else if (0 == wcscmp(exeName, LE2_ExecutableName))
        {
            wcscpy(winTitle, LE2_WindowTitle);
            Game = LEGameVersion::LE2;
        }
        else if (0 == wcscmp(exeName, LE3_ExecutableName))
        {
            wcscpy(winTitle, LE3_WindowTitle);
            Game = LEGameVersion::LE3;
        }
        else
        {
            GLogger.writeFormatLine(L"WaitForDenuvo: UNSUPPORTED EXE NAME %s", exeName);
            Game = LEGameVersion::Unsupported;
            exit(-1);
        }
    }

public:
    void Initialize()
    {
        GetModuleFileNameW(NULL, ExePath, MAX_PATH);
        StripPathFromFileName(ExePath, ExeName);
        AssociateWindowTitle(ExeName, WinTitle);
    }
};

// Global instance for easier access.
AppProxyInfo GAppProxyInfo;