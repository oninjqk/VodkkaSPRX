//





bool all_write_sync1 = false;
void all_write_sync(bool enable) {
	*(int*)0x9FD36C = enable ? 0x4E800020 : 0x7C0802A6; // rage_netArrayHandlerBase_WriteSyncData
	*(int*)0xA19990 = enable ? 0x4E800020 : 0x7C0802A6; // rage__netHostBroadcastDataHandlerBase_WriteSyncData
	*(int*)0xA8BF68 = enable ? 0x4E800020 : 0x7C0802A6; // WriteSyncDataUint64_post_plus_0xC
	*(int*)0xA8C5C0 = enable ? 0x4E800020 : 0x7C0802A6; // WriteSyncDataString_post_plus_0xC
	*(int*)0xD23384 = enable ? 0x4E800020 : 0x7C0802A6; // SendWriteSyncDataToNpid
	*(int*)0x12BCF8C = enable ? 0x4E800020 : 0x7C0802A6; // CScriptArrayDataVerifyEvent_WriteSyncData
	*(int*)0x12C8640 = enable ? 0x4E800020 : 0x7C0802A6; // CPlayerTauntEvent_WriteSyncData
	*(int*)0x12CEA9C = enable ? 0x4E800020 : 0x7C0802A6; // CScriptEntityStateChangeEvent_WriteSyncData
	*(int*)0x1626844 = enable ? 0x4E800020 : 0x7C0802A6; // WriteSyncDataNetMessageId
	*(int*)0x1626A4C = enable ? 0x4E800020 : 0x7C0802A6; // WriteSyncDataNetMessage_RemoveGamersFromSessionCmd
	*(int*)0x1633B7C = enable ? 0x4E800020 : 0x7C0802A6; // WriteSyncDataNetMessage_snMsgRegisterForMatchRequest
	*(int*)0x1634050 = enable ? 0x4E800020 : 0x7C0802A6; // WriteSyncDataNetMessage_JoinRequest
	*(int*)0x172FF44 = enable ? 0x4E800020 : 0x7C0802A6; // CStartNetworkPedArrestEvent_WriteSyncData_callback
}


bool escreve_saida1 = false;
void escreve_saida(bool enable)
{
	*(unsigned int*)0xA5F438 = enable ? 0x4E800020 : 0x7C0802A6; // rage_msgScriptNewHost_ReadSyncData
	//*(int*)0x1626A4C = enable ? 0x4E800020 : 0x7C0802A6; // WriteSyncDataNetMessage_RemoveGamersFromSessionCmd 
}





void ATTACH_OBJECT_TO_CLIENT(int Client, char* ObjectName, float X = 0, float Y = 0, float Z = 0, float Pitch = 0, float Roll = 0, float Yaw = 0, bool HasPhysics = false)
{
	// Obter o ped do jogador
	int Player = PLAYER::GET_PLAYER_PED(Client);

	// Obter as coordenadas para onde o objeto será criado
	Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Player, X, Y, Z);

	// Criar o objeto
	Hash ObjectHash = GAMEPLAY::GET_HASH_KEY(ObjectName);
	unsigned int Object;
	STREAMING::REQUEST_MODEL(ObjectHash);
	if (STREAMING::HAS_MODEL_LOADED(ObjectHash))
	{
		Object = OBJECT::CREATE_OBJECT(ObjectHash, Coords.x, Coords.y, Coords.z, true, true, false);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(ObjectHash);

		// Anexar o objeto ao jogador
		ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Player, 0, X, Y, Z, Pitch, Roll, Yaw, 1, 0, 0, 1, 2, 1);

		// Se o objeto precisar de física, configurá-lo
		if (HasPhysics)
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Object, true);
			ENTITY::SET_ENTITY_COLLISION(Object, true, false);
		}
	}
}




