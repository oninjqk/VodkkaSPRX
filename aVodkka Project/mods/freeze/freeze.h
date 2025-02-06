//

bool deportation_bag = false;
bool sync_boolean = false;
bool sync_string = false;
bool sync_byte = false;
bool interager = false;
bool brodcast_data = false;
bool array_base = false;
bool array_data = false;
bool array_calculator = false;
bool array_update = false;
bool script_id = false;
bool tree_base = false;
bool base_node = false;
bool iped_node_data_accessor = false;
bool cnet_object = false;
bool point_info = false;
bool teste_ou = false;
bool subes = false;


void Deportation_bag(bool enable)
{
	*(unsigned int*)0x1775F50 = enable ? 0x60000000 : 0x306307F4; // russian - DE
}

bool variacao41 = false;
void variacao4(bool enable)
{
	*(unsigned int*)0xA0F0A4 = enable ? 0x60000000 : 0x8167001C; //
	*(unsigned int*)0xA0F0BC = enable ? 0x60000000 : 0x2C030000; //
}


bool eu641 = false;
void eu64(bool enable)
{
	*(int*)0xA8C1C4 = enable ? 0x4E800020 : 0x7C0802A6;
}


bool write_serialize1 = false;
void write_serialize(bool enable)
{
	*(int*)0xA8B5FC = enable ? 0x4E800020 : 0x7CC81E70; //SerializeSyncDataWriter
}


void Boolean(bool enable)
{
	*(unsigned int*)0xA8C328 = enable ? 0x4E800020 : 0x7C0802A6; // WriteSyncDataBool_post_plus_0xC
	*(unsigned int*)0xA8C32C = enable ? 0x4E800020 : 0x48A7E765; // WriteSyncDataBool_post_plus_0xC
	*(unsigned int*)0x16542D4 = enable ? 0x60000000 : 0x4B438055; // rage_CSyncDataWriter_WriteBool

}

void String(bool enable)
{
	*(unsigned int*)0x1654F70 = enable ? 0x4E800020 : 0x7C0802A6; // rage_CSyncDataWriter_WriteString
	*(unsigned int*)0xA8BC90 = enable ? 0x4E800020 : 0x7C0802A6; // sub_A8BC90  //serialize string
}

void Byte(bool enable)
{
	*(unsigned int*)0x1654684 = enable ? 0x4E800020 : 0x7C0802A6; // rage_CSyncDataWriter_WriteByte
}


void Interager(bool enable)
{
	*(unsigned int*)0x16544E8 = enable ? 0x4E800020 : 0x7C0802A6; // rage_CSyncDataWriter_WriteIntegerAlot
	*(unsigned int*)0x16547A8 = enable ? 0x60000000 : 0x2C030000; // rage_CSyncDataWriter_WriteInteger
	*(unsigned int*)0x1654784 = enable ? 0x4E800020 : 0x7C0802A6; // rage_CSyncDataWriter_WriteInteger
}

void BrodcastData(bool enable)
{
	*(unsigned int*)0x9FB3CC = enable ? 0x4E800020 : 0x48B0F681; // CGamePlayerBroadcastDataHandler_Local_WriteLogSyncData
	*(unsigned int*)0x9FB3C8 = enable ? 0x4E800020 : 0x7C0802A6; // CGamePlayerBroadcastDataHandler_Local_WriteLogSyncData
}

bool Arrays1 = false;
void Arrays(bool enable)
{
	*(unsigned int*)0x9FD774 = enable ? 0x60000000 : 0x7C0802A6; // rage_netArrayHandlerBase_HandleReceived
	*(unsigned int*)0x12BCF8C = enable ? 0x4E800020 : 0x7C0802A6; // CScriptArrayDataVerifyEvent_WriteSyncData
	*(unsigned int*)0x1656A18 = enable ? 0x60000000 : 0x38600004; // rage_netArrayHandler_SyncDataSizeCalculator
	*(unsigned int*)0x9FF3A8 = enable ? 0x4E800020 : 0x7C0802A6; // rage_netArrayManager_msgUpdateAck  a raiz de todos eu acho
	*(unsigned int*)0x9FBC18 = enable ? 0x4E800020 : 0x7C0802A6; // sub - XREF -> rage_netArrayManager_msgUpdateAck+120↓p
}





bool pirata_v1_1 = false;
void pirata_v1(bool enable)
{
	*(int*)0x136B350 = enable ? 0x4E800020 : 0x7C0802A6;
}
bool pirata_v2_1 = false;
void pirata_v2(bool enable)
{
	*(unsigned int*)0x136B350 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(unsigned int*)0x136B898 = enable ? 0x4E800020 : 0x7C0802A6; //raizona
}

