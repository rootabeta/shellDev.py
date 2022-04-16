#include <shellDev>

void shellFunc shellEntry(void) { 
	char knl32[] = "kernel32.dll";
	char winex[] = "WinExec";
	PVOID addr = getFuncAddr(getModAddr(knl32), winex);
	func<decltype(&WinExec)> exec((FARPROC)addr);

	char cmd[] = "msg * PWND";
	exec(cmd,0); //TODO: Maybe make this 0 for some extra stealth?
}
