#pragma once

bool ant_sms1 = false;
void ant_sms(bool enable) {
	*(unsigned int*)0x13DF0C8 = enable ? 0x4E800020 : 0x7C0802A6; // MsgTextMessageHandler
}


bool block_call1 = false;
void block_call(bool enable) {
	*(unsigned int*)0x39D380 = enable ? 0x3BC00001 : 0x3BC00000;
	*(unsigned int*)0x39CFE8 = enable ? 0x3BC00001 : 0x3BC00000;
}




//this does not autofreeze in this location
bool ant_freeze_host1 = false;
void ant_freeze_host(bool enable) {
	*(unsigned int*)0x1309AC8 = enable ? 0x4E800020 : 0x7C0802A6;
}


bool block_entities1 = false;
void block_entities(bool enable) {

	*(unsigned int*)0x133CA34 = enable ? 0x48000044 : 0x8BD70029; // CNetworkObjectMgr_HandleCloneCreate Cars
	*(unsigned int*)0x133CBF0 = enable ? 0x48000044 : 0x8BD70029; // CNetworkObjectMgr_HandleCloneCreate Bikes
	*(unsigned int*)0x133CDA0 = enable ? 0x48000044 : 0x8BD70029; // CNetworkObjectMgr_HandleCloneCreate Boats + Submarines
	*(unsigned int*)0x133CE78 = enable ? 0x48000044 : 0x8BD70029; // CNetworkObjectMgr_HandleCloneCreate
	*(unsigned int*)0x133CE0C = enable ? 0x48000044 : 0x8BD70029; // CNetworkObjectMgr_HandleCloneCreate Planes
	*(unsigned int*)0x133CD34 = enable ? 0x48000044 : 0x8BD70029; // CNetworkObjectMgr_HandleCloneCreate Helicopters
	*(unsigned int*)0x133CAA4 = enable ? 0x48000044 : 0x8BD70029; // CNetworkObjectMgr_HandleCloneCreate Objetos
	*(unsigned int*)0x133C9F4 = enable ? 0x48000018 : 0x62C30000; // CNetworkObjectMgr_HandleCloneCreate
	*(unsigned int*)0x133CB14 = enable ? 0x48000044 : 0x8BD70029; // CNetworkObjectMgr_HandleCloneCreate Pickups
	*(unsigned int*)0x133CC5C = enable ? 0x48000044 : 0x8BD70029; // CNetworkObjectMgr_HandleCloneCreate Trailer + Trains

	*(unsigned int*)0x10C1E9C = enable ? 0x4E800020 : 0x7C0802A6; // CModelInfoStreamingModule_SetMapType
	*(unsigned int*)0x4B48A0 = enable ? 0x4E800020 : 0x7C0802A6; // sub_4B48A0
	*(unsigned int*)0x733F88 = enable ? 0x60000000 : 0x88DE0008; // sub_733F30
	*(unsigned int*)0xEDF944 = enable ? 0x60000000 : 0x4BFFFD05; // sub_EDF834
	*(unsigned int*)0xEDF9EC = enable ? 0x60000000 : 0x4BFFFC5D; // sub_EDF834
	*(unsigned int*)0xEE20A0 = enable ? 0x60000000 : 0x4BFFD5A9; // sub_EE2084
	*(unsigned int*)0xEE20B4 = enable ? 0x60000000 : 0x48FFD595; // sub_EE2084
	*(unsigned int*)0x13BFE78 = enable ? 0x60000000 : 0x4BB33C79; // sub_13BFE08
	*(unsigned int*)0x13BFED0 = enable ? 0x60000000 : 0x4BA7DF3D; // sub_13BFE08
	*(unsigned int*)0x13BFF18 = enable ? 0x60000000 : 0x4BB3E8FD; // sub_13BFE08
	*(unsigned int*)0x13BFF40 = enable ? 0x60000000 : 0x4BB36071; // sub_13BFE08
	*(unsigned int*)0x13BF834 = enable ? 0x60000000 : 0x41820030; // sub_13BF800
	*(unsigned int*)0x13C01E8 = enable ? 0x60000000 : 0x4BB33C75; // sub_13C0110
	*(unsigned int*)0x13C0208 = enable ? 0x60000000 : 0x4BA7DC05; // sub_13C0110
	*(unsigned int*)0x13BFF64 = enable ? 0x60000000 : 0x4180FFAC; // sub_13BFE08
	*(unsigned int*)0x1327673 = enable ? 0x01807A0E : 0X4804C205; // sub_1327498

	*(unsigned int*)0xFEB51C = enable ? 0x4E800020 : 0x7C0802A6; //patch stick bomb freeze
	//*(unsigned int*)0xFEB5B0 = enable ? 0x60000000 : 0xA084000E; //vehicleFragmentPhysics - //Adder/Big Vehicle Patch crashed myself after I threw the sticky bomb
}



