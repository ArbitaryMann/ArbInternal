#include "Hooks.h"
#include "includes.h"
using namespace std;

DWORD rainbow() {

	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;

	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	}
	else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	}
	else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	}
	else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	}
	else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	}
	else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}

	x += 0.25f; //increase this value to switch colors faster
	if (x >= 255.0f)
		x = 0.0f;

	y += 0.25f; //increase this value to switch colors faster
	if (y > 1530.0f)
		y = 0.0f;


	return D3DXCOLOR((int)r, (int)g, (int)b, 255);
}



void createHookMH(uint32_t hookwhere,int comm) {
	MH_QueueEnableHook((LPVOID)hookwhere);
	MH_CreateHook((LPVOID)hookwhere, &comm, NULL);
	MH_EnableHook((LPVOID)hookwhere);
}
void deactivateHook(uint32_t hookwhere) {
	MH_QueueDisableHook((LPVOID)hookwhere);

	MH_DisableHook((LPVOID)hookwhere);
}
