#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winternl.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD_PTR ul_reason_for_call, LPVOID lpReserved) {
  if (ul_reason_for_call == DLL_PROCESS_ATTACH) {  
    // i should probably make this detect whether its attached to a 32bit or 64bit process but i couldnt care less loll
    PPEB pPeb = (PPEB)__readgsqword(0x60);
    pPeb->BeingDebugged = 0;
  }

  return TRUE;
}