bool testes_malucos1 = false;
void testes_malucos(bool enable)
{
	*(int*)0x1654A00 = enable ? 0x4E800020 : 0x7C0802A6;//rage_CSyncDataWriter_WriteUshort_size_0xD  -  SYNC TREE notification teste funcionou
}


bool lindona1 = false;
void lindona(bool enable)
{
	//*(int*)0x9F87F4 = enable ? 0x4E800020 : 0x7C0802A6;
	//*(int*)0x3E8F48 = enable ? 0x4E800020 : 0x7C0802A6;
	// *(int*)0x9F87BC = enable ? 0x60000000 : 0xF821FF91;
	*(int*)0x9716D8 = enable ? 0x60000000 : 0xF821FF91;
}


bool MAMAE1 = false;
void MAMAE(bool enable)
{
	*(int*)0x46E30C = enable ? 0x4E800020 : 0x7C0802A6;
	*(int*)0x46E12C = enable ? 0x4E800020 : 0x7C0802A6;
}


bool papai1 = false;
void papai(bool enable)
{
	*(int*)0x9F87F4 = enable ? 0x4E800020 : 0x7C0802A6;
}













//
//namespace PlayerMods {
//    namespace eventCreator {
//        void callScriptEvent(ScriptArg* args, int argsCount, unsigned int playerBits) {
//            SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, argsCount, playerBits);
//        }
//    };
//};
//
//bool depositfreeze = false;
//void givePlayerMoney(int player, int amount) {//refunds to themself. max 20k
//    for (int i = 16; i < amount / 20000 + 16; i++) {
//        ScriptArg args[4];
//        args[0].i = 219;//0xDA = 218;
//        args[1].i = i;//player;//cash giver (them cuz they refund themself)
//        args[2].i = 20000;//46
//        args[3].i = 1;
//        unsigned int bits = (1 << player);//0xFFFFFFFF;
//        PlayerMods::eventCreator::callScriptEvent(args, 4, bits);
//    }
//}
//void Depositfreeze() {
//    static int delay = 0;
//    if (delay < GAMEPLAY::GET_GAME_TIMER()) {
//        givePlayerMoney(int_NetworkOptions[0], 100000000/*0x7FFFFFFF*/);
//        delay = GAMEPLAY::GET_GAME_TIMER() + 250;
//        drawText("~y~Takes About 20 Seconds To Freeze Them! \n Then Turn Option Off!", 0, 0.425, 0.82, 0.29, 0.45, 255, 255, 255, 255, true);
//    }
//}










bool megafree1 = false;
void megafree(bool enable)
{
	*(int*)0xA0F210 = congela ? 0x60000000 : 0x81070020;
	*(int*)0xA0F224 = congela ? 0x60000000 : 0x2C030000;
}


bool naka1 = false;
void naka(bool enable)
{
	*(int*)0x1775F58 = congela ? 0x60000000 : 0x30630810; //rage_netSyncDataNode_WriteArchType
}


bool maca1 = false;
void maca(bool enable)
{
	*(int*)0x1775F68 = congela ? 0x4E800020 : 0x7C0802A6; //rage_netSyncDataNode_WriteArchType
}



bool patinho1 = false;
void patinho(bool enable)
{
	*(int*)0xA17248 = congela ? 0x60000000 : 0x807C0008; // netSyncTree_ReadFromBuffer protecao
}



bool ant_session_invite1 = false;
void ant_session_invite(bool enable)
{
	*(int*)0x3E413C = congela ? 0x60000000 : 0xF821FF91; //
}



bool spoof_failed_sync_error1 = false;
void spoof_failed_sync_error(bool enable)
{
	*(int*)0x158384C = congela ? 0x4E800020 : 0x7C0802A6; //
}


///
bool testedbgl1 = false;
void testedbgl(bool enable)
{
	*(unsigned int*)0xA007B8 = enable ? 0x4E800020 : 0x7C0802A6; //rage__netGameEvent_TimeToResend
}
///

