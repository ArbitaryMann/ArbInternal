#pragma once
	
	/*/
	THESE ARE THE OFFSETS WHICH ARE HARDCODED TO WORK ON 3.59+
	/*/

	uint32_t enet_peer = 0x0;
	uint32_t packet_handle = 0x41C620;
	uint32_t send_packet_raw = 0x41C6A0;
	uint32_t framerate = 0x132E0;
	uint32_t log_msg = 0x37DCD0;
	uint32_t gameLogic = 0xE1D20;
	uint32_t fps_limit = 0x20C13;
	uintptr_t base;
	uint64_t spOffset;