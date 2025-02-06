#include "includes.h"

#pragma diag_suppress 77
SYS_MODULE_INFO("VodkkaSPRX", 0, 1, 1);
SYS_MODULE_START(Vodkka_Start);


#pragma region GameExitOnFreeze_Thread
#define CELL_UTIL_PAD_MAX 7
static CellPadInfo2 sPadInfo2;
bool updatePadInfo()
{
	CellPadInfo2 pad_info2;
	int32_t cr = cellPadGetInfo2(&pad_info2);
	if (cr != CELL_PAD_OK) return false;

	sPadInfo2 = pad_info2;

	return true;
}
bool isConnected(uint8_t pad)
{
	if (pad >= CELL_UTIL_PAD_MAX) return false;
	if (pad >= sPadInfo2.max_connect) return false;

	return (sPadInfo2.port_status[pad] & CELL_PAD_STATUS_CONNECTED);
}
bool cellPadUtilIsConnected(uint8_t pad)
{
	if (!updatePadInfo()) {
		return false;
	}
	return isConnected(pad);
}
//inject sprx bip bop
int modres;
sys_prx_id_t LoadSPRX(const char* path)
{
	return sys_prx_load_module(path, 0, nullptr);
}
void StartSPRX(sys_prx_id_t prxID)
{
	sys_prx_start_module(prxID, 0, nullptr, &modres, 0, nullptr);
}
void UnloadSPRX(sys_prx_id_t prxID)
{
	sys_prx_stop_module(prxID, 0, nullptr, &modres, 0, nullptr);
	sys_prx_unload_module(prxID, 0, nullptr);
}
sys_prx_id_t prxID;
//tiny tiny hehe
bool timer = true;
void forcequitgame(uint64_t gamecrashexit)
{
	sleep(30000);
	while (timer) 
	{
		sleep(100);//delay that loop
		static int pad = -1;
		if (pad == -1) {
			for (int i = 0; i < CELL_UTIL_PAD_MAX; i++) {
				if (cellPadUtilIsConnected(i))
					pad = i;
			}
		}
		CellPadData tmppaddata;
		static CellPadData paddata;
		int32_t ret = cellPadGetData(pad == -1 ? 0 : pad, &tmppaddata);
		if (ret == CELL_PAD_OK && tmppaddata.len != 0) {
			paddata = tmppaddata;
		}
		int data = paddata.button[CELL_PAD_BTN_OFFSET_DIGITAL1];
		if ((data & CELL_PAD_CTRL_SELECT) && (data & CELL_PAD_CTRL_START))
		{
			sys_process_exit(0);
		}
	}

}
#pragma endregion


//unload unnecessary things from memory thanks ixBryan
void memory_purge()
{
	const char** modules = new const char* [3];
	modules[0] = "cellSsl_Library";
	modules[1] = "sceNpCommercer2_Library";
	modules[2] = "cellNp_Library";

	for (int i = 0; i < 3; ++i) {
		int ret, stop_res;
		ret = sys_prx_get_module_id_by_name(modules[i], 0, 0);
		if (ret > 0) {
			sys_prx_stop_module(ret, 0, nullptr, &stop_res, 0, nullptr);
			sys_prx_unload_module(ret, 0, nullptr);
		}
	}

	delete[] modules;
}

typedef unsigned long long ui64;
template <typename T>
__ALWAYS_INLINE T(*call(unsigned int address, unsigned int toc = TOC))(...) {
	volatile opd_s opd = { address,toc };
	T(*func)(...) = (T(*)(...)) & opd;
	return func;
}

//finally stop wasting time with the shitty prologue
int prologueBypass(unsigned int addr) {

	*(char*)(0x1389EA4 + 0x3) = 5;//bypass the other 0x387 check that is from the native NETWORK_CAN_ACCESS_MULTIPLAYER. Set to 5 so the bne triggers cuz it is never 5

	//*(char*)(0x8797C+0x3) = 1;
	if (*(int*)*(int*)(addr + 0x8) == 0x387) {
		*(int*)*(int*)(addr) = 1;//completed prologue
		return 1;
	}
	/*if (*(int*)*(int*)(addr+0x8) == 0x392) {
		*(int*)*(int*)(addr) = 0;//completed prologue 2
		return 1;
	}
	if (*(int*)*(int*)(addr+0x8) == 0x393) {
		*(int*)*(int*)(addr) = 2;//completed prologue 3
		return 1;
	}*/
	return call<int>(0x1580310)(addr);

}

char is_player[16];

//original = 0x3E3A20
//does_cam_exist = 0x3A3288
//tiny = 0x9FAB6729



void Thread(uint64_t nothing)
{
	sleep(30000);
	g_Natives = (Native_s**)FindNativeTableAddress();
	sleep(1000);
	PatchInJump(NativeAddress(0x9FAB6729, true), (int)Hook, false);

	*(int*)0x1CF74E4 = 0xE93E90; //saving bypass
	*(int*)0x136BF04 = 0x4E800020; // player apparence

	*(ui64*)(0x1C27060) = *(ui64*)((int)prologueBypass); //gopro again

	char MUB[] = {0x3C, 0x60, 0x02, 0x8A, 0x60, 0x63, 0xD0, 0x00, 0x90, 0x7E, 0x00, 0x18, 0x3C, 0x60, 0xB7, 0x49,0x60, 0x63, 0xA4, 0x3B, 0x90, 0x7E, 0x00, 0x1C, 0x60, 0x00, 0x00, 0x00}; // gopro -> modloader/script bypass
	write_process((void*)0x1316254, MUB, 28);

	/*char original_updte_size[] = { 0x3C, 0x60, 0x00, 0xEB, 0x38, 0x63, 0x3A, 0x30, 0x3C, 0x80, 0x01, 0xCF, 0xF8, 0x64, 0x74, 0xE0, 0x4E, 0x80, 0x00, 0x20 };
	memcpy((void*)0x12E3AC8, original_updte_size, sizeof(original_updte_size));*/ //other...functional too.

	sys_ppu_thread_exit(nothing);
}


extern "C"
{
	int Vodkka_Start()
	{
		zeigen("Welcome To\nVodkka SPRX\nOpen    +   ");
		memory_purge();
		sys_ppu_thread_t ThreadModuleID;
		sys_ppu_thread_t GameExitThreadID;
		sys_ppu_thread_create(&ThreadModuleID, Thread, 0, 10, 0x10, 0, "Started");
		sys_ppu_thread_create(&GameExitThreadID, forcequitgame, 0, 10, 0x10, 0, "ExitGame");
		toggleRedux(true);
		return 0;
	}
}
