#pragma once


enum Buttons
{
	Button_A = 0xC1,
	Button_B = 0xC3,
	Button_X = 0xC2,
	Button_Y = 0xC0,
	Button_Back = 0xBF,
	Button_L1 = 0xC4,
	Button_L2 = 0xC6,
	Button_L3 = 0xC8,
	Button_R1 = 0xC5,
	Button_R2 = 0xC7,
	Button_R3 = 0xC9,
	Dpad_Up = 0xCA,
	Dpad_Down = 0xCB,
	Dpad_Left = 0xCC,
	Dpad_Right = 0xCD
};

enum ScaleformButtons
{
	ARROW_UP,
	ARROW_DOWN,
	ARROW_LEFT,
	ARROW_RIGHT,
	BUTTON_DPAD_UP,
	BUTTON_DPAD_DOWN,
	BUTTON_DPAD_RIGHT,
	BUTTON_DPAD_LEFT,
	BUTTON_DPAD_BLANK,
	BUTTON_DPAD_ALL,
	BUTTON_DPAD_UP_DOWN,
	BUTTON_DPAD_LEFT_RIGHT,
	BUTTON_LSTICK_UP,
	BUTTON_LSTICK_DOWN,
	BUTTON_LSTICK_LEFT,
	BUTTON_LSTICK_RIGHT,
	BUTTON_LSTICK,
	BUTTON_LSTICK_ALL,
	BUTTON_LSTICK_UP_DOWN,
	BUTTON_LSTICK_LEFT_RIGHT,
	BUTTON_LSTICK_ROTATE,
	BUTTON_RSTICK_UP,
	BUTTON_RSTICK_DOWN,
	BUTTON_RSTICK_LEFT,
	BUTTON_RSTICK_RIGHT,
	BUTTON_RSTICK,
	BUTTON_RSTICK_ALL,
	BUTTON_RSTICK_UP_DOWN,
	BUTTON_RSTICK_LEFT_RIGHT,
	BUTTON_RSTICK_ROTATE,
	BUTTON_A,
	BUTTON_B,
	BUTTON_X,
	BUTTON_Y,
	BUTTON_LB,
	BUTTON_LT,
	BUTTON_RB,
	BUTTON_RT,
	BUTTON_START,
	BUTTON_BACK,
	RED_BOX,
	RED_BOX_1,
	RED_BOX_2,
	RED_BOX_3,
	LOADING_HALF_CIRCLE_LEFT,
	ARROW_UP_DOWN,
	ARROW_LEFT_RIGHT,
	ARROW_ALL,
	LOADING_HALF_CIRCLE_LEFT_2,
	SAVE_HALF_CIRCLE_LEFT,
	LOADING_HALF_CIRCLE_RIGHT,
};

bool bVar0 = false;
bool iVar1 = false;





bool vinval_ = true;
bool invinciblecar = false;
bool carinvstext;
bool looprainbow1 = false;



//Adress

//self
bool godmode = true;
bool no_ragdoll = true;
bool not_target = true;
bool invisible = false;
bool shrink = false;
bool ammo = false;
bool n_wanted = true;
bool slow = false;

bool change_outfit = false;
bool change_ped = false;
bool ultra = false;
bool gunz = false;
//misc
//bool slow = false;
//freezes
bool spam = false;
bool loop_message = false;
bool RAPID_FIRE = false;
bool car_godmod = false;
bool car_godmod1 = false;

bool car_invisible = false;
bool invisible_car1 = false;

bool seriaize_sync_tree_base = false;
bool sync_base_node = false;
bool pointz = false;
bool net_array_handler_base = false;
bool script_array_data = false;
bool serialize_string = false;
bool destroy_net = false;
bool cnet_obj = false;
bool congela = false;
bool lobby_semjas = false;
bool teste = false;
bool terra_modz_v2 = false;
bool GoldenV13 = false;
bool force_all = false;
bool desync_v1 = false;
bool desync_v2 = false;
bool desync_v3 = false;

bool sync_tree_buff = false;
//protections



bool frage = false;
//tempo
bool TimeStopped = false;


bool teste_v1 = false;

bool teste_v2 = false;
bool teste_v3 = false;
bool teste_v4 = false;
bool exe_event = false;
bool sync_handler = false;
bool join_request = false;
bool remove_gamer = false;
bool host_request = false;
bool host_migrate = false;