//patch 0x00F6CFDC 0x00F6CFF4 0x00F6D064
bool ant_clima1 = false;
void ant_clima(bool enable)
{
	*(unsigned int*)0x1093228 = enable ? 0x60000000 : 0x4BA525E5; // Weather
}



bool ant_big_vhc1 = false;
void ant_big_vhc(bool enable) {
	*(unsigned int*)0x10C1E9C = enable ? 0x4E800020 : 0x7C0802A6; // CModelInfoStreamingModule_SetMapType
	*(unsigned int*)0x4B48A0 = enable ? 0x4E800020 : 0x7C0802A6; // sub_4B48A0
	*(unsigned int*)0x733F88 = enable ? 0x60000000 : 0x88DE0008; // sub_733F30
	*(unsigned int*)0xEDF944 = enable ? 0x60000000 : 0x4BFFFD05; // sub_EDF834
	*(unsigned int*)0xEDF9EC = enable ? 0x60000000 : 0x4BFFFC5D; // sub_EDF834
	*(unsigned int*)0xEE20A0 = enable ? 0x60000000 : 0x4BFFD5A9; // sub_EE2084
	*(unsigned int*)0xEE20B4 = enable ? 0x60000000 : 0x48FFD595; // sub_EE2084
	*(unsigned int*)0x13BFE78 = enable ? 0x60000000 : 0x4BB33C79; // sub_13BFE08
	*(unsigned int*)0x13BFED0 = enable ? 0x60000000 : 0x4BA7DF3D; // sub_13BFE08
	*(unsigned int*)0x13BFF18 = enable ? 0x60000000 : 0x4BB3E8FD; // sub_13BFE08
	*(unsigned int*)0x13BFF40 = enable ? 0x60000000 : 0x4BB36071; // sub_13BFE08
	*(unsigned int*)0x13BF834 = enable ? 0x60000000 : 0x41820030; // sub_13BF800
	*(unsigned int*)0x13C01E8 = enable ? 0x60000000 : 0x4BB33C75; // sub_13C0110
	*(unsigned int*)0x13C0208 = enable ? 0x60000000 : 0x4BA7DC05; // sub_13C0110
	*(unsigned int*)0x13BFF64 = enable ? 0x60000000 : 0x4180FFAC; // sub_13BFE08
	*(unsigned int*)0x1327673 = enable ? 0x60000000 : 0X4804C205; // sub_1327498
}


bool bigorna1 = false;
void bigorna(bool enable) {
	*(unsigned int*)0x10C1E9C = enable ? 0x4E800020 : 0x7C0802A6; // CModelInfoStreamingModule_SetMapType
	*(unsigned int*)0x4B48A0 = enable ? 0x4E800020 : 0x7C0802A6; // sub_4B48A0
	*(unsigned int*)0x733F30 = enable ? 0x4E800020 : 0x7C0802A6; // sub_733F30
	*(unsigned int*)0xEDF834 = enable ? 0x4E800020 : 0x7C0802A6; // sub_EDF834
	*(unsigned int*)0xEE2084 = enable ? 0x4E800020 : 0x7C0802A6; // sub_EE2084
	*(unsigned int*)0x13BFE08 = enable ? 0x4E800020 : 0x7C0802A6; // sub_13BFE08
	*(unsigned int*)0x13BF800 = enable ? 0x4E800020 : 0x7C0802A6; // sub_13BF800
	*(unsigned int*)0x13C0110 = enable ? 0x4E800020 : 0x7C0802A6; // sub_13C0110
	*(unsigned int*)0x13BFE08 = enable ? 0x4E800020 : 0x7C0802A6; // sub_13BFE08
	*(unsigned int*)0x1327498 = enable ? 0x4E800020 : 0x7C0802A6; // sub_1327498
}



