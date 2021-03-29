#include "includes.h"
#include "phook.h"
#include "unbanner.h"
#include "proton/rtparam.hpp"
#include "proton/hash.hpp"
#include "proton/variant.hpp"
#include "proton/vector.hpp"

#include <fstream>
#include "Hooks.h"
#include <random>
#include "i_offsets.h"
#include "Style.h"


/*/
	THIS IS MADE BY ARBITARYMANN ALSO THIS PROJECT IS FULLY BASED ON MINHOOK LIBRARY
	OUR PROJECT IS SHIPPED WITH GNU LICENSE COVERING OUR RIGHTS ON THE PROJECT
	SO PREFERING YOU TO GIVE ME CREDIT IF YOU ARE GOING TO SHIP THIS INTERNAL SOFT
	HAVE FUN USING IT THANKS FOR DOWNLOADING TRUSTED SOURCES - UNKNOWNCHEATS/GITHUB
/*/


HWND window;
void* pDevice[119];
PTR EndSceneAddress;
EndScene oEndScene;
WNDPROC oWndProc;

using namespace std;
#pragma warning (disable : 4996)
typedef void(__fastcall* _enetPacket)(int type, string packet_content, uint64_t peer);
_enetPacket enetPacket;
typedef void(__fastcall* _SendRawPackets)(int a1, void* a2, int sz, void* a4, int a5,int a6);
_SendRawPackets SendRawPacketReliable;
typedef void(__fastcall* _OnFunc)(int type, variantlist_t packet_content, uint64_t peer);
_OnFunc OnFunc;
typedef void(__cdecl* _OnConsoleMessage)(const char* msg, INT64 idk, INT64 idk2);
_OnConsoleMessage SendConsoleMessage;

typedef INT64(__fastcall* __System)(const char* v1);
__System LOG;


uintptr_t ltchook;
uintptr_t sendpacker_newfunc;
uintptr_t sendraw_newfunc;





struct GameLogicComponent {

};

typedef uint64_t(__fastcall* GTApplication)();
GTApplication GTApp;








HANDLE gthandle; 


int enet_raw_packet(int a1, void* a2, int sz, void* a4, uint64_t a5, int a6) {
	createHookMH(sendraw_newfunc, enet_raw_packet(a1, a2, sz, a4, a5, a6));

	byte* a2data = (byte*)a2;

	if (a2data[0] == 25) {
		SendConsoleMessage("this might get you banned lmao retarded shit ass", 0, 0);
	}
	SendRawPacketReliable(a1, a2, sz, a4, a5, a6);

	deactivateHook(sendraw_newfunc);
	return 1337;
}
int setupHooks() {
	base = (uintptr_t)GetModuleHandle(NULL);
	gthandle = GetCurrentProcess();
	DWORD aa;

	VirtualProtectEx(gthandle, (LPVOID)(base + 0x2EDD53), 2, PAGE_EXECUTE_READWRITE, &aa);
	VirtualProtectEx(gthandle, (LPVOID)(base + 0xE398A), 6, PAGE_EXECUTE_READWRITE, &aa);
	memset((PVOID)(base + 0x2EDD53), 0x74, 1);
	SendConsoleMessage = (_OnConsoleMessage)(base + log_msg);
	LOG = (__System)(base + log_msg);
	sendpacker_newfunc = (base + packet_handle);
	sendraw_newfunc = (base + send_packet_raw);
	MH_CreateHook(&(PVOID&)sendpacker_newfunc, &enet_send_packet, 0);
	MH_CreateHook(&(PVOID&)sendraw_newfunc, &enet_raw_packet, 0);
	OnFunc = (_OnFunc)(base + packet_handle);
	enetPacket = (_enetPacket)(base + packet_handle);
	SendRawPacketReliable = (_SendRawPackets)(base + send_packet_raw);
	return 0;
}
string last_packet = "";
int enet_send_packet(int a1, string a2, uint64_t a3) {
	createHookMH(sendpacker_newfunc, enet_send_packet(a1, a2, a3));
	string q = "[realInternal-MH] ";
	string y = q.append(a2);
	last_packet = a2;
	SendConsoleMessage(y.c_str(), 30i64, 0);
	
	
	
	enetPacket(a1, a2.c_str(), a3);
	deactivateHook(sendpacker_newfunc);

	return 0;

}



bool initialized = false;