bool putinhav1 = false;
void putinhav(bool enable)
{
	*(unsigned int*)0x1657508 = enable ? 0x4E800020 : 0x7C0802A6;
}

void ScriptID(bool enable)
{
	*(unsigned int*)0x46E30C = enable ? 0x4E800020 : 0x7C0802A6; // CGameScriptId_Serialize
	*(unsigned int*)0xA5544C = enable ? 0x4E800020 : 0x7C0802A6; // sub_A5544C - XREF -> CGameScriptId_Serialize+18↑p
}

void TreeBase(bool enable) {
	*(unsigned int*)0x136D6E8 = enable ? 0x60000000 : 0x4B71EC41; // SyncTreeBase_SerializeType
}

void BaseNode(bool enable) {
	*(unsigned int*)0xA0F070 = enable ? 0x60000000 : 0x4807D2B9; // rage_netSyncNodeBase_HasBeenSent
}



void IPedNodeDataAccessor(bool enable)
{
	*(unsigned int*)0x133D6EC = enable ? 0x4E800020 : 0x7C0802A6;
	*(unsigned int*)0x136752C = enable ? 0x4E800020 : 0x7C0802A6;
}




void CNetObject(bool enable)
{
	*(unsigned int*)0x9F8DE0 = enable ? 0x4E800020 : 0xF821FF91; // GetNetworkObject é usado sim
}


bool ice_o1 = false;
void ice_o(bool enable)
{
	*(unsigned int*)0xA8B690 = enable ? 0x4E800020 : 0x7C0802A6; // sub_A8B690
}


bool sub_freezes1 = false;
void sub_freezes(bool enable)
{
	*(unsigned int*)0x6B342C = enable ? 0x4E800020 : 0x80C60000; // CClonedGoToPointAnyMeansInfo_GoToPointSync - 1 NAO SUB
	*(unsigned int*)0x9D3D84 = enable ? 0x4E800020 : 0x7C0802A6; //registerRawStreamingFile //pantera 2021 - 2 NAO SUB
	*(unsigned int*)0x1367BC0 = enable ? 0x4E800020 : 0x7C0802A6; //sub_1367BC0 = enable ? 0x4E800020 : 0x7C0802A6; privado eu acho rizzex ou algo asim
	*(unsigned int*)0x12C96B4 = enable ? 0x4E800020 : 0x7C0802A6; //sub_12C96B4 freeze loobby do anon
	*(unsigned int*)0xAE5820 = enable ? 0x60000000 : 0x7C0802A6; //jenkinsHash custam crash rizzex
	*(unsigned int*)0x9FBEC4 = enable ? 0x4E800020 : 0x7C0802A6; // sub - # CODE XREF: sub_A00604+C4↓p
	*(unsigned int*)0x1367DCC = enable ? 0x4E800020 : 0x7C0802A6; // sub_1367DCC - # CODE XREF: sub_1367BC0+54↑j //nao sei
	*(unsigned int*)0x13682C0 = enable ? 0x4E800020 : 0x7C0802A6; //sub_13682C0 //terra
	*(unsigned int*)0x1367EF4 = enable ? 0x4E800020 : 0x7C0802A6; //sub_1367EF4 //terra
	*(unsigned int*)0x13678F0 = enable ? 0x4E800020 : 0x7C0802A6; // sub_13678F0 //terra
	*(unsigned int*)0x9FBE10 = enable ? 0x4E800020 : 0x7C0802A6; //sub_9FBE10 //terra
	//*(unsigned int*)0xD97680 = enable ? 0x4E800020 : 0x7C0802A6; //sub_D97680 //pantera 2021 faz o menu desaparecer
}







//void war_location()
//{
//	Vector3 Coords;
//	Coords.x = -15997.0615f;
//	Coords.y = 15675.5517f;
//	Coords.z = 10780.3662f;
//	ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
//	ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), true);
//
//}




bool isTaskCleared = false;
void war_location()
{
	Vector3 Coords;
	Coords.x = -15997.0615f;
	Coords.y = 15675.5517f;
	Coords.z = 10780.3662f;

	if (!isTaskCleared)
	{
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
		ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), true);
		isTaskCleared = true;
	}
	else
	{
		AI::CLEAR_PED_TASKS(PLAYER::PLAYER_PED_ID());
		ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), false);
		isTaskCleared = false;
	}
}

void sunshade_sky_crash() {
	Vector3 coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), -1336.0, -3044.0, 450.0, false, false, false);
	PLAYER::_0x5D382498(PLAYER::PLAYER_ID(), -0x72FD8E8E); // prop_beach_parasol_04 - yes, negative hexadecimal numbers still have the "-" sign in front lol
	AI::TASK_SKY_DIVE(PLAYER::PLAYER_PED_ID());
}