bool ant_freeze_v31 = false;
void ant_freeze_v3(bool enable) {
	if (enable) {
		*(unsigned int*)0x9FBBC8 = 0x60000000;
		*(unsigned int*)0x9FBBCC = 0x60000000;
		*(unsigned int*)0x9FBA00 = 0x60000000;
	}
	else {
		*(unsigned int*)0x9FBBC8 = 0x7FE10808;
		*(unsigned int*)0x9FBBCC = 0x4BFFFDA8;
		*(unsigned int*)0x9FBA00 = 0x7FE10808;
	}
}


bool vejetal1 = false;
void vejetal(bool enable) {
	if (enable) {
		*(unsigned int*)0x133C430 = 0x4E800020;
	}
	else {
		*(unsigned int*)0x133C430 = 0x7C0802A6;
	}
}




bool sync_protection1 = false;
void sync_protection(bool enable)
{
	*(unsigned int*)0x9FBBC4 = enable ? 0x60000000 : 0x4082FDB0;//CGamePlayerBroadcastDataHandler_Local_HandleReceived
	//*(unsigned int*)0x9FB8F8 = enable ? 0x4E800020 : 0x7C0802A6;//CGamePlayerBroadcastDataHandler_Local_HandleReceived - nao funciona freeze brodcast
}



bool ant_invalid1 = false;
void ant_invalid(bool enable)
{
	*(unsigned int*)0x421C08 = enable ? 0x60000000 : 0x48905411; //sub_421BBC - ant invalid
}




bool tool_session1 = false;
void tool_session(bool enable) {

	*(unsigned int*)0x9FCFB4 = enable ? 0x60000000 : 0x7FE10808; // CNetworkEventMgr__MakeSpace
	*(unsigned int*)0x130A300 = enable ? 0x60000000 : 0x4BFB2F59; // CGameHostBroadcastDataHandler_VerifyScriptDataEvent
}


bool block_change_sh1;
void block_change_sh(bool enable)
{
	*(unsigned int*)0xA5F438 = enable ? 0x4E800020 : 0x7C0802A6; // rage_msgScriptNewHost_ReadSyncData
}



bool congela_mapa1 = false;
void congela_mapa(bool enable) {

	*(unsigned int*)0xA097F0 = enable ? 0x60000000 : 0x4BFFF961; // rage_net_updateSyncMsgPackets
	*(unsigned int*)0x133D6EC = enable ? 0x4E800020 : 0x7C0802A6; // CNetworkObjectMgr_HandleCloneSync
	*(unsigned int*)0x13390CC = enable ? 0x4E800020 : 0x7C0802A6; // CNetworkObjectMgr_Update
	*(unsigned int*)0xA09150 = enable ? 0x4E800020 : 0x7C0802A6; // rage_net_cloneSyncMsg teste
}


