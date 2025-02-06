#pragma once

#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <sys/process.h>
#include <string.h>
#include <stdio.h>
#include "rage/Natives.h"


void HookNative(int native, int dest);
int write_process(void* destination, const void* source, size_t size);
void PatchInJump(uint64_t Address, int Destination, bool Linked);
unsigned int FindNativeTableAddress();
int NativeAddress(int Native, bool PatchInJump);
bool henChk();
__attribute__((noinline)) int checkIfCEX_stub();
bool isDEX();
int writeMem(uint64_t address, const void* data, size_t size);
int readMem(uint64_t address, void* data, size_t size);
sys_prx_id_t LoadSPRX(const char* path);
void StartSPRX(sys_prx_id_t prxID);
void UnloadSPRX(sys_prx_id_t prxID);
void Thread(uint64_t nothing);
extern "C" {
    int Vodkka_Start();
    int Vodkka_Stop();
}
