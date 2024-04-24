#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winternl.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD_PTR ul_reason_for_call, LPVOID lpReserved) {
  if (ul_reason_for_call == DLL_PROCESS_ATTACH) {  
    #if defined (_WIN64)
    #define PEB_OFFSET 0x60
    #else
    #define PEB_OFFSET 0x30
    #endif

    PPEB pPeb = (PPEB)__readgsqword(PEB_OFFSET);
    pPeb->BeingDebugged = 1;
  }

  return TRUE;
}