bool disable_phone1 = false;
void disable_phone(bool enable) {
	if (enable) {
		MOBILE::DESTROY_MOBILE_PHONE();
	}
}



bool clone_sync_byme1 = false;
void clone_sync_byme(bool enable)
{
	*(unsigned int*)0xA076FC = enable ? 0x4E800020 : 0x7C0802A6; //UpdateNetworkObject
}


//
////*(int*)0xA17248 =  0x60000000;  // netSyncTree_ReadFromBuffer
//*(int*)0x133B084 = 0x60000000; // sub_133B03C
//*(int*)0x1327674 = 0x60000000; // sub_1327498 - teleport e antimation
//*(int*)0xEE96C4 = 0x60000000; // rizzex me travou com chireta



bool location_spof1 = false;
void location_spof(bool enable)
{
	*(unsigned int*)0xD11D0C = enable ? 0x4E800020 : 0x7C0802A6; //SendReliableCommand - jezani send me this,but this is the root of the function and not the address he sent me
}


bool force_sync1 = false;
void force_sync(bool enable)
{
	*(unsigned int*)0x1160F58 = enable ? 0x4E800020 : 0x7C0802A6; //forceGameState
}


bool patch_frozen_cloud1 = false;
void patch_frozen_cloud(bool enable)
{
	*(unsigned int*)0xA0EF20 = enable ? 0x4E800020 : 0x7C0802A6; //
}



bool raikaza1 = false;
void raikaza(bool enable)
{
	*(unsigned int*)0xA54514 = enable ? 0x60000000 : 0xF821FF91;
}



bool bauza1 = false;
void bauza(bool enable)
{
	*(unsigned int*)0x16545E0 = enable ? 0x4E800020 : 0x7C0802A6;
}








//void freeze_vehicle_protection()
//{
//	int iVar0;
//	int iVar1;
//	var uVar2;
//	int iVar3;
//	int iVar4;
//	int iVar5;
//	bool bVar6;
//
//	if (iLocal_197 < get_game_timer())
//	{
//		iVar0 = 10;
//		iVar1 = 11;
//		uVar2 = 10;
//		iVar3 = get_ped_nearby_vehicles(PLAYER::PLAYER_PED_ID(), &uVar2);
//		iVar4 = 0;
//		if (iVar4 < iVar3)
//		{
//			iVar5 = (iVar4 + 1);
//			if (ENTITY::DOES_ENTITY_EXIST(uVar2.f_[iVar5 * 1]))
//			{
//				bVar6 = true;
//				if (ENTITY::IS_ENTITY_ATTACHED(uVar2.f_[iVar5 * 1]))
//				{
//					if (get_entity_attached_to(uVar2.f_[iVar5 * 1]) == PLAYER::PLAYER_PED_ID())
//					{
//					}
//					else
//					{
//					}
//					if (!0)
//					{
//						bVar6 = false;
//					}
//					if (bVar6)
//					{
//						if (network_request_control_of_entity(uVar2.f_[iVar5 * 1]))
//						{
//							if (network_has_control_of_entity(uVar2.f_[iVar5 * 1]))
//							{
//								network_request_control_of_entity(uVar2.f_[iVar5 * 1]);
//								set_entity_as_mission_entity(uVar2.f_[iVar5 * 1], 0, 1);
//								network_request_control_of_entity(uVar2.f_[iVar5 * 1]);
//								network_request_control_of_entity(uVar2.f_[iVar5 * 1]);
//								network_request_control_of_entity(uVar2.f_[iVar5 * 1]);
//								delete_entity(&(uVar2.f_[iVar5 * 1]));
//								print("Tried Freeze you with Vehicle", 1000);
//							}
//						}
//					}
//					iVar4++;
//					if (!iVar4 < iVar3)
//					{
//						iLocal_197 = (get_game_timer() + 500);
//					}
//
//				}
//			}
//		}
//	}
//}