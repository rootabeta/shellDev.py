#include <shellDev>

void shellFunc shellEntry(void) {
	PVOID addr;

	char knl32[] = "kernel32.dll";
	char ldLibastr[] = "LoadLibraryA";
	addr = getFuncAddr(getModAddr(knl32), ldLibastr);
	func<decltype(&LoadLibraryA)> loadLibA((FARPROC)addr);

	char usr32[] = "user32.dll";
	char msgboxastr[] = "MessageBoxA";
	addr = getFuncAddr(loadLibA(usr32), msgboxastr);
	func<decltype(&MessageBoxA)> msgbox((FARPROC)addr);

	char msg[] = "Get rekt msfvenom!";
	char title[] = "There's no 0x00 in this shellcode :D";
	msgbox(0, msg, title, 0);
}
