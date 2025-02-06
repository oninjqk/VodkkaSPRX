

int Hook() {
	notify_attacks();
	sync_tree_protection();
	notify_change_model();
	monitor();
	otherLoop();
	optionCount = 0;
	switch (submenu) {

#pragma region Main Menu
	case main_menu:
		addTitle("V O D K K A");
		addSubmenuOption("Self", self);
		addSubmenuOption("Players", client_list);
		addSubmenuOption("Friends", friend_list);
		addSubmenuOption("Weather", weather);
		addSubmenuOption("Vehicles Spaw", vehicles_list);
		addSubmenuOption("Vehicle Manager", vehicle_manager);
		addSubmenuOption("Crashes", all_freezes);
		addSubmenuOption("Protections", protection);
		addSubmenuOption("Teleports", teleports);
		addSubmenuOption("Recovery", recovery);
		addSubmenuOption("Misc", misc);
		addSubmenuOption("Lobby", lobby);
		addSubmenuOption("Settings", settings);
		addSubmenuOption("InDEV :|", tester);
		addOption("Credits", credits_1);
		break;
#pragma endregion

#pragma region Car Manager
	case vehicle_manager:
		addTitle("MANAGER VEHICLE");
		addOption("Max Upgrade", max_up_car);
		addOption("Fix Vehicle", fix_vehicle);
		addOption("Paint Random", random_paint);
		break;
#pragma endregion

#pragma region Self
	case self:
		addTitle("SELF");
		addSubmenuOption("Change Model", change_model);
		addSubmenuOption("Animations", animations);
		addSubmenuOption("Scenarios", scenarios);
		addSubmenuOption("Walking Style", walkings);
		addSubmenuOption("Weapons", weapons);
		addSubmenuOption("Outfits", closet);
		addBoolOption("Godmode", godmode);
		addBoolOption("No Ragdoll", no_ragdoll);
		addBoolOption("No Target", not_target);
		addBoolOption("Invisibility", invisible);
		addBoolOption("Super Jump", SuperJump);
		addBoolOption("Never Wanted", n_wanted);
		addBoolOption("Off Radar", off_radar);
		addBoolOption("Shrink", shrink);
		break;
#pragma endregion

#pragma region Closet
	case closet:
		addTitle("OUTFITS");
		addSubmenuOption("Male", closet_male);
		addSubmenuOption("Female", closet_female);
		break;
#pragma endregion

#pragma region Closet Male
	case closet_male:
		addTitle("MALE OUTFITS");
		addOption("Outfit 1", outfit_male_1);
		addOption("Outfit 2", outfit_male_2);
		addOption("Outfit 3", outfit_male_3);
		break;
#pragma endregion

#pragma region Closet Female
	case closet_female:
		addTitle("FEMALE OUTFITS");
		addOption("Outfit 1", outfit_female_1);
		addOption("Outfit 2", outfit_female_2);
		addOption("Outfit 3", outfit_female_3);
		break;
#pragma endregion

#pragma region Self
	case change_model:
		addTitle("MODELS");
		addSubmenuOption("Defaults", default_model);
		addSubmenuOption("Invalids", invalid_model);
		addSubmenuOption("Animals", animals_model);
		break;
#pragma endregion

#pragma region Default Models
	case default_model:
		addTitle("DEFAULT MODELS");
		addChangeModel("Default Male", "mp_m_freemode_01");
		addChangeModel("Default Female", "mp_f_freemode_01");
		addChangeModel("Lamar Davis", "ig_lamardavis");
		addChangeModel("Jesus", "u_m_m_jesus_01");
		addChangeModel("Tyler", "ig_tylerdix");
		addChangeModel("Mariachi", "s_m_m_mariachi_01");
		addChangeModel("John Marston", "mp_m_marston_01");
		addChangeModel("Narcotraficante", "g_m_y_strpunk_01");
		addChangeModel("Space", "s_m_m_movspace_01");
		addChangeModel("Fireman", "s_m_y_fireman_01");
		addChangeModel("Nigger", "s_m_y_prismuscl_01");
		addChangeModel("North Cop", "s_m_m_snowcop_01");
		addChangeModel("Statue", "s_m_m_strperf_01");
		break;
#pragma endregion

#pragma region Invalid Models
	case invalid_model:
		addTitle("INVALID MODELS");
		addChangeModel("Player Zero", "player_zero");
		addChangeModel("Player One", "player_one");
		addChangeModel("Player Two", "player_two");
		addChangeModel("Lester  Crest", "ig_lestercrest");
		addChangeModel("Grandmother", "cs_mrs_thornhill");
		addChangeModel("Grandfather", "a_m_o_genstreet_01");
		addChangeModel("Orleans", "ig_orleans");
		addChangeModel("Niko", "mp_m_niko_01");
		addChangeModel("Brad Cadaver", "cs_bradcadaver");
		addChangeModel("Gammer", "cs_mrsphillips");
		addChangeModel("Karen Daniels", "ig_karen_daniels");
		addChangeModel("Imporage", "u_m_y_imporage");
		addChangeModel("Topless Girl", "a_f_y_topless_01");
		addChangeModel("Johnny Klebitz", "ig_johnnyklebitz");
		addChangeModel("Wade", "ig_wade");
		addChangeModel("Mountain Lion", "a_c_mtlion");
		break;
#pragma endregion

#pragma region Animal Models
	case animals_model:
		addTitle("ANIMALS MODELS");
		addChangeModel("Chop", "a_c_chop");
		addChangeModel("Rhesus", "a_c_rhesus");
		addChangeModel("Chimp", "a_c_chimp");
		addChangeModel("Mountain Lion", "a_c_mtlion");
		addChangeModel("Pogo", "u_m_y_pogo_01");
		addChangeModel("Boar", "a_c_boar");
		addChangeModel("Pig", "a_c_pig");
		addChangeModel("Coyote", "a_c_coyote");
		addChangeModel("Husky", "a_c_husky");
		addChangeModel("Retriever", "a_c_retriever");
		addChangeModel("Rottweiler", "a_c_rottweiler");
		addChangeModel("German Shepherd", "a_c_shepherd");
		break;
#pragma endregion

#pragma region Animations
	case animations:
		addTitle("ANIMATIONS");
		addOption("Clear All Tasks", clear_all_tasks);
		addAnimation("Pole Dance", "mini@strip_club@pole_dance@pole_dance1", "pd_dance_01");
		addAnimation("Private Dance", "mini@strip_club@private_dance@part1", "priv_dance_p1");
		addAnimation("Shag 01", "rcmpaparazzo_2", "shag_loop_poppy");
		addAnimation("Shag 02", "rcmpaparazzo_2", "shag_loop_a");
		addAnimation("Idle", "mini@strip_club@idles@stripper", "stripper_idle_04");
		addAnimation("Push Ups", "amb@world_human_push_ups@male@base", "base");
		addAnimation("Sit Ups", "amb@world_human_sit_ups@male@base", "base");
		addAnimation("Celebrate", "rcmfanatic1celebrate", "celebrate");
		addAnimation("Suicide", "mp_suicide", "pistol");
		addAnimation("Electrocute", "ragdoll@human", "electrocute");
		addAnimation("Monkey 01", "missfbi5ig_30monkeys", "monkey_a_freakout_loop");
		addAnimation("Monkey 02", "missfbi5ig_30monkeys", "monkey_b_freakout_loop");
		addAnimation("Guitar", "switch@trevor@guitar_beatdown", "001370_02_trvs_8_guitar_beatdown_idle_busker");
		addAnimation("Fishing", "amb@world_human_stand_fishing@base", "base");
		addAnimation("Crap", "missfbi3ig_0", "shit_loop_trev");
		addAnimation("Zombie", "special_ped@zombie@monologue_1@monologue_1e", "iamundead_4");
		break;
#pragma endregion

#pragma region Scenarios
	case scenarios:
		addTitle("ANIMATIONS");
		addOption("Clear All Tasks", clear_all_tasks);
		addScenario("Play Music", "WORLD_HUMAN_MUSICIAN");
		addScenario("Paparazzi", "WORLD_HUMAN_PAPARAZZI");
		addScenario("Binoculars", "WORLD_HUMAN_BINOCULARS");
		addScenario("Drink", "WORLD_HUMAN_DRINKING");
		addScenario("Play Golf", "WORLD_HUMAN_GOLF_PLAYER");
		addScenario("Lift Weights", "WORLD_HUMAN_MUSCLE_FREE_WEIGHTS");
		addScenario("Smoke Pot", "WORLD_HUMAN_SMOKING_POT");
		addScenario("Handyman", "WORLD_HUMAN_HAMMERING");
		addScenario("Yoga", "WORLD_HUMAN_YOGA");
		addScenario("Flex Muscles", "WORLD_HUMAN_MUSCLE_FLEX");
		addScenario("Mechanic", "WORLD_HUMAN_VEHICLE_MECHANIC");
		addScenario("Welding", "WORLD_HUMAN_WELDING");
		addScenario("Cheering", "WORLD_HUMAN_CHEERING");
		addScenario("Hold Clipboard", "WORLD_HUMAN_CLIPBOARD");
		addScenario("Drill", "WORLD_HUMAN_CONST_DRILL");
		addScenario("Deal Drugs", "WORLD_HUMAN_DRUG_DEALER");
		addScenario("Gardener Leaf Blower", "WORLD_HUMAN_GARDENER_LEAF_BLOWER");
		addScenario("Gardener Plant", "WORLD_HUMAN_GARDENER_PLANT");
		addScenario("Guard Patrol", "WORLD_HUMAN_GUARD_PATROL");
		addScenario("Guard Stand", "WORLD_HUMAN_GUARD_STAND");
		addScenario("Human Statue", "WORLD_HUMAN_HUMAN_STATUE");
		addScenario("Maid Clean", "WORLD_HUMAN_MAID_CLEAN");
		addScenario("Partying", "WORLD_HUMAN_PARTYING");
		addScenario("Picnic", "WORLD_HUMAN_PICNIC");
		addScenario("Prostitute Low Class", "WORLD_HUMAN_PROSTITUTE_LOW_CLASS");
		addScenario("Prostitute High Class", "WORLD_HUMAN_PROSTITUTE_HIGH_CLASS");
		addScenario("Shine Torch", "WORLD_HUMAN_SECURITY_SHINE_TORCH");
		addScenario("Sunbathe", "WORLD_HUMAN_SUNBATHE");
		addScenario("Sunbathe Back", "WORLD_HUMAN_SUNBATHE_BACK");
		addScenario("Superhero", "WORLD_HUMAN_SUPERHERO");
		addScenario("Swimming", "WORLD_HUMAN_SWIMMING");
		addScenario("Play Tennis", "WORLD_HUMAN_TENNIS_PLAYER");
		addScenario("Tourist Holding Map", "WORLD_HUMAN_TOURIST_MAP");
		addScenario("BBQ", "PROP_HUMAN_BBQ");
		break;
#pragma endregion

#pragma region Walkings
	case walkings:
		addTitle("WALKING STYLES");
		ChangeWalkingType("Generic Male", "move_m@generic");
		ChangeWalkingType("Generic Female", "move_f@generic");
		ChangeWalkingType("Injured Male", "move_m@injured");
		ChangeWalkingType("Drunk Very Drunk", "move_m@drunk@verydrunk");
		ChangeWalkingType("Fat Male A", "move_m@fat@a");
		ChangeWalkingType("Film Reel Female", "move_f@film_reel");
		ChangeWalkingType("Business Male A", "move_m@business@a");
		ChangeWalkingType("Hiking", "move_m@hiking");
		break;
#pragma endregion

#pragma region Weapons
	case weapons:
		addTitle("WEAPONS");
		addOption("Give All Weapons", give_weapons);
		addBoolOption("Infinite Ammo", ammo);
		addBoolOption("Rapid Fire", RAPID_FIRE);
		break;
#pragma endregion

#pragma region Client list
	case client_list:
		addTitle("CLIENT LIST");
		for (int i = 0; i < 18; i++) {
			char* playerName = PLAYER::GET_PLAYER_NAME(i);
			char NameBuffer[30];
			if (!NETWORK::NETWORK_IS_PLAYER_ACTIVE(i)) {
				sprintf(NameBuffer, "*offline*");
				playerName = NameBuffer;
			}

			addOption(playerName);
		}
		if (optionPress) {
			selectedPlayer = currentOption - 1;
			changeSubmenu(client_options);
		}
		break;
#pragma endregion


#pragma region Friends
	case friend_list:
		addTitle("FRIEND LIST");

		GAMEPLAY::NETWORK_SET_SCRIPT_IS_SAFE_FOR_NETWORK_GAME();

		int friendCount = NETWORK::NETWORK_GET_FRIEND_COUNT();
		for (int i = 0; i < friendCount; i++) {
			char friendName[30];
			strcpy(friendName, NETWORK::NETWORK_GET_FRIEND_NAME2(i));
			addOption(friendName);
		}

		if (optionPress) {
			if (currentOption > 0) {
				selectedPlayer = currentOption - 1;
				if (selectedPlayer >= 0) {
					changeSubmenu(friend_options);
				}
			}
		}
		break;
#pragma endregion



#pragma region Friend Options
	case friend_options:
		if (selectedPlayer >= 0) {
			char* playerName = NETWORK::NETWORK_GET_FRIEND_NAME2(selectedPlayer);
			addTitle(playerName);
			addOption("InvitePlayer");
		}

		if (optionPress) {
			if (selectedPlayer >= 0) {
				char* playerName = NETWORK::NETWORK_GET_FRIEND_NAME2(selectedPlayer);
				printf("sending invite to: %s\n", playerName); //print but freeze aaaaa
				int invitePlayer = 0x139ECB0;
				char buffer[0x100] = {};
				WriteBytes(0x1004004C, buffer, sizeof(buffer));
				WriteString(0x1004004C + 8, playerName);
				((void(*)(int, unsigned int, int, int, int, int, int, int, int)) & invitePlayer)(
					0x40022280,
					0x1004004C,
					1, 0, 0, 0,
					0x540, 0x4ec, 0x59 
					);
			}
		}
		break;
#pragma endregion




#pragma region Client Options
	case client_options:
		addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		consulta(true);
		//PlayerInfoMenuBase(true);
		draw_box_and_head_marker(selectedPlayer);
		addSubmenuOption("Player Options", good_options);
		addSubmenuOption("Forces", forces);
		addOption("Teleport To Client", []() {
			teleport_to_client((PLAYER::GET_PLAYER_PED(selectedPlayer)));
			});
		addOption("Host Kick", []() {
			host_kick(selectedPlayer);
			});
		addOption("Non Host Kick", []() {
			non_host_kick(selectedPlayer);
			});
		addOption("Vote Kick", vote_kick);
		addOption("Teleport Client To Me", []() {
			Vector3 tmp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 1.3, 0.0);
			teleport_client_to_me(PLAYER::GET_PLAYER_PED(selectedPlayer), "missfbi5ig_30monkeys", "monkey_a_freakout_loop", tmp.x, tmp.y, tmp.z);
			});
		break;
#pragma endregion


#pragma region Good Options
	case good_options:
		addTitle("Good Options");
		addBoolOption("Give 40k Money(Loop)", net_40k);
		addOption("Give Weapons", []() {
			GiveAllWeapons(selectedPlayer);
			});
		addOption("Take Weapons", TakeWeaponsClient);
		addOption("Try Water Kill", []() {
			freeze_teleport(selectedPlayer);
			});
		addOption("Cage", bota_jaula);
		addOption("Break Object Crash", freeze_objc_break);
		addBoolOption("DogStyle", comida_online1, comida_online);
		addBoolOption("BlowJob", mamada_online1, mamada_online);
		addOption("Explosion", ExplodePlayer);
		break;
#pragma endregion






#pragma region Forces
	case forces:
		addTitle("FORCE TO...");
		addOption("Fakeleave", []() {
			make_fakeleave(selectedPlayer);
			}); //fake leave
		addOption("Golf", []() {
			force_to_golf(selectedPlayer);
			}); //job
		addOption("Dardos", []() {
			force_dardos(selectedPlayer);
			}); //job
		addOption("Match", []() {
			force_partida(selectedPlayer, selectedPlayer);
			});
		addOption("Arm Wrestling", []() {
			force_queda_de_braco(selectedPlayer);
			});
		addOption("Hospital Bill", []() {
			send_to_bad_sport(selectedPlayer);
			}); //hospital bill
		addOption("Tutorial", []() {
			send_to_tutorial(selectedPlayer);
			}); //cutscene
		addOption("Reset View", []() {
			reset_selectedPlayer_view(selectedPlayer);
			}); //reset view
		addOption("Apartment", []() {
			apartment_invite2(selectedPlayer, selectedPlayer, 10);
			}); //apartment
		addOption("Aparment Loop", []() {
			selectedPlayerProperty(selectedPlayer, 0, 0, 0);
			}); //apartment
		addOption("Give Money", []() {
			give_money(selectedPlayer);
			}); //money
		break;
#pragma endregion


#pragma region Teleports
	case teleports:
		addTitle("TELEPORT");
		addOption("Waypoint", TPtoWaypoint);
		addOption("2 Meters Forward", Move2MetersForward);
		addOption("2 Meters Up", Move2MetersUp);
		addOption("Teleport to Nearest Car", toNearestCar);
		addOption("Maze Bank", TPtoMazeBank);
		addOption("Main Airport", TPtoMainAirport);
		addOption("Control Tower", TPtoControlTower);
		addOption("Mount Chilliad", TPtoMountChilliad);
		addOption("Fort Zancudo", TPtoFortZancudo);
		addOption("LS Customs", TPtoLSCustoms);
		addOption("Mask Shop", TPtoMaskShop);
		addOption("Clothes Store", TPtoClothesStore);
		addOption("Ammunation", TPtoAmmunation);
		addOption("Outside Garage", TPtoOutsideGarage);
		addOption("Inside FIB Building", TPtoInsideFIBBuilding);
		addOption("Inside Fort Tower", TPtoInsideFortTower);
		addOption("Car Impound", TPtoCarImpound);
		addOption("Mors Mutual Impound", TPtoMorsMutualImpound);
		addOption("Sandy Shores Airfield", TPtoSandyShoresAirfield);
		addOption("Waterfall Hangout", TPtoWaterfallHangout);
		break;
#pragma endregion

#pragma region Freezes
	case all_freezes:
		addTitle("CRASHES");
		addSubmenuOption("Crashes :)", freezes);
		addOption("Invalid Water(HOST)", invalid_water);
		addOption("Invalid Hight(HOST)", invalid_hight);
		addOption("Fast Respaw", kill_ped);
		addOption("Sunshade Sky Crash", sunshade_sky_crash);
		addOption("Love Location <3", war_location);
		addBoolOption("Random Weather", random_weather);
		addBoolOption("RP Spam", spam);
		addBoolOption("Message Spam", loop_message);
		break;
#pragma endregion

#pragma region Lobby
	case lobby:
		addTitle("LOBBY");
		addBoolOption("Clear Area", clear_area_loop);
		addSubmenuOption("Disable Shits ->", disable_protection);
		break;
#pragma endregion

#pragma region Protecion
	case disable_protection:
		addTitle("Disable Shits");
		addBoolOption("Call", block_call1, block_call);
		addBoolOption("Ant Time Out", ant_time_out1, ant_time_out);
		addBoolOption("Phone", disable_phone1, disable_phone);
		addBoolOption("Prints", block_prints1, block_prints);
		addBoolOption("Session Error", spoof_failed_sync_error1, spoof_failed_sync_error);
		addBoolOption("Ped Texture", s_boneco1, s_boneco);
		addBoolOption("Map Texture", s_mapa1, s_mapa);
		addBoolOption("Vehicle Texture", vehicle_texture1, vehicle_texture);
		addBoolOption("Jobs", hide_missions1, hide_missions);
		break;
#pragma endregion

#pragma region crashes
	case freezes:
		addTitle("CRASHES");
		addBoolOption("No Russian", deportation_bag, Deportation_bag); //Abschiebetasche xd
		addBoolOption("Boolean", sync_boolean, Boolean);
		addBoolOption("Brodcast Data", brodcast_data, BrodcastData);
		addBoolOption("PirataPutaV1", pirata_v2_1, pirata_v2);
		addBoolOption("Ice(fuck sync)", ice_o1, ice_o);
		addBoolOption("Hextic v3", sync_tree_buff, SyncTreeBuff);
		addBoolOption("String", sync_string, String);
		addBoolOption("Base Node", base_node, BaseNode);
		addBoolOption("Tree Base", tree_base, TreeBase);
		addBoolOption("Short Write", testes_malucos1, testes_malucos);
		addBoolOption("Arrays", Arrays1, Arrays);
		addBoolOption("Script ID", script_id, ScriptID);
		addBoolOption("Interager", interager, Interager);
		addBoolOption("Bytes", sync_byte, Byte);
		addBoolOption("Resend", testedbgl1, testedbgl);
		addOption("!!!!!!!!!!!!!!!!!"); //dubious addresses...
		addBoolOption("52C", iped_node_data_accessor, IPedNodeDataAccessor);
		addBoolOption("RANDOM ADRESS", sub_freezes1, sub_freezes);
		addBoolOption("SENDED RZX", eu641, eu64);
		addBoolOption("PirataPutaV2Free", putinhav1, putinhav);
		break;
#pragma endregion

#pragma region protection
	case protection:
		addTitle("PROTECTIONS");
		addBoolOption("SMS", ant_sms1, ant_sms);
		addBoolOption("Freeze Host", ant_freeze_host1, ant_freeze_host);
		addBoolOption("Entities/Big Vehicles ", block_entities1, block_entities);
		addBoolOption("Weather", ant_clima1, ant_clima);
		addBoolOption("Freeze v3", ant_freeze_v31, ant_freeze_v3);
		addBoolOption("Vegetal(fuck session)", vejetal1, vejetal);
		addBoolOption("Tool Session", tool_session1, tool_session);
		addBoolOption("All Events", all_events1, all_events);
		addBoolOption("Change Name", ant_invalid1, ant_invalid); //**invalid**
		addBoolOption("Hextic Patch", patch_hextic1, patch_hextic);
		addBoolOption("Cloud", patch_frozen_cloud1, patch_frozen_cloud);
		addBoolOption("Spoof Loc", location_spof1, location_spof);
		addBoolOption("Clone Sync By Me(stg)", clone_sync_byme1, clone_sync_byme);
		addBoolOption("OtherCloneSync", CLONE_SYNC1, CLONE_SYNC);
		addBoolOption("AMOR EMBALAVEL", joana1, joana);
		addBoolOption("Block SH Migration", block_change_sh1, block_change_sh);
		addBoolOption("Block Data/Sync", congela_mapa1, congela_mapa);
		break;
#pragma endregion


#pragma region weather
	case weather:
		addTitle("WEATHER");
		addOption("+1 Hour", []() {
			int h = TIME::GET_CLOCK_HOURS();
			h = (h == 23) ? 0 : h + 1;
			NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(h, TIME::GET_CLOCK_MINUTES(), 0);
			});
		addOption("Set Noon", []() {
			NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(12, 0, 0);
			});
		addOption("Real Snow", set_weather_xmas);
		addOption("Snowing", set_weather_snow);
		addOption("Blizzard", set_weather_blizzard);
		addOption("Light Snow", set_weather_snowlight);
		addOption("Green Sky", set_weather_neutral);
		addOption("Sunny", set_weather_extrasunny);
		addOption("Clear", set_weather_clear);
		addOption("Cloudy", set_weather_clouds);
		addOption("Foggy", set_weather_foggy);
		addOption("Stormy", set_weather_thunder);
		addOption("OverCast", set_weather_overcast);
		addOption("Set Midnight", []() {
			NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(0, 0, 0);
			});
		addOption("-1 Hour", []() {
			int h = TIME::GET_CLOCK_HOURS();
			h = (h == 0) ? 23 : h - 1;
			NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(h, TIME::GET_CLOCK_MINUTES(), 0);
			});
		break;
#pragma endregion


#pragma region misc
	case misc:
		addTitle("MISC");
		addSubmenuOption("Map Loader", map_loader);
		addOption("Clone Ped", ClonePedAndExecute);
		addBoolOption("Mosties", away_water);
		addBoolOption("2D Mod", WeeslysDankHax);
		addBoolOption("Rainbow Menu", rainbow_menu);
		addOption("Force Save(dev)", force_save);
		addOption("No Shadows", _no_shadow);
		addBoolOption("CrazyScreenV1", FunyScreen1, FunyScreen);
		addBoolOption("CrazyScreenV2", funny_screen_2_1, funny_screen_2);
		addBoolOption("Slow", slow);
		addBoolOption("ponta cabeza", pontadas);
		break;
#pragma endregion

#pragma region Script Loader
	case load_script:
		addTitle("LOADER");
		addBoolOption("Api II Intense", load_unload_ap_intense1, load_unload_ap_intense); //it was working in addOption but I managed to mess it up by trying to put it in addBoolOption : /
		break;
#pragma endregion

#pragma region recovery
	case recovery:
		addTitle("RECOVERY");
		addSubmenuOption("Money ->", money);
		addSubmenuOption("Rank ->", ranks);
		addOption("Max Skills", skills);
		addOption("Tatoos", tatoos);
		addOption("Max Snacks", snacks);
		addOption("Armor", armor);
		addOption("Fireworks", fireworks);
		addOption("Camos", camos);
		addOption("Hairs", hair);
		addOption("Los Santos Custom", los_santos_custom);
		addOption("All Trophies", trophies);
		addOption("Fast Run", fast_run);
		addOption("Modd Roll", modd_roll);
		break;
#pragma endregion

#pragma region Money
	case money:
		addTitle("MONEY");
		addOption("Give 1M", cash_1m);
		addOption("Give 10M", cash_10m);
		addOption("Remove 10M", cash_10m_remove);
		addOption("Remove 50M", cash_50m_remove);
		break;
#pragma endregion

#pragma region rank
	case ranks:
		addTitle("RANK");
		addOption("Rank 120", rank_120);
		addOption("Rank 500", rank_500);
		break;
#pragma endregion

#pragma region vehicle list
	case vehicles_list:
		addTitle("VEHICLE");
		addSubmenuOption("Super Cars", Super);
		addSubmenuOption("Sports Cars", Sports);
		addSubmenuOption("Classics Cars", Classics);
		addSubmenuOption("Muscle Cars", Muscle);
		addSubmenuOption("Sedans", Sedans);
		addSubmenuOption("Coupes", Coupes);
		addSubmenuOption("Compact Wagen", Compaktwagen);
		addSubmenuOption("SUV and Pickups", SUV_Pickups);
		addSubmenuOption("Trucks", Trucks);
		addSubmenuOption("Vans", Vans);
		addSubmenuOption("Off Road", Off_Road);
		addSubmenuOption("Aircrafts", Aircrafts);
		addSubmenuOption("Emergency Vehicles", Emergency);
		addSubmenuOption("Service Vehicles", Service_Vehicles);
		addSubmenuOption("Military Vehicles", Military);
		addSubmenuOption("Motorcycles", Motorcycles);
		addSubmenuOption("Bicycles", Bicycles);
		addSubmenuOption("Commercial Vehicles", Commercial_Vehicles);
		addSubmenuOption("Boats", Boats);
		addSubmenuOption("Trailers", Trailers);
		addSubmenuOption("Heist", Heist);
		break;
#pragma endregion

#pragma region Super
	case Super:
		addTitle("SUPER");
		addVehicle("Adder", "adder");
		addVehicle("Bullet", "bullet");
		addVehicle("Cheetah", "cheetah");
		addVehicle("Entity XF", "ENTITYXF");
		addVehicle("Infernus", "infernus");
		addVehicle("Turismo", "turismor");
		addVehicle("Vacca", "vacca");
		addVehicle("Voltic", "voltic");
		addVehicle("Osiris", "osiris");
		addVehicle("Zentorno", "zentorno");
		addVehicle("Progen T20", "t20");
		break;
#pragma endregion

#pragma region Sports
	case Sports:
		addTitle("SPORTS");
		addVehicle("Annis Elegy RH8", "elegy2");
		addVehicle("Hijak Khamelion", "khamelion");
		addVehicle("Grotti Carbonizzare ", "carbonizzare");
		addVehicle("Benefactor Feltzer 1", "feltzer2");
		addVehicle("Benefactor Feltzer 2 ", "feltzer3");
		addVehicle("Dewbauchee Rapid GT 1 ", "rapidgt");
		addVehicle("Dewbauchee Rapid GT 2", "rapidgt2");
		addVehicle("Inverto Coquette 1", "coquette");
		addVehicle("Obey 9F Cabrio ", "ninef");
		addVehicle("Obey 9F", "ninef2");
		addVehicle("Benefactor Surano", "surano");
		addVehicle("Bravado Banshee", "banshee");
		addVehicle("Pfister Comet", "comet");
		addVehicle("Benefactor Schwartzer", "schwarzer");
		addVehicle("Schyster Fusilade", "fusilade");
		addVehicle("Bravado Buffalo", "buffalo");
		addVehicle("Bravado Buffalo 2", "buffalo2");
		addVehicle("Maibatsu Penumbra", "penumbra");
		addVehicle("Karin Sultan", "sultan");
		addVehicle("Karin Futo", "futo");
		addVehicle("Lampadati Furore GT", "furoregt");
		addVehicle("Dewbauchee Massacro 1", "massacro");
		addVehicle("Dewbauchee Massacro 2", "massacro2");
		addVehicle("Dinka Jester 1", "jester");
		addVehicle("Dinka Jester 2", "jester2");
		addVehicle("Enus Windsor", "windsor");
		addVehicle("Albany Alpha", "alpha");
		addVehicle("Karin Kuruma 1", "kuruma");
		addVehicle("Karin Kuruma 2", "kuruma2");
		break;
#pragma endregion

#pragma region Classics
	case Classics:
		addTitle("CLASSICS");
		addVehicle("Inverto Coquette 2", "coquette2");
		addVehicle("Inverto Coquette 3", "coquette3");
		addVehicle("Truffade Z-Type", "ztype");
		addVehicle("Grotti Stinger GT", "stingergt");
		addVehicle("Grotti Stinger", "stinger");
		addVehicle("Pegassi Monroe", "monroe");
		addVehicle("Dewbauchee JB 700", "jb700");
		addVehicle("Declasse Tornado 1", "tornado");
		addVehicle("Declasse Tornado 2", "tornado2");
		addVehicle("Declasse Tornado 3", "tornado3");
		addVehicle("Declasse Tornado 4", "tornado4");
		addVehicle("Vapid Peyote", "peyote");
		addVehicle("Albany Manana", "manana");
		addVehicle("Albany Virgo", "virgo");
		addVehicle("Albany Roosevelt", "btype");
		addVehicle("Vapid Blade", "blade");
		addVehicle("Benefactor Glendale", "glendale");
		addVehicle("Lampadati Pigalle", "pigalle");
		addVehicle("Lampadati Casco", "casco");
		addVehicle("Vapid Chino", "chino");
		break;
#pragma endregion

#pragma region Muscle
	case Muscle:
		addTitle("MUSCLE");
		addVehicle("Vapid Hotknife", "hotknife");
		addVehicle("Bravado Gauntlet", "gauntlet");
		addVehicle("Declasse Vigero", "vigero");
		addVehicle("Vapid Dominator", "dominator");
		addVehicle("Albany Buccaneer", "buccaneer");
		addVehicle("Imponte Phoenix", "phoenix");
		addVehicle("Declasse Sabre Turbo", "sabregt");
		addVehicle("Imponte Ruiner", "ruiner");
		addVehicle("Declasse Voodoo", "voodoo2");
		addVehicle("Cheval Picador", "picador");
		addVehicle("Rat Loader 1", "ratloader");
		addVehicle("Rat Loader 2", "ratloader2");
		break;
#pragma endregion

#pragma region Sedans
	case Sedans:
		addTitle("SEDANS");
		addVehicle("Enus Super Diamond", "superd");
		addVehicle("Ubermacht Oracle I", "oracle");
		addVehicle("Ubermacht Oracle II", "oracle2");
		addVehicle("Dundreary Stretch", "stretch");
		addVehicle("Cheval Fugitive", "fugitive");
		addVehicle("Cheval Surge", "surge");
		addVehicle("Benefactor Schafter", "schafter2");
		addVehicle("Karin Asterope", "asterope");
		addVehicle("Karin Intruder", "intruder");
		addVehicle("Albany Washington", "washington");
		addVehicle("Vapid Stanier", "stanier");
		addVehicle("Vulcan Ingot", "ingot");
		addVehicle("Albany Emperor I", "emperor");
		addVehicle("Albany Emperor II", "emperor2");
		addVehicle("Albany Emperor III", "emperor3");
		addVehicle("Albany Primo", "primo");
		addVehicle("Dundreary Regina", "regina");
		addVehicle("Chariot Romero Hearse", "romero");
		addVehicle("Obey Tailgater", "tailgater");
		addVehicle("Declasse Premier", "premier");
		addVehicle("Zirconium Stratum", "stratum");
		addVehicle("Declasse Asea I", "asea");
		addVehicle("Declasse Asea II", "asea2");
		break;
#pragma endregion

#pragma region Coupes
	case Coupes:
		addTitle("COUPES");
		addVehicle("Dewbauchee Exemplar", "exemplar");
		addVehicle("Enus Cognoscenti Cabrio", "cogcabrio");
		addVehicle("Lampadati Felon GT", "felon2");
		addVehicle("Lampadati Felon,", "felon");
		addVehicle("Ubermacht Zion Cabri", "zion");
		addVehicle("Ubermacht Zion", "zion2");
		addVehicle("Ubermacht Sentinel XS", "sentinel");
		addVehicle("Ubermacht Sentinel", "sentinel2");
		addVehicle("Ocelot F620", "f620");
		addVehicle("Ocelot Jackal", "jackal");
		break;
#pragma endregion

#pragma region Compaktwagen
	case Compaktwagen:
		addTitle("COMPACT WAGEN");
		addVehicle("Karin Dilettante I", "dilettante");
		addVehicle("Karin Dilettante II", "dilettante2");
		addVehicle("Weeny Issi", "issi2");
		addVehicle("Bollokan Prairie", "prairie");
		addVehicle("Dinka Blista", "blista");
		addVehicle("Declasse Rhapsody", "rhapsody");
		addVehicle("Vulcar Warrener", "warrener");
		addVehicle("Benefactor Panto", "panto");
		break;
#pragma endregion

#pragma region SUV Pickups
	case SUV_Pickups:
		addTitle("SUV & PICKUPS");
		addVehicle("Gallivanter Baller 1", "baller");
		addVehicle("Gallivanter Baller 2", "baller2");
		addVehicle("Obey Rocoto", "rocoto");
		addVehicle("Albany Cavalcade 1", "cavalcade");
		addVehicle("Albany Cavalcade 2", "cavalcade2");
		addVehicle("Benefactor Dubsta 1", "dubsta");
		addVehicle("Benefactor Dubsta 2", "dubsta2");
		addVehicle("Benefactor Dubsta 3", "dubsta3");
		addVehicle("Benefactor Serrano", "serrano");
		addVehicle("Dundreary Landstalker", "landstalker");
		addVehicle("Fathom FQ 2", "fq2");
		addVehicle("Mammoth Patriot", "patriot");
		addVehicle("Emperor Habanero", "habanero");
		addVehicle("Vapid Radius", "radi");
		addVehicle("Declasse Granger", "granger");
		addVehicle("Canis Mesa 1", "mesa");
		addVehicle("Canis Mesa 2", "mesa2");
		addVehicle("Canis Seminole", "seminole");
		addVehicle("Canis Kalahari", "kalahari");
		addVehicle("Bravado Gresley", "gresley");
		addVehicle("Karin BeeJay XL", "bjxl");
		addVehicle("Enus Huntley", "huntley");
		addVehicle("Sadler 1", "sadler");
		addVehicle("Sadler 2", "sadler2");
		addVehicle("Vapid Guardian", "guardian");
		addVehicle("HVY Insurgent 1", "insurgent2");
		addVehicle("HVY Insurgent 2", "insurgent");
		addVehicle("Karin Technical", "technical");
		break;
#pragma endregion

#pragma region Trucks
	case Trucks:
		addTitle("TRUCKS");
		addVehicle("Monster Truck", "monster");
		addVehicle("Vapid Sandking XL", "sandking");
		addVehicle("BF Dune Buggy", "dune");
		addVehicle("BF Dune 2 (Space Docker)", "dune2");
		addVehicle("BF Injection", "bfinjection");
		addVehicle("BF Bifta", "bifta");
		addVehicle("Nagasaki Blazer 1", "blazer");
		addVehicle("Nagasaki Blazer 2 (Trevors)", "blazer3");
		addVehicle("Canis Mesa (Merryweather", "mesa3");
		addVehicle("Vapid Sandking SWB", "sandking2");
		addVehicle("Bravado Duneloader", "dloader");
		addVehicle("Canis Bodhi", "bodhi2");
		addVehicle("Declasse Rancher XL 1", "rancherxl");
		addVehicle("Declasse Rancher XL 2", "rancherxl2");
		addVehicle("Karin Rebel 1", "rebel");
		addVehicle("Karin Rebel 2", "rebel2");;
		addVehicle("Nagasaki Blazer Lifeguard", "blazer2");
		addVehicle("Coil Brawler", "brawler");
		addVehicle("Dinka Enduro", "enduro");;
		break;
#pragma endregion

#pragma region Vans
	case Vans:
		addTitle("VANS");
		addVehicle("Bravado Bison 1", "bison");
		addVehicle("Bravado Bison 2", "bison2");
		addVehicle("Bravado Bison 3", "bison3");
		addVehicle("Bravado Paradise", "paradise");
		addVehicle("Zirconium Journey", "journey");
		addVehicle("Vapid Minivan", "minivan");
		addVehicle("Vapid Bobcat XL", "bobcatxl");
		addVehicle("Bravado Rumpo 1", "rumpo");
		addVehicle("Bravado Rumpo 2", "rumpo2");
		addVehicle("Brute Pony 1", "pony");
		addVehicle("Brute Pony 2", "pony2");
		addVehicle("Declasse Burrito 1", "burrito");
		addVehicle("Declasse Burrito 2", "burrito2");
		addVehicle("Declasse Burrito 3", "burrito3");
		addVehicle("Declasse Burrito 4", "burrito4");
		addVehicle("Declasse Burrito 5", "burrito5");
		addVehicle("Declasse Burrito 6", "burrito6");
		addVehicle("Declasse Burrito 7", "burrito7");
		addVehicle("Vapid Speedo 1", "speedo");
		addVehicle("Vapid Speedo 2", "speedo2");
		addVehicle("Bravado Youga", "youga");
		addVehicle("Boxville 1", "boxville");
		addVehicle("Boxville 2", "boxville2");
		addVehicle("Boxville 3", "boxville3");
		addVehicle("Boxville 4", "boxville4");
		addVehicle("Brute Camper", "camper");
		addVehicle("Taco Van", "taco");
		addVehicle("BF Surfer", "surfer");
		addVehicle("BF Surfer (Rusted)", "surfer2");
		addVehicle("Vapid Slamvan 1", "slamvan");
		addVehicle("Vapid Slamvan 2", "slamvan2");
		break;
#pragma endregion

#pragma region Off Road
	case Off_Road:
		addTitle("OFF ROAD");
		addVehicle("Brawler", "brawler");
		addVehicle("Dune Buggy", "dune");
		addVehicle("Liberator", "monster");
		addVehicle("Sanchez", "sanchez");
		break;
#pragma endregion
#pragma region Aircrafts

	case Aircrafts:
		addTitle("AIRCRAFTS");
		addVehicle("Big Cargo Plane", "cargoplane");
		addVehicle("Annihilator", "annihilator");
		addVehicle("Buzzard", "buzzard");
		addVehicle("Cargobob", "cargobob");
		addVehicle("Maverick", "maverick");
		addVehicle("Skylift", "skylift");
		addVehicle("Trevor's Cargobob", "cargobob3");
		addVehicle("Mammatus", "mammatus");
		addVehicle("Luxor", "luxor");
		addVehicle("Lazer", "lazer");
		addVehicle("Miljet", "miljet");
		addVehicle("Titan", "titan");
		addVehicle("Vestra", "vestra");
		addVehicle("Mallard", "stunt");
		addVehicle("Frogger", "frogger");
		addVehicle("Swift", "swift");
		addVehicle("Besra", "besra");
		addVehicle("Shamal", "shamal");
		addVehicle("Cuban 800", "cuban800");
		addVehicle("Duster", "duster");
		addVehicle("Velum", "velum");
		addVehicle("Atomic Blimp", "blimp");
		break;
#pragma endregion

#pragma region Emergency
	case Emergency:
		addTitle("EMERGENCY");
		addVehicle("FIB", "fbi");
		addVehicle("FIB SUV", "fbi2");
		addVehicle("Firetruck", "firetruk");
		addVehicle("Ambulance", "ambulance");
		addVehicle("Police 1", "police");
		addVehicle("Police 2", "police2");
		addVehicle("Police 3", "police3");
		addVehicle("Police 4", "police4");
		addVehicle("Police Bike", "policeb");
		addVehicle("Police Old 1", "policeold1");
		addVehicle("Police Old 2", "policeold2");
		addVehicle("Police Van", "policet");
		addVehicle("Swat Truck", "riot");
		addVehicle("Sheriff 1", "sheriff");
		addVehicle("Sheriff 2", "sheriff2");
		addVehicle("Prison Bus", "pbus");
		addVehicle("Park Ranger", "pranger");
		addVehicle("Life Guard SUV", "lguard");
		break;
#pragma endregion

#pragma region Service_Vehicles
	case Service_Vehicles:
		addTitle("SERVICE VEHICLES");
		addVehicle("Airport Bus", "airbus");
		addVehicle("Dashhound", "coach");
		addVehicle("Bus", "bus");
		addVehicle("Rental Shuttle Bus", "rentalbus");
		addVehicle("Tour Bus", "tourbus");
		addVehicle("Taxi", "taxi");
		break;
#pragma endregion

#pragma region Military
	case Military:
		addTitle("MILITARY");
		addVehicle("Rhino Tank", "rhino");
		addVehicle("Barracks 1", "barracks");
		addVehicle("Barracks 2", "barracks2");
		addVehicle("Barracks 3 ", "barracks3");
		addVehicle("Canis Crusader", "crusader");
		addVehicle("Tanker 1", "tanker");
		addVehicle("Tanker 2", "tanker2");
		break;
#pragma endregion

#pragma region Motorcycles
	case Motorcycles:
		addTitle("MOTOCYCLES");
		addVehicle("Nagasaki Carbon RS", "carbonrs");
		addVehicle("Pegassi Bati 801", "bati2");
		addVehicle("LCC Hexer", "hexer");
		addVehicle("LCC Innovation", "innovation");
		addVehicle("Dinka Double-T", "double");
		addVehicle("Dinka Thrust", "thrust");
		addVehicle("Dinka Vindicator", "vindicator");
		addVehicle("Pegassi Ruffian", "ruffian");
		addVehicle("Shitzu Vader", "vader");
		addVehicle("Shitzu PCJ 600", "pcj");
		addVehicle("Shitzu Hakuchou", "hakuchou");
		addVehicle("Dinka Akuma", "akuma");
		addVehicle("Maibatsu Sanchez (Decal)", "sanchez");
		addVehicle("Maibatsu Sanchez", "sanchez2");
		addVehicle("Pegassi Faggio", "faggio2");
		addVehicle("Western Daemon", "daemon");
		addVehicle("Western Bagger", "bagger");
		addVehicle("Principe Nemesis", "nemesis");
		addVehicle("Sovereign", "sovereign");
		addVehicle("Principe Lectro", "lectro");
		break;
#pragma endregion

#pragma region Bicycles
	case Bicycles:
		addTitle("BICYCLES");
		addVehicle("Whippet Race Bike", "tribike");
		addVehicle("Tri-Cycles Race Bike", "tribike3");
		addVehicle("Scorcher", "scorcher");
		addVehicle("Endurex Race Bike", "tribike2");
		addVehicle("Cruiser", "cruiser");
		addVehicle("BMX", "bmx");
		addVehicle("Fixter", "fixter");
		break;
#pragma endregion

#pragma region Commercial_Vehicles
	case Commercial_Vehicles:
		addTitle("COMMERCIAL VEHICLES");
		addVehicle("Maibatsu Mule 1", "mule");
		addVehicle("Maibatsu Mule 2", "mule2");
		addVehicle("Maibatsu Mule 3", "mule3");
		addVehicle("JoBuilt Phantom", "phantom");
		addVehicle("Vapid Benson", "benson");
		addVehicle("MTL Packer", "packer");
		addVehicle("MTL Pounder", "pounder");
		addVehicle("JoBuilt Hauler", "hauler");
		addVehicle("Brute Stockade 1", "stockade");
		addVehicle("Brute Stockade 2", "stockade3");
		addVehicle("HVY Biff", "biff");
		addVehicle("HVY Dump", "dump");
		addVehicle("HVY Dozer", "bulldozer");
		addVehicle("HVY Forklift", "forklift");
		addVehicle("HVY Handler", "handler");
		addVehicle("HVY Cutter", "cutter");
		addVehicle("Utility Truck 1", "utillitruck");
		addVehicle("Utility Truck 2", "utillitruck2");
		addVehicle("Utility Truck 3", "utillitruck3");
		addVehicle("Trashmaster 1", "trash");
		addVehicle("Trashmaster 2", "trash2");
		addVehicle("Towtruck 1", "towtruck");
		addVehicle("Towtruck 2", "towtruck2");
		addVehicle("TipTruck 1", "tiptruck");
		addVehicle("TipTruck 2", "tiptruck2");
		addVehicle("Mixer 1", "mixer");
		addVehicle("Mixer 2", "mixer2");
		addVehicle("Flatbed Truck", "flatbed");
		addVehicle("Airport Ripley", "ripley");
		addVehicle("Rubble", "rubble");
		addVehicle("Vapid Scrap Truck", "scrap");
		addVehicle("Lawnmower", "mower");
		addVehicle("Dock Tug", "docktug");
		addVehicle("Airport Tug", "airtug");
		addVehicle("Tractor 1", "tractor");
		addVehicle("Tractor 2", "tractor2");
		addVehicle("Tractor 3", "tractor3");
		addVehicle("Caddy 1", "caddy");
		addVehicle("Caddy 2", "caddy2");
		break;
#pragma endregion

#pragma region Boats
	case Boats:
		addTitle("BOATS");
		addVehicle("Dinka Marqui", "marquis");
		addVehicle("Shitzu Jetmax", "jetmax");
		addVehicle("Shitzu Squalo, ", "squalo");
		addVehicle("Shitzu Suntrap", "suntrap");
		addVehicle("Shitzu Tropic", "tropic");
		addVehicle("Speedophile Seashark 1", "seashark");
		addVehicle("Speedophile Seashark 2", "seashark2");
		addVehicle("Police Predator", "predator");
		addVehicle("Submarine", "submersible");
		addVehicle("Pegassi Speeder", "speeder");
		addVehicle("Nagasaki Dinghy 1", "dinghy");
		addVehicle("Nagasaki Dinghy 2", "dinghy2");
		addVehicle("Nagasaki Dinghy 3", "dinghy3");
		addVehicle("Lampadati Toro", "toro");
		break;
#pragma endregion

#pragma region Trailers
	case Trailers:
		addTitle("TRAILERS");
		addVehicle("Army Tanker", "armytanker");
		addVehicle("Army Tanker 1", "armytrailer");
		addVehicle("Army Tanker 2", "armytrailer2");
		addVehicle("Bale Trailer", "baletrailer");
		addVehicle("Boat Trailer", "boattrailer");
		addVehicle("Cablecar", "cablecar");
		addVehicle("Dock Trailer", "docktrailer");
		addVehicle("Freight Car 1", "freight");
		addVehicle("Freight Car 2", "freightcar");
		addVehicle("Freight Container 1", "freightcont1");
		addVehicle("Freight Container 2", "freightcont2");
		addVehicle("Freight Train Boxcar", "freightgrain");
		addVehicle("Grain Trailer", "graintrailer");
		addVehicle("Metro Train", "metrotrain");
		addVehicle("Mobile Home Trailer", "proptrailer");
		addVehicle("Rake Trailer", "raketrailer");
		addVehicle("Train Fuel Tank Car", "tankercar");
		addVehicle("Car Carrier Trailer", "tr2");
		addVehicle("Marquis Trailer", "tr3");
		addVehicle("Super Car Carrier Trailer", "tr4");
		addVehicle("Trailer Logs", "trailerlogs");
		addVehicle("Trailers 1", "trailers");
		addVehicle("Trailers 2", "trailers2");
		addVehicle("Trailers 3", "trailers3");
		addVehicle("Trailer Small", "trailersmall");
		addVehicle("Trailer Flat", "trflat");
		addVehicle("Tv Trailer", "tvtrailer");
		break;
#pragma endregion

#pragma region Heist
	case Heist:
		addTitle("HEIST");
		addVehicle("Enduro", "enduro");
		addVehicle("Guardian", "guardian");
		addVehicle("Kuruma", "kuruma");
		addVehicle("Armored Kuruma", "kuruma2");
		addVehicle("Casco", "casco");
		addVehicle("Seater Velum", "velum2");
		addVehicle("Hydra", "hydra");
		addVehicle("Insurgent 50cal", "insurgent");
		addVehicle("Insurgent Pick-Up", "insurgent2");
		addVehicle("Valkyrie", "valkyrie");
		addVehicle("Technical", "technical");
		addVehicle("Savage", "savage");
		addVehicle("Lectro", "lectro");
		addVehicle("Lost Slamvan", "slamvan2");
		break;
#pragma endregion

#pragma region Especial Vehicles
	case Especial_Vehicles:
		subTitle("ESPECIAL VEHICLES");
		addVehicle("Space Docker", "dune2");
		addVehicle("Bmx", "bmx");
		addVehicle("Dock Handler", "handler");
		addVehicle("Dozer", "bulldozer");
		addVehicle("Hotknife", "hotknife");
		addVehicle("Blazer", "blazer3");
		addVehicle("Tourbus", "tourbus");
		addVehicle("Limo", "stretch");
		addVehicle("Bus", "bus");
		addVehicle("Clown Van", "speedo2");
		addVehicle("Airtug", "airtug");
		addVehicle("Caddy", "caddy2");
		addVehicle("Docktug", "docktug");
		addVehicle("Tractor", "tractor");
		addVehicle("Forklift", "forklift");
		addVehicle("Lawn Mower", "mower");
		addVehicle("Tow Truck", "towtruck");
		addVehicle("HVY Cutter", "cutter");
		break;
#pragma endregion

#pragma region maps loaders
	case map_loader:
		addTitle("MAPS");
		addOption("North Yankton", download_north_yankton);
		break;
#pragma endregion



#pragma region Settings
	case settings:
		addTitle("SETTINGS");
		addSubmenuOption("Menu Settings", menu_settings);
		addOption("Bypass Prologo", bypass_prologo);
		addOption("Skip Prologue", skip_prologue);
		addSubmenuOption("Script Loader", load_script);
		addSubmenuOption("Paradise", stuff_paradise);
		addBoolOption("Clarear Game", toggleRedux1, toggleRedux);
		addBoolOption("Motion Blur", motion_blur);
		addOption("Restart GTA V", restart_gta);
		addOption("Change Sessions", fast_change_session);
		break;
#pragma endregion


#pragma region menu settings
	case menu_settings:
		addTitle("SETTINGS");
		addSubmenuOption("Display Options", display_options);
		addSubmenuOption("Banner", Settings_Banners);
		addSubmenuOption("Body", Settings_Body);
		addBoolOption("Sounds", menuSounds);
		addBoolOption("Instructions", instructions);
		//addCustomBoolOption("Right Sided", menuXCoord, 0.845f);
		addIntOption("Max Options", &MaxOption, 1, 25, false);
		break;
#pragma endregion


#pragma region Display Options
	case display_options:
		addBoolOption("ESP Lobby", linha);
		addBoolOption("Show FPS", display_fps);
		addBoolOption("Show Host", display_host);
		addBoolOption("Show Host Hex", display_hex_host);
		addBoolOption("Show Script Host", display_script_host);
		addBoolOption("Show Temperature(in dev)", display_temperature);
		addBoolOption("Session Status(in dev)", display_session_status);
		break;
#pragma endregion


#pragma region banner settings
	case Settings_Banners:
		addTitle("BANNERS");
		addIntOption("Banner Opacity", &BannerColorA, 0, 255, true);
		addIntOption("Banner Red", &BannerColorR, 0, 255, true);
		addIntOption("Banner Green", &BannerColorG, 0, 255, true);
		addIntOption("Banner Blue", &BannerColorB, 0, 255, true);
		addIntOption("Text Font", &bannerTextFont, 0, 7, true);
		addIntOption("Text Red", &bannerTextRed, 0, 255, true);
		addIntOption("Text Green", &bannerTextGreen, 0, 255, true);
		addIntOption("Text Blue", &bannerTextBlue, 0, 255, true);
		addIntOption("Text Opacity", &bannerTextOpacity, 0, 255, true);
		break;
#pragma endregion


#pragma region body settings
	case Settings_Body:
		addTitle("BODY");
		addIntOption("Background Opacity", &MenuColorA, 0, 255, true);
		addIntOption("Background Red", &MenuColorR, 0, 255, true);
		addIntOption("Background Green", &MenuColorG, 0, 255, true);
		addIntOption("Background Blue", &MenuColorB, 0, 255, true);
		addIntOption("Text Font", &optionsFont, 0, 7, false);
		addIntOption("Text Red", &optionsRed, 0, 255, true);
		addIntOption("Text Green", &optionsGreen, 0, 255, true);
		addIntOption("Text Blue", &optionsBlue, 0, 255, true);
		addIntOption("Text Opacity", &optionsOpacity, 0, 255, true);
		break;
#pragma endregion


		//gopro things...
#pragma region paradise 
	case stuff_paradise:
		addTitle("WELCOME TO PARADISE");
		addOption("Black Screen Lobby", []() {

			if (((char*)0x223F0C0)) {
				opd_s cw_t = { 0x12C2ECC,TOC };
				void(*cw)(unsigned int r3, unsigned int r4, unsigned int r5, unsigned int r6) = (void(*)(unsigned int, unsigned int, unsigned int, unsigned int)) & cw_t;
				cw(1, 0xE, (volatile unsigned int)(0x2148E84 + 0xD04), 0);
			}

			});
		addOption("Freeze V2 Lobby", []() {

			if (((char*)0x223F0C0)) {
				opd_s cw_t = { 0x12C2ECC,TOC };
				void(*cw)(unsigned int r3, unsigned int r4, unsigned int r5, unsigned int r6) = (void(*)(unsigned int, unsigned int, unsigned int, unsigned int)) & cw_t;
				cw(1, -1, (volatile unsigned int)(0x2148E84 + 0xD04), 0);
			}

			});
		break;
#pragma endregion



#pragma region tester
	case tester:
		addTitle("TRY OR FREEZE");
		addBoolOption("PATCH FILADELFIA", otro_patch1, otro_patch);
		addBoolOption("Force Sync", force_sync1, force_sync);
		addBoolOption("My Patch <3 Norus", ninja_patch1, ninja_patch);
		addBoolOption("Path v2", blackos1, blackos);
		addBoolOption("PATCH NORUSSIAN", variacao41, variacao4);
		addBoolOption("PATCH VOID", megafree1, megafree);
		addBoolOption("Variation-2", naka1, naka);
		addBoolOption("Variation-3", maca1, maca);
		addOption("Put Tatto", bota_tatu);
		addBoolOption("escreve tudooo", all_write_sync1, all_write_sync);
		addBoolOption("Outfit Loop(test)", outfit_loop);
		break;
#pragma endregion

	}





	resetVars();
	return true;
}