bool all_events1 = false;
void all_events(bool enable) {

	*(unsigned int*)0xA0284C = enable ? 0x4E800020 : 0x7C0802A6;// CNetworkEventMgr__ExecuteEvent - Raiz dos eventos
	//*(unsigned int*)0x12BCF00 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12BD36C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12BDFCC = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C0128 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C1AF4 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C2314 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C2988 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C2E2C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C31AC = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C37EC = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C3ACC = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C3C74 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C413C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C4A44 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C5638 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C69F0 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C78DC = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C7D74 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C7FE8 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C83D0 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C87AC = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C8950 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C8D60 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C922C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C96B4 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C99E8 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12C9FFC = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CA484 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CA7AC = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CAE68 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CB198 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CB55C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CB930 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CB70C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CBE34 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CC28C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CC958 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CCCA0 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CCE10 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CCF44 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CD568 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CDB54 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CDFA4 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CE70C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CFDE8 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D0248 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D0584 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D09D4 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D0E0C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D114C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D137C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CD934 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D17E0 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D1A50 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D1E28 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D2104 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D2500 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D29E4 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D2E54 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D35A0 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D3B40 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12CD244 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D427C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D4660 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D4970 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D5098 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D58FC = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D5CB4 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D4C38 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D5FB8 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D64D4 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D6E50 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D734C = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x12D3088 = enable ? 0x4E800020 : 0x4BCDE089;
	//*(unsigned int*)0x12D303C = enable ? 0x4E800020 : 0x4B725BFD;
	//*(unsigned int*)0x12D2C48 = enable ? 0x4E800020 : 0x4B725FF1;//added. ant vote kick
	//
	//*(unsigned int*)0xA03B08 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0xA04100 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0xA04728 = enable ? 0x4E800020 : 0x7C0802A6;

}


//travei pro pirata em   Type  Function                        Line number  Filename  Stack Size  Module  
//Unknown  0x00A0EFE4 (0xA0F0A4)                         0x00e0
//Unknown  0x00A0EFE4 (0xA0F0BC)                         0x00e0




bool s_boneco1 = false;
void s_boneco(bool enable) {
	*(unsigned int*)0x11B1CF4 = enable ? 0x4E800020 : 0x7C0802A6; // TIRA TEXTURA DO BONECO
}

bool s_mapa1 = false;
void s_mapa(bool enable) {
	*(unsigned int*)0x1271A70 = enable ? 0x4E800020 : 0x7C0802A6; // TIRA TEXTURA DO MAPA E DO BONECO
}

bool hide_missions1 = false;
void hide_missions(bool enable) {
	*(unsigned int*)0x159A64C = enable ? 0x4E800020 : 0x7C0802A6; // sub_159A64C
}


bool remote_revolution1 = false;
void remote_revolution(bool enable) {
	*(unsigned int*)0x172D73C = enable ? 0x2C060000 : 0x40820068;  // sub_172D710
}


