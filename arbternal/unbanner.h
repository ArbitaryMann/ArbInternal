#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <thread>
#include <map>
#include <chrono>
#include <memory>

using namespace std;

HANDLE hProc;
void gen_random(char *s, const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}

void macunban() {
	static char mac[20] = "123";
	DWORD oldProtect = 0;
						DWORD OLDPROTECT;
						int oldprot = 0;
						LPVOID entrys = (LPVOID)((uintptr_t)GetModuleHandle(NULL) + 0x462C5C);
						HANDLE as = GetCurrentProcess();
						VirtualProtectEx(as, entrys, sizeof(mac), PAGE_EXECUTE_READWRITE, &OLDPROTECT);
						memcpy(entrys, mac, sizeof(mac));

}
void ridunban() {
	static char rid[20] = "123";
	DWORD oldProtect = 0;
						DWORD OLDPROTECT;
						int oldprot = 0;
						LPVOID entrys = (LPVOID)((uintptr_t)GetModuleHandle(NULL) + 0x462C28);
						HANDLE as = GetCurrentProcess();
						VirtualProtectEx(as, entrys, sizeof(rid), PAGE_EXECUTE_READWRITE, &OLDPROTECT);
						memcpy(entrys, rid, sizeof(rid));
}