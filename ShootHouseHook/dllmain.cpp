#include "base.h"
#include "hooks.h"
#include "engine.h"

void MainThread()
{
    AllocConsole();
    freopen("CONOUT$", "w", stdout);

    Engine::Initialize();
    Hooks::Initialize();

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{

    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        HANDLE hThread = CreateThread(NULL, 0,
            (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL);

        if (hThread)
            CloseHandle(hThread);
    }

    return TRUE;
}

