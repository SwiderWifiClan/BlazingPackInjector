// Injekta.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <Windows.h>
#include <iostream>
#include <string>
#include <TlHelp32.h>
#include <filesystem>

void injektowanieLOL() {
    DWORD procId;
    HANDLE handle = 0;
    const char* dllPath = "Swider.dll";
    HWND hwnd = FindWindowA(("AAAA"),0);
    SetWindowText(hwnd, L"Minecraft 1.8.8 (BlazenPack.pl) [ver. 185]");
    char dllkafixed[MAX_PATH];
    GetFullPathNameA(dllPath, MAX_PATH, dllkafixed, NULL);
    // Sprawdzanie czy wszystko fajnie smiga
    std::cout << "HWND  - ";
    std::cout << hwnd;

    GetWindowThreadProcessId(hwnd, &procId);
    std::cout << "\nProc ID  - ";
    std::cout << procId;
    handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
    std::cout << "\nHandle  - ";
    std::cout << handle;
    if (handle && handle != INVALID_HANDLE_VALUE)
    {
        void* loc = VirtualAllocEx(handle, 0, MAX_PATH, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        std::cout << "\nLOC - ";
        std::cout << loc;
        std::cout << "\nInjectowanie\n";
        WriteProcessMemory(handle, loc, dllkafixed, strlen(dllkafixed) + 1, 0);

        HANDLE hThread = CreateRemoteThread(handle, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, loc, 0, 0);
        std::cout << "hThread - ";
        std::cout << hThread << std::endl;
        if(hThread){
            system("cls");
            std::cout << "Giga Chad Dziala";
        CloseHandle(hThread);
        }
    }

    if (handle)
    {
       std::cout << "\nClosing Handle" << std::endl;
       CloseHandle(handle);
    }
    system("\npause");
}
int main()
{
    SetConsoleTitleA("BlazingInject Made By Swider");
    std::cout << "Hello World!\n";
    injektowanieLOL();

}