void InitImGui(LPDIRECT3DDEVICE9 device)
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX9_Init(device);
}


int wrenchToInt(int NIDcount) {
	for (int netid = 0; netid < NIDcount; netid++) {
		string x = "action|wrench\nnetid|";
		string y = x.append(to_string(netid));
		enetPacket(2, y, enet_peer);
	}
}

int FindENETSendOffset(uint32_t size,uint64_t range) {
	for (uint64_t begin = 0;begin < range;++begin) {
		DWORD aa;
		VirtualProtectEx(gthandle, (LPVOID)(base + begin), 2, PAGE_EXECUTE_READWRITE, &aa); //unlock it for read/write
		BYTE pattern[5] = { 0x48, 0x8D, 0x68, 0xA1, 0x48 };
		BYTE scanned_Pattern[5];
		ReadProcessMemory(gthandle, (LPVOID)(base + begin), scanned_Pattern, 5, 0);
		if (scanned_Pattern == pattern) {
			// WE'VE MATCHED WITH THE OFFSET HAVE FUN UPDATED PACKET ADDRESS WITHOUT IDA
			
			return begin; // OUR OFFSET

		}
		
	}
}
ID3DXFont* dx_Font;
bool mn_1 = true;
bool mn_2 = false;
bool mn_3 = false;
long __stdcall PHook::hkEndScene(LPDIRECT3DDEVICE9 device)
{
	if (!initialized)
	{
		
		InitImGui(device);
		initialized = true;
		ImGui::SetNextWindowSize(ImVec2(532, 323));
		


	}
	/*/
	THIS SETUPS THE UI
	/*/
	IMLoadMenu();
	if (dx_Font != 0)
	{
		dx_Font->Release();
	}
	
	dx_Font = 0;
	D3DXCreateFontA(device, 22, 12, FW_MEDIUM, 0, 0, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &dx_Font);

	D3DXCreateFontA(device, 15, 8,FW_NORMAL, 0, 160, DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &dx_Font);
	dx_Font->DrawTextA(NULL, "Made By ArbitaryMann (c) 2020-2021", strlen("Made By ArbitaryMann (c) 2020-2021"), 0, DT_NOCLIP, rainbow());
	device->ShowCursor(false);

	GTApp = (GTApplication)(base + gameLogic);

	auto enet_peer= *(uint64_t*)(*(uint64_t*)(GTApp() + 3784) + 168i64); // USE THIS FOR CREATING PEER -> RECEIVING PEER SOCK


	if (ImGui::Button("Packet Simulation",ImVec2(140, 30))) {
		mn_1 = true;
		mn_2 = false;
		mn_3 = false;
	}
	ImGui::SameLine();
	if (ImGui::Button("Client Information",ImVec2(140,30))) {
		mn_2 = true;
		mn_1 = false;
		mn_3 = false;
	}
	ImGui::SameLine();
	if (ImGui::Button("More", ImVec2(140, 30))) {
		mn_2 = false;
		mn_3 = true;
		mn_1 = false;
	}
	static int w = 1;
	if (mn_3 == true) {


		ImGui::Text("World Management");
		ImGui::Separator();
		ImGui::InputInt("netID", &w);

		if (ImGui::Button("Execute")) {
			wrenchToInt(w);
			for (int netid = 0; netid < w; netid++) {
				string x = "action|wrench\nnetid|";
				string y = x.append(to_string(netid));
				enetPacket(2, y, enet_peer);
				enetPacket(3, y, enet_peer);
				enetPacket(1, y, enet_peer);
			}

		}
		ImGui::SameLine();
		if (ImGui::Button("Kick")) {
			wrenchToInt(w);
			for (int netid = 0; netid < w; netid++) {
				string x = "action|dialog_return\ndialog_name|popup\nnetid|";
				string y = x.append(to_string(netid));
				string w = y.append("|\nnetID|");
				string wws = w.append(to_string(netid));
				string q = wws.append("|\nbuttonClicked|kick");
				enetPacket(2, q, enet_peer);
				enetPacket(3, q, enet_peer);
				enetPacket(1, q, enet_peer);
			}



		}



		ImGui::SameLine();
		if (ImGui::Button("Pull")) {
			wrenchToInt(w);
			for (int netid = 0; netid < w; netid++) {
				string x = "action|dialog_return\ndialog_name|popup\nnetid|";
				string y = x.append(to_string(netid));
				string w = y.append("|\nnetID|");
				string wws = w.append(to_string(netid));
				string q = wws.append("|\nbuttonClicked|pull");
				enetPacket(2, q, enet_peer);
				enetPacket(3, q, enet_peer);
				enetPacket(1, q, enet_peer);
			}
			if (ImGui::Button("Ban")) {
				wrenchToInt(w);
				for (int netid = 0; netid < w; netid++) {
					string x = "action|dialog_return\ndialog_name|popup\nnetid|";
					string y = x.append(to_string(netid));
					string w = y.append("|\nnetID|");
					string wws = w.append(to_string(netid));
					string q = wws.append("|\nbuttonClicked|ban");
					enetPacket(2, q, enet_peer);
					enetPacket(3, q, enet_peer);
					enetPacket(1, q, enet_peer);
				}

			}
		}
	}
		
	
		
	
	if (mn_1 == true) {
		static char text[1024 * 16];
		static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;

		ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), flags);
		static int i0 = 2;

		ImGui::InputInt("packet type", &i0);
		static char str0[128];


		if (ImGui::Button("send packet")) {
			enetPacket(i0, text, enet_peer);
			
			string packet = text;
			std::vector<std::uint32_t> pData;
			
			string msg = "Packet Type -> ";
			string a2 = msg.append(to_string(i0));
			string a3 = a2.append("\nPacket -> ");
			string a4 = a3.append(packet);
			string a5 = a4.append("\n[CLIENT] Parsed & Executed!");
			SendConsoleMessage(a5.c_str(), 30i64, 0);


		}
		ImGui::SameLine();
		


		ImGui::SameLine();
		if (ImGui::Button("send to exit")) {
			enetPacket(3, "action|quit_to_exit", enet_peer);
		}
	}
	if (mn_2 == true) {
		ImGui::Separator();
		ImGui::Text("ENet Information & Client Information");
		string test = "ENet Peer Address -> 0x";
		string peer_addr = test.append(to_string(enet_peer));
		string packet_header = "enet_packet -> ";
		string pData = packet_header.append(last_packet);
		if (enet_peer > 0) {
			ImGui::Separator();

			const char* listbox_items[] = { peer_addr.c_str(), "ENet Client State -> connected", pData.c_str(),  };
			static int listbox_item_current = -1, listbox_item_current2 = -1;
			



			ImGui::PushItemWidth(-1);
			ImGui::ListBox("##listbox1", &listbox_item_current2, listbox_items, IM_ARRAYSIZE(listbox_items), 4);
			ImGui::PopItemWidth();
		}
		else {
		
			const char* listbox_items[] = { peer_addr.c_str(), "ENet Client State -> disconnected", pData.c_str() };
			static int listbox_item_current = -1, listbox_item_current2 = -1;
			ImGui::Separator();
			


			ImGui::PushItemWidth(-1);
			ImGui::ListBox("##listbox1", &listbox_item_current2, listbox_items, IM_ARRAYSIZE(listbox_items), 4);
			ImGui::PopItemWidth();

		}
	
		ImGui::Text("Hardcoded Offsets & IDA");
		ImGui::Separator();
		string offset_1 = "sendpacket -> 0x";
		string offset_1addr = offset_1.append(to_string(packet_handle));
		string offset_2 = "app -> 0x";
		string offset_2addr = offset_2.append(to_string(gameLogic));
		string offset_3 = "sendrawpacket -> 0x";
		string offset_3addr = offset_3.append(to_string(send_packet_raw));
		string offset_4 = "logmsg -> 0x";
		string offset_4addr = offset_4.append(to_string(log_msg));
		ImGui::SameLine();
		const char* listbox_items[] = { offset_1addr.c_str(),offset_2addr.c_str(),offset_3addr.c_str(),offset_4addr.c_str() };
		static int listbox_item_current = -1, listbox_item_current2 = -1;
		ImGui::Separator();



		ImGui::PushItemWidth(-1);
		ImGui::ListBox("##listbox2", &listbox_item_current2, listbox_items, IM_ARRAYSIZE(listbox_items), 4);
		ImGui::PopItemWidth();
		
		
	}
		
		
	




	



	ImGui::End();

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	return oEndScene(device);
}



extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall PHook::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		setupHooks();
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)PHook::Init, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)PHook::Shutdown, hMod, 0, nullptr);
		break;
	}
	return TRUE;
}