#pragma once
#include "includes.h"
using namespace std;

	DWORD rainbow();
	void createHookMH(uint32_t hookwhere, int comm);
	void deactivateHook(uint32_t hookwhere);
	int enet_send_packet(int a1, string a2, uint64_t a3);
	struct TankPacketStruct
	{
#pragma pack (push,1)
		byte packetType;
		byte padding1;
		short padding2;
		int NetID;
		int secondaryNetID;
		int characterState;
		float padding3;
		int value;
		float x, y;
		int XSpeed, YSpeed;
		int padding4;
		int punchX, punchY;
		int extDataSize = 0;
#pragma pack (pop)
	};

	byte* packTankStruct(TankPacketStruct* tPckt);
	