bool bunkerino1 = false;
void bunkerino(bool enable) {

	*(unsigned int*)0x97603C = enable ? 0x4E800020 : 0x7C0802A6; // ReadSyncDataNetMessage_ConfigRequest

	/*
	*(unsigned int*)0x9FD3EC = enable ? 0x4E800020 : 0x7C0802A6; // rage_netArrayHandlerBase_ReadSyncData
	*(unsigned int*)0xA19A30 = enable ? 0x4E800020 : 0x7C0802A6; // rage__netHostBroadcastDataHandlerBase_ReadSyncData
	*(unsigned int*)0xA5F0CC = enable ? 0x4E800020 : 0x7C0802A6; // rage_msgScriptVerifyHostAck_ReadSyncData
	*(unsigned int*)0xA5F208 = enable ? 0x4E800020 : 0x7C0802A6; // rage_msgScriptVerifyHost_ReadSyncData
	*(unsigned int*)0xA5F438 = enable ? 0x4E800020 : 0x7C0802A6; // rage_msgScriptNewHost_ReadSyncData
	*(unsigned int*)0xA5F638 = enable ? 0x4E800020 : 0x7C0802A6; // rage_msgScriptHostRequest_ReadSyncData
	*(unsigned int*)0xA5F8F0 = enable ? 0x4E800020 : 0x7C0802A6; // rage_msgScriptMigrateHost_ReadSyncData
	*(unsigned int*)0xA60E38 = enable ? 0x4E800020 : 0x7C0802A6; // CGameScriptHandlerMgr_ReadSyncData
	*(unsigned int*)0x12BD0A8 = enable ? 0x4E800020 : 0x7C0802A6; // CScriptArrayDataVerifyEvent_ReadSyncData
	*(unsigned int*)0x12CEAF4 = enable ? 0x4E800020 : 0x7C0802A6; // CScriptEntityStateChangeEvent_ReadSyncData
	*/

	*(unsigned int*)0x16271AC = enable ? 0x4E800020 : 0x7C0802A6; // ReadSyncDataRageNetMessageId
	*(unsigned int*)0x16276C4 = enable ? 0x4E800020 : 0x7C0802A6; // ReadSyncDataRageNetMessageId2
	*(unsigned int*)0x16279E4 = enable ? 0x4E800020 : 0x7C0802A6; // ReadSyncDataRageNetMessage_JoinRequest
	*(unsigned int*)0x1627EAC = enable ? 0x4E800020 : 0x7C0802A6; // ReadSyncDataRageNetMessage_RemoveGamersFromSessionCmd
	*(unsigned int*)0x16280E0 = enable ? 0x4E800020 : 0x7C0802A6; // ReadSyncDataNetMessage_RequestGamerInfo
	*(unsigned int*)0x162826C = enable ? 0x4E800020 : 0x7C0802A6; // ReadSyncDataNetMessage_GamerMatchInfoRequest

	*(unsigned int*)0x1726238 = enable ? 0x4E800020 : 0x7C0802A6; // CRemoveAllWeaponsEvent_ReadSyncData
	*(unsigned int*)0x1728A24 = enable ? 0x4E800020 : 0x7C0802A6; // CGameClockEvent_ReadSyncData
	*(unsigned int*)0x1728F40 = enable ? 0x4E800020 : 0x7C0802A6; // CGameWeatherEvent_ReadSyncData
	*(unsigned int*)0x1729C34 = enable ? 0x4E800020 : 0x7C0802A6; // CGiveWeaponEvent_ReadSyncData
	*(unsigned int*)0x1729E60 = enable ? 0x4E800020 : 0x7C0802A6; // CRemoveWeaponEvent_ReadSyncData
	*(unsigned int*)0x172D348 = enable ? 0x4E800020 : 0x7C0802A6; // CPlayerTauntEvent_ReadSyncData
	*(unsigned int*)0x172E038 = enable ? 0x4E800020 : 0x7C0802A6; // CScriptWorldStateEvent_ReadSyncData
	*(unsigned int*)0x172F200 = enable ? 0x4E800020 : 0x7C0802A6; // CStartNetworkSyncedSceneEvent_ReadSyncData
	*(unsigned int*)0x1730300 = enable ? 0x4E800020 : 0x7C0802A6; // CStartNetworkPedUncuffEvent_ReadSyncData
	*(unsigned int*)0x1732054 = enable ? 0x4E800020 : 0x7C0802A6; // CSendKickVotesEvent_ReadSyncData
	*(unsigned int*)0x1734260 = enable ? 0x4E800020 : 0x7C0802A6; // CUpdatePlayerScarsEvent_ReadSyncData
	*(unsigned int*)0x1736A4C = enable ? 0x4E800020 : 0x7C0802A6; // CReportCashSpawnEvent_ReadSyncData
	*(unsigned int*)0x1737FB8 = enable ? 0x4E800020 : 0x7C0802A6; // CScriptEntityStateChangeEvent_CSettingOfLookAtEntity_ReadSyncData
	*(unsigned int*)0x17385D8 = enable ? 0x4E800020 : 0x7C0802A6; // CScriptEntityStateChangeEvent_CSetPedFacialIdleAnimOverride_ReadSyncData
	*(unsigned int*)0x1738A50 = enable ? 0x4E800020 : 0x7C0802A6; // CScriptEntityStateChangeEvent_CSetVehicleExclusiveDriver_ReadSyncData
	*(unsigned int*)0x1750B58 = enable ? 0x4E800020 : 0x7C0802A6; // CNetGamePlayerDataMsg_ReadSyncData

	*(unsigned int*)0x17553D4 = enable ? 0x4E800020 : 0x7C0802A6; // ReadSyncDataRageNetMessage_MsgTransitionParameters
}




bool block_prints1 = false;
void block_prints(bool enable)
{
	*(unsigned int*)0x16276C4 = enable ? 0x4E800020 : 0x7C0802A6; //ReadSyncDataRageNetMessageId2
}




bool aparencia1 = false;
void aparencia(bool enable) {
	*(unsigned int*)0x13CA768 = enable ? 0x4E800020 : 0x7C0802A6; // CNetObjPlayer_PlayerAppearance_minus0x334
}


bool ultra_stealth1 = false;
void ultra_stealth(bool enable) {
	*(unsigned int*)0xD11DC0 = enable ? 0x60000000 : 0x4BFF6251;
}




bool FunyScreen1 = false;
void FunyScreen(bool enable) {
	*(unsigned int*)0x15BCF0 = enable ? 0x3E800000 : 0x3F800000;
}



bool mamas1 = false;
void mamas(bool enable) {
	*(unsigned int*)0xD15F28 = enable ? 0x4E800020 : 0x7C0802A6; //SendReliableCommand_5
}



bool xmas1 = false;
void xmas(bool enable) {
	*(unsigned int*)0x133EB18 = enable ? 0x4E800020 : 0x7C0802A6; //CNonPhysicalPlayerData_Log
}



bool leitada1 = false;
void leitada(bool enable) {
	*(unsigned int*)0x1396D24 = enable ? 0x60000000 : 0x3084F440; //sub_1396748
}



bool pirtas1 = false;
void pirtas(bool enable) {
	*(unsigned int*)0x1331FD0 = enable ? 0x60000000 : 0x3084F8C0; //CSectorPositionDataNode
}


bool teshost1 = false;
void teshost(bool enable) {
	*(unsigned int*)0x3E8F48 = enable ? 0x60000000 : 0x7C0802A6;
}




bool jaro_sync_patch1 = false;
void jaro_sync_patch(bool enable)
{
	*(uint64_t*)(0x1C707F0) = *(uint64_t*)(NetworkObjectMgr_HandleCloneSync); // jaro patch 2 sync
}


bool jaro_patch1 = false;
void jaro_patch(bool enable)
{
	*(uint32_t*)(0xA128BC) = 0x48000310; // jaro patch 1
}





//tudo r0

// 0x12D3BB8 //SendCNetworkShoutTargetPositionEvent
// 
// 0x12F7BE0 //getNetPlayerRelevancePosition
// 
// 0x12F7B1C //getNetPlayerRelevancePosition2
// 
// 0x1344390 //CNetObjPlayer_GetSyncPosition


//isso é protecao e nao freeze

void SyncTreeBuff(bool enable) {
	*(unsigned int*)0xA17248 = enable ? 0x60000000 : 0x807C0008; // netSyncTree_ReadFromBuffer  orginal hextic v3
}


bool aa1 = false;
void aa(bool enable) {
	*(unsigned int*)0x12D3BB8 = enable ? 0x4E800020 : 0x7C0802A6;
}


bool bb1 = false;
void bb(bool enable) {
	*(unsigned int*)0x12F7BE0 = enable ? 0x4E800020 : 0x7C0802A6;
}


bool cc1 = false;
void cc(bool enable) {
	*(unsigned int*)0x12F7B1C = enable ? 0x4E800020 : 0x7C0802A6;
}


bool dd1 = false;
void dd(bool enable) {
	*(unsigned int*)0x1344390 = enable ? 0x4E800020 : 0x7C0802A6;
}

bool CLONE_SYNC1 = false;
void CLONE_SYNC(bool enable)
{
	*(int*)0xA077B0 = enable ? 0x60000000 : 0x3063A478; //cloneSyncMsg [UpdateNetworkObject]
}



bool joana1 = false;
void joana(bool enable)
{
	*(int*)0x133D784 = enable ? 0x60000000 : 0x4BFA6F35;
	*(int*)0x133DA0C = enable ? 0x60000000 : 0x809C0000;
}


