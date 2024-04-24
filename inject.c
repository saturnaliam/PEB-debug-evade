// this is a standard boring dll injector modified to work better with plain c rather than c++
// you can find a billion other ones that look identical to this but i used this as reference https://github.com/GameHackingAcademy/DLL_Injector/

#include <windows.h>
#include <tlhelp32.h>

const char* PATH = "E:\\dev\\debug-evade\\patch.dll";

int main(int argc, char** argv) {
  HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, TRUE, atoi(argv[1]));

  void* base_address = VirtualAllocEx(process, NULL, strlen(PATH) + 1, MEM_COMMIT, PAGE_READWRITE);

  WriteProcessMemory(process, base_address, PATH, strlen(PATH) + 1, NULL);

  HMODULE kernel32base = GetModuleHandle("kernel32.dll");
  HANDLE thread = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(kernel32base, "LoadLibraryA"), base_address, 0, NULL);

  WaitForSingleObject(thread, INFINITE);

  VirtualFreeEx(process, base_address, 0, MEM_RELEASE);
  CloseHandle(thread);
  CloseHandle(process);

	return 0;
}