//Rede
bool DoFreezeConsole;
bool DeleteSpawnedPedFreeze;

//network loops
bool bubuino = false;
bool net_frz = false;
bool net_40k;
bool v1net_40k;
bool loop_explo;
bool nespam;
bool danca;
bool models;
bool notify_mode = false;
bool JAJAJA = false;
bool bugando = false;



bool pontadas = false;
bool WeeslysDankHax = false;
bool motion_blur = true;

bool load_models = false;
bool load_anim = false;
bool load_icons = false;
bool off_radar = false;
bool away_water = false;
bool rainbow_menu = false;

bool SlodFreeze;
bool SlodFreezeTimer;
int model = 0x3F039CBA;
int SlodHandle;
int SlodSelectedPed;

bool outfit_loop = false;
bool message_loop = false;
bool SuperJump = false;
bool random_weather = false;
bool Take_RP = false;
bool repetess = false;
bool CloneProtection = false;
bool clear_area_loop = false;
bool exit_load_bug = true;

bool tutorial_loop = false;
bool make_fakeleave_loop = false;
bool force_golf_loop = false;
bool apartment_blackscreen_loop = false;
bool hospital_bill_loop = false;
bool make_sound_loop = false;
bool force_dardos_loop = false;
bool flight_school_loop = false;
bool reset_view_loop = false;
bool sound_0_loop = false;
bool sound_1_loop = false;
bool take_rp_loop = false;
bool give_rp_loop = false;
bool give_money_loop = false;
bool take_money_loop = false;



bool bug_host_1 = false;
bool bug_host_2 = false;
bool bug_host_3 = false;
bool bug_host_4 = false;
bool bug_host_5 = false;
bool bug_host_6 = false;
bool bug_host_7 = false;



//troll
bool attachrape;
bool BlowMe;


bool linha = true;
bool head_box = false;
bool ped_box = false;


enum Submenus
{
	Closed,

	//submenus
	main_menu,
	self,
	client_list,
	friend_list,
	vehicle_spaw,
	vehicle_manager,

	keyboard_add_player_by_name,
	RemotePlayers,

	client_options,
	friend_options,
	attach,
	teleports_net,
	netw_frz,
	glue,
	troll,
	net_reco,
	forces,
	metodo_teste,
	lobby,
	disable_protection,
	block_protection,
	paradaisu,
	spam_all,
	vehicle_spawner,
	vehicle_mod,
	teleports,
	freezes,
	others_functions,
	golden_frz,
	protection,
	cars,
	frz_host,
	all_freezes,
	weapons,
	closet,
	closet_female,
	closet_male,
	animations,
	scenarios,
	change_model,
	default_model,
	invalid_model,
	animals_model,
	walkings,
	weather,
	vehicles_list,
	misc,
	load_script,
	recovery,
	map_loader,
	script_loader,
	settings,
	menu_settings,
	tester,
	persa,
	money,
	ranks,
	spaw_vehicle,
	ListPlayer,
	options_player,
	bad_options,
	attach_object,
	freeze_vehicle,
	good_options,
	putas,

	//carros
	Classics,
	Muscle,
	Sedans,
	Coupes,
	Compaktwagen,
	SUV_Pickups,
	Trucks,
	Vans,
	Off_Road,
	Aircrafts,
	Emergency,
	Service_Vehicles,
	Military,
	Motorcycles,
	Bicycles,
	Commercial_Vehicles,
	Boats,
	Trailers,
	Heist,
	Especial_Vehicles,
	Super,
	Sports,
	Especial,
	//

	car_manager,

	//outros
	Settings_Banners,
	Settings_Body,
	stuff_paradise,
	Settings_Scroller,
	display_options,
	Settings_Indicators
};




enum Addresses2
{
	TOC = 0x1C85330, // 0x1809384,
	//GET_INDEX_OF_CURRENT_LEVEL = 0x3D7B04, //0x1C171E0,
	SNPRINTF = 0x14FE110//0x14F9E1C 

};

enum PedConfigFlags
{
	PED_FLAG_SHRINK = 223,
};


int MarkerVar1;
int MarkerVar;
bool AllESP = false;
bool hasESP = false;
char* Marker[] = { "Line", "Marker", "Box", "Head Marker" };