////RIZZEX TRAVOU PRO PIRATA
//
//00A0F0A4
//00A0F0BC
//
/////TRAVEI PRO PIRATA
//Type  Function                         Line number  Filename  Stack Size  Module
//Unknown  0x00A0F15C (0xA0F210)                          0x00b0
//Unknown  0x00A0F15C (0xA0F224)                          0x00b0




//falhei miseravelmente...mas a outra funcionou :)
bool patch_duplo1 = false;
void patch_duplo(bool enable)
{
	*(int*)0xA0F080 = enable ? 0x60000000 : 0x7A940020;//rage_netSyncNodeBase_HasBeenSent -> localizada
	*(int*)0xA0EF40 = enable ? 0x60000000 : 0x789E0020;//rage_netSyncParentNode_RecursiveDestory -> localizada
}




bool ninja_patch1 = false;
void ninja_patch(bool enable)
{
	*(int*)0xA0EFDC = enable ? 0x4E800020 : 0x7C0802A6;//rage_netSyncNodeBase_HasBeenSent - rizzex travou pro pirata
}


bool otro_patch1 = false;
void otro_patch(bool enable)
{
	*(int*)0xA0F080 = enable ? 0x60000000 : 0x7A940020;//rage_netSyncNodeBase_HasBeenSent localizada
}


bool jakinn1 = false;
void jakinn(bool enable)
{
	*(unsigned int*)0xAE580C = enable ? 0x60000000 : 0x2C030000; //full jenkinsHash
}


bool panter_protection1 = false;
void panter_protection(bool enable)
{
	//protection
	*(unsigned int*)0x9B8888 = enable ? 0x60000000 : 0x7FE10808; //sub_9B8888 //pantera 2021
	*(unsigned int*)0x3D3EB8 = enable ? 0x60000000 : 0x41820044; //sub_3D3E90 //pantera 2021
	*(unsigned int*)0x10953A4 = enable ? 0x60000000 : 0x418200AC; //sub_109536C //pantera 2021
	*(unsigned int*)0x10953F8 = enable ? 0x60000000 : 0x41820058; //sub_109536C //pantera 2021
	*(unsigned int*)0x130D104 = enable ? 0x4E800020 : 0x7C0802A6; //sub_109536C //pantera 2021
	*(unsigned int*)0xA5A674 = enable ? 0x4E800020 : 0x7C0802A6; //sub_A5A674 //pantera 2021
	*(unsigned int*)0xA5A4F0 = enable ? 0x4E800020 : 0x7C0802A6; //sub_A5A4F0 //pantera 2021
}

bool patch_hextic1 = false;
void patch_hextic(bool enable)
{
	*(unsigned int*)0xA128E4 = enable ? 0x60000000 : 0x7FE10808; //netObjectMgrBase__RegisterNetworkObject - anon
}


bool custom_protect_rizzex1 = false;
void custom_protect_rizzex(bool enable)
{
	*(unsigned int*)0x1358EF8 = enable ? 0x60000000 : 0x41820054; //CFingerOfGodPresenceEvent_HandleReceived
	*(unsigned int*)0x130A300 = enable ? 0x60000000 : 0x4BFB2F59; //CGameHostBroadcastDataHandler_VerifyScriptDataEvent
	*(unsigned int*)0x135184C = enable ? 0x60000000 : 0x4B9EEC75; //sub_135178C
	*(unsigned int*)0x13702E4 = enable ? 0x60000000 : 0x7C8903A6; //sub_1370198
	*(unsigned int*)0x1357CF4 = enable ? 0x60000000 : 0x907E0004; //CFingerOfGodPresenceEvent_GetJsonVals
	*(unsigned int*)0x115E2DC = enable ? 0x60000000 : 0xC0630778; //sub_115E2D0
	*(unsigned int*)0x1358EE8 = enable ? 0x60000000 : 0x41820234; //CFingerOfGodPresenceEvent_HandleReceived
	*(unsigned int*)0x1309E50 = enable ? 0x60000000 : 0x4180FFBC; //sub_1309AC8
	*(unsigned int*)0x1358F08 = enable ? 0x60000000 : 0x41820188; //CFingerOfGodPresenceEvent_HandleReceived
}






