#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

int main(void) {
  BOOLEAN last_debug_status = IsDebuggerPresent();

  printf("%s\n", last_debug_status ? "[-] Debugger present!" : "[+] No debugger present!");

  while (TRUE) {
    if (IsDebuggerPresent() != last_debug_status) {
      last_debug_status = IsDebuggerPresent();
      printf("%s\n", last_debug_status ? "[-] Debugger present!" : "[+] No debugger present!");
    }
  }

  return 0;
}