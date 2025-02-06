#pragma once


// internal functions

Native_s** g_Natives;

void TriggerScriptEvent(int* Args, int ArgCount, Player BitsetPlayer) {
	int Bitset = 0;
	SET_BIT(&Bitset, BitsetPlayer);
	if (Bitset != 0) {
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, Args, ArgCount, Bitset);
	}
}
bool cstrcmp(const char* s1, const char* s2) {
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}
int* zeigen(char* msg) {
	Dialog::msgdialog_mode = Dialog::MODE_STRING_OK;
	Dialog::Show(msg);
}
void sleep(usecond_t time) // 1 second = 1000
{
	sys_timer_usleep(time * 1000);
}
void set_text_component(char* text) {
	GRAPHICS::_0x3AC9CB55("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	GRAPHICS::_0x386CE0B8();
}
void instructionsSetup() {
	mov = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::_0x7B48E696(mov, 255, 255, 255, 0);
	GRAPHICS::_0x215ABBE8(mov, "CLEAR_ALL");
	GRAPHICS::_0x02DBF2D7();
	GRAPHICS::_0x215ABBE8(mov, "SET_CLEAR_SPACE");
	GRAPHICS::_0x716777CB(200);
	GRAPHICS::_0x02DBF2D7();
	instructCount = 0;
}
void addInstruction(int button, char* text) {
	if (!instructionsSetupThisFrame) {
		instructionsSetup();
		instructionsSetupThisFrame = false;
	}
	GRAPHICS::_0x215ABBE8(mov, "SET_DATA_SLOT");
	GRAPHICS::_0x716777CB(instructCount);
	GRAPHICS::_0x716777CB(button);
	set_text_component(text);
	GRAPHICS::_0x02DBF2D7();
	instructCount++;
}
void instructionsClose() {
	GRAPHICS::_0x215ABBE8(mov, "DRAW_INSTRUCTIONAL_BUTTONS");
	GRAPHICS::_0x02DBF2D7();
	GRAPHICS::_0x215ABBE8(mov, "SET_BACKGROUND_COLOUR");
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(80);
	GRAPHICS::_0x02DBF2D7();
}
void ogdrawText(char* text, int font, float x, float y, float scalex, float scaley, int r, int g, int b,
	int a, bool center) {
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}

void drawText(char* text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a,
	bool center) {
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center); // centralizacao
	UI::SET_TEXT_DROPSHADOW(5, 5, 5, 0, 80);
	UI::SET_TEXT_EDGE(2, 255, 255, 255, 150);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}

void drawNotification(char* msg) {
	if (menuXCoord == 0.845f) {
		UI::_0x574EE85C("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(msg);
		UI::_SET_NOTIFICATION_MESSAGE("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", true, 4, "Menu Base", "");
		UI::_DRAW_NOTIFICATION(false, true);
	}
	else {
		UI::_0xF42C43C7("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(msg);
		UI::_0x38F82261(3000, 1);
	}
}
void playSound(char* sound) {
	if (menuSounds)
		AUDIO::PLAY_SOUND_FRONTEND(-1, sound, "HUD_FRONTEND_DEFAULT_SOUNDSET");
}
bool isNumericChar(char x) { return (x >= '0' && x <= '9') ? true : false; }
int StoI(char* str) {
	if (*str == NULL)
		return 0;

	int res = 0, sign = 1, i = 0;

	if (str[0] == '-') {
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; ++i) {
		if (isNumericChar(str[i]) == false)
			return 0;
		res = res * 10 + str[i] - '0';
	}
	return sign * res;
}
char* ItoS(int num) {
	char buf[30];
	snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}
char* FtoS(float input) {
	char returnvalue[64];
	int wholenumber = (int)input;
	input -= wholenumber;
	input *= 100;
	sprintf(returnvalue, "%d.%d", wholenumber, (int)input);
	return returnvalue;
}
void startKeyboard(int action, char* defaultText, int maxLength) {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "FMMC_KEY_TIP8", "", defaultText, "", "", "", maxLength);
	keyboardAction = action;
	keyboardActive = true;
}
void changeSubmenu(int newSubmenu) {
	lastSubmenu[submenuLevel] = submenu;
	lastOption[submenuLevel] = currentOption;
	currentOption = 1;
	submenu = newSubmenu;
	submenuLevel++;
}
void SetupTimer(int tickTime) {
	if (newTimerTick) {
		maxTimerCount = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick = false;
	}
}
bool IsTimerReady() { return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount; }
void ResetTimer() { newTimerTick = true; }
void SetupTimer2(int tickTime) {
	if (newTimerTick2) {
		maxTimerCount2 = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick2 = false;
	}
}
bool IsTimerReady2() { return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount2; }
void ResetTimer2() { newTimerTick2 = true; }

char* get_player_name(int id) {
	char* Name = PLAYER::GET_PLAYER_NAME(id);
	if (cstrcmp(Name, "**Invalid**"))
		return "-";
	else
		return Name;
	return str;
}

int getNumPlayers() {
	int Amount = 0;
	for (int i = 0; i < 18; i++) {
		if (!(cstrcmp(get_player_name(i), "-")))
			Amount++;
	}
	return Amount;
};

// int getHost() { return NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0); }char* getHostName() {
// return PLAYER::GET_PLAYER_NAME(getHost()); }
int getScriptHost() { return NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0); }

#pragma region Internals
//////////
////////
///////
//////
/////
////
/// 
//THANK YOU CHAT GPT FOR EXPLAINING ME HOW THIS WORKS <3

// Função para "hookar" uma função nativa, substituindo seu endereço.
void HookNative(int native, int dest) {
	int FuncBytes[1];
	FuncBytes[0] = *(int*)dest;          // Obtém o endereço da função de destino.
	memcpy((void*)native, FuncBytes, 4); // Copia os bytes da função de destino para a função nativa.
}


// Função para escrever dados em um processo.
int write_process(void* destination, const void* source, size_t size) {
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)destination, size, (uint64_t)source);
	return_to_user_prog(int);
}

// Verifica se o HEN está ativo.
bool henChk() {
	system_call_1(8, 0x1337); // Chamada de sistema para checar HEN.
	return (p1 == 0x1337);    // Retorna verdadeiro se a verificação foi bem-sucedida.
}

// Função de verificação para identificar CEX.
__attribute__((noinline)) int checkIfCEX_stub() {
	int total = 50; // Inicializa um total.
	for (int i = 0; i < 10; i++) {
		total = total + (int)checkIfCEX_stub; // Acumula o valor da função stub.
	}
	return total; // Retorna o total acumulado.
}

// Verifica se o console é DEX.
bool isDEX() {
	static bool hasChecked = false; // Marca se a verificação já foi feita.
	static bool isDEX = false;      // Armazena o resultado da verificação.

	if (hasChecked == true)
		return isDEX; // Retorna o resultado se já foi verificado.

	int firstVal = checkIfCEX_stub();                   // Obtém o primeiro valor.
	int functionAddress = *(int*)(int)checkIfCEX_stub; // Obtém o endereço da função stub.

	// Dados para modificar uma função.
	char data[] = { 0x38, 0x60, 0x07, 0xEB, 0x4E, 0x80, 0x00, 0x20 }; // li %r3, 2027    blr

	// Chamada de sistema para escrever dados na função.
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)functionAddress, 8, (uint64_t)data);

	int secondVal = checkIfCEX_stub(); // Obtém o segundo valor.

	if (firstVal != secondVal) {
		// Se os valores diferem, significa que a função foi alterada, indicando que é DEX.
		isDEX = true;
	}

	hasChecked = true; // Marca que a verificação foi feita.
	return isDEX;      // Retorna se é DEX.
}

// Verifica o tipo de console e imprime o resultado.
static void ConsoleTypeCheck(void) {
	uint64_t consoleType;
	system_call_1(985, (uint32_t)&consoleType); // Chamada para obter o tipo de console.

	// Exibe o tipo de console com base no valor retornado.
	if (consoleType == 0)
		printf("\nConsole Types are as listed.\n\n1 = CEX\n2 = DEX\n3 = TOOL\n\nYour Console Value type is: "
			"IDK\n"); // Desconhecido
	if (consoleType == 1)
		printf("\nConsole Types are as listed.\n\n1 = CEX\n2 = DEX\n3 = TOOL\n\nYour Console Value type is: "
			"CEX\n"); // Retail
	if (consoleType == 2)
		printf("\nConsole Types are as listed.\n\n1 = CEX\n2 = DEX\n3 = TOOL\n\nYour Console Value type is: "
			"DEX\n"); // Debug
	if (consoleType == 3)
		printf("\nConsole Types are as listed.\n\n1 = CEX\n2 = DEX\n3 = TOOL\n\nYour Console Value type is: "
			"Debugger\n"); // Debugger
}

// Função para escrever na memória.
int writeMem(uint64_t address, const void* data, size_t size) {
	if (henChk()) { // Verifica se está usando HEN.
		system_call_6(8, 0x7777, 0x32, (uint64_t)sys_process_getpid(), (uint64_t)address, (uint64_t)data,
			(uint64_t)size);
		return_to_user_prog(int);
	}
	else if (isDEX()) { // Se for DEX.
		system_call_4(905, (uint64_t)sys_process_getpid(), address, size, (uint64_t)data);
		return_to_user_prog(int32_t);
	}
	else {                                // Se for CEX.
		memcpy((void*)address, data, 4 * 4); // Copia os dados diretamente.
	}
}

// Função para ler da memória.
int readMem(uint64_t address, void* data, size_t size) {
	if (henChk()) { // Se HEN está ativo.
		system_call_6(8, 0x7777, 0x31, (uint64_t)sys_process_getpid(), (uint64_t)address, (uint64_t)data,
			(uint64_t)size);
		return_to_user_prog(int);
	}
	else if (isDEX()) { // Se for DEX.
		system_call_4(904, (uint64_t)sys_process_getpid(), address, size, (uint64_t)data);
		return_to_user_prog(int32_t);
	}
	else {                        // Se for CEX.
		readMem(address, data, size); // Chama a função de leitura.
	}
}

// Função para patch de salto em uma função.
void PatchInJump(uint64_t Address, int Destination, bool Linked) {
	int FuncBytes[4]; // Array para armazenar os bytes da função.

	Destination = *(int*)Destination; // Obtém o endereço de destino.

	// Calcula os bytes para o salto.
	FuncBytes[0] = 0x3D600000 + ((Destination >> 16) & 0xFFFF); // lis %r11, dest>>16
	if (Destination & 0x8000)                                   // Se o bit 16 é 1...
		FuncBytes[0] += 1;                                        // Ajusta o valor.

	FuncBytes[1] = 0x396B0000 + (Destination & 0xFFFF); // addi %r11, %r11, dest&0xFFFF
	FuncBytes[2] = 0x7D6903A6;                          // mtctr %r11
	FuncBytes[3] = 0x4E800420;                          // bctr

	if (Linked)
		FuncBytes[3] += 1; // bctrl se estiver vinculado.

	writeMem(Address, (void*)FuncBytes, 16); // Escreve os bytes na memória.
}

// Função para encontrar o endereço da tabela nativa.
unsigned int FindNativeTableAddress() {
	unsigned int l_uiNativeTableAddress = 0;
	unsigned int l_uiStartAddress = 0x390000; // Endereço inicial para busca.
	unsigned int l_uiAddress = 0;

	for (unsigned int i = 0; i < 0x10000; i++) {
		// Verifica se os bytes correspondem a uma função específica.
		if (*(unsigned int*)(l_uiStartAddress + i) == 0x3C6072BD)
			if (*(unsigned int*)(l_uiStartAddress + i + 8) == 0x6063E002) {
				l_uiAddress = *(unsigned int*)(l_uiStartAddress + i + 0x10);
				l_uiAddress &= 0xFFFFFF;
				l_uiAddress += (l_uiStartAddress + i + 0x10) - 1; // Ajusta o endereço.
				printf("CONSOL TYPE: 0x%08x\n", l_uiAddress);
				break;
			}
	}

	l_uiNativeTableAddress =
		(*(unsigned int*)(l_uiAddress + 0x24) << 16) + (*(unsigned int*)(l_uiAddress + 0x2C) & 0xFFFF);
	l_uiNativeTableAddress -= 0x10000; // Ajusta o endereço final.

	return l_uiNativeTableAddress; // Retorna o endereço da tabela nativa.
}

int NativeAddress(int Native, bool PatchInJump = true) {
	int Hash = Native & 0xFF;                                    // Calcula o hash da função.
	int Table = *(int*)(FindNativeTableAddress() + (Hash * 4)); // Obtém a tabela nativa.

	while (Table != 0) {
		int NativeCount = *(int*)(Table + 0x20); // Obtém a contagem de funções nativas.

		for (int i = 0; i < NativeCount; i++) {
			// Verifica se a função corresponde ao hash nativo.
			if (*(int*)((Table + 0x24) + (i * 4)) == Native) {
				if (PatchInJump) {
					int NativeLocation =
						*(int*)(*(int*)((Table + 4) + (i * 4))); // Obtém o endereço da função nativa.

					// Busca por um endereço específico.
					for (int i = 0; i < 50; ++i) {
						short CurrentPlace = *(short*)(NativeLocation + (i * 4));
						if (CurrentPlace == 0x4AE6 || CurrentPlace == 0x4AA8 || CurrentPlace == 0x4AE4 ||
							CurrentPlace == 0x4AE5) {
							// Retorna o endereço ajustado.
							return (((*(int*)(NativeLocation + (i * 4))) - 0x48000001) + (NativeLocation + (i * 4))) -
								0x4000000;
						}
					}
				}
				else {
					return *(int*)((Table + 4) + (i * 4)); // Retorna o endereço se não for para patch.
				}
			}
		}
		Table = *(int*)(Table); // Move para o próximo item na tabela.
	}
}
#pragma endregion Internals

int title_color_r = 255;
int title_color_g = 255;
int title_color_b = 255;
int title_color_a = 255;

void addTitle(char* title) {
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0) {
		cycleTimer += GAMEPLAY::GET_FRAME_TIME();

		if (cycleTimer >= 0.2f) {
			cycleTimer = 0.0f;
			colorCycle++;
			if (colorCycle > 11)
				colorCycle = 0;
		}

		if (isVisible) {
			visibilityTimer += GAMEPLAY::GET_FRAME_TIME();

			if (visibilityTimer >= 0.1f) {
				visibilityTimer = 0.0f;
				currentLetterIndex++;

				if (currentLetterIndex > strlen(title)) {
					currentLetterIndex = strlen(title);
					isVisible = false;
				}
			}
		}
		else {
			visibilityTimer += GAMEPLAY::GET_FRAME_TIME();

			if (visibilityTimer >= 0.6f) {
				visibilityTimer = 0.0f;
				isVisible = true;
				currentLetterIndex = 0;
			}
		}

		char displayText[100];
		strncpy(displayText, title, currentLetterIndex);
		displayText[currentLetterIndex] = '\0';

		drawText(displayText, bannerTextFont, menuXCoord, 0.110f, 0.75f, 0.75f, title_color_r, title_color_g, title_color_b, title_color_a,
			true);
	}
}



void DrawOnOff(char* Streamedtexture, char* textureName, float x, float y, float width, float height,
	float rotation, int r, int g, int b, int a) {

	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture)) {
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
		return;
	}
	GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
}

//valeu mano por isso mano Bryan
float InfiniteScroll(float optionCurrentDrawn) {
	if ((currentOption <= MaxOption && optionCurrentDrawn <= MaxOption) ||
		((optionCurrentDrawn > (currentOption - MaxOption)) && optionCurrentDrawn <= currentOption)) {
		float buf = (currentOption <= MaxOption && optionCurrentDrawn <= MaxOption)
			? (optionCurrentDrawn)
			: (optionCurrentDrawn - (currentOption - MaxOption));

		return buf;
	}
	return 0;
}
void DrawSprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height,
	float rotation, int r, int g, int b, int a) {
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture)) {
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
	}
	else {
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
	}
}

void View_Sprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height,
	float rotation, int r, int g, int b, int a) {
	if (currentOption <= maxOptions && optionCount <= maxOptions) {
		DrawSprite(Streamedtexture, textureName, x, (optionCount * 0.035f + y), width, height, rotation, r, g, b,
			a);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption) {
		DrawSprite(Streamedtexture, textureName, x, ((optionCount - (currentOption - maxOptions)) * 0.035f + y),
			width, height, rotation, r, g, b, a);
	}
}

void addOption(char* option, void(*callback)() = nullptr) {
	optionCount++;
	float buf = InfiniteScroll(optionCount);
	if (buf > 0) {
		drawText(option, optionsFont, textXCoord, (buf * 0.025f + 0.135f), 0.3f, 0.3f, optionsRed, optionsGreen,
			optionsBlue, optionsOpacity, false);
	}
	if (IsTimerReady() && currentOption == optionCount) {
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A)) {
			if (callback)
				callback();
			SetupTimer(100);
		}
	}
}

void addSubmenuOption(char* option, int newSubmenu) {
	optionCount++;
	float buf = InfiniteScroll(optionCount);
	if (buf > 0) {
		drawText(option, optionsFont, textXCoord, (buf * 0.025f + 0.135f), 0.3f, 0.3f, optionsRed, optionsGreen,
			optionsBlue, optionsOpacity, false);
	}
	if (IsTimerReady() && currentOption == optionCount) {
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A)) {
			changeSubmenu(newSubmenu);

			SetupTimer(100);
		}
	}
}

void addBoolOption(char* right, bool& value, void(*callback)(bool) = nullptr) {
	optionCount++;
	float buf = InfiniteScroll(optionCount);
	if (buf > 0) {
		drawText(right, optionsFont, textXCoord, (buf * 0.025f + 0.135f), 0.3f, 0.3f, optionsRed, optionsGreen,
			optionsBlue, optionsOpacity, false);
		if (value)
			DrawOnOff("mprankbadge", "globe_bg", 0.165f, (buf * 0.025f + 0.150f), 0.005, 0.01, 0, 0, 255, 0,
				255);
		else
			DrawOnOff("mprankbadge", "globe_bg", 0.165f, (buf * 0.025f + 0.150f), 0.005, 0.01, 0, 255, 0, 0,
				255);
	}

	if (IsTimerReady() && currentOption == optionCount) {
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A)) {
			value ^= 1;
			if (callback)
				callback(value);
			SetupTimer(100);
		}
	}
}

void addChangeModel(char* option, char* Model) {
	optionCount++;
	float buf = InfiniteScroll(optionCount);
	if (buf > 0) {
		drawText(option, optionsFont, textXCoord, (buf * 0.025f + 0.135f), 0.3f, 0.3f, optionsRed, optionsGreen,
			optionsBlue, optionsOpacity, false);
	}

	if (IsTimerReady() && currentOption == optionCount) {
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A)) {
			oped = Model;
			load_models = true;
			SetupTimer(100);
		}
	}
}
void addAnimation(char* option, char* anim, char* dict) {

	optionCount++;
	float buf = InfiniteScroll(optionCount);
	if (buf > 0) {
		drawText(option, optionsFont, textXCoord, (buf * 0.025f + 0.135f), 0.3f, 0.3f, optionsRed, optionsGreen,
			optionsBlue, optionsOpacity, false);
	}

	if (IsTimerReady() && currentOption == optionCount) {
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A)) {
			baixar_animacao = anim;
			animacao2_nao = dict;
			load_anim = true;
			SetupTimer(100);
		}
	}
}
void addScenario(char* option, char* scenarioName) {
	optionCount++;
	float buf = InfiniteScroll(optionCount);

	if (buf > 0) {
		drawText(option, optionsFont, textXCoord, (buf * 0.025f + 0.135f), 0.3f, 0.3f, optionsRed, optionsGreen,
			optionsBlue, optionsOpacity, false);
	}

	if (IsTimerReady() && currentOption == optionCount) {
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A)) {
			int playerPed = PLAYER::PLAYER_PED_ID();
			AI::TASK_START_SCENARIO_IN_PLACE(playerPed, scenarioName, 0, true);
			SetupTimer(100);
		}
	}
}

bool SpawnVehicle = false;
Hash hash_veh;

void addVehicle(char* option, char* model) {
	optionCount++;
	float buf = InfiniteScroll(optionCount);

	if (buf > 0) {
		drawText(option, optionsFont, textXCoord, (buf * 0.025f + 0.135f), 0.3f, 0.3f, optionsRed, optionsGreen,
			optionsBlue, optionsOpacity, false);
	}
	if (IsTimerReady() && currentOption == optionCount) {
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A)) {
			hash_veh = GAMEPLAY::GET_HASH_KEY(model);
			SpawnVehicle = true;
			SetupTimer(100);
		}
	}
}

void ChangeWalkingType(char* option, char* WalkType) {
	optionCount++;
	float buf = InfiniteScroll(optionCount);

	if (buf > 0) {
		drawText(option, optionsFont, textXCoord, (buf * 0.025f + 0.135f), 0.3f, 0.3f, optionsRed, optionsGreen,
			optionsBlue, optionsOpacity, false);
	}

	// Verifica se o botão foi pressionado e executa a ação
	if (IsTimerReady() && currentOption == optionCount) {
		if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A)) {
			// Carrega o conjunto de animações e aplica o movimento
			STREAMING::_REQUEST_ANIM_SET(WalkType);
			if (STREAMING::_HAS_ANIM_SET_LOADED(WalkType)) {
				PED::_SET_PED_MOVEMENT_CLIPSET(PLAYER::PLAYER_PED_ID(), WalkType,
					1048576000); //clipset
			}
			SetupTimer(100); 
		}
	}
}

///////////////
///

template <typename TYPE>

void addCustomBoolOption(char* option, TYPE value, TYPE match, char* info = NULL) {
	char buf[30];
	if (value == match) {
		DrawOnOff("mprankbadge", "globe_bg", 0.180f, (buf * 0.025f + 0.150f), 0.005, 0.01, 0, 0, 255, 0,
			255); // Cor verde
		addOption(buf);
	}
	else {
		DrawOnOff("mprankbadge", "globe_bg", 0.180f, (buf * 0.025f + 0.150f), 0.005, 0.01, 0, 255, 0, 0,
			255); // Cor vermelha
		addOption(buf);
	}
}
void addIntOption(char* option, int* var, int min, int max, bool keyboard, char* info = NULL) {
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %i >", option, *var);
	addOption(buf);
	if (currentOption == optionCount) {
		lrInstruction = true;
		if (rightPress) {
			playSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress) {
			playSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
		if (keyboard) {
			squareInstruction = true;
			if (squarePress) {
				startKeyboard(0, "", (strlen(ItoS(max)) + 1));
				keyboardVar = var;
			}
		}
	}
}
void addbuf2(char* option, int vari = 0) {
	if (currentOption <= maxOptions && optionCount <= maxOptions) // guiTextOpacity guiOpacity
		drawText(option, 4, textXCoord + .215, (optionCount * 0.035f + 0.123f), .57, .52, 255, 255, 255, 255,
			vari);
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
		drawText(option, 4, textXCoord + .215, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.123f),
			.57, .52, 255, 255, 255, 255, vari);
}
void addIntOption2(char* option, int* var, int min, int max, bool keyboard, bool fastpress = false) {
	char buf[30];
	char buf1[30];
	snprintf(buf, sizeof(buf), "%s", option);

	addOption(buf);

	if (currentOption == optionCount) {
		snprintf(buf1, sizeof(buf1), "< %i >", *var, max);
		addbuf2(buf1);
		if (leftPress) {
			playSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
		else if (rightPress) {
			playSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		if (fastpress) {
			if (fastLeftPress) { // 45 110 185     <font size= \"33"\ font colour=\"#ffffff\"> text here </font> wtdf
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 1;
			}
			else if (fastRightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 1;
			}
		}
	}
	else {
		snprintf(buf1, sizeof(buf1), "%i", *var, max);
		addbuf2(buf1);
	}
}
void addFloatOption(char* option, float* var, float min, float max, bool holdPress, char* info = NULL) {
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %s >", option, FtoS(*var));
	addOption(buf);
	if (currentOption == optionCount) {
		lrInstruction = true;
		if (holdPress) {
			if (fastRightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 0.01f;
			}
			else if (fastLeftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 0.01f;
			}
		}
		else {
			if (rightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 0.01f;
			}
			else if (leftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 0.01f;
			}
		}
	}
}
void addKeyboardOption(char* option, int action, char* defaultText, int maxLength, char* info = NULL) {
	addOption(option);
	if (currentOption == optionCount) {
		xInstruction = true;
		if (optionPress)
			startKeyboard(action, defaultText, maxLength);
	}
}
#pragma endregion

int getOption() {
	/*xInstruction = true;
	if (optionPress)
	return currentOption;*/
	return 0;
}

union ScriptArg {
	unsigned int ui;
	float f;
	int i;
	char* str;
};



//I got something here now it opens in cutscenes but I can't get into the submenus yet aaaaaaaaaa
void monitor() {
	SetupTimer(20);

	if (submenu == Closed) {
		if (IsTimerReady()) {
			if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, Button_R1) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, Dpad_Right)) {
				submenu = main_menu;
				submenuLevel = 0;
				currentOption = 1;
				//playSound("YES");
			}
			ResetTimer();
		}
	}
	else {
		if (IsTimerReady()) {
			if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Button_B)) {
				if (submenu == main_menu) {
					submenu = Closed;
				}
				else {
					submenu = lastSubmenu[submenuLevel - 1];
					newSubmenu = lastSubmenu[submenuLevel - 1];
					currentOption = lastOption[submenuLevel - 1];
					submenuLevel--;
				}
				playSound("Back");
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Button_A)) {
				optionPress = true;
				playSound("SELECT");
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Dpad_Up)) {
				currentOption--;
				if (currentOption < 1) {
					currentOption = optionCount;
				}
				playSound("NAV_UP_DOWN");
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Dpad_Down)) {
				currentOption++;
				if (currentOption > optionCount) {
					currentOption = 1;
				}
				playSound("NAV_UP_DOWN");
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Dpad_Right)) {
				rightPress = true;
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Dpad_Left)) {
				leftPress = true;
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, Dpad_Right)) {
				fastRightPress = true;
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, Dpad_Left)) {
				fastLeftPress = true;
			}
			else if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, Button_X)) {
				squarePress = true;
			}

			ResetTimer();
		}
	}
}


int scroller_color_r = 255;
int scroller_color_g = 255;
int scroller_color_b = 255;
int scroller_color_a = 70;


void disable_controls() {
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 19);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 20);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 21);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 27);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 54);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 123);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 124);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 125);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 126);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 138);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 139);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 140);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 177);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 178);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 179);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 207);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 166);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 167);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 177);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 178);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 193);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 194);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 195);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 202);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 203);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 204);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 205);
	//CONTROLS::DISABLE_CONTROL_ACTION(1, 161);//fix flash idk
	if (UI::IS_PAUSE_MENU_ACTIVE())
	{
		submenu = false;
	}
}


void design()
{
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0) {

		double menuHeight = (optionCount > MaxOption) ? 0.025f * MaxOption : 0.025f * optionCount;
		if (optionCount > 0) {

			GRAPHICS::DRAW_RECT(menuXCoord, menuYCoord - 0.0050, 0.14f, 0.050f, BannerColorR, BannerColorG,
				BannerColorB, BannerColorA); // banner
			GRAPHICS::DRAW_RECT(menuXCoord, (menuYCoord + 0.020f + (menuHeight / 2)), 0.14f, menuHeight, MenuColorR,
				MenuColorG, MenuColorB, MenuColorA); // background

			float scrollerWidth = 0.14f;
			float scrollerHeight = 0.025f; // 25
			float scrollerY = ((currentOption * 0.025f) + 0.14f + 0.007f);

			if (currentOption > MaxOption) {
				scrollerY = (MaxOption * 0.025f) + 0.14f + 0.007f;
			}
			GRAPHICS::DRAW_RECT(menuXCoord, scrollerY, scrollerWidth, scrollerHeight, scroller_color_r, scroller_color_g, scroller_color_b, scroller_color_a); // scroll
		}
	}
}



void lexicon_design() //dev
{
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
	{
		if (optionCount > maxOptions)
		{
			GRAPHICS::DRAW_RECT(menuXCoord, 0.176f, 0.21f, 0.035f, 0, 0, 0, 220); // top box
			GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions + 1) * 0.035f) + 0.1755f), MenuWidth, 0.035f, 0, 0, 0, 220); // Bottom Box
			DrawSprite("commonmenu", "shop_arrows_upanddown", menuXCoord, (((maxOptions + 1) * 0.035f) + 0.1755f), 0.02f, 0.04f, 0, 255, 255, 255, 255); //up & down scroll arrows
			GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions * 0.035f) / 2) + 0.192f), MenuWidth, (maxOptions * 0.035f), 16, 16, 16, 190); //background
			if (currentOption > maxOptions)
			{
				GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.175f), MenuWidth, 0.035f, 255, 255, 255, 220); // Scroller
			}
			else
			{
				GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.175f), MenuWidth, 0.035f, 255, 255, 255, 220); // Scroller
			}
			char buffer[30];
			sprintf(buffer, "%i / %i", currentOption, optionCount);
			//drawTextRightJustify(buffer, 0, optioncountx, (((maxOptions + 1) * 0.00f) + 0.1605f), 0.40f, 0.35f, 255, 255, 255, 255, false); //option count
		}
		else
		{
			GRAPHICS::DRAW_RECT(menuXCoord, 0.176f, 0.21f, 0.035f, 0, 0, 0, 220); // top box
			GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount * 0.035f) / 2) + 0.192f), MenuWidth, (optionCount * 0.035f), 16, 16, 16, 190); //background
			GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.175f), MenuWidth, 0.035f, 255, 255, 255, 220); // Scroller
			char buffer[30];
			sprintf(buffer, "%i / %i", currentOption, optionCount);
			//drawTextRightJustify(buffer, 0, optioncountx, (((optionCount + 1) * 0.00f) + 0.1605f), 0.40f, 0.35f, 255, 255, 255, 255, false); //option count
		}
	}
}


void resetVars() {
	if (submenu != Closed)
		disable_controls();
	design();
	//lexicon_design();
	optionPress = false;
	rightPress = false;
	leftPress = false;
	fastRightPress = false;
	fastLeftPress = false;
	squarePress = false;
	infoText = nullptr;
	instructionsSetupThisFrame = false;
	squareInstruction = false;
	xInstruction = false;
	lrInstruction = false;
}


#pragma endregion

Hash GETHASHKEY(char* Input) { return GAMEPLAY::GET_HASH_KEY(Input); }

void print(char* text, int time = 2000) {
	UI::_0xF42C43C7("STRING" /*"CnCTG_IN_BF"*/);
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_0x38F82261(time /*3000*/, 1);
	printf("%s\n", text);
}
void WriteInt32(int Address, int Input) { *(int*)Address = Input; }
bool Write_Global(int a_uiGlobalID, int a_uiValue) {
	int Ptr = *(int*)((TunablePointer - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	if (Ptr != 0) {
		*(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4)) = a_uiValue;
		return true;
	}
	return false;
}
void PatchInJump(unsigned int functionStartAddress, unsigned int newFunction) {
	unsigned int jumpInstructions[]{
		0x3D600000 | ((newFunction >> 16) & 0xFFFF), // lis %r11, newFunction@h
			0x616B0000 | (newFunction & 0xFFFF),         // ori %r11, %r11, newFunction@l
			0x7D6903A6,                                  // mtctr %r11
			0x4E800420                                   // bctr
	};

	writeMem(functionStartAddress, jumpInstructions, 0x10);
}
void HookFunctionStart(unsigned int functionStartAddress, unsigned int newFunction,
	unsigned int functionStub) {
	unsigned int originalInstructions[4];
	readMem(functionStartAddress, originalInstructions, 0x10);

	// The stub will execute the first 4 instruction and then jump back to where it should
	readMem(functionStub, originalInstructions, 0x10);
	PatchInJump(functionStub + 0x10, functionStartAddress + 0x10);

	// Finally, make the function we want to hook jump to ours
	PatchInJump(functionStartAddress, newFunction);
}

void fast_change_session() {
	Write_Global(1315298, 30);
	Write_Global(60515, 0);
	Write_Global(1312335, 1);
}

bool ant_time_out1 = false;

void ant_time_out(bool enable) {
	Write_Global(0x4004E, 0x7FFFFFFF);
	Write_Global(0x4006A, 0x7FFFFFFF);
	Write_Global(0x4006B, 0x7FFFFFFF);
	Write_Global(0x40A18, 0x7FFFFFFF);
}

void bypass_prologo() {
	Write_Global(0x1389F63, 0); // Escreve 0 no endereço 0x01389F63
	Write_Global(0x8797F, 0);   // Escreve 0 no endereço 0x0008797F
	print("~b~OK", 3000);
}

void skip_prologue() {
	Write_Global(0x4004E, 0x157C0);
	Write_Global(0x4006A, 0x3B9AC9FF);
	Write_Global(0x4006B, 0x3B9AC9FF);
	Write_Global(266744, 0x3B9AC9FF);
	Write_Global(266745, 0x3B9AC9FF);
	Write_Global(266746, 0x3B9AC9FF);
	Write_Global(266747, 0x3B9AC9FF);
	Write_Global(266825, 0x3B9AC9FF);
	Write_Global(0x24DF02, 0xF423F);
	Write_Global(0x143B04, 0xF423F);
	Write_Global(0x4004A, 0x3B9AC9FF);
	Write_Global(0x4004B, 0x3B9AC9FF);
	Write_Global(0x4004C, 0x3B9AC9FF);
	Write_Global(0x4004D, 0x3B9AC9FF);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_NO_MORE_TUTORIALS"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_FM_TRIGTUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_FM_HOLDTUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_FM_RACETUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_FM_CMODTUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_NO_TUT_SPAWN"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_FRONT_END_JIP_UNLOCKED"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_FM_NOTUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_FM_INTRO_CUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP0_FM_INTRO_MISS_DONE"), 1, true);

	STATS::STAT_SET_BOOL(GETHASHKEY("MP1_FM_TRIGTUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP1_FM_HOLDTUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP1_FM_RACETUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP1_FM_CMODTUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP1_NO_TUT_SPAWN"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP1_FRONT_END_JIP_UNLOCKED"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP1_FM_NOTUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP1_FM_INTRO_CUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MP1_FM_INTRO_MISS_DONE"), 1, true);

	STATS::STAT_SET_BOOL(GETHASHKEY("MPPLY_FM_INTRO_CUT_DONE"), 1, true);
	STATS::STAT_SET_BOOL(GETHASHKEY("MPPLY_NO_MORE_TUTORIALS"), 1, true);
}

void ClonePedAndExecute() {
	int clonedPed =
		PED::CLONE_PED(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 1, 1);
}

void drawline() {
	for (int i = 0; i < 18; i++) {
		Vector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(i, 0, 0, 0);
		Vector3 mepos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);

		GRAPHICS::DRAW_LINE(mepos.x, mepos.y, mepos.z, handleCoords.x, handleCoords.y, handleCoords.z, 0, 0, 255,
			255);
	}
}

char* GetIPExternal(int TheAttackingPlayer) {
	char RegionBuffer[2][10];
	char playersIP[1000];
	int Handle[13];
	char IPInfo[4][50];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER2(TheAttackingPlayer, &Handle[0], 13);
	char* RealName = NETWORK::NETWORK_GET_GAMERTAG_FROM_HANDLE(&Handle[0]);
	char* ipName = ReadBytes(0x40025C80 + (TheAttackingPlayer * 136), 100);
	if (!strcmp(RealName, ipName)) {
		int ip = *(int*)(0x40025CC8 + (TheAttackingPlayer * 0x88));
		int p1 = (ip & 0xff000000) >> 24;
		int p2 = (ip & 0x00ff0000) >> 16;
		int p3 = (ip & 0x0000ff00) >> 8;
		int p4 = (ip & 0x000000ff) >> 0;
		sprintf(IPInfo[0], "%i.%i.%i.%i", p1, p2, p3, p4);
		if (strstr(IPInfo[0], "255.255.255.255") == NULL && strstr(IPInfo[0], "0.0.0.0") == NULL) {
			snprintf(playersIP, sizeof(playersIP), "%s", IPInfo[0]);
			return playersIP;
		}
		else {
			snprintf(playersIP, sizeof(playersIP), "%s", "N/A");
			return playersIP;
		}
	}
}


//very, very shit, I didn't like it
char protectionMessage[128];
void sms_ip_attacker(char* playerName) {
	int data[2];
	for (int i = 0; i < 16; i++) {
		if (GAMEPLAY::ARE_STRINGS_EQUAL(playerName, PLAYER::GET_PLAYER_NAME(i))) {
			snprintf(protectionMessage, sizeof(protectionMessage), "~g~ninjqk ;)\ninformatsiya : ~g~%s",
				GetIPExternal(i));
			NETWORK::NETWORK_HANDLE_FROM_PLAYER44(i, &data[0], 13);
			NETWORK::NETWORK_SEND_TEXT_MESSAGE2(protectionMessage, &data[0]);
		}
	}
}

char* lastAttacker = "N/A";

opd_s _0x012C8D60_t = { 0x0012C8D60, TOC };
unsigned int(*_0x0012C8D60)(unsigned int r3, unsigned int senderData, unsigned int recieverData,
	unsigned int r6, unsigned int r7, unsigned int r8,
	unsigned int r9) = (unsigned int(*)(unsigned int, unsigned int, unsigned int,
		unsigned int, unsigned int, unsigned int,
		unsigned int)) &
	_0x012C8D60_t;
char scriptEventDialogText[100];
unsigned int scriptEventDetour(unsigned int r3, unsigned int senderData, unsigned int recieverData,
	unsigned int r6, unsigned int r7, unsigned int r8, unsigned int r9) {
	int addressOfArgs = r3 + 10 * 0x4;
	char* senderName = (char*)(*(int*)(senderData + 0x78) + 0x10);

	if (*(int*)addressOfArgs == 0x2 && *(int*)(addressOfArgs + 0x8) == 0x35) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s  ~w~Tried To Non Host Kick You!",
			senderName);
		print(scriptEventDialogText);
		lastAttacker = senderName;
		*(int*)addressOfArgs = 0;
	}
	if (*(int*)addressOfArgs == 0x2 && *(int*)(addressOfArgs + 0x8) == 0x34) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s  ~w~Tried Fake leave On You!",
			senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}
	if (*(int*)addressOfArgs == 0x2 && *(int*)(addressOfArgs + 0x8) == 0x2e) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s  ~w~Tried To Reset Your View!",
			senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0xDA || *(int*)addressOfArgs == 0xDB) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s  ~w~Tried To Give You Money!",
			senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x3) {
		if (*(int*)(addressOfArgs + 0x8) == 0x14) {
			snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
				"~b~%s  ~w~Tried To Force You Into To Tutorial!", senderName);
			print(scriptEventDialogText);
			*(int*)addressOfArgs = 0;
		}
	}

	if (*(int*)addressOfArgs == 0x37) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s ~w~Tried to Kick You From Your Car!", senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x138) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s ~w~Tried To Force u Pay Hospital Bill!", senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)(addressOfArgs + 0x8) == 0x3A) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried To Force You Into Flight School!", senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)(addressOfArgs + 0x8) == 0x40) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried To Remove Your HUD And Phone!", senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)(addressOfArgs + 0x8) == 0x35) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried To Force You To Arm Wresteling!", senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)(addressOfArgs + 0x8) == 0x36) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried To Force You To Join A Dardos!", senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)(addressOfArgs + 0x8) == 0x37) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried To Force You To Join A Golf!", senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)(addressOfArgs + 0x8) == 0x38) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried To Force You To Join A Random Job!", senderName);
		print(scriptEventDialogText);
		// lastAttacker = senderName;
		// sms_ip_attacker(senderName);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0xD8) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s  ~w~Tried To Give You %i RP!",
			senderName, *(int*)(addressOfArgs + 0x8));
		print(scriptEventDialogText);
		// lastAttacker = senderName;
		// sms_ip_attacker(senderName);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x16C) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried Forcing You Into Apartment!", senderName);
		print(scriptEventDialogText);
		// lastAttacker = senderName;
		// sms_ip_attacker(senderName);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x23) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried To Activate Broadcast App!", senderName);
		print(scriptEventDialogText);
		// lastAttacker = senderName;
		// sms_ip_attacker(senderName);
		*(int*)addressOfArgs = 0;
	}
	if (*(int*)addressOfArgs == 0x24) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried To Desactivate Broadcast App!", senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x98) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s  ~w~Tried Fake Join Job Message!",
			senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x37) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s Tried To Kick You From Your Car!",
			senderName);
		print(scriptEventDialogText, 5000);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x29) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText),
			"~b~%s  ~w~Tried To Send DeathMatch Invite!", senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x1E) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s  ~w~Tried Play Sound Type 0!",
			senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x1F) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s  ~w~Tried Play Sound Type?!",
			senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}

	if (*(int*)addressOfArgs == 0x187198C) {
		snprintf(scriptEventDialogText, sizeof(scriptEventDialogText), "~b~%s  ~w~Tried Change Weather!",
			senderName);
		print(scriptEventDialogText);
		*(int*)addressOfArgs = 0;
	}
	return _0x0012C8D60(r3, senderData, recieverData, r6, r7, r8, r9);
}
void notify_attacks() { // call this on game start to set it up aka put in Hook()
	*(int*)(0x1C6BD80) =
		*(int*)(/*this returns the opd struct address Function*/ (int)&scriptEventDetour); // same
	*(int*)((0x1C6BD80 + 0x4)) =
		*(int*)(/*this returns the opd struct address TOC*/ (int)&scriptEventDetour + 0x4);
}
//idk forum
void TN_Stub(int r3, int r4) {
	r3 = 0; // Definindo o valor de r3 diretamente
}
int TN_Hook(int r3, int r4) {
	if (*(int*)0x17087CC > 7 && *(int*)0x17087CC < 11) {     // BLES -> 0x17087CC BLUS ->0x170864C
		print("~w~Someone Tried Freeze You with Black Screen!"); // dont work
		return 0; // Interrompe a execução, caso a condição seja atendida
	}
	else {
		TN_Stub(r3, r4); // Chama a função original
		return 1;        // Retorna sucesso
	}
}
void blackscreen_p() {
	HookFunctionStart(0x8A2430, (int)TN_Stub, (int)TN_Hook); // BLES -> 0x8A2430 // BLUS ->0x8A2260
}

// ta correto

void teleport_to_client(int selectedPlayer) {
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(selectedPlayer, 1);
	if (PED::IS_PED_SITTING_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID()))
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Coords.x, Coords.y,
			Coords.z, 1, 0, 0, 1);
	else
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z, 1, 0, 0, 1);
}



void teleport_client_to_me(int playerid, char* anim, char* animid, float X, float Y, float Z) {
	AI::CLEAR_PED_TASKS_IMMEDIATELY(playerid);
	Vector3 pedpos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerid, 0.0f, 0.0f, 0.0f);
	int scene2 = NETWORK_CREATE_SYNCHRONISED_SCENE_3(X, Y, Z, 0.0, 0.0, 0.0, 2, 0, 0, 0, 0, 0);
	NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE_3(playerid, scene2, anim, animid, 8.0f, -8.0, 5, 0, 30, 0);
	NETWORK::NETWORK_START_SYNCHRONISED_SCENE(scene2);
}




void freeze_teleport(int selectedPlayer)
{
	int player = PLAYER::GET_PLAYER_PED(selectedPlayer);
	STREAMING::REQUEST_ANIM_DICT("oddjobs@bailbond_mountain");
	if (STREAMING::HAS_ANIM_DICT_LOADED("oddjobs@bailbond_mountain"))
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(player);
		Vector3 pedpos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(player, 0.0, 0.0, 0.0);
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		int SceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(Coords.x, Coords.y, Coords.z, 0.0, +1.5, 0.0, 2, 0, 1, 1.0, 0.0f, 1.0);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(player, SceneID, "oddjobs@bailbond_mountain", "excited_idle_c", 8.0f, -8.0, 6, 0, 100.0, 1);
		NETWORK::NETWORK_ATTACH_SYNCHRONISED_SCENE_TO_ENTITY(SceneID, player, 0);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(SceneID);
	}
}




Vector3 TPCoords;
void ChangeCoords(Vector3 Coords) {
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0)) {
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, 0), Coords.x, Coords.y, Coords.z, 0, 0, 0,
			1);
	}
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}

void drawInfos(char* A, char* B, char* C, char* D) {
	// DisplayText("~g~Lobby Info:", 6, 0.225, 0.730, 0.590, 0.590, 255, 255, 255, 255, false);
	drawText(C, 6, 0.225, 0.780, 0.590, 0.590, 255, 255, 255, 255, false);
	// DisplayText(D, 6, 0.225, 0.790, 0.590, 0.590, 255, 255, 255, 255, false);
}

void setupdraw() {
	UI::SET_TEXT_FONT(0);
	UI::SET_TEXT_SCALE(0.4f, 0.4f);
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(0);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
}

void drawstring(char* text, float X, float Y) {
	UI::_SET_TEXT_ENTRY("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_DRAW_TEXT(X, Y);
}

void clear_area() {
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	float radius = 10.0f;
	// GAMEPLAY::CLEAR_AREA(Pos.x, Pos.y, Pos.z, radius, true, true, true, true);
	GAMEPLAY::CLEAR_AREA_OF_COPS(Pos.x, Pos.y, Pos.z, radius, false);
	GAMEPLAY::CLEAR_AREA_OF_OBJECTS(Pos.x, Pos.y, Pos.z, radius, false);
	GAMEPLAY::CLEAR_AREA_OF_VEHICLES(Pos.x, Pos.y, Pos.z, radius, false, false, false, false, false);
	GAMEPLAY::CLEAR_AREA_OF_PEDS(Pos.x, Pos.y, Pos.z, radius, false);
	GAMEPLAY::CLEAR_AREA_OF_PROJECTILES(Pos.x, Pos.y, Pos.z, radius, false);
}

char opt[100];
void drawTextJustify(char* text, int font, float x, float y, float scalex, float scaley, int r, int g, int b,
	int a) {
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_DROPSHADOW(5, 5, 5, 0, 80);
	UI::SET_TEXT_EDGE(2, 255, 255, 255, 150);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}

bool Is_Player_Friend(Player player) {
	bool BplayerFriend = false;
	bool bplayerFriend = false;
	int handle[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYERTEST(player, &handle[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID2(&handle[0], 13)) {
		BplayerFriend = NETWORK::NETWORK_IS_FRIEND(&handle[0]);
	}
	if (BplayerFriend)
		bplayerFriend = true;
	else
		bplayerFriend = false;

	return bplayerFriend;
}

void drawTextRightJustify1(char* text, int font, float x, float y, float scalex, float scaley, int r, int b,
	int g, int a, int vari = 0) {
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0) {
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_RIGHT_JUSTIFY(true);
		UI::SET_TEXT_WRAP(0.0f, 0.40f); //(0.1f, .714f);
		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		if (currentOption == optionCount) {
			UI::SET_TEXT_COLOUR(0, 0, 0, 255);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);
			snprintf(opt, sizeof(opt), "%s", text);
		}
		else {
			UI::SET_TEXT_COLOUR(r, g, b, a);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);
			;
		}
		UI::_DRAW_TEXT(x, y);
	}
}
void drawTexJustify(char* text, int font, float x, float y, float scalex, float scaley, int r, int g, int b,
	int a) {
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_DROPSHADOW(5, 5, 5, 0, 80);
	UI::SET_TEXT_EDGE(2, 255, 255, 255, 150);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}

opd_s GET_TIME_SINCE_LAST_ARREST_t = { 0x424DCC, TOC };
int GlobalToAddress(int Global, int imm) {
	return (int)(GLOBALPTR + ((Global & 0xFFFFFF) >> 16 & 0xFFFC) + (imm * 4));
}
int ReadGlobal(int Global, int imm) { return *(int*)(GlobalToAddress(Global, imm)); }
int Read_Global(int a_uiGlobalID) {
	int Ptr = *(int*)((TunablePointer - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	if (Ptr != 0)
		return *(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4));
	return 0;
}
int getPlayerStat(int player, int stat) { return Read_Global(1581767 + (player * 306) + stat); }
int getPlayerRank(int player) { return getPlayerStat(player, 185); }
int getPlayerCash(int player) { return getPlayerStat(player, 182); }

int Read_GlobalKD(int a_uiGlobalID) {
	int Ptr = *(int*)((0x1E70374 - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	if (Ptr != 0)
		return *(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4));
	return 0;
}

float ItoF(int input) {
	float Output = *(float*)&input;
	return Output;
}

void consulta(bool isSelected) {
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0) {

		const char* playerName = PLAYER::GET_PLAYER_NAME(selectedPlayer);
		char playerNameBuffer[100];
		strncpy(playerNameBuffer, playerName, sizeof(playerNameBuffer) - 1);
		playerNameBuffer[sizeof(playerNameBuffer) - 1] = '\0';

		// drawText(playerNameBuffer, 6, 0.265f, 0.105f, 0.5f, 0.5f, 255, 255, 255, 255, false);

		GRAPHICS::DRAW_RECT(0.255f, 0.165f, 0.09f, 0.040f, 0, 0, 0, 200); // banner de cima
		GRAPHICS::DRAW_RECT(0.255f, 0.395f, 0.09f, 0.420f, 0, 0, 0, 140); // background
		GRAPHICS::DRAW_RECT(0.255f, 0.615f, 0.09f, 0.020f, 0, 0, 0, 200); // banner de baixo

		int KD = Read_GlobalKD(1581972 + (306 * selectedPlayer));
		float KD_Float = ItoF(KD);
		char KD_buf[90];
		char* KD_String = FtoS(KD_Float);
		char apnet[4][50];
		char apnetk[50];
		char buffer_acc_region[2][3];
		char Cash[50];
		char Rank[50];
		char Health[50];
		char Armour[50];
		char DeadOrAlive[50];
		char IsArmed[50];
		char InVehicle[50];
		char Vehicle[50];
		char CoordsX[50];
		char CoordsY[50];
		char CoordsZ[50];
		char modder_check[50];

		Player ui_slectedPlayer = selectedPlayer, ui_currentPlayer = currentOption - 1;
		Player OnlinePlayer = PLAYER::GET_PLAYER_PED(isSelected ? ui_slectedPlayer : ui_currentPlayer);
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(OnlinePlayer, 1);
		sprintf(Cash, "%i", getPlayerCash(isSelected ? ui_slectedPlayer : ui_currentPlayer));
		sprintf(Rank, "%i", getPlayerRank(isSelected ? ui_slectedPlayer : ui_currentPlayer));
		sprintf(Health, "%i/%i", ENTITY::GET_ENTITY_HEALTH(OnlinePlayer),
			ENTITY::GET_ENTITY_MAX_HEALTH(OnlinePlayer));
		sprintf(Armour, "%i", PED::GET_PED_ARMOUR(OnlinePlayer));
		sprintf(IsArmed, "%s", WEAPON::IS_PED_ARMED(OnlinePlayer, 7) ? "Yes" : "No");
		snprintf(KD_buf, sizeof(KD_buf), "%s", KD_String);
		sprintf(InVehicle, "%s", PED::IS_PED_IN_ANY_VEHICLE(OnlinePlayer, 1) ? "Yes" : "No");
		sprintf(DeadOrAlive, "%s", PED::_IS_PED_DEAD(OnlinePlayer, 1) ? "No" : "Yes");
		sprintf(modder_check, "%s",
			NETWORK::NETWORK_PLAYER_IS_ROCKSTAR_DEV(OnlinePlayer) ? "Ya"
			: "No"); // in dev... this shit not work idk
		sprintf(CoordsX, "%i", (int)Coords.x);
		sprintf(CoordsY, "%i", (int)Coords.y);
		sprintf(CoordsZ, "%i", (int)Coords.z);

		for (int i = 0; i < 34; i++) {
			int Handle[13];
			NETWORK::NETWORK_HANDLE_FROM_PLAYER2(isSelected ? ui_slectedPlayer : ui_currentPlayer, &Handle[0], 13);
			char* RealName = NETWORK::NETWORK_GET_GAMERTAG_FROM_HANDLE(&Handle[0]);
			char* ipName = ReadBytes(0x40025C80 + (i * 136), 100);
			if (!strcmp(RealName, ipName)) {
				int ip = *(int*)(0x40025CC8 + (i * 0x88));
				int p1 = (ip & 0xff000000) >> 24;
				int p2 = (ip & 0x00ff0000) >> 16;
				int p3 = (ip & 0x0000ff00) >> 8;
				int p4 = (ip & 0x000000ff) >> 0;

				int internal_ip = *(int*)(0x40025CA8 + (i * 0x88));
				int p5 = (internal_ip & 0xff000000) >> 24;
				int p6 = (internal_ip & 0x00ff0000) >> 16;
				int p7 = (internal_ip & 0x0000ff00) >> 8;
				int p8 = (internal_ip & 0x000000ff) >> 0;

				char* Region = ReadBytes(0x40025c96 + (i * 0x88), 100);

				int port = *(int*)(0x40025ccd + (i * 0x88));
				int p9 = (port & 0xff000000) >> 24;
				int p10 = (port & 0x00ff0000) >> 16;
				int portToShow = (p9 << 8) | p10;

				sprintf(apnet[0], "%i.%i.%i.%i", p1, p2, p3, p4);
				sprintf(apnet[1], "%i.%i.%i.%i", p5, p6, p7, p8);
				sprintf(apnet[2], "%s", Region);
				sprintf(apnet[3], "%i", portToShow);

				if (strstr(apnet[0], "255.255.255.255") == NULL && strstr(apnet[0], "0.0.0.0") == NULL) {
					strcpy(buffer_acc_region[0], apnet[2]);
					memcpy(buffer_acc_region[1], buffer_acc_region[0], strlen(buffer_acc_region[0]) - 3);

					drawTextJustify(apnet[0], 6, .262, .185, 0, .38, 255, 255, 255, 255);             // ip
					drawTextJustify(apnet[1], 6, .280, .205, 0, .38, 255, 255, 255, 255);             // internal ip
					drawTextJustify(buffer_acc_region[1], 6, .285, .265, 0, .38, 255, 255, 255, 255); // region
				}
			}
		}

		drawText("IP:", 6, .215, .185, 0, .38, 255, 255, 255, 255, 0);
		drawText("Internal:", 6, .215, .205, 0, .38, 255, 255, 255, 255, 0);
		drawText("City:", 6, .215, .225, 0, .38, 255, 255, 255, 255, 0);
		drawText("State:", 6, .215, .245, 0, .38, 255, 255, 255, 255, 0);
		drawText("Country:", 6, .215, .265, 0, .38, 255, 255, 255, 255, 0);
		drawText("PSN Account:", 6, .215, .285, 0, .38, 255, 255, 255, 255, 0);

		drawText("Cash:", 6, .215, .305, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(Cash, 6, .240, .305, 0, .38, 255, 255, 255, 255);

		drawText("Rank:", 6, .215, .325, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(Rank, 6, .250, .325, 0, .38, 255, 255, 255, 255);

		drawText("Health:", 6, .215, .345, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(Health, 6, .250, .345, 0, .38, 255, 255, 255, 255);

		drawText("Armour:", 6, .215, .365, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(Armour, 6, .245, .365, 0, .38, 255, 255, 255, 255);

		drawText("Armed:", 6, .215, .385, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(IsArmed, 6, .240, .385, 0, .38, 255, 255, 255, 255);

		drawText("KD:", 6, .215, .405, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(KD_buf, 6, .235, .405, 0, .38, 255, 255, 255, 255);

		drawText("In Vehicle:", 6, .215, .425, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(InVehicle, 6, .250, .425, 0, .38, 255, 255, 255, 255);

		drawText("Alive:", 6, .215, .445, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(DeadOrAlive, 6, .235, .445, 0, .38, 255, 255, 255, 255);

		drawText("X Coord:", 6, .215, .465, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(CoordsX, 6, .260, .465, 0, .38, 255, 255, 255, 255);

		drawText("Y Coord:", 6, .215, .485, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(CoordsY, 6, .260, .485, 0, .38, 255, 255, 255, 255);

		drawText("Z Coord:", 6, .215, .505, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(CoordsZ, 6, .260, .505, 0, .38, 255, 255, 255, 255);

		drawText("Modder:", 6, .215, .525, 0, .38, 255, 255, 255, 255, 0);
		drawTextJustify(modder_check, 6, .260, .525, 0, .38, 255, 255, 255, 255);
	}
}

void TakeWeaponsClient() { WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1); }

void GiveAllWeapons(int Pedhandle) {
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1716189206, -1, true, true); // WEAPON_KNIFE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1737195953, -1, true,
		true); // WEAPON_NIGHTSTICK
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1317494643, -1, true, true);  // WEAPON_HAMMER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1786099057, -1, true, true); // WEAPON_BAT
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1141786504, -1, true, true); // WEAPON_GOLFCLUB
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -2067956739, -1, true, true); // WEAPON_CROWBAR
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 453432689, -1, true, true);   // WEAPON_PISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1593441988, -1, true,
		true); // WEAPON_COMBATPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 584646201, -1, true, true); // WEAPON_APPISTO
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1716589765, -1, true,
		true);                                                         // WEAPON_PISTOL50
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 324215364, -1, true, true); // WEAPON_MICROSMG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 736523883, -1, true, true); // WEAPON_SMG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -270015777, -1, true,
		true); // WEAPON_ASSAULTSMG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1074790547, -1, true,
		true); // WEAPON_ASSAULTRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -2084633992, -1, true,
		true); // WEAPON_CARBINERIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1357824103, -1, true,
		true); // WEAPON_ADVANCEDRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1660422300, -1, true, true); // WEAPON_MG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2144741730, -1, true, true); // WEAPON_COMBATMG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 487013001, -1, true,
		true); // WEAPON_PUMPSHOTGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2017895192, -1, true,
		true); // WEAPON_SAWNOFFSHOTGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -494615257, -1, true,
		true); // WEAPON_ASSAULTSHOTGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1654528753, -1, true,
		true); // WEAPON_BULLPUPSHOTGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 911657153, -1, true,
		true); // WEAPON_STUNGUN**********************
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 100416529, -1, true,
		true); // WEAPON_SNIPERRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 205991906, -1, true,
		true); // WEAPON_HEAVYSNIPER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1568386805, -1, true,
		true); // WEAPON_GRENADELAUNCHER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1312131151, -1, true, true); // WEAPON_RPG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1752584910, -1, true, true); // WEAPON_STINGER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1119849093, -1, true, true); // WEAPON_MINIGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -1813897027, -1, true, true); // WEAPON_GRENADE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 741814745, -1, true,
		true); // WEAPON_STICKYBOMB
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -37975472, -1, true,
		true); // WEAPON_SMOKEGRENADE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), -615608432, -1, true, true); // WEAPON_MOLOTOV
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 101631238, -1, true,
		true); // WEAPON_FIREEXTINGUISHER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 883325847, -1, true, true); // WEAPON_PETROLCAN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 600439132, -1, true, true);  // WEAPON_BALL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1233104067, -1, true, true); // WEAPON_FLARE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1627465347, -1, true,
		true); // WEAPON_GUSENBERG
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 4192643659, -1, true, true); // WEAPON_BOTTLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3231910285, -1, true,
		true); // WEAPON_SPECIALCARBINE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3523564046, -1, true,
		true); // WEAPON_HEAVYPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3218215474, -1, true,
		true); // WEAPON_SNSPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2132975508, -1, true,
		true); // WEAPON_BULLPUPRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2460120199, -1, true, true); // WEAPON_DAGGER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 137902532, -1, true,
		true); // WEAPON_VINTAGEPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2138347493, -1, true, true); // WEAPON_FIREWORK
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2828843422, -1, true, true); // WEAPON_MUSKET
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 984333226, -1, true,
		true); // WEAPON_HEAVYSHOTGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3342088282, -1, true,
		true); // WEAPON_MARKSMANRIFLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1672152130, -1, true,
		true); // WEAPON_HOMINGLAUNCHER
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 2874559379, -1, true, true); // WEAPON_PROXMINE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 126349499, -1, true, true); // WEAPON_SNOWBALL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 1198879012, -1, true, true); // WEAPON_FLAREGUN
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 171789620, -1, true, true); // WEAPON_COMBATPDW
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3696079510, -1, true,
		true); // WEAPON_MARKSMANPISTOL
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 3638508604, -1, true, true); // WEAPON_KNUCKLE
	WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(Pedhandle), 4222310262, -1, true,
		true); // GADGET_PARACHUTE
}

void addOptionRightJustify(char* option, int vari = 0) {
	if (currentOption <= maxOptions && optionCount <= maxOptions) // guiTextOpacity guiOpacity
		drawTextJustify(option, 4, textXCoord + .215, (optionCount * 0.035f + 0.123f), .57, .52, 255, 0, 255,
			255);
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
		drawTextJustify(option, 4, textXCoord + .215,
			((optionCount - (currentOption - maxOptions)) * 0.035f + 0.123f), .57, .52, 255, 0, 255,
			255);
}

void cleartasks() {
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
	ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), false);
}

void clear_task_lobby() {
	for (int i = 0; i < 18; i++) {
		if (i == PLAYER::PLAYER_ID())
			continue;
		AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(i));
	}
}
void ForceSaveGame() {
	if (!STATS::STAT_SAVE_PENDING()) {
		GAMEPLAY::DO_AUTO_SAVE();
		print("~g~Saving...");
	}
	else {
		print("~g~Salved..");
	}
}

// NO PLAYER

void disable_selectedPlayer_passive_mode(int selectedPlayer) {
	int Args[3];
	Args[0] = 0x118;
	Args[1] = selectedPlayer;
	Args[2] = 0;
	TriggerScriptEvent(Args, 3, selectedPlayer);
}
void enable_broadcast_app(int selectedPlayer) {
	int Args[3];
	Args[0] = 2;
	Args[1] = selectedPlayer;
	Args[2] = 0x23; // 35
	TriggerScriptEvent(Args, 3, selectedPlayer);
}
void desactive_broadcast_app(int selectedPlayer) {
	int Args[3];
	Args[0] = 2;
	Args[1] = selectedPlayer;
	Args[2] = 0x24; // 36
	TriggerScriptEvent(Args, 3, selectedPlayer);
}
void send_mensage(int selectedPlayer, char* message) {
	int Args[2];
	Args[0] = 0x98;
	Args[1] = selectedPlayer;
	TriggerScriptEvent(Args, 2, selectedPlayer);
}
void fake_join_job_menssage(int selectedPlayer) // fake_join_job_menssage
{
	int Args[2];
	Args[0] = 152;
	Args[1] = selectedPlayer;
	TriggerScriptEvent(Args, 2, selectedPlayer);
}
void force_partida(int sender, int reciever) // force_deathmatch
{
	int Args[2];
	Args[0] = 0x29;
	Args[1] = sender;
	TriggerScriptEvent(Args, 2, selectedPlayer);
}

void tentar_desconectar_outros_sessao(int selectedPlayer) // drop_net_event
{
	int Args[4];
	Args[0] = 290;
	Args[1] = selectedPlayer;
	Args[2] = -1;
	Args[3] = 8;
	TriggerScriptEvent(Args, 4, selectedPlayer);
}

void leave_dialog(int selectedPlayer) {
	int Args[2];
	Args[0] = 193;
	Args[1] = (selectedPlayer);
	TriggerScriptEvent(Args, 2, selectedPlayer);
}

void give_bounty(int selectedPlayer) {
	int Var0[20];
	Var0[0] = 58;
	Var0[1] = selectedPlayer;
	Var0[2] = selectedPlayer;
	Var0[3] = selectedPlayer + 1;
	Var0[4] = 1;
	Var0[5] = 2;
	Var0[6] = 3;
	Var0[7] = 4;
	Var0[8] = 5;
	Var0[9] = 6;
	Var0[10] = 7;
	Var0[11] = 8;
	Var0[12] = selectedPlayer + 2;
	Var0[13] = 1;
	Var0[14] = 2;
	Var0[15] = 3;
	Var0[16] = 4;
	Var0[17] = 2000000;
	Var0[18] = 5;
	Var0[19] = 1;
	SET_BIT(&Var0[16], 0);
	TriggerScriptEvent(Var0, 20, selectedPlayer);
}

void event_kill(int selectedPlayer) // talvez faz ele nao renascer
{

	int Args[9];
	Args[0] = 0x0;
	Args[1] = selectedPlayer; // cash giver (them cuz they refund themself)
	Args[2] = 0x67;           // 46
	Args[3] = 0;
	Args[4] = 0;
	Args[5] = selectedPlayer;
	Args[6] = 0;
	Args[7] = 0;
	Args[8] = 0;
	TriggerScriptEvent(Args, 9, selectedPlayer);
}

void change_selectedPlayer_weather(int selectedPlayer, char* weather = "RAIN") {
	int Args[3];
	Args[0] = 16;
	Args[1] = selectedPlayer;
	Args[2] = 0x187198C;
	TriggerScriptEvent(Args, 3, selectedPlayer);
}

void selectedPlayerProperty(int selectedPlayer, int arg1, int arg2, int arg3) {
	int Args[5];
	Args[0] = 364;
	Args[1] = selectedPlayer; // apartment of this selectedPlayer
	Args[2] = 0;
	Args[3] = 0;
	Args[4] = 0;
	TriggerScriptEvent(Args, 5, selectedPlayer);
}

void delete_phone_hud2(int selectedPlayer) {
	int vVar1[3];

	if (selectedPlayer != PLAYER::PLAYER_ID()) // Verifica se o jogador não é o jogador local
	{
		vVar1[0] = 3;
		vVar1[1] = selectedPlayer;
		vVar1[2] = 64;
		TriggerScriptEvent(vVar1, 3, selectedPlayer);
	}
}

void force_queda_de_braco(int selectedPlayer) {
	int Args[4];
	Args[0] = 0x3;
	Args[1] = selectedPlayer;
	Args[2] = 0x35;
	TriggerScriptEvent(Args, 3, selectedPlayer);
}

void ultra_apartment(int selectedPlayer) {
	int Args[8];
	Args[1] = selectedPlayer;
	Args[2] = 10;
	Args[3] = 32;
	Args[4] = 53;
	Args[5] = 0x16c;
	Args[6] = 0;
	Args[7] = 0;
	TriggerScriptEvent(Args, 8, selectedPlayer);
}

void give_blackscreen(int selectedPlayer) {
	int Args1[4];
	Args1[0] = 3;
	Args1[1] = selectedPlayer; // Especifica o jogador alvo
	Args1[2] = 20;
	Args1[3] = -1;
	TriggerScriptEvent(Args1, 4, selectedPlayer);
}

void admin_kick(int selectedPlayer) {
	int Args[5];
	Args[0] = 0x52C17A01;
	Args[1] = selectedPlayer; // Especifica o jogador alvo
	Args[2] = 0xC7C6C7C0;
	Args[3] = 0xC6C7C6C7;
	Args[4] = 0xC7C7C7F1;
	TriggerScriptEvent(Args, 5, selectedPlayer);
}

void sound_loop() {
	int Args[1];
	Args[1] = selectedPlayer;
	TriggerScriptEvent(Args, 1, selectedPlayer);
}

void force_dardos(int selectedPlayer) {
	int Args[3];
	Args[0] = 3;
	Args[1] = selectedPlayer;
	Args[2] = 0x36;
	TriggerScriptEvent(Args, 3, selectedPlayer);
}

void flight_school(int selectedPlayer) {
	int Args[3];
	Args[0] = 0x3;
	Args[1] = selectedPlayer;
	Args[2] = 0x3A;
	TriggerScriptEvent(Args, 0x3, selectedPlayer);
}

void remove_phone_hud(int selectedPlayer) {
	int Args[3];
	Args[0] = 0x3;
	Args[1] = selectedPlayer;
	Args[2] = 0x40;
	TriggerScriptEvent(Args, 0x3, selectedPlayer);
}

void apartment_invitee(int selectedPlayer) {
	int Args[2];
	Args[1] = selectedPlayer;
	Args[2] = 53;
	TriggerScriptEvent(Args, 2, selectedPlayer);
}

void enter_to_apartment(int selectedPlayer) {
	int Args[364];
	Args[1] = selectedPlayer;
	Args[2] = 10;
	Args[2] = 0;
	Args[2] = 0;
	TriggerScriptEvent(Args, 5, selectedPlayer);
}

void apartment_invite(int sender, int reciever) {
	int Args[2];
	Args[0] = 32;
	Args[1] = sender;
	TriggerScriptEvent(Args, 5, selectedPlayer);
}

void apartment_invite2(int selectedPlayerToInvite, int apartmentOwner, int apartmentNum) {
	int Args[3];
	Args[0] = 0x16c;
	Args[1] = 1;
	Args[2] = 1;
	TriggerScriptEvent(Args, 5, selectedPlayer);
}

void force_to_golf(int selectedPlayer) {
	int Args[3];
	Args[0] = 0x3;
	Args[1] = selectedPlayer;
	Args[2] = 0x37;
	TriggerScriptEvent(Args, 0x3, selectedPlayer);
}

void send_to_tutorial(int selectedPlayer) {
	int Args[3];
	Args[0] = 0x3;
	Args[1] = selectedPlayer;
	Args[2] = 0x14;
	TriggerScriptEvent(Args, 0x3, selectedPlayer);
}

void delete_phone_hud(int selectedPlayer) {
	int Args[3];
	Args[0] = 0x3;
	Args[1] = selectedPlayer; // Especifica o jogador alvo
	Args[2] = 0x14;
	TriggerScriptEvent(Args, 0x3, selectedPlayer);
}

void reset_selectedPlayer_view(int selectedPlayer) {
	int Args[3];
	Args[0] = 0x2;
	Args[1] = selectedPlayer;
	Args[2] = 0x2e;
	TriggerScriptEvent(Args, 3, selectedPlayer);
}

void send_to_bad_sport(int selectedPlayer) {
	int Args[4];
	Args[0] = 0x138;
	Args[1] = selectedPlayer;
	Args[2] = 20000;
	Args[3] = 0;
	TriggerScriptEvent(Args, 4, selectedPlayer);
}

void make_fakeleave(int selectedPlayer) {
	int Args[3];
	Args[0] = 0x2;
	Args[1] = selectedPlayer;
	Args[2] = 0x34;
	TriggerScriptEvent(Args, 3, selectedPlayer);
}

void make_sound(int selectedPlayer, int type) // types: 0 or 1
{
	int Args[2];
	Args[0] = 30 + type;
	Args[1] = selectedPlayer;
	TriggerScriptEvent(Args, 2, selectedPlayer);
}

void give_money(int SelectedPlayer) {
	int Args2[5];
	Args2[0] = 219;
	Args2[1] = 40;
	Args2[2] = 100000;
	Args2[3] = 1;
	Args2[4] = 1;
	TriggerScriptEvent(Args2, 5, selectedPlayer);
}

void give_zero_rp(int SelectedPlayer) {
	int Args7[5];
	Args7[0] = 0xD8;
	Args7[1] = selectedPlayer;
	Args7[2] = -2165850; // segundo quandotidade
	Args7[3] = 0;
	Args7[4] = 0;
	TriggerScriptEvent(Args7, 5, selectedPlayer);
}

// NO LOBBY

void derank_rp_lobby(int rp) {
	for (int i = 0; i < 18; i++) {
		if (i == PLAYER::PLAYER_ID())
			continue;
		int Args[5];
		Args[0] = 0xD8;
		Args[1] = i;
		Args[2] = rp;
		Args[3] = 0;
		Args[4] = 0;
		TriggerScriptEvent(Args, 5, i);
	}
}

void rp_loop_jaro666v2(int Rp) {
	for (int i = 0; i < 18; i++) {
		if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()) {
			int Args[5];
			Args[0] = 0xD8;
			Args[1] = i;
			Args[2] = Rp;
			Args[3] = 0;
			Args[4] = 0;
			TriggerScriptEvent(Args, 5, i);
		}
	}
}

void derank_rp(int rpzahl) {
	bool bVar0;
	int Var1[5];

	for (int i = 0; i < 18; i++) {
		if (cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) {
			if (i != PLAYER::PLAYER_ID()) {
				Var1[0] = 216;
				Var1[1] = i;
				Var1[2] = rpzahl;
				Var1[3] = 0;
				Var1[4] = 0;
				TriggerScriptEvent(Var1, 5, i);
			}
		}
		i++;
		if (i < 18) {
		}
	}
}

void enter_apartment() {
	// bool bVar0;
	int args[5];

	// bVar0 = false;
	for (int i = 0; i < 18; i++) {
		if (cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) {
			if (i != PLAYER::PLAYER_ID()) {
				args[0] = 364;
				args[1] = i;
				args[2] = 10;
				args[3] = 0;
				args[4] = 0;
				TriggerScriptEvent(args, 5, i);
			}
		}
		i++;
		if (i < 18) {
		}
	}
}

void reset_cam_lobby() {
	// bool bVar0;
	int vVar1[3];

	// bVar0 = false;
	for (int i = 0; i < 18; i++) {
		if (cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) {
			if (i != PLAYER::PLAYER_ID()) {
				vVar1[0] = 2;
				vVar1[1] = i;
				vVar1[2] = 46;
				TriggerScriptEvent(vVar1, 3, i);
			}
		}
		i++;
		if (i < 18) {
		}
	}
}
void delete_phone_hud() {
	// bool bVar0;
	int vVar1[3];

	// bVar0 = false;
	for (int i = 0; i < 18; i++) {
		if (cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) {
			if (i != PLAYER::PLAYER_ID()) {
				vVar1[0] = 3;
				vVar1[1] = i;
				vVar1[2] = 64;
				TriggerScriptEvent(vVar1, 3, i);
			}
		}
		i++;
		if (i < 18) {
		}
	}
}

// Vector3 vVar0;
// Vector3 uVar1;
//
// void weedgun()
//{
//	// Definindo uVar0 e uVar1 como Vector3
//	float uVar0;
//	Vector3 uVar1;
//
//	// Verifique se o jogador está disparando
//	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
//	{
//		// Aqui passamos &uVar0 como ponteiro de Vector3
//		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &uVar0))
//		{
//			// Copia as coordenadas de uVar0 para uVar1
//			uVar1.x = uVar0.x;
//			uVar1.y = uVar0.y;
//			uVar1.z = uVar0.z;
//
//			// Atualizando valores de memória. Certifique-se de que os endereços são válidos.
//			*(int*)11060008 = 1317011488;
//			*(int*)10466252 = 1317011488;
//			*(int*)10466248 = 1317011488;
//			*(int*)11060008 = 1317011488;
//			*(int*)10466252 = 1317011488;
//			*(int*)10466248 = 1317011488;
//		}
//	}
// }
// void frzgun()
//{
//	float uVar0;
//	Vector3 uVar1;
//
//	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
//	{
//		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &uVar0))
//		{
//			uVar1.x = uVar0.x;
//			uVar1.y = uVar0.y;
//			uVar1.z = uVar0.z;
//			enter_apartment();
//			delete_phone_hud();
//			derank_rp(-9999999);
//			derank_rp(-6666666);
//			derank_rp(9999999);
//			derank_rp(6666666);
//			*(int*)11060008 = 1317011488;
//			*(int*)10466252 = 1317011488;
//			*(int*)10466248 = 1317011488;
//			*(int*)11060008 = 1317011488;
//			*(int*)10466252 = 1317011488;
//			*(int*)10466248 = 1317011488;
//		}
//	}
// }

// void friends()
//{
//	// Adiciona o título "Friends List"
//	addTitle("Friends List");
//
//	// Itera pela lista de amigos (máximo de 18)
//	for (int i = 0; i < 18; i++)
//	{
//		// Obtém o nome do amigo da lista e adiciona como uma opção no menu
//		const char* friendName = NETWORK::NETWORK_GET_FRIEND_NAME(i); // Corrigido: usa o índice do
//amigo 		if (friendName != nullptr) // Verifica se o nome do amigo foi obtido com sucesso
//		{
//			addOption(friendName);
//		}
//	}
//
//	// Verifica se o botão X foi pressionado e se o amigo selecionado está online
//	if (PressX && PLAYER::IS_PLAYER_ONLINE(currentOption - 1))
//	{
//		// Define o jogador selecionado com base na opção atual do menu
//		selectedPlayer = currentOption - 1;
//
//		// Troca para o menu FriendsList
//		ChangeMenu(FriendsList);
//	}
// }
//
//// Lógica para o menu FriendsList
// void FriendsList()
//{
//	// Mostra as informações do amigo selecionado
//	FriendsInfo(true, selectedPlayer);
//
//	// Adiciona o título com o nome do amigo selecionado
//	const char* selectedFriendName = NETWORK::NETWORK_GET_FRIEND_NAME(selectedPlayer);
//	if (selectedFriendName != nullptr) // Verifica se o nome foi obtido
//	{
//		addTitle(selectedFriendName);
//	}
// }

void subTitle(char* title) {
	drawText(title, 0, SubTitleXCoord, 0.18f, 0.35f, 0.35f, bannerTextRed, bannerTextGreen, bannerTextBlue, 255,
		false);
}

void setAnimation(char* anim, char* animid) {
	Anim = anim;
	AnimID = animid;
	LoadingAnim = true;
}

void setPlayerAnimation(char* anim, char* animid) {
	Anim = anim;
	AnimID = animid;
	LoadingPlayerAnim = true;
}

void toggleIPL(const char* IPLName) {
	char* mutableIPLName = const_cast<char*>(IPLName);
	if (STREAMING::IS_IPL_ACTIVE(mutableIPLName)) {
		STREAMING::REMOVE_IPL(mutableIPLName);
	}
	else {
		STREAMING::REQUEST_IPL(mutableIPLName);
	}
}

const char* ReadString(const char* address) {
	if (address == nullptr) // Verifica se o endereço é inválido
		return nullptr;

	return address; // Retorna a string no endereço
}



void notify_change_model() {
	int currentPlayer = 0;
	int maxPlayers = 18;
	char messageBuffer[128];
	char suffix[] = "~b~ Changed The PED Model";

	unsigned int femaleModelHash = 0x9C9EFFD8;
	unsigned int maleModelHash = 0x705E61F2;

	static unsigned int lastPlayerModel[18] = { 0 };

	while (currentPlayer < maxPlayers) {
		if (NETWORK::NETWORK_IS_PLAYER_ACTIVE(currentPlayer)) {
			if (currentPlayer != PLAYER::PLAYER_ID()) {
				int playerModel = ENTITY::GET_ENTITY_MODEL(PLAYER::GET_PLAYER_PED(currentPlayer));
				if (playerModel != femaleModelHash && playerModel != maleModelHash) {
					if (playerModel != lastPlayerModel[currentPlayer]) {
						strncpy(messageBuffer, PLAYER::GET_PLAYER_NAME(currentPlayer), sizeof(messageBuffer) - 1);
						messageBuffer[sizeof(messageBuffer) - 1] = '\0';
						strncat(messageBuffer, suffix, sizeof(messageBuffer) - strlen(messageBuffer) - 1);

						char modelHashBuffer[32];
						snprintf(modelHashBuffer, sizeof(modelHashBuffer), "~w~(0x%08X)", playerModel);
						strncat(messageBuffer, modelHashBuffer, sizeof(messageBuffer) - strlen(messageBuffer) - 1);

						print(messageBuffer, 2000);
					}

					lastPlayerModel[currentPlayer] = playerModel;
				}
			}
		}
		currentPlayer++;
	}
}



//void notify_change_model() { //COM DELAY DE 1 SEGUNDO PRA NAO TRAVAR
//	int currentPlayer = 0;
//	int maxPlayers = 18;
//	char messageBuffer[128];
//	char suffix[] = "~b~ Changed The PED Model";
//	static int lastNotificationTime = 0;
//
//	unsigned int femaleModelHash = 0x9C9EFFD8;
//	unsigned int maleModelHash = 0x705E61F2;
//
//	static unsigned int lastPlayerModel[18] = { 0 };
//
//	while (currentPlayer < maxPlayers) {
//		if (NETWORK::NETWORK_IS_PLAYER_ACTIVE(currentPlayer)) {
//			if (currentPlayer != PLAYER::PLAYER_ID()) {
//				int playerModel = ENTITY::GET_ENTITY_MODEL(PLAYER::GET_PLAYER_PED(currentPlayer));
//
//				if (playerModel != lastPlayerModel[currentPlayer]) {
//					strncpy(messageBuffer, PLAYER::GET_PLAYER_NAME(currentPlayer), sizeof(messageBuffer) - 1);
//					messageBuffer[sizeof(messageBuffer) - 1] = '\0';
//					strncat(messageBuffer, suffix, sizeof(messageBuffer) - strlen(messageBuffer) - 1);
//
//					char modelHashBuffer[32];
//					snprintf(modelHashBuffer, sizeof(modelHashBuffer), "~w~(0x%08X)", playerModel);
//					strncat(messageBuffer, modelHashBuffer, sizeof(messageBuffer) - strlen(messageBuffer) - 1);
//
//					if (lastNotificationTime <= GAMEPLAY::GET_GAME_TIMER()) {
//						print(messageBuffer, 1600);
//						lastNotificationTime = GAMEPLAY::GET_GAME_TIMER() + 1000;
//					}
//				}
//				lastPlayerModel[currentPlayer] = playerModel;
//			}
//		}
//		currentPlayer++;
//	}
//}



void freeze_host_bug(float x, float y, float z) {
	CAM::_ANIMATE_GAMEPLAY_CAM_ZOOM(1.0f, 1500.0f);
	Entity player = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(player, false)) {
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(player, false);
		int randomRotation = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 360);
		ENTITY::SET_ENTITY_COORDS(vehicle, x, y, z, false, false, false, true);
		ENTITY::SET_ENTITY_ROTATION(vehicle, 0.0f, 0.0f, (float)randomRotation, 2,
			true);
	}
	else {
		int randomRotation = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 360);
		ENTITY::SET_ENTITY_COORDS(player, x, y, z, false, false, false, true);
		ENTITY::SET_ENTITY_ROTATION(player, 0.0f, 0.0f, (float)randomRotation, 2,
			true);
	}
	if (GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 2) == 0) {
		float randomOffsetX =
			(float)GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-5, 5); 
		float randomOffsetY =
			(float)GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-5, 5);
		float randomOffsetZ =
			(float)GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-5, 5);
		ENTITY::SET_ENTITY_COORDS(player, x + randomOffsetX, y + randomOffsetY, z + randomOffsetZ, false, false,
			false, true);
	}
	CAM::_ANIMATE_GAMEPLAY_CAM_ZOOM(1.0f, 1500.0f);
	if (GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 5) == 0) {
		AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "GENERIC_ERROR", player, "DLC_HEIST_HACKING_SOUNDS", false,
			0);
	}
}

Hash WepArray[59] = { 0x42BF8A85, 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD,
0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF,
0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318,
0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x5FC3C11, 0xC472FE2, 0xA284510B, 0x4DD2DC56,
0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0xA0973D5E,
0x24B17070, 0x60EC506, 0x34A67B97, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683,
0xD205520E, 0xBFD21232, 0x92A27487, 0x83839C4, 0xA89CB99E, 0xC0A3098D, 0x7F229F94,
0x7F7497E5, 0x787F0BB, 0xAB564B93, 0x63AB0442, 0x47757124, 0xA3D4D34, 0x3AABBBAA,
0xC734385A, 0xA3D4D34, 0xDC4DB296 };

Hash Props[132] = {
	0xB467C540, /*p_spinning_anus_s*/
	0xC2BC19CD, /*p_cs_mp_jet_01_s*/
	0xC42C019A, /*prop_ld_ferris_wheel*/
	0xFB631122, /*prop_bumper_car_01*/
	0x745F3383, /*prop_windmill_01*/
	0xBF8918DE, /*prop_jetski_ramp_01*/
	0xB157C9E4, /*prop_mp_ramp_01*/
	0xF4F1511E, /*prop_mp_ramp_02*/
	0x93948E5E, /*prop_mp_ramp_03*/
	0x6DB9599A, /*prop_bskball_01*/
	0x2E28CA22, /*p_tram_crash_s*/
	0xC079B265, /*prop_beach_fire*/
	0xE8032E4,  /*prop_weed_pallet*/
	0x8973A868, /*prop_air_bigradar*/
	0x8E8C7A5B, /*prop_crashed_heli*/
	0xBD8AE007, /*prop_space_pistol*/
	0x6F9939C7, /*prop_ld_toilet_01*/
	0x4B3D240F, /*prop_wheelchair_01*/
	0x961CCC04, /*prop_cs_trolley_01*/
	0xE3BA450,  /*Xmas Tree*/
	0x7121AC4,  /*Large Xmas Tree*/
	0xB7C30A72, /*prop_tv_06*/
	0xF0A61994, /*prop_bong_01*/
	0xED2E79F0, /*prop_cs_ice_locker*/
	0x37FDC243, /*prop_mp_cone_01*/
	0x35AE1F39, /*prop_air_stair_03*/
	0xF7FCF988, /*prop_bank_vaultdoor*/
	0xE0264F5D, /*prop_roadcone01a*/
	0x6B795EBC, /*prop_alien_egg_01*/
	0x1405669B, /*prop_boxing_glove_01*/
	0x671C5C38, /*prop_boombox_01*/
	0xE6CB661E, /*prop_cs_dildo_01*/
	0xE2BA016F, /*prop_cs_katana_01*/
	0xEE95F258, /*prop_wheel_01*/
	0x52660DBB, /*prop_car_seat*/
	0xC89630B8, /*prop_minigun_01*/
	0xD733DF,   /*root_scroll_anim_skel*/
	0xFA686C0E, /*prop_bin_04a*/
	0xF830B63E, /*prop_swiss_ball_01*/
	0xF3565180, /*prop_cs_meth_pipe*/
	0xF15FB3DD, /*prop_beggers_sign_01*/
	0xF046EA37, /*prop_gold_bar*/
	0xEFC4165A, /*prop_food_van_01*/
	0xEDA96F47, /*prop_distantcar_night*/
	0xEB7D0265, /*prop_golf_bag_01b*/
	0xE92E717E, /*prop_carwash_roller_vert*/
	0xE8E8AADA, /*prop_skip_01a*/
	0xE44D5CEC, /*prop_cash_crate_01*/
	0xE3CE09E2, /*prop_dummy_plane*/
	0xE1C17F6F, /*prop_kayak_01*/
	0xD541462D, /*p_ld_soc_ball_01*/
	0xD44295DD, /*p_cablecar_s*/
	0xCB74FE41, /*prop_roller_car_02*/
	0xCB290EE2, /*prop_fbibombplant*/
	0xC79A987E, /*prop_beach_volball01*/
	0xC54C0CD2, /*prop_huge_display_01*/
	0xC381B3E6, /*prop_lifeblurb_02*/
	0xC2451209, /*prop_air_lights_02a*/
	0xC20633F4, /*prop_cup_saucer_01*/
	0xBE862050, /*prop_portacabin01*/
	0xBB314853, /*prop_player_gasmask*/
	0xB60A04EC, /*prop_water_corpse_01*/
	0xB58BE281, /*prop_byard_rowboat1*/
	0xB58259BD, /*prop_security_case_01*/
	0xB39B99E2, /*prop_jet_bloodsplat_01*/
	0xB321DD82, /*prop_cs_leg_chain_01*/
	0xB21C3926, /*prop_hose_2*/
	0xB20E5785, /*prop_sculpt_fix*/
	0xB155FD87, /*prop_entityxf_covered*/
	0xB155B61D, /*prop_drop_armscrate_01*/
	0xA9BD0D16, /*prop_coke_block_01*/
	0xA67C935F, /*prop_bowling_pin*/
	0xA50DDDD0, /*prop_bball_arcade_01*/
	0xA22CEA2,  /*prop_cs_bowie_knife*/
	0x9C762726, /*prop_lev_des_barge_02*/
	0x98752042, /*prop_ld_fan_01_old*/
	0x97A58869, /*prop_inflatearch_01*/
	0x927A5723, /*prop_fan_01*/
	0x922C2A43, /*prop_big_shit_01*/
	0x8E146BFF, /*prop_ld_monitor_01*/
	0x8DA1C0E,  /*Orange Ball?*/
	0x8AF58425, /*prop_lev_des_barge_01*/
	0x8A451C5C, /*prop_ferris_car_01*/
	0x84898EFE, /*prop_big_shit_02*/
	0x7FFBC1E2, /*prop_dummy_01*/
	0x7F2B2371, /*prop_ld_fireaxe*/
	0x72F54E90, /*prop_jb700_covered*/
	0x72C8A3FB, /*prop_ld_shovel*/
	0x6F204E3A, /*prop_sprink_golf_01*/
	0x6B5FFA1D, /*prop_gravetomb_01a*/
	0x6AD326C2, /*prop_space_rifle*/
	0x699C8FC0, /*prop_ld_bomb_anim*/
	0x678FC2DB, /*prop_wheelchair_01_s*/
	0x60F90AD4, /*prop_cs_heist_bag_02*/
	0x5C1D75A6, /*prop_chair_05*/
	0x5B5C4263, /*prop_chip_fryer*/
	0x5A6DF96A, /*prop_hockey_bag_01*/
	0x58D3B4EA, /*prop_micro_01*/
	0x5869A8F8, /*prop_large_gold*/
	0x5571173D, /*prop_beer_neon_01*/
	0x5411322E, /*prop_ld_haybail*/
	0x532B1DD1, /*prop_rub_trolley01a*/
	0x50A607D0, /*prop_buck_spade_08*/
	0x4DA19524, /*prop_cs_cardbox_01*/
	0x4AF9D1D9, /*prop_shamal_crash*/
	0x478A8882, /*prop_rad_waste_barrel_01*/
	0x456AA864, /*prop_dj_deck_01*/
	0x434BFB7C, /*prop_burgerstand_01*/
	0x40F52369, /*p_v_43_safe_s*/
	0x3DC31836, /*prop_tv_flat_01*/
	0x3C3B89F0, /*prop_cs_bin_01_skinned*/
	0x39885BB5, /*prop_chickencoop_a*/
	0x392D62AA, /*prop_gold_cont_01*/
	0x37D80B0E, /*prop_cheetah_covered*/
	0x369D8410, /*prop_el_guitar_02*/
	0x34D5D3FD, /*prop_golf_bag_01*/
	0x2BE688E0, /*prop_dock_bouy_2*/
	0x2AE13DFA, /*prop_armchair_01*/
	0x29E362FF, /*prop_bucket_01a*/
	0x29CB0F3C, /*prop_armour_pickup*/
	0x240D3E4B, /*prop_pizza_box_01*/
	0x1F811CE1, /*prop_drug_package*/
	0x1F550C17, /*prop_chair_01a*/
	0x1D8A4162, /*prop_hotel_clock_01*/
	0x1AFA6A0A, /*prop_weed_01*/
	0x1AB39621, /*prop_lawnmower_01*/
	0x16A39A90, /*prop_dog_cage_01*/
	0x14E3D6EB, /*prop_inflategate_01*/
	0x113FD533, /*prop_money_bag_01*/
	0x0E8032E4, /*prop_weed_pallet*/
	0x0E3BA450, /*prop_xmas_tree_int*/
	0x07121AC4, /*prop_xmas_ext*/
};






//pc function
void AttackPlayerWithRandomPeds(Ped selectedPed)
{
	//function not working
	if (PED::IS_PED_IN_ANY_VEHICLE(selectedPed, false))
	{
		Vehicle selectedVehicle = PED::GET_VEHICLE_PED_IS_USING(selectedPed);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(selectedVehicle); //requesting permission to fuck up another player

		//Remove PED from vehicle and lock it up
		AI::CLEAR_PED_TASKS_IMMEDIATELY(selectedPed);
		VEHICLE::SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(selectedVehicle, true);
	}
	//select a random ped arround player
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(selectedPed, false);
	Vector3 createdPos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(selectedPed, 0.0f, 35.0f, 0.0f);
	//transvest hash: 0x5715E410
	//stungun hash: 0x1E4A619F

	Ped createdPed = PED::CREATE_PED(130, 0x5715E410, createdPos.x, createdPos.y, createdPos.z, 1.0, false, true);

	PED::SET_PED_CAN_SWITCH_WEAPON(createdPed, true);
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(createdPed, 0x1E4A619F, 1000, true);

	PED::REGISTER_TARGET(createdPed, selectedPed);
	AI::TASK_COMBAT_PED(createdPed, selectedPed, 0, 1);

	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x5715E410);
}



void TeleportToLoc(float x, float y, float z) {

	int iVar0;
	int iVar1;
	CAM::_ANIMATE_GAMEPLAY_CAM_ZOOM(1, 1500);
	iVar0 = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(iVar0, 0x00000000)) {
		iVar1 = PED::GET_VEHICLE_PED_IS_IN(iVar0, 0x00000000);
		ENTITY::SET_ENTITY_COORDS(iVar1, x, y, z, 0x00000000, 0x00000000, 0x00000000, 0x00000001);
		CAM::_ANIMATE_GAMEPLAY_CAM_ZOOM(1, 1500);
	}
	else {
		ENTITY::SET_ENTITY_COORDS(iVar0, x, y, z, 0x00000000, 0x00000000, 0x00000000, 0x00000001);
		CAM::_ANIMATE_GAMEPLAY_CAM_ZOOM(1, 1500);
	}
}

void addIntTeleportOption(char* option, char** From, int* var, int min, int max, bool any = false) {
	char buf[50];
	if (!any) {
		snprintf(buf, sizeof(buf), "%s: < %s >", option, From[*var]);
		addOption(buf);
		if (currentOption == optionCount) {
			lrInstruction = true;
			if (rightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 1;
			}
			else if (leftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 1;
			}
		}
	}
	else {
		snprintf(buf, sizeof(buf), "%s: < %s >", option, From[*var]);
		addOption(buf);
		if (currentOption == optionCount) {
			lrInstruction = true;
			if (rightPress) {
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 1;
			}
			else if (leftPress) {
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 1;
			}
		}
	}
}

void TeleportToOcean(int selectedPlayer) {
	uint handle = PLAYER::GET_PLAYER_PED(selectedPlayer);

	if (PED::IS_PED_IN_ANY_VEHICLE(handle, 0)) {
		handle = PED::GET_VEHICLE_PED_IS_IN(handle, 0);
	}

	if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(handle)) {
		Vector3 Coords = { 103.4720, 7744.1870, -158.1106 };
		ENTITY::SET_ENTITY_COORDS(handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
}

void cash_1m() {
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(1000000); // 1 milhões
}

void cash_10m() {
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000); // 10 milhões
}

void cash_1b() {
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
	NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000);
}

void cash_10m_remove() {
	NETWORKCASH::NETWORK_SPENT_CASH_DROP2(10000000); // Remove 10 milhões
}

void cash_50m_remove() {
	NETWORKCASH::NETWORK_SPENT_CASH_DROP2(50000000); // Remove 50 milhões
}

void cash_250m_remove() {
	NETWORKCASH::NETWORK_SPENT_CASH_DROP2(250000000); // Remove 250 milhões
}

void cash_1b_remove() {
	NETWORKCASH::NETWORK_SPENT_CASH_DROP2(1000000000); // Remove 1 bilhão
}

opd_s STAT_SET_INT1_t = { 0x42BE0C, TOC };
void(*STAT_SET_INT1)(int hash, int stat) = (void(*)(int, int)) & STAT_SET_INT1_t;

void rank_120() {
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 2165850);
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_XP_FM"), 2165850);
}
void rank_300() {
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 8299350);
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_XP_FM"), 8299350);
}
void rank_500() {
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 17014350);
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_XP_FM"), 17014350);
}
void rank_8000() {
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), 1787576850);
	STAT_SET_INT1(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_XP_FM"), 1787576850);
}

void advance_auto(char* option, int* var, int min, int max, bool keyboard, char* info = NULL) {
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %i >", option, *var);
	addOption(buf);

	if (currentOption == optionCount) {
		lrInstruction = true;

		if (rightPress) {
			playSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress) {
			playSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}

		NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(*var, TIME::GET_CLOCK_MINUTES(), TIME::GET_CLOCK_SECONDS());
		if (keyboard) {
			squareInstruction = true;
			if (squarePress) {
				startKeyboard(0, "", (strlen(ItoS(max)) + 1));
				keyboardVar = var;
			}
		}
	}
}

/*

// Definir um código para envio de convite de jogo
#define SEND_GAME_INVITE 0x982B00 * 2

// Estrutura para armazenar a função que envia o convite
struct SendGameInvitePSN_t {
int inviteCode;
int toc;
};

// Instancia a estrutura com os dados necessários
SendGameInvitePSN_t sendGameInviteData = { SEND_GAME_INVITE, TOC };

// Define a função que chama o envio do convite, mapeando para a estrutura
void(*SendGameInvitePSN)(int unk, int a1, int a2, int a3, int a4, int a5, int a6) =
(void(*)(int, int, int, int, int, int, int)) & sendGameInviteData;

// Função para enviar o convite para um amigo via PSN
void SendGameInvite(char* PSN)
{
char buffer[70] = {}; // Buffer de dados para o envio

// Escreve os dados no endereço especificado
WriteBytes((int)0x1004004C, buffer, 0x100);

// Escreve o nome do PSN no local correto na memória
WriteString(0x1004004C + 8, PSN);

// Chama a função para enviar o convite com os parâmetros necessários
SendGameInvitePSN(0x40054CE0, 0x1004004C, 1, 0, 0, 0, 0x1C3324C);
}

int oclient;

// Função para obter a lista de amigos e enviar convite
void GrabberFriendList()
{
// Variável para armazenar o índice do amigo
int currentFriendIndex;

// Obtém o número total de amigos
int friendCount = NETWORK::NETWORK_GET_FRIEND_COUNT();

// Percorre todos os amigos
for (int i = 0; i < friendCount; i++)
{
// Obtém o nome do amigo atual
char* friendName = NETWORK::NETWORK_GET_FRIEND_NAME2(i);

// Verifica se o amigo está online
if (NETWORK::NETWORK_IS_FRIEND_ONLINE(friendName))
{
// Armazena o índice do amigo
currentFriendIndex = i;
oclient = currentFriendIndex; // Define a variável global com o índice do amigo

// Adiciona uma opção para enviar convite de jogo
addOption(friendName, "Send Invite Game", client_list, []
{
// Quando a opção for selecionada, envia o convite para o amigo
SendGameInvite(NETWORK_GET_FRIEND_NAME2(oclient));
});
}
}
}

*/






void AttachEntityToBack() {
	ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED(int_NetworkOptions[0]), -1,
		0.0, -0.3, 0.0, 0.0, 0.0, 0.0, 1, 0, 0, 1, 2, 1);
}

void AttachEntityTohead() {
	ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED(int_NetworkOptions[0]), -1,
		0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 1, 0, 0, 1, 2, 1);
}

void DetachEntity() { ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true); }

bool comida_online1 = false;
void comida_online(bool enable) {
	if (enable) {
		AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(selectedPlayer));

		Vector3 tmp = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);

		sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE1(tmp.x, tmp.y, tmp.z, 0.0f, 0.0f, 0.0f, 2, 1, 0,
			1065353216, 0, 1065353216);

		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE1(PLAYER::GET_PLAYER_PED(selectedPlayer), sceneID,
			"rcmpaparazzo_2", "shag_loop_poppy", 8.0f, -8.0f, 6, 0,
			1.5f);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE1(sceneID);

		ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED(selectedPlayer), 51826,
			0.0f, -0.2f, 0.0f, 0, 0, 0, 1, 1, 0, 0, 2, 1);

		Anim = "rcmpaparazzo_2";
		AnimID = "shag_loop_a";
		LoadingAnim = true;

	}
	else {
		AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
		AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(selectedPlayer));
		ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED(selectedPlayer), true);
	}
}

bool mamada_online1 = false;
void mamada_online(bool enable) {
	if (enable) {
		AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(selectedPlayer));
		Vector3 tmp = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE1(tmp.x, tmp.y, tmp.z, 0.0f, 0.0f, 0.0f, 2, 1, 0,
			1065353216, 0, 1065353216);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE1(PLAYER::GET_PLAYER_PED(selectedPlayer), sceneID,
			"misscarsteal2pimpsex", "pimpsex_hooker", 8.0f, -8.0f, 6,
			0, 1.5f);
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE1(sceneID);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED(selectedPlayer), 51826,
			0.0f, 0.6f, 0.0f, -91.0f, -163.0f, 0, 1, 1, 0, 0, 2, 1);
		Anim = "misscarsteal2pimpsex";
		AnimID = "pimpsex_hooker";
		LoadingPlayerAnim = true;

		Anim = "misscarsteal2pimpsex";
		AnimID = "pimpsex_punter";
		LoadingAnim = true;
	}
	else {
		AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
		AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(selectedPlayer));
		ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_PED(selectedPlayer), true);
	}
}

bool download_north_yankton1 = false;
void download_north_yankton() {
	const char* northYanktonIPLs[] = {
		"prologue01", "Prologue01c", "Prologue01d", "Prologue01e",
		"Prologue01f", "Prologue01g", "prologue01h", "prologue01i",
		"prologue01j", "prologue01k", "prologue01z", "prologue02",
		"prologue03", "prologue03b", "prologue03_grv_cov", "prologue03_grv_dug",
		"prologue03_grv_fun", "prologue04", "prologue04b", "prologue04_cover",
		"prologue05", "prologue05b", "prologue06", "prologue06b",
		"prologue06_int", "prologuerd", "prologuerdb", "prologue_DistantLights",
		"prologue_grv_torch", "prologue_m2_door", "prologue_LODLights", "DES_ProTree_start",
		"DES_ProTree_start_lod" };
	for (int i = 0; i < sizeof(northYanktonIPLs) / sizeof(northYanktonIPLs[0]); i++) {
		toggleIPL(northYanktonIPLs[i]);
	}
	Vector3 coords;
	coords.x = 3595.39673f;
	coords.y = -4893.727f;
	coords.z = 115.838394f;
	ChangeCoords(coords);
}


//freeze my game shit
#define I_AM_ONLINE ((char)0x223F0C0)
void paradise_black_screen() {
	if (I_AM_ONLINE) {
		opd_s cw_t = { 0x12C2ECC, TOC };
		void(*cw)(unsigned int r3, unsigned int r4, unsigned int r5, unsigned int r6);
		cw = (void(*)(unsigned int, unsigned int, unsigned int, unsigned int)) & cw_t;
		cw(1, 0xE, (volatile unsigned int)(0x2148E84 + 0xD04), 0);
	}
}
void paradise_freeze_v2() {
	if (I_AM_ONLINE) {
		opd_s cw_t = { 0x12C2ECC, TOC };
		void(*cw)(unsigned int r3, unsigned int r4, unsigned int r5, unsigned int r6);
		cw = (void(*)(unsigned int, unsigned int, unsigned int, unsigned int)) & cw_t;
		cw(1, -1, (volatile unsigned int)(0x2148E84 + 0xD04), 0);
	}
}
#undef I_AM_ONLINE

void paradise_black_screen_2() {
	if (((char)0x223F0C0)) {
		opd_s cw_t = { 0x12C2ECC, TOC };
		void(*cw)(unsigned int r3, unsigned int r4, unsigned int r5, unsigned int r6);
		cw = (void(*)(unsigned int, unsigned int, unsigned int, unsigned int)) & cw_t;
		cw(1, 0xE, (volatile unsigned int)(0x2148E84 + 0xD04), 0);
	}
}
void paradise_freeze_v2_2() {
	if (((char)0x223F0C0)) {
		opd_s cw_t = { 0x12C2ECC, TOC };
		void(*cw)(unsigned int r3, unsigned int r4, unsigned int r5, unsigned int r6);
		cw = (void(*)(unsigned int, unsigned int, unsigned int, unsigned int)) & cw_t;
		cw(1, -1, (volatile unsigned int)(0x2148E84 + 0xD04), 0);
	}
}

void clear_all_tasks() {
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
	ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), false);
}


//test exodus :)
bool SavedLocation = false;
float SaveLocation[8];
void saveloc() {
	Vector3 Location = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	SaveLocation[0] = Location.x;
	SaveLocation[1] = Location.y;
	SaveLocation[2] = Location.z;
	SavedLocation = true;
}
void loadloc() {
	ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), SaveLocation[0], SaveLocation[1], SaveLocation[2], 1, 1,
		1, 1);
}



void ExplodePlayer() {
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, 0.5f, true, false, 5.0f);
}

void bota_jaula() {

	Vector3 TheirCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), false);
	int O = OBJECT::CREATE_OBJECT(0x7B059043, TheirCoords.x, TheirCoords.y, TheirCoords.z - 1, true, true,
		false); // prop_rub_cage01a
	ENTITY::FREEZE_ENTITY_POSITION(O, true);
	int Ob = OBJECT::CREATE_OBJECT(0x7B059043, TheirCoords.x, TheirCoords.y, TheirCoords.z + 1, true, true,
		false); // prop_rub_cage01a
	ENTITY::SET_ENTITY_ROTATION(Ob, 0, 180, 90, 0, false);

	// Congelar a posição do segundo objeto
	ENTITY::FREEZE_ENTITY_POSITION(Ob, true);
}

void drawTextRight(char* text, int font, float x, float y, float scalex, float scaley) {
	if (strcmp(SCRIPT::GET_THIS_SCRIPT_NAME(), "ingamehud") == 0) {
		UI::SET_TEXT_FONT(font);
		UI::SET_TEXT_SCALE(scalex, scaley);
		UI::SET_TEXT_RIGHT_JUSTIFY(true);
		if (currentOption == optionCount) {
			UI::SET_TEXT_WRAP(0.1f, x);
			UI::SET_TEXT_COLOUR(0, 255, 0, 255);
			snprintf(opt, sizeof(opt), "%s", text);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);
		}
		else {
			UI::SET_TEXT_COLOUR(255, 255, 255, 255);
			UI::_SET_TEXT_ENTRY("STRING");
			UI::_ADD_TEXT_COMPONENT_STRING(text);
			UI::SET_TEXT_WRAP(0.1f, x);
		}
		UI::_DRAW_TEXT(0.010f, y);
	}
}

void RightText(char* option, float x) {
	if (currentOption <= maxOptions && optionCount <= maxOptions) {
		drawTextRight(option, optionsFont, x, (optionCount * 0.025f + 0.135f), 0.3f, 0.3f);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption) {
		drawTextRight(option, optionsFont, x, ((optionCount - (currentOption - maxOptions)) * 0.025f + 0.135f),
			0.3f, 0.3f);
	}
}

void addVehicle(char* option, char* Default, int hash_vehil, int* var, int min, int max) {
	char buf[1000];
	addOption(option);
	if (currentOption == optionCount) {
		snprintf(buf, sizeof(buf), "< %s >", Default, *var, max);
		RightText(buf, 0.1800);
		if (rightPress) {
			PlaySounds = true;
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress) {
			PlaySounds = true;
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
		if (optionPress) {
			hash_veh = hash_vehil;
			SpawnVehicle = true;
		}
	}
	else {
		snprintf(buf, sizeof(buf), "< %s >", Default, *var, max);
		RightText(buf, 0.1800);
	}
}










bool ant_fakeleave_dropkick1 = false;
void ant_fakeleave_dropkick(bool enable) {

	*(unsigned int*)0x9FB8F8 = enable ? 0x4E800020 : 0x7C0802A6; //fakeleave atualizado
	*(unsigned int*)0x9FF81C = enable ? 0x4E800020 : 0x7C0802A6; //dropkick atualizado


	//*(unsigned int*)0x9FBACC = enable ? 0x60000000 : 0x2C030000; // CGamePlayerBroadcastDataHandler_Local_HandleReceived fakeleave
	//*(unsigned int*)0x9FFF00 = enable ? 0x4E800020 : 0x7C0802A6; // sub
	//*(unsigned int*)0x9FFF80 = enable ? 0x60000000 : 0x48000024; // sub_9FFF00
}




#define __ALWAYS_INLINE static inline __attribute__((always_inline))
#define GetSyncTreeForType(cNetworkObjectMgr, syncTreetype)                                                  \
	GameCall<uintptr_t>(0x13398D4)(cNetworkObjectMgr, syncTreetype)
#define CNetworkObjectMgr_HandleCloneSyncFn(cNetworkObjectMgr, CNetGamePlayer_client, CNetGamePlayer_self,   \
	syncTreetype, objectId, sync_data, sequenceId, timestamp)        \
	GameCall<uint32_t>(0x133D6EC)(cNetworkObjectMgr, CNetGamePlayer_client, CNetGamePlayer_self, syncTreetype, \
	objectId, sync_data, sequenceId, timestamp)
template <typename R> __ALWAYS_INLINE R(*GameCall(std::uint32_t addr, std::uint32_t toc = TOC))(...) {
	volatile opd_s opd = { addr, toc };
	R(*func)(...) = (R(*)(...)) & opd;
	return func;
}
const char* GetGamerTagFromCNetGamePlayer(uintptr_t netGamePlayer) {
	if (!netGamePlayer)
		return "someone";

	uintptr_t playersInfo = *(volatile uintptr_t*)(netGamePlayer + 0x78);
	if (!playersInfo)
		return "someone";

	return (const char*)(playersInfo + 0x10);
}
uint32_t NetworkObjectMgr_HandleCloneSync(uintptr_t networkObjectMgr, uintptr_t netGamePlayer_client,
	uintptr_t netGamePlayer_self, uint16_t syncTreeType,
	uint32_t objectId, uintptr_t syncData, uint32_t sequenceId,
	int32_t timestamp) {

	uintptr_t syncPool = GetSyncTreeForType(networkObjectMgr, syncTreeType);
	if (!syncPool) {
		if (netGamePlayer_client) {
			char buffer[100];
			sprintf(buffer, "%s tried to freeze you\n", GetGamerTagFromCNetGamePlayer(netGamePlayer_client));
			drawNotification(buffer);
			if (netGamePlayer_client != NETWORK::NETWORK_IS_HOST()) {
				char buffer2[100];
				sprintf(buffer, "%s is host and they tried to freeze you.\n",
					GetGamerTagFromCNetGamePlayer(netGamePlayer_client));
				drawNotification(buffer2);
			}
			NETWORK::NETWORK_SESSION_KICK_PLAYER(*(volatile uint8_t*)(netGamePlayer_client + 0x29));
			// KickPlayer(*(volatile uint8_t*)(netGamePlayer_client + 0x29));
		}

		return 7;
	}

	return CNetworkObjectMgr_HandleCloneSyncFn(networkObjectMgr, netGamePlayer_client, netGamePlayer_self,
		syncTreeType, objectId, syncData, sequenceId, timestamp);
}

//
// template <typename T>
//__ALWAYS_INLINE T(*call(unsigned int address, unsigned int toc = TOC))(...) {
//	volatile opd_s opd = { address, toc };
//	T(*func)(...) = (T(*)(...)) & opd;
//	return func;
//}
#define VALID_ADDR(x) ((unsigned int)(x) > 0x10000)
// uint32_t received_clone_sync(uint32_t cNetworkObjectMgr, uint32_t CNetGamePlayer_client, uint32_t
// CNetGamePlayer_self, uint32_t syncTreetype, uint32_t r7, uint32_t r8, uint32_t r9, uint32_t r10)
//{
//
//	uint32_t sync_pool = call<uint32_t>(0x12AD270)(cNetworkObjectMgr, syncTreetype);
//	static char buf[100];
//	//printf("sync_pool: %i\n", sync_pool);
//	if (sync_pool == 0)
//	{
//		//Thx gopro to detect:
//		if (CNetGamePlayer_client)
//		{
//			uint32_t playerInfo = *(volatile uint32_t*)(CNetGamePlayer_client + 0x78);
//			char* name = 0;
//			if (VALID_ADDR(playerInfo)) {
//				name = (char*)(playerInfo + 0x10);
//			}
//			else
//			{
//				name = "Someone";
//			}
//			uint8_t player = *(volatile uint8_t*)(CNetGamePlayer_client + 0x29);
//			static char buf[100];
//			sprintf(buf, "Freeze (Sync pool) attempted by: ~r~%s", name);
//			print(buf, 2000);
//			return 6;
//		}
//	}
//
//	return call<int>(0x12B0ECC)(cNetworkObjectMgr, CNetGamePlayer_client, CNetGamePlayer_self,
//syncTreetype, r7, r8, r9, r10);
// }

void host_kick(int selectedPlayer) {
	if (NETWORK::NETWORK_IS_PLAYER_ACTIVE(selectedPlayer)) {
		NETWORK::NETWORK_SESSION_KICK_PLAYER(selectedPlayer);
	}
}

void vote_kick() { Write_Global(0x183D83 + selectedPlayer, 1); }

void restart_gta() { NETWORK::SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME(); }

void non_host_kick(int selectedPlayer) {
	int args[3];              // Array de argumentos
	args[0] = 0x2;            // Argumento 1
	args[1] = selectedPlayer; // Argumento 2: player que será deslogado
	args[2] = 0x35;           // Argumento 3: código especial (presumido 0x35 como você indicou)

	int bitset = 0;
	SET_BIT(&bitset, selectedPlayer); // Setando o bit do jogador selecionado

	if (bitset != 0) // Verificando se o bit foi configurado corretamente
	{
		SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, bitset); // Chamando o evento com os parâmetros
	}
}

void get_temperature(uint32_t _dev, uint32_t* _temp) {
	system_call_2(383, (uint64_t)(uint32_t)_dev, (uint64_t)(uint32_t)_temp);
	// temp 0 = cpu temp 1 = rsx
}

void fix_vehicle() {
	int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehID)) {
		VEHICLE::SET_VEHICLE_FIXED(VehID);
	}
}

void max_up_car() {
	int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);

	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehID)) {
		VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
		VEHICLE::SET_VEHICLE_COLOURS(VehID, 120, 120);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehID, "KK");
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(VehID, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 18, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 22, 1);
		VEHICLE::SET_VEHICLE_MOD(VehID, 16, 5, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 12, 2, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 11, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 14, 14, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 15, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 13, 2, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehID, 6);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(VehID, 5);
		VEHICLE::SET_VEHICLE_MOD(VehID, 23, 19, 1);
		VEHICLE::SET_VEHICLE_MOD(VehID, 0, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 1, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 2, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 3, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 4, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 5, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 6, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 7, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 8, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 9, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehID, 10, 1, 0);
	}
}


void random_paint() {
	int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehID)) {
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255),
			GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255),
			GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255),
			GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255),
			GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
	}
}

//
// bool noclipCallback1 = false;
// void noclipCallback()
//{
//	noclip::toggle();
//}
//
//
// void noclipCallback333()
//{
//	//noclip::enabled();
//}
//
//

void change_name(const char* newname = "") {
	strncpy((char*)0x41143344, newname, strlen(newname));
	*(char*)(0x41143344 + strlen(newname)) = 0;
	strncpy((char*)0x01FF248C, newname, strlen(newname));
	*(char*)(0x01FF248C + strlen(newname)) = 0;
}

//
// void rockstardev_name()
//{
//	change_name(rockstarDEV);
//}
//
//
//
// void invalid_name()
//{
//	change_name(kasdksadadqqhdwqdb);
//}

//
bool funny_screen_2_1 = false;
void funny_screen_2(bool enabled) // ´precisa chamar no loop
{
	if (enabled == true) {
		*(char*)(0x1D260) = 0x40, 0x00, 0x00, 0x00;
	}
	else {
		*(char*)(0x1D260) = 0x3F, 0x80, 0x00, 0x00;
	}
}

//goprooo
#define BWGAMMA (*(int *)(0x2068780 + 0x12D8)) // 0 is black and white
#define DOFBLUR (*(int *)(0x2068780 + 0x12DC)) // makes far away objects blurry when value is higher
#define PUDDLE_DATA (*(int *)(0x1CFB154))      // FA9410 puddleData
#define PUDDLE_DATA2 (*(int *)(PUDDLE_DATA + 0x74))
#define SOME_BRIGHTNESS (*(int *)(0x22223E0 + 0x20)) // when too high this causes many issues  3E000000
#define SOME_SATURATION (*(int *)(0x22223E0 + 0x28)) // 0x3CC00000
void toggleRedux(bool enable) {
	static bool redux = false;
	static int br = 0;
	static int s = 0;
	if (redux == false) {
		// currently off
		br = SOME_BRIGHTNESS;
		s = SOME_SATURATION;
	}
	redux = !redux;
	if (redux) {
		SOME_BRIGHTNESS = 0x3E000000;
		SOME_SATURATION = 0x3D500000;
	}
	else {
		SOME_BRIGHTNESS = br;
		SOME_SATURATION = s;
	}
}

// void toggle_redux()
//  {
//	static bool redux = false;
//	static int originalBrightness = *(int*)(0x22223E0 + 0x20);  // Armazena o valor original de brilho
//	static int originalSaturation = *(int*)(0x22223E0 + 0x28);  // Armazena o valor original de saturação
//
//	redux = !redux;
//
//	if (redux) {
//		// Ativa os efeitos Redux
//		*(int*)(0x22223E0 + 0x20) = 0x3E000000;  // Valor de brilho para o efeito Redux
//		*(int*)(0x22223E0 + 0x28) = 0x3D500000;  // Valor de saturação para o efeito Redux
//	}
//	else {
//		// Restaura os valores originais
//		*(int*)(0x22223E0 + 0x20) = originalBrightness;
//		*(int*)(0x22223E0 + 0x28) = originalSaturation;
//	}
// }

// males
void outfit_male_1() {

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, 11, 0, 0); 

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, 4, 0, 0); 

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, 25, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, 11, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, 1, 0, 0);

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, 0, 0, 0);
}

void outfit_male_2() {

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, 5, 0, 0);

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, 21, 0, 0); 

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, 15, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, 2, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, 2, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, 0, 0, 0);
}

void outfit_male_3() {
	
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, 5, 0, 0); 

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, 7, 0, 0); 

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, 15, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, 2, 0, 0);

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, 3, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, 0, 0, 0);
}



void outfit_female_1() {

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, 8, 0, 0);

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, 38, 0, 0); 

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, 6, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, 6, 0, 0);

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, 2, 0, 0);

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, 2, 0, 0); 
}

void outfit_female_2() {

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, 11, 0, 0); 

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, 38, 0, 0); 

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, 15, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, 2, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, 1, 0, 0);

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, 2, 0, 0);
}

void outfit_female_3() {

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, 11, 0, 0);

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, 20, 0, 0);

	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, 15, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 0, 6, 0, 0);

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, 5, 0, 0); 

	PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, 1, 0, 0);
}


// void setCustomMapRes(bool yes) {
//	*(char*)(MAPRESS_GLOBAL + 0x48) = yes;
//	//*(volatile unsigned int*)(MAPRESS_GLOBAL+0x44) =
//yes?bit_renderMapLow|bit_renderEntities:bit_renderMapUltra|bit_renderEntities;//mode type, overritten here
//0x377514
//	*(volatile unsigned int*)0x377514 = 0x60000000;//make it not set back to 21
//	if (*(volatile unsigned int*)(MAPRESS_GLOBAL + 0x44) == 0) {
//		//set to default
//		setCustomMapResParam(bit_renderMapUltra | bit_renderEntities);
//	}
// }

// void toggleResBit(unsigned int bit, bool value) {
//	unsigned int cur = *(volatile unsigned int*)(MAPRESS_GLOBAL + 0x44);
//	if (value) {
//		cur = cur | bit;
//	}
//	else {
//		cur = ~bit & cur;
//	}
//	setCustomMapResParam(cur);
// }

// void setLowRes() {
//	setLowPolyCars(true);
//	enableShadows(false);
//	setCustomMapRes(true);
//	setCustomMapResParam(bit_renderMapLow);
//	toggleResBit(bit_renderEntities, renderEntitiesBool);
// }
// void setMediumRes() {
//	setLowPolyCars(true);
//	enableShadows(false);
//	setCustomMapRes(true);
//	setCustomMapResParam(bit_renderMapMed);
//	toggleResBit(bit_renderEntities, renderEntitiesBool);
// }
// void setHighRes() {
//	setLowPolyCars(false);
//	enableShadows(true);
//	setCustomMapRes(false);//we can't simulate what the game does by overriting with custom so just set to
//off
//	//setCustomMapResParam(bit_renderMapUltra|bit_renderMapHigh);
//	//toggleResBit(bit_renderEntities,renderEntitiesBool);
// }

//
//	bool doNotUsePresence = false;
// void NETWORK_SET_RICH_PRESENCE_2_hook(NativeArg_s *args) {
//	//printf("Presense: %i %s\n",args->ArgValues[0].i,args->ArgValues[1].str);
//	if (doNotUsePresence == false) {
//		//patch the function so it doesn't use gxt2:
//		*(unsigned int*)0x3EBFF0 = 0x7FC3F378;//for uunk_0x17E6777 which is used for setting what game
//ur playing  mr %r3, %r30
//		//*(unsigned int*)0x3EC000 = 0x60000000;
//		*(unsigned int*)0x3EBFD4 = 0x60000000;//check iif gtx exists patch
//
//		args->ArgValues[1].str = "using Paradise SPRX";
//		args->ArgValues[0].i = 1;
//	}
//	call<int>(0x3EBF30)(args->ArgValues[0].i,args->ArgValues[1].str);
//}





char bytes1_on[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x1B, 0xFA, 0xE0, 0x00, 0x03,
0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x33, 0x1B, 0xFA, 0xC0, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x3E, 0x4C, 0xE7, 0x04, 0x3D, 0xF0, 0xD8, 0x45, 0x3E, 0x4C, 0xE7, 0x04, 0x3D,
0xF0, 0xD8, 0x45, 0x44, 0x7A, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x40, 0xA0, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x3F, 0xC0, 0x00,
0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC7 };
char bytes2_on[] = { 0x47, 0xC3, 0x4F, 0x80 };
char bytes3_on[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
char bytes4_on[] = { 0x0C, 0x00, 0x00, 0x00 };

void spoofvehicle() {
	WriteBytes(0x402D3890, bytes1_on, 144);
	WriteBytes(0x4120CF88, bytes2_on, 4);
	WriteBytes(0x4120D060, bytes3_on, 16);
	WriteBytes(0x4120D08C, bytes4_on, 4);
}

bool Lobbflobbyyf() {
	char* FuncByteshelicopterA = ReadBytes(0x402D77F0, 0x90); // helicopter
	WriteBytes((int)0x402D3890, FuncByteshelicopterA, 0x90);  // ADDER = 0x402DEA80
	char cmd1A[] = { 0x47, 0xF0, 0x4F, 0x80 };
	char cmd2A[0x10] = {};
	WriteBytes((int)0x4120CC28, cmd1A, 4);
	WriteBytes((int)0x4120CD00, cmd2A, 0x10);
	print("Fly Around To -r~Crash -g~LOBBY!!!", 1000);
	uint Handle = PLAYER::PLAYER_PED_ID();
	Vector3 c = ENTITY::GET_ENTITY_COORDS(Handle, 1);
	int hash = GAMEPLAY::GET_HASH_KEY("tribike");
	STREAMING::REQUEST_MODEL(hash);
	if (STREAMING::HAS_MODEL_LOADED(hash)) {
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, c.x, c.y, c.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle)) {
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			return true;
		}
		return false;
	}
	return false;
}

bool Lobbflobbyyf1() {
	char* FuncByteshelicopterA = ReadBytes(0x402D77F0, 0x90); // helicopter
	WriteBytes((int)0x402BADB0, FuncByteshelicopterA, 0x90);  // Coquette
	char cmd1A[] = { 0x47, 0xF0, 0x4F, 0x80 };
	char cmd2A[0x10] = {};
	WriteBytes((int)0x4120CC28, cmd1A, 4);
	WriteBytes((int)0x4120CD00, cmd2A, 0x10);
	uint Handle = PLAYER::PLAYER_PED_ID();
	Vector3 c = ENTITY::GET_ENTITY_COORDS(Handle, 1);
	int hash = GAMEPLAY::GET_HASH_KEY("coquette");
	STREAMING::REQUEST_MODEL(hash);
	if (STREAMING::HAS_MODEL_LOADED(hash)) {
		int Vehicle = VEHICLE::CREATE_VEHICLE(hash, c.x, c.y, c.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle)) {
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			return true;
		}
		return false;
	}
	return false;
}

void freeze_t20() {
	if (freeze_t20)
	{
		Lobbflobbyyf1();
		print("Using T20 For Freeze", 500);
	}
	else 
	{
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		GAMEPLAY::CLEAR_AREA(MyCoords.x, MyCoords.y, MyCoords.z, 100.0f, 0, 0, 0,
			0); 
	}
}

void freeze_bike() {
	if (freeze_bike) 
	{
		Lobbflobbyyf();
		print("Using Bike For Freeze", 500);
	}
	else 
	{
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		GAMEPLAY::CLEAR_AREA(MyCoords.x, MyCoords.y, MyCoords.z, 100.0f, 0, 0, 0,
			0); 
	}
}

void freeze_adder() {
	if (freeze_adder) 
	{
		char bytes14[] = { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04 };
		WriteBytes(0x402DEAC8, bytes14, 16);
		print("Using Adder For Freeze", 500);
	}
	else 
	{
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		GAMEPLAY::CLEAR_AREA(MyCoords.x, MyCoords.y, MyCoords.z, 100.0f, 0, 0, 0,
			0);
	}
}

void freeze_coquete() {
	if (freeze_coquete) 
	{
		char bytes14[] = { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04 };
		WriteBytes(0x402BADB0, bytes14, 16);
		print("Using Coquette For Freeze", 500);
	}
	else 
	{
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		GAMEPLAY::CLEAR_AREA(MyCoords.x, MyCoords.y, MyCoords.z, 100.0f, 0, 0, 0,
			0); 
	}
}

bool load_unload_ap_intense1 = true;
void load_unload_ap_intense(bool enable) {
	if (enable) {
		// Carregar o script
		SCRIPT::REQUEST_SCRIPT("rock_menu2");
		int tick = 0;
		while (!SCRIPT::HAS_SCRIPT_LOADED("rock_menu2")) {
			tick++;
			if (tick >= 500) {
				print("ne naydeno.");
				return;
			}
			SYSTEM::WAIT(0);
		}
		SYSTEM::START_NEW_SCRIPT("rock_menu2", 1024);
		SCRIPT::SET_SCRIPT_AS_NO_LONGER_NEEDED("rock_menu2");
		print("zagruzka v pamyat zavershena.");
	}
	else {
		// Descarregar o script
		if (SCRIPT::HAS_SCRIPT_LOADED("rock_menu2")) {
			GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("rock_menu2");
			print("udalen iz pamyati.");
		}
	}
}


////PLAYERS DRAW
////////// SETAS E LINHAS
int formato1 = 20; 

void marker_player(int SelectedIndex) {
	Vector3 coord = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(SelectedIndex), false);


	int r = 0;   
	int g = 0;   
	int b = 0;     
	int alpha = 255; 

	GRAPHICS::DRAW_MARKER(formato1,   
		coord.x, coord.y, coord.z + 1.35,
		0.0f, 0.0f, 0.0f,         
		0.0f, 180.0f, 0.0f,        
		1.0f, 1.0f, 1.0f,   
		r, g, b, alpha,            
		1, 0, 2,                     
		1, 0, 0, 0                  
	);
}

int formato2 = 25; 

void marker_box_player(int SelectedIndex) {

	Vector3 coord = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(SelectedIndex), false);

	int r = 0;    
	int g = 0;    
	int b = 0; 
	int alpha = 255; 

	float heightAdjustment = -0.90f; 

	// Desenha o marcador
	GRAPHICS::DRAW_MARKER(formato2,   
		coord.x, coord.y, coord.z + heightAdjustment, 
		0.0f, 0.0f, 0.0f,                     
		0.0f, 180.0f, 0.0f,                           
		1.0f, 1.0f, 1.0f,                    
		r, g, b, alpha,                         
		1, 0, 2,
		1, 0, 0, 0                  
	);
}

void ligas(Vector3 Cords, float XXX, float ZZZ) {
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y + XXX, Cords.z + ZZZ, Cords.x + XXX, Cords.y - XXX,
		Cords.z + ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y - XXX, Cords.z + ZZZ, Cords.x - XXX, Cords.y - XXX,
		Cords.z + ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y - XXX, Cords.z + ZZZ, Cords.x - XXX, Cords.y + XXX,
		Cords.z + ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y + XXX, Cords.z + ZZZ, Cords.x + XXX, Cords.y + XXX,
		Cords.z + ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y - XXX,
		Cords.z - ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y - XXX,
		Cords.z - ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y + XXX,
		Cords.z - ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y + XXX,
		Cords.z - ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y + XXX,
		Cords.z + ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y - XXX,
		Cords.z + ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y - XXX,
		Cords.z + ZZZ, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y + XXX,
		Cords.z + ZZZ, 255, 0, 0, 255);
}

void draw_box_and_head_marker(int selectedPlayer) {
	Ped selectedPed = PLAYER::GET_PLAYER_PED(selectedPlayer);
	Vector3 pedCoords = ENTITY::GET_ENTITY_COORDS(selectedPed, true);
	// box
	pedCoords.z -= 0.1f; 
	ligas(pedCoords, 0.4f, 0.9f);

	/*
	//head
	pedCoords.z += 0.7f; //box da cabecinha pra cima
	ligas(pedCoords, 0.1f, 0.1f);
	*/
}

////

bool panterala1 = false;
void panterala(bool enable) {
	*(unsigned int*)0x130A300 = enable ? 0x60000000 : 0x4BFB2F59;
	*(unsigned int*)0xA097F0 = enable ? 0x60000000 : 0x4BFFF961;
	*(unsigned int*)0x9FCFB4 = enable ? 0x60000000 : 0x7FE10808;
	*(unsigned int*)0x9FBBC8 = enable ? 0x60000000 : 0x7FE10808;
	*(unsigned int*)0x9FBBCC = enable ? 0x60000000 : 0x4BFFFDA8;
	*(unsigned int*)0x9FBA00 = enable ? 0x60000000 : 0x7FE10808;
	*(unsigned int*)0x130D104 = enable ? 0x4E800020 : 0x7C0802A6;
	*(unsigned int*)0xA5A4F0 = enable ? 0x4E800020 : 0x7C0802A6;
	*(unsigned int*)0xA5A674 = enable ? 0x7C0802A6 : 0x7C0802A6;
	*(unsigned int*)0x9B8888 = enable ? 0x60000000 : 0x7FE10808;
	*(unsigned int*)0x3D3EB8 = enable ? 0x60000000 : 0x41820044;
	*(unsigned int*)0x10953A4 = enable ? 0x60000000 : 0x418200AC;
	*(unsigned int*)0x10953F8 = enable ? 0x60000000 : 0x41820058;
	*(unsigned int*)0xA17248 = enable ? 0x60000000 : 0x807C0008;
	*(unsigned int*)0x133B084 = enable ? 0x60000000 : 0x7FE10808;
}



bool blackos1 = false;
void blackos(bool enable) {
	*(int*)0XA0F154 = enable ? 0x4E800020 : 0X7C0802A6;//rage_netSyncNodeBase_IsEntityTypeSynced - travei pro pirata
}



// 0x1358AAC ant host kick

bool random_patchs1 = false;
void random_patchs(bool enable) {
	*(unsigned int*)0xA17248 = enable ? 0x60000000 : 0x807C0008;  // netSyncTree_ReadFromBuffer
	*(unsigned int*)0x133B084 = enable ? 0x60000000 : 0x7FE10808; // sub_133B03C
	*(unsigned int*)0x1327674 = enable ? 0x60000000 : 0x807A0E30; // sub_1327498 - teleport e antimation
	*(unsigned int*)0xEE96C4 = enable ? 0x60000000 : 0x807A0E30; // rizzex me travou com chireta
}

//*(unsigned int*)0xA0F750 = enable ? 0x60000000 : 0x80A30000; //sub_A0F718 - crash idk rizzex maybe shit
//vehicles NAO FUNCIONA 0x01341474 0x00EF5FB0 0x013BFF44

// Type  Function                         Line number  Filename  Stack Size  Module
// Unknown  0x0227D910 (0x227D920)
//? ? ? 0x0227D63C
// Unknown  0x0227D790 (0x227D7D4)                         0x0080
//? ? ? 0x024D8854
//? ? ? 0x024E7F7C
// Unknown  0x0159B474 (0x159B484)                         0x0080

// stuff old paradise

bool yuri1 = false;
void yuri(bool enable) {
	*(unsigned int*)0xAE7B00 = enable ? 0x7FC3F378 : 0x3C600003;
	*(unsigned int*)0x3D7AE0 = enable ? 0x4E800020 : 0xF821FF91;
	*(unsigned int*)0xA4D944 = enable ? 0x60000000 : 0x7FE10808;
	*(unsigned int*)0x9B3AF8 = enable ? 0x60000000 : 0x7FE10808;
	*(unsigned int*)0xAA00C4 = enable ? 0x48000110 : 0x41820110;
	*(unsigned int*)0xAAB3E0 = enable ? 0x60000000 : 0x7FE10808;
}

bool indianos1 = false;
void indianos(bool enable) {
	*(unsigned int*)0x13390CC = enable ? 0x4E800020 : 0x7C0802A6; // CNetworkObjectMgr_Update
	*(unsigned int*)0x1654784 = enable ? 0x4E800020 : 0x7C0802A6; // rage_CSyncDataWriter_WriteInteger
	*(unsigned int*)0x10B6C3C = enable ? 0x4E800020 : 0x7C0802A6; // DownloadAndRegisterBGScriptsFileFunc
	*(unsigned int*)0x12E7A78 = enable ? 0x4E800020 : 0x7C0802A6; // CFacebook_FacebookManager
	*(unsigned int*)0x3D7AE0 = enable ? 0x4E800020 : 0x7C0802A6;  // PopulateNowFunc
}

bool vehicle_texture1 = false;
void vehicle_texture(bool enable) {
	*(unsigned int*)0x12382BC = enable ? 0x60000000 : 0xC03E0A20; // sub_12380F8 - REMOVE VEHICLES TEXTURE
}

bool path_freeze_console1 = false;
void path_freeze_console(bool enable) {
	//*(unsigned int*)0x3EBFD4 = enable ? 0x60000000 : 0x00000000;
	*(unsigned int*)0x9FD774 = enable ? 0x60000000 : 0x4E9E0421; // rage_netArrayHandlerBase_HandleReceived
	//*(unsigned int*)0x3D9590 = enable ? 0x60000000 : 0x00000000;
	//*(unsigned int*)0x3D958C = enable ? 0x60000000 : 0x00000000;
	*(unsigned int*)0xA5672C = enable ? 0x60000000 : 0x41820130; // requestForScriptHost
	*(unsigned int*)0x9FCFB4 = enable ? 0x60000000 : 0x7FE10808; // CNetworkEventMgr__MakeSpace
	*(unsigned int*)0x130A300 =
		enable ? 0x60000000 : 0x4BFB2F59; // CGameHostBroadcastDataHandler_VerifyScriptDataEvent
	*(unsigned int*)0xA4D944 = enable ? 0x60000000 : 0x7FE10808;  // sub_A4D79C
	*(unsigned int*)0x9B3AF8 = enable ? 0x60000000 : 0x7FE10808;  // sub_9B397C
	*(unsigned int*)0xAAB3E0 = enable ? 0x60000000 : 0x7FE10808;  // sub_AAB3E0
	*(unsigned int*)0x1309ED4 = enable ? 0x60000000 : 0x4081FF18; // sub_1309AC8
	*(unsigned int*)0x1309EA4 = enable ? 0x60000000 : 0x38600001; // sub_1309AC8
	*(unsigned int*)0x1309EB4 = enable ? 0x60000000 : 0x4181FFB8; // sub_1309AC8
	*(unsigned int*)0x1309EC4 = enable ? 0x60000000 : 0x4081FF34; // sub_1309AC8
	*(unsigned int*)0x1309E50 = enable ? 0x60000000 : 0x4180FFBC; // sub_1309AC8
	*(unsigned int*)0x115E2DC = enable ? 0x60000000 : 0xC0630778; // sub_115E2D0
	*(unsigned int*)0x12D30D8 =
		enable ? 0x60000000 : 0x8084007C; // CNetworkSpecialFireEquippedWeaponEvent_HandleReceived
	*(unsigned int*)0x12D3118 =
		enable ? 0x60000000 : 0x8086007C; // CNetworkSpecialFireEquippedWeaponEvent_HandleReceived
	*(unsigned int*)0x1358F08 = enable ? 0x60000000 : 0x41820188; // CFingerOfGodPresenceEvent_HandleReceived
	*(unsigned int*)0x1358EF8 = enable ? 0x60000000 : 0x41820054; // CFingerOfGodPresenceEvent_HandleReceived
	*(unsigned int*)0x1358EE8 = enable ? 0x60000000 : 0x41820234; // CFingerOfGodPresenceEvent_HandleReceived
	*(unsigned int*)0x9FBBC8 =
		enable ? 0x60000000 : 0x7FE10808; // CGamePlayerBroadcastDataHandler_Local_HandleReceived
	*(unsigned int*)0x9FBBCC =
		enable ? 0x60000000 : 0x4BFFFDA8; // CGamePlayerBroadcastDataHandler_Local_HandleReceived
	//*(unsigned int*)0x3B07B4 = enable ? 0x60000000 : 0x00000000;
	*(unsigned int*)0x404B24 = enable ? 0x60000000 : 0x41820530;  // createPedFunc - duvidoso
	*(unsigned int*)0x10953F8 = enable ? 0x60000000 : 0x41820058; // sub_109536C
	*(unsigned int*)0x10953A4 = enable ? 0x60000000 : 0x418200AC; // sub_109536C
	//*(unsigned int*)0x3D3EB0 = enable ? 0x60000000 : 0x00000000;
	//*(unsigned int*)0x3B0104 = enable ? 0x60000000 : 0x00000000;
	//*(unsigned int*)0x3AA038 = enable ? 0x60000000 : 0x00000000;
	//*(unsigned int*)0x3EA030 = enable ? 0x60000000 : 0x00000000;
	//*(unsigned int*)0x3EA190 = enable ? 0x60000000 : 0x00000000;

	*(unsigned int*)0x13AE8A8 = enable ? 0x60000000 : 0x41810228; // sub_13AE638
	//*(unsigned int*)0x377514 = enable ? 0x60000000 : 0x00000000;
}

// declaration bypass fake e drop kkj
unsigned char ReadByte(int Address) { return *(unsigned char*)Address; }
bool NETWORK_IS_GAME_AND_PLAYER_READY() {
	if (0 == (int)ReadByte(0x1D65D91) && NETWORK::NETWORK_IS_GAME_IN_PROGRESS() == true)
		return true;
	else
		return false;
}

// NEED FIX

// Type  Function                         Line number  Filename  Stack Size  Module
// Unknown  0x0227D910 (0x227D920)
//? ? ? 0x0227D63C
// Unknown  0x0227D790 (0x227D7D4)                         0x0080
//? ? ? 0x024D8620
//? ? ? 0x024E80F4
// Unknown  0x0159B474 (0x159B484)                         0x0080

void kill_ped() {
	ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0);
	PED::RESURRECT_PED(PLAYER::PLAYER_PED_ID());
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
}

//-1138
//-2692
// 13


void force_save() // need fix
{
	if (NETWORK::NETWORK_IS_GAME_IN_PROGRESS()) {
		if (STATS::STAT_SAVE_PENDING()) {
			STATS::STAT_SAVE(3, 1, 0);
			STATS::STAT_SAVE_PENDING();
			STATS::STAT_SAVE(3, 1, 0);
			GAMEPLAY::DO_AUTO_SAVE();
			print("Saved.", 3000);
		}
	}
}

int getFreeSpots() {
	int amount = getNumPlayers();
	return (18 - amount);
}

// int customSpoofLocationPlayer = 0;
// Vector3 customSpoofPosition = { -1371.6047,58.0968,53.7 };
// void getCoordinatesOfCNetObjPlayer_spoof(float coordinatesOut[3], CNetObj* player)
//{
//	coordinatesOut[0] = customSpoofPosition.x;
//	coordinatesOut[1] = customSpoofPosition.y;
//	coordinatesOut[2] = customSpoofPosition.z;
// }

void setWeather(char* weather) {
	*(int*)17388536 = 1610612736;
	*(int*)17388452 = 1610612736;
	*(int*)4013744 = 1610612736;
	GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST(weather);
}

void RainbowWeath(bool bParam0) {
	switch (bParam0) {
	case 0:
		setWeather("NEUTRAL");
		break;

	case 1:
		setWeather("BLIZZARD");
		break;

	case 2:
		setWeather("FOGGY");
		break;

	case 3:
		setWeather("RAIN");
		break;

	case 4:
		setWeather("SNOW");
		break;

	case 5:
		setWeather("XMAS");
		break;

	case 6:
		setWeather("OVERCAST");
		break;
	}
}



void credits_1() {
	zeigen("ninjqk(Creator)\nDontCry361x(Instruct Me) \nxiBryan(Some Codes)");
}

void _no_shadow() { GRAPHICS::SET_TIMECYCLE_MODIFIER("NoDirectLight"); }

void freeze_objc_break() {
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);
	int obj = GAMEPLAY::GET_HASH_KEY("prop_fragtest_cnst_04");
	STREAMING::REQUEST_MODEL(obj);
	if (STREAMING::HAS_MODEL_LOADED(obj)) {
		int freeze = OBJECT::CREATE_OBJECT(obj, PlayerCoords.x, PlayerCoords.y, PlayerCoords.z, 1, 1, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(freeze);
	}
}

void veh_crashs(int selectedPlayer) {
	int vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), 0);
	if (vehicle != 0) {
		VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, true, true);
		VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 1000.0f);
		VEHICLE::SET_VEHICLE_TYRE_BURST(vehicle, 0, true, 1000.0f);
		VEHICLE::SET_VEHICLE_TYRE_BURST(vehicle, 1, true, 1000.0f);
		VEHICLE::SET_VEHICLE_TYRE_BURST(vehicle, 2, true, 1000.0f);
		VEHICLE::SET_VEHICLE_TYRE_BURST(vehicle, 3, true, 1000.0);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(vehicle);
		SYSTEM::WAIT(10);
	}
}

#pragma region sync tree
opd_s _0x12F7188_t = { 0x12F7188, TOC };
opd_s _0x13398D4_t = { 0x13398D4, TOC };
opd_s _0x133D6EC_t = { 0x133D6EC, TOC };
uint32_t(*getCNetGamePlayer)(uint32_t playerId) = (uint32_t(*)(uint32_t)) & _0x12F7188_t;
uint32_t(*getSyncTreePool)(uint32_t cNetworkObjectMgr, uint32_t syncTreetype) =
(uint32_t(*)(uint32_t, uint32_t)) & _0x13398D4_t; // 0x13398D4
uint32_t(*sub_133D6EC)(uint32_t CNetworkObjectMgr, uint32_t CNetGamePlayer_client,
	uint32_t CNetGamePlayer_self, uint32_t syncTreetype, uint32_t r7, uint32_t r8,
	uint32_t r9, uint32_t r10) = (uint32_t(*)(uint32_t, uint32_t, uint32_t, uint32_t,
		uint32_t, uint32_t, uint32_t, uint32_t)) &
	_0x133D6EC_t; // 0x133D6EC
void kickLocal(int playerID) {
	uint64_t* hostUUID = (uint64_t*)(*(unsigned int*)(*(unsigned int*)(0x1CF72C4) + 0x40) + 0x1EB8);
	uint64_t realHostUUID = *hostUUID;

	uint32_t address = getCNetGamePlayer(playerID);
	uint32_t cplayerinfo = *(uint32_t*)(address + 0x78);
	uint64_t uuid = *(uint32_t*)(address + 0x40);

	*hostUUID = uuid;
	NETWORK::NETWORK_SESSION_KICK_PLAYER(playerID);
	*hostUUID = realHostUUID;
}

uint32_t sub_133D6EC_hooked(uint32_t CNetworkObjectMgr, uint32_t CNetGamePlayer_client,
	uint32_t CNetGamePlayer_self, uint32_t syncTreetype, uint32_t r7, uint32_t r8,
	uint32_t r9, uint32_t r10) {
	uint32_t sync_pool = getSyncTreePool(CNetworkObjectMgr, syncTreetype);
	if (sync_pool == 0) {
		uint32_t cPlayerInfo = *(uint32_t*)(CNetGamePlayer_client + 0x78);
		char* name = (char*)(cPlayerInfo + 0x10);

		char buff[100];
		snprintf(buff, sizeof(buff), "~b~%s ~w~Tried To Freeze Lobby Sync Tree", name);
		print(buff, 3000);

		return 6;
	}
	return sub_133D6EC(CNetworkObjectMgr, CNetGamePlayer_client, CNetGamePlayer_self, syncTreetype, r7, r8, r9,
		r10);
}

void sync_tree_protection() { *(int*)(0x1C707F0) = *(int*)((int)&sub_133D6EC_hooked); } //tiny
#pragma endregion

// void Invalid_head_overlay_crash()
//{
//	STREAMING::REQUEST_MODEL(0x3F039CBA);
//	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
//	pos.y += 1000.0f;
//	int z = PED::CREATE_PED(0, 0x3F039CBA, pos, 0.0f, true, true, true, true);
//	PED::SET_PED_HEAD_OVERLAY(PLAYER::GET_PLAYER_PED(selectedPlayer), 0, z);
//	PED::SET_PED_HEAD_OVERLAY(PLAYER::GET_PLAYER_PED(selectedPlayer), 1, z);
//	PED::SET_PED_HEAD_OVERLAY(PLAYER::GET_PLAYER_PED(selectedPlayer), 2, z);
//	PED::SET_PED_HEAD_OVERLAY(PLAYER::GET_PLAYER_PED(selectedPlayer), 3, z);
//	PED::SET_PED_HEAD_OVERLAY(PLAYER::GET_PLAYER_PED(selectedPlayer), 4, z);
//	SYSTEM::WAIT(200);
//	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::GET_PLAYER_PED(selectedPlayer), Vector3(1087.982,
//-2031.811, 114); 	SYSTEM::WAIT(10);
// }

// bool NETWORK_INCREMENT_STAT_EVENT_HANDLE(CNetGamePlayer* sender, CNetGamePlayer* receiver,
// eventArgumentData* eventData) { 	char* senderName = sender->playerInfo->name; 	int senderPlayerId =
//sender->nonPhysicalPlayerData->playerIndex;
//
//	unsigned int* statHash = eventData->getpUInt(0);
//	int* statValue = eventData->getpInt(1);
//	char* scriptEventDialogText = global_temporary_buf;
//	snprintf$(scriptEventDialogText, sizeof(scriptEventDialogText), "%s tried to set stat 0x%X with value
//0x%X", senderName, *statHash, *statValue); 	print2(scriptEventDialogText, 5000); 	printf("%s: hash 0x%X value
//0x%X %i\n", senderName, *statHash, *statValue, *statValue); 	*statHash = 0;//stat name 	*statValue = 0;//stat
//value 	return true;
// }

void set_tatto(char* tatto) {
	PED::_0x70559AC7(PLAYER::PLAYER_PED_ID(), GAMEPLAY::GET_HASH_KEY("multiplayer_overlays"),
		GAMEPLAY::GET_HASH_KEY(tatto));
}

void bota_tatu() {
	set_tatto("FM_Tat_M_008");
	set_tatto("FM_Tat_M_023");
	set_tatto("FM_Tat_M_026");
	set_tatto("FM_Tat_M_032");
	set_tatto("FM_Tat_M_033");
	set_tatto("FM_Tat_M_035");
	set_tatto("FM_Tat_M_037");
	set_tatto("FM_Tat_M_007");
	set_tatto("FM_Tat_M_017");
	set_tatto("FM_Tat_M_022");
	set_tatto("FM_Tat_M_039");
	set_tatto("FM_Tat_M_040");
	set_tatto("FM_Tat_M_043");
	set_tatto("FM_Tat_Award_M_002");
	set_tatto("FM_Tat_Award_M_002");
	set_tatto("FM_Tat_M_000");
	set_tatto("FM_Tat_M_001");
	set_tatto("FM_Tat_M_003");
	set_tatto("FM_Tat_M_014");
	set_tatto("FM_Tat_M_018");
	set_tatto("FM_Tat_M_027");
	set_tatto("FM_Tat_M_028");
	set_tatto("FM_Tat_M_038");
	set_tatto("FM_Tat_M_042");
	set_tatto("FM_Tat_Award_M_001");
	set_tatto("FM_Tat_Award_M_007");
	set_tatto("FM_Tat_Award_M_015");
	set_tatto("FM_Tat_M_005");
	set_tatto("FM_Tat_M_006");
	set_tatto("FM_Tat_M_015");
	set_tatto("FM_Tat_M_031");
	set_tatto("FM_Tat_M_041");
	set_tatto("FM_Tat_M_004");
	set_tatto("FM_Tat_M_012");
	set_tatto("FM_Tat_M_024");
	set_tatto("FM_Tat_M_029");
	set_tatto("FM_Tat_M_036");
	set_tatto("FM_Tat_M_044");
}



//........
void invite_mano(char* PSN_Name) {
	char patch[] = { 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00 };
	write_process((char*)0x10020200, patch, 8);
	strcpy((char*)0x10020208, PSN_Name); //0x10020208
	//possibility 1: 0x3E70B0
	//possibility 2: 0x3E70D8
	//ACTUAL ONE: 0x139ECB0
	opd_s INVITE_t = { 0x139ECB0, TOC };
	void(*INVITE)(int unk1, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7, int unk8, int unk9, int unk10, int unk11) = (void(*)(int, int, int, int, int, int, int, int, int, int, int)) & INVITE_t;
	INVITE(0x40022280, 0x10020200, 1, 0, 0, 0, 1344, 1260, 89, 0xD0040858, 0x10007060);
}
















Vector3 get_coords_from_cam(float distance)
{
	Vector3 Rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	Vector3 Coord = CAM::GET_GAMEPLAY_CAM_COORD();

	Rot.y = distance * SYSTEM::COS(Rot.x);
	Coord.x = Coord.x + Rot.y * SYSTEM::SIN(Rot.z * -1.0f);
	Coord.y = Coord.y + Rot.y * SYSTEM::COS(Rot.z * -1.0f);
	Coord.z = Coord.z + distance * SYSTEM::SIN(Rot.x);

	return Coord;
}


void sendText(int player, char* text, int font) {
	if (player == PLAYER::PLAYER_ID()) {
		UI::SET_TEXT_FONT(font);
		UI::_0x574EE85C("STRING");
		_ADD_TEXT_COMPONENT_STRING(text);
		UI::_DRAW_NOTIFICATION(false, true);
	}
	else {
		int NetHandleBuffer = 0x10070200;
		NETWORK_HANDLE_FROM_PLAYER(player, NetHandleBuffer, 13);
		NETWORK_SEND_TEXT_MESSAGE(text, NetHandleBuffer);
	}
}
void message1test(int selectedPlayer)
{
	sendText(selectedPlayer, "\xF0\x9F\xA5\xB6 My ~p~Blimp Blimp ~g~Fucking ~y~You ~r~xD ~w~\xF0\x9F\xA5\xB6", 7);//emoji congelado
}




void best_send_msg(int selectedPlayer) {

	if (selectedPlayer == PLAYER::PLAYER_ID()) {

		UI::SET_TEXT_FONT(7);  //fonts
		UI::_0x574EE85C("STRING");
		_ADD_TEXT_COMPONENT_STRING("\xF0\x9F\xA5\xB6 My ~p~Blimp Blimp ~g~Fucking ~y~You ~r~xD ~w~\xF0\x9F\xA5\xB6");
		UI::_DRAW_NOTIFICATION(false, true);
	}
	else {
		int NetHandleBuffer = 0x10070200;
		NETWORK_HANDLE_FROM_PLAYER(selectedPlayer, NetHandleBuffer, 13);
		NETWORK_SEND_TEXT_MESSAGE("\xF0\x9F\xA5\xB6 My ~p~Blimp Blimp ~g~Fucking ~y~You ~r~xD ~w~\xF0\x9F\xA5\xB6", NetHandleBuffer);
	}
}

int BigMeme = 1;
void big_gun()
{
	*(float*)(0x1D260) = BigMeme;
}




//void get_face_player()
//{
//	handle = PED::REGISTER_PEDHEADSHOT(PLAYER::GET_PLAYER_PED(selectedPlayer));
//	if (PED::IS_PEDHEADSHOT_READY(handle))
//	{
//		/*string str */char* str = PED::GET_PEDHEADSHOT_TXD_STRING(handle);
//		GRAPHICS::DRAW_SPRITE(str, str, 0.685, 0.5840f, 0.1250f, 0.1250f, 0.0, 255, 255, 255, 255);
//		//notifyMap(str, str, "", "", "");
//	}
//}

unsigned int getTime()
{
	return sys_time_get_system_time() / 1000;
}


void otherLoop() {
	if (keyboardActive) {
		if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 1) {
			keyboardActive = false;
			switch (keyboardAction) {
			case 0: //addIntOption
				*
					keyboardVar = StoI(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
				break;
			}
		}
		else if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 2 || GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 3) {
			keyboardActive = false;
		}
	}

	if (godmode) {
		PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), true);
	}
	else {
		PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), false);
	}
	if (not_target) {
		PED::SET_PED_CAN_BE_TARGETTED(PLAYER::PLAYER_PED_ID(), false);
		PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID()); // remove blood
	}
	else {
		PED::SET_PED_CAN_BE_TARGETTED(PLAYER::PLAYER_PED_ID(), true);
	}
	if (invisible) {
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false);
	}
	else {
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);
	}
	if (shrink) {
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), PED_FLAG_SHRINK, true);
	}
	else {
		PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), PED_FLAG_SHRINK, false);
	}

	if (ammo) {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(playerPed, true);

		int weaponHashes[] = {
			-1716189206,
			1737195953,
			1317494643,
			-1786099057,
			1141786504,
			-2067956739,
			453432689,
			1593441988,
			584646201,
			-1716589765,
			324215364,
			736523883,
			-270015777,
			-1074790547,
			-2084633992,
			-1357824103,
			-1660422300,
			2144741730,
			487013001,
			2017895192,
			-494615257,
			-1654528753,
			911657153,
			100416529,
			205991906,
			-1568386805,
			1312131151,
			1752584910,
			1119849093,
			-1813897027,
			741814745,
			-37975472,
			-615608432,
			101631238,
			883325847,
			600439132,
			1233104067,
			1627465347,
			4192643659,
			3231910285,
			3523564046,
			3218215474,
			2132975508,
			2460120199,
			137902532,
			2138347493,
			2828843422,
			984333226,
			3342088282,
			1672152130,
			2874559379,
			126349499,
			1198879012,
			171789620,
			3696079510,
			3638508604,
			4222310262
		};
		for (int i = 0; i < sizeof(weaponHashes) / sizeof(weaponHashes[0]); i++) {
			int weaponHash = weaponHashes[i];
			if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, weaponHash, false)) {
				int maxAmmo;
				if (WEAPON::GET_MAX_AMMO(playerPed, weaponHash, &maxAmmo)) {
					WEAPON::SET_PED_AMMO(playerPed, weaponHash, maxAmmo);
				}
			}
		}
		PED::SET_PED_CONFIG_FLAG(playerPed, 235, true);
	}
	else {
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(playerPed, false);
		PED::SET_PED_CONFIG_FLAG(playerPed, 235, false);
	}
	if (no_ragdoll) {
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), false);
	}
	else {
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), true);
	}
	if (n_wanted) {
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
	}
	else {
		n_wanted = false;
	}

	if (slow) {
		GAMEPLAY::SET_TIME_SCALE(0.2);
	}
	else {
		GAMEPLAY::SET_TIME_SCALE(1);
	}

	if (spam) {
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 999999999));
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-999999999, 99999999));
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-500000000, 50000000));
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-750000000, 750000000));
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 1000000000));
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-1000000000, 0));
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-500000000, 1000000000));
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-9, 100));
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(9, -20));
		derank_rp_lobby(GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-1, 9999999999999999999));
	}

	// //minha

	//<font size = '69'>haha


	if (loop_message) {
		for (int i = 0; i < 18; i++) {
			if (i == PLAYER::PLAYER_ID()) {
				continue;
			}
			int NetHandleBuffer = 0x10070200;
			NETWORK_HANDLE_FROM_PLAYER(i, NetHandleBuffer, 13);
			NETWORK_SEND_TEXT_MESSAGE("~y~\xF0\x9F\x98\x88~r~Fucking You Skid~y~\xF0\x9F\x98\x88", NetHandleBuffer);
		}
	}



	if (RAPID_FIRE) //Maybe by increasing the delay it will stop freezing when shooting from pump shotgun idk xdd
	{
		Hash currentWeapon;
		static int lastShotTime = 0;
		int delay = 500;

		if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &currentWeapon, 1) && WEAPON::IS_WEAPON_VALID(currentWeapon))
		{
			if (!WEAPON::HAS_WEAPON_ASSET_LOADED(currentWeapon))
			{
				WEAPON::REQUEST_WEAPON_ASSET(currentWeapon, 31, 0);
				SYSTEM::WAIT(0);
			}
			else
			{
				PED::SET_PED_FIRING_PATTERN(PLAYER::PLAYER_PED_ID(), FIRING_PATTERN_BURST_FIRE_PUMPSHOTGUN);

				int currentTime = GAMEPLAY::GET_GAME_TIMER();
				if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_ATTACK) && (currentTime - lastShotTime) > delay)
				{
					Vector3 Rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
					Vector3 Coord = CAM::GET_GAMEPLAY_CAM_COORD();
					Rot.y = 3.0f * SYSTEM::COS(Rot.x);
					Coord.x = Coord.x + Rot.y * SYSTEM::SIN(Rot.z * -1.0f);
					Coord.y = Coord.y + Rot.y * SYSTEM::COS(Rot.z * -1.0f);
					Coord.z = Coord.z + 3.0f * SYSTEM::SIN(Rot.x);
					Vector3 camvf = Coord;
					Rot.y = 100.0f * SYSTEM::COS(Rot.x);
					Coord.x = Coord.x + Rot.y * SYSTEM::SIN(Rot.z * -1.0f);
					Coord.y = Coord.y + Rot.y * SYSTEM::COS(Rot.z * -1.0f);
					Coord.z = Coord.z + 100.0f * SYSTEM::SIN(Rot.x);
					Vector3 camvt = Coord;

					GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(camvf.x, camvf.y, camvf.z,
						camvt.x, camvt.y, camvt.z,
						250, 1, currentWeapon, PLAYER::PLAYER_PED_ID(), 0, 1, 500.0f);

					lastShotTime = currentTime;
				}
			}
		}
	}



	if (display_session_status) {
		const char* sessionType = "STORY MODE";
		if (NETWORK::NETWORK_IS_SESSION_ACTIVE()) {
			if (NETWORK::_0x56E75FE4()) sessionType = "FRIENDS";
			else if (NETWORK::_0xA95299B9()) sessionType = "CREW";
			else if (NETWORK::_0x3D2C1916()) sessionType = "SOLO";
			else if (NETWORK::_0xDB67785D()) sessionType = "INVITE";
			else sessionType = "PUBLIC";
		}
		char sessionStatusText[100];
		snprintf(sessionStatusText, sizeof(sessionStatusText), "SESSION STATUS: %s", sessionType);
		drawText(sessionStatusText, 6, 0.1300f, 0.960f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	}


	if (NETWORK::NETWORK_IS_SESSION_ACTIVE() && display_hex_host) {
		char hostHexText[100];
		char hostHex[128] = "0x";
		const char* sessionHostName = "";

		const int* baseAddress = reinterpret_cast<const int*>(0x1CF72C4);
		if (baseAddress != nullptr) {
			const char* hostAddress = reinterpret_cast<const char*>(*baseAddress + 0x10);
			const char* hostName = ReadString(hostAddress);

			if (hostName != nullptr && strlen(hostName) > 0) {
				sessionHostName = hostName;
			}
			else {
				sessionHostName = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());
			}
		}
		else {
			sessionHostName = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());
		}

		if (strcmp(sessionHostName, "") != 0) {
			for (int i = 0; i < strlen(sessionHostName); ++i) {
				char hexChar[4];
				snprintf(hexChar, sizeof(hexChar), "%02X", sessionHostName[i]);
				strncat(hostHex, hexChar, sizeof(hostHex) - strlen(hostHex) - 1);
			}

			// Formata e desenha o texto na tela
			snprintf(hostHexText, sizeof(hostHexText), "HX: %s", hostHex);
			drawText(hostHexText, 6, 0.2300f, 0.960f, 0.5f, 0.5f, 255, 255, 255, 255, false);
		}
	}



	if (NETWORK::NETWORK_IS_SESSION_ACTIVE()) {
		if (display_host) {
			const char* sessionHostName = "";

			const int* baseAddress = reinterpret_cast <
				const int*> (0x1CF72C4);
			if (baseAddress != nullptr) {
				const char* hostAddress = reinterpret_cast <
					const char*> (*baseAddress + 0x10);
				const char* hostName = ReadString(hostAddress);

				if (hostName != nullptr && strlen(hostName) > 0) {
					sessionHostName = hostName;
				}
				else {
					sessionHostName = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());
				}
			}
			char sessionHostText[100];
			snprintf(sessionHostText, sizeof(sessionHostText), "H: %s", sessionHostName);
			drawText(sessionHostText, 6, 0.4300f, 0.960f, 0.5f, 0.5f, 255, 255, 255, 255, false);
		}
	}

	if (NETWORK::NETWORK_IS_SESSION_ACTIVE()) {
		if (display_script_host) {
			bool isHost = NETWORK::NETWORK_IS_HOST();
			const char* sessionHostName = "";

			if (!isHost) {
				int sessionHostIndex = NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0);

				if (NETWORK::NETWORK_IS_PLAYER_ACTIVE(sessionHostIndex)) {
					sessionHostName = PLAYER::GET_PLAYER_NAME(sessionHostIndex);
				}
				else {
					sessionHostName = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());
				}
			}
			else {
				sessionHostName = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());
			}

			char sessionHostText[100];
			snprintf(sessionHostText, sizeof(sessionHostText), "SH: %s", sessionHostName);

			drawText(sessionHostText, 6, 0.5300f, 0.960f, 0.5f, 0.5f, 255, 255, 255, 255, false);
		}
	}




	if (display_fps) {
		static unsigned int lastFpsUpdate = 0;
		static char FPStext[15] = "FPS: 0";
		unsigned int currentTime = getTime();

		if (currentTime - lastFpsUpdate >= 1000) {
			lastFpsUpdate = currentTime;

			float LastFrameTime = GAMEPLAY::GET_FRAME_TIME();
			int FPS = static_cast<int>(1.0f / LastFrameTime);

			snprintf(FPStext, sizeof(FPStext), "FPS: %d", FPS);
		}

		drawText(FPStext, 6, 0.7300f, 0.960f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	}


	if (display_temperature) {
		static unsigned int lastTemperatureUpdate = 0;
		static char tempText[2][15] = { "CPU: 0C", "RSX: 0C" };
		unsigned int currentTime = getTime();

		if (currentTime - lastTemperatureUpdate >= 1000) {
			lastTemperatureUpdate = currentTime;

			uint32_t cpu_temp_c = 0, rsx_temp_c = 0;
			get_temperature(0, &cpu_temp_c); // 0 para CPU
			get_temperature(1, &rsx_temp_c); // 1 para RSX

			cpu_temp_c >>= 24;
			rsx_temp_c >>= 24;

			snprintf(tempText[0], sizeof(tempText[0]), "CPU: %iC", cpu_temp_c);
			snprintf(tempText[1], sizeof(tempText[1]), "RSX: %iC", rsx_temp_c);
		}
		drawText(tempText[0], 6, 0.9300f, 0.960f, 0.5f, 0.5f, 255, 255, 255, 255, false);
		drawText(tempText[1], 6, 0.8300f, 0.960f, 0.5f, 0.5f, 255, 255, 255, 255, false);
	}




	if (net_40k)
	{
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 0);
		float Loc[3];
		STREAMING::REQUEST_MODEL(0x113FD533);
		if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1)
		{
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, MyCoords.x, MyCoords.y, MyCoords.z + 1.2, 0, 40000, 0x113FD533, 0, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
		}
	}


	if (v1net_40k) {
		STREAMING::REQUEST_MODEL(0x113FD533);
		if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1) {
			Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);

			Vector3 headCoords = mycoords;
			headCoords.z = headCoords.z + 1.0f;

			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, headCoords.x, headCoords.y, headCoords.z, 0, 55000, 0x113FD533, 0, 1);

			Entity object = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(headCoords.x, headCoords.y, headCoords.z, 1.0f, 0x113FD533, false);

			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);
		}
	}

	//esp lobby
	for (int i = 0; i < 16; i++) {
		if (i == PLAYER::PLAYER_ID() || cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-"))
			continue;
		if (linha) {
			int pedTarget = PLAYER::GET_PLAYER_PED(i);
			if (!ENTITY::DOES_ENTITY_EXIST(pedTarget))
				continue;
			Vector3 localCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			Vector3 targetCoords = ENTITY::GET_ENTITY_COORDS(pedTarget, true);
			if (targetCoords.x == 0 && targetCoords.y == 0 && targetCoords.z == 0)
				continue;

			GRAPHICS::DRAW_LINE(
				localCoords.x, localCoords.y, localCoords.z,
				targetCoords.x, targetCoords.y, targetCoords.z,
				0, 0, 0, 255
			);
		}
	}

	if (motion_blur) {
		const float motionBlurValue = 0.3f;
		if (VALID_ADDR(*(int*)0x1DDD224)) {
			*(float*)(*(int*)0x1DDD224 + 0x80) = motionBlurValue;
		}
	}

	if (pontadas) {
		Ped ped = PLAYER::PLAYER_PED_ID();
		Vector3 rotacao = {
			180.0f,
			0.0f,
			0.0f
		};
		ENTITY::SET_ENTITY_ROTATION(ped, rotacao.x, rotacao.y, rotacao.z, 2, true);
	}

	if (load_models) {
		int hash = GAMEPLAY::GET_HASH_KEY(oped);

		STREAMING::REQUEST_MODEL(hash);

		if (STREAMING::HAS_MODEL_LOADED(hash)) {
			PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), hash);

			PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());

			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);

			oped = nullptr;
			animacao2_nao = false;
			load_models = false;
		}
	}



	if (WeeslysDankHax) {
		char BYTES_ON[] = { 0x60, 0x00, 0x00, 0x00 };
		WriteBytes(0x1555B60, BYTES_ON, 4);
	}
	else {
		char BYTES_OFF[] = { 0x7C, 0x43, 0xF9, 0xCE };
		WriteBytes(0x1555B60, BYTES_OFF, 4);
	}



	if (load_anim) {
		STREAMING::REQUEST_ANIM_DICT(baixar_animacao);
		if (STREAMING::HAS_ANIM_DICT_LOADED(baixar_animacao)) {
			ENTITY::SET_ENTITY_ANIM_SPEED(PLAYER::PLAYER_PED_ID(), baixar_animacao, animacao2_nao, 100);
			AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), baixar_animacao, animacao2_nao, 8, 0.0f, -1, 9, 0, 0, 0, 0);
			baixar_animacao = nullptr;
			animacao2_nao = nullptr;
			vadia = false;
		}
	}

	if (SuperJump) {
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
	}

	if (off_radar) {
		WriteInt32(ReadInt32(OffTheRadarPointer) + OffTheRadarGap, 2147483647);
		Write_Global(2390201 + PLAYER::PLAYER_ID() * 223 + 170, 1);
		Write_Global(2394218 + 55, 2147483647);
	}
	else {
		WriteInt32(ReadInt32(OffTheRadarPointer) + OffTheRadarGap, 0);
	}

	if (away_water) {
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		WATER::MODIFY_WATER(Coords.x, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 2, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x, Coords.y + 2, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 2, Coords.y + 2, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 4, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x, Coords.y + 4, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 4, Coords.y + 4, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 6, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x, Coords.y + 6, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 6, Coords.y + 6, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 8, Coords.y, -10, 10);
		WATER::MODIFY_WATER(Coords.x, Coords.y + 8, -10, 10);
		WATER::MODIFY_WATER(Coords.x + 8, Coords.y + 8, -10, 10);
	}


	if (rainbow_menu)
	{
		static int titleColor[] = { 255, 0, 0 };
		static int colorStage = 0;

		switch (colorStage)
		{
		case 0: titleColor[2]++; if (titleColor[2] == 255) colorStage = 1; break;
		case 1: titleColor[0]--; if (titleColor[0] == 0) colorStage = 2; break;
		case 2: titleColor[1]++; if (titleColor[1] == 255) colorStage = 3; break;
		case 3: titleColor[2]--; if (titleColor[2] == 0) colorStage = 4; break;
		case 4: titleColor[0]++; if (titleColor[0] == 255) colorStage = 5; break;
		case 5: titleColor[1]--; if (titleColor[1] == 0) colorStage = 0; break;
		}

		title_color_r = titleColor[0];
		title_color_g = titleColor[1];
		title_color_b = titleColor[2];
		title_color_a = 255;

		scroller_color_r = titleColor[0];
		scroller_color_g = titleColor[1];
		scroller_color_b = titleColor[2];
		scroller_color_a = 70;
	}


	if (SlodFreeze)
	{
		STREAMING::REQUEST_MODEL(model);
		if (STREAMING::HAS_MODEL_LOADED(model))
		{
			Vector3 coord = ENTITY::GET_ENTITY_COORDS(SlodSelectedPed, 0);
			if (!ENTITY::DOES_ENTITY_EXIST(SlodHandle))
				SlodHandle = PED::CREATE_PED(26, model, coord.x, coord.y, coord.z, 0, 0, 0);
			SlodFreezeTimer++;
			if (SlodFreezeTimer >= 150)
			{
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(SlodHandle);
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(SlodHandle, 0, 1);
				ENTITY::DELETE_ENTITY(&SlodHandle);
				SlodFreezeTimer = 0;
				SlodFreeze = false;
				SlodHandle = 0;
			}
		}
	}


	if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L1) && CONTROLS::IS_CONTROL_PRESSED(0, Button_R1) && CONTROLS::IS_CONTROL_PRESSED(0, Button_L3) && CONTROLS::IS_CONTROL_PRESSED(0, Button_R3))
	{
		for (int i = 0; i < 18; i++)
		{
			//blocksyncs[i] = true;
			print("~g~Block Data Enabled");
		}
	}

	if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2) && CONTROLS::IS_CONTROL_PRESSED(0, Button_R2) && CONTROLS::IS_CONTROL_PRESSED(0, Button_L3) && CONTROLS::IS_CONTROL_PRESSED(0, Button_R3))
	{
		for (int i = 0; i < 18; i++)
		{
			//blocksyncs[i] = false;
			print("~r~Block Data Disabled");
		}
	}





	if (outfit_loop) {
		static int components[] = {
			0,  // Cabeça
			1,  // Torso
			2,  // Pé
			3,  // Acessórios (luvas, relógios, etc.)
			4,  // Calças
			5,  // Sapatos
			6,  // Acessórios (colar, etc.)
			7,  // Roupas superiores
			8,  // Máscaras
			9,  // Capacetes
			10, // Acessórios faciais
			11, // Acessórios corporais
			12, // Blusas
			13, // Calças
			14, // Óculos
			15, // Cintos
			16, // Tatuagens
			17  // Outros
		};

		static int numComponents = sizeof(components) / sizeof(components[0]);
		static unsigned int seed = 0xDEADBEEF;
		static float lastChangeTime = 0.0f; // Armazena o tempo da última mudança
		float currentTime = GAMEPLAY::GET_GAME_TIMER() / 1000.0f; // Obtém o tempo atual em segundos

		// Defina o intervalo desejado entre as mudanças, por exemplo, 1 segundo
		float interval = 1.0f;

		if (currentTime - lastChangeTime >= interval) {
			// Mudar as roupas aleatoriamente
			seed = (seed * 1103515245 + 12345) & 0x7FFFFFFF;
			int randomComponentIndex = seed % numComponents;
			int componentIndex = components[randomComponentIndex];

			int numDrawables = PED::GET_NUMBER_OF_PED_DRAWABLE_VARIATIONS(PLAYER::PLAYER_PED_ID(), componentIndex);
			int numTextures = PED::GET_NUMBER_OF_PED_TEXTURE_VARIATIONS(PLAYER::PLAYER_PED_ID(), componentIndex, 0);

			int drawableIndex = (seed % numDrawables);
			int textureIndex = (seed % numTextures);

			PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), componentIndex, drawableIndex, textureIndex, 0);

			// Atualiza o tempo da última mudança
			lastChangeTime = currentTime;
		}
	}






	if (bypass_fake_e_drop) {
		if (NETWORK_IS_GAME_AND_PLAYER_READY()) {
			ant_fakeleave_dropkick(true);
		}
		else {
			ant_fakeleave_dropkick(false);
		}
	}

	if (SpawnVehicle) {
		Ped pedHandle = PLAYER::PLAYER_PED_ID();
		Vehicle vehHandle = PED::GET_VEHICLE_PED_IS_USING(pedHandle);

		if (!STREAMING::HAS_MODEL_LOADED(hash_veh))
			STREAMING::REQUEST_MODEL(hash_veh);
		else {
			if (PED::IS_PED_IN_ANY_VEHICLE(pedHandle, true)) {
				VEHICLE::DELETE_VEHICLE(&vehHandle);
			}
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			int SpawnedVeh = VEHICLE::CREATE_VEHICLE(hash_veh, coords.x, coords.y, coords.z, 0, 1, 0);
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedVeh)) {
				ENTITY::SET_ENTITY_HEADING(SpawnedVeh, ENTITY::GET_ENTITY_HEADING(pedHandle));
				PED::SET_PED_INTO_VEHICLE(pedHandle, SpawnedVeh, -1);
				ENTITY::SET_ENTITY_INVINCIBLE(SpawnedVeh, true);
				VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(SpawnedVeh, false);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(SpawnedVeh, "OFFLINE?");
				SpawnVehicle = false;
			}
		}
	}




	if (clear_area_loop) {
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		float radius = 200.0f;
		//GAMEPLAY::CLEAR_AREA(Pos.x, Pos.y, Pos.z, radius, true, true, true, true);
		GAMEPLAY::CLEAR_AREA_OF_COPS(Pos.x, Pos.y, Pos.z, radius, false);
		GAMEPLAY::CLEAR_AREA_OF_OBJECTS(Pos.x, Pos.y, Pos.z, radius, false);
		GAMEPLAY::CLEAR_AREA_OF_VEHICLES(Pos.x, Pos.y, Pos.z, radius, false, false, false, false, false);
		GAMEPLAY::CLEAR_AREA_OF_PEDS(Pos.x, Pos.y, Pos.z, radius, false);
		GAMEPLAY::CLEAR_AREA_OF_PROJECTILES(Pos.x, Pos.y, Pos.z, radius, false);
	}



	if (exit_load_bug) {
		if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, Button_L3) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, Dpad_Left)) {
			NETWORK::_0xF3768F90(false);
			NETWORK::NETWORK_SESSION_LEAVE_SINGLE_PLAYER();
		}
	}






	if (tutorial_loop)
	{
		int Args[3];
		Args[0] = 0x3;
		Args[1] = selectedPlayer;
		Args[2] = 0x14;
		TriggerScriptEvent(Args, 0x3, selectedPlayer);
	}


	if (sound_0_loop)
	{
		int Args[2];
		Args[0] = 30 + 0;
		Args[1] = selectedPlayer;
		TriggerScriptEvent(Args, 2, selectedPlayer);
	}

	if (sound_1_loop)
	{
		int Args[2];
		Args[0] = 30 + 1;
		Args[1] = selectedPlayer;
		TriggerScriptEvent(Args, 2, selectedPlayer);
	}

	if (force_dardos_loop) {
		int Args[3];
		Args[0] = 3;
		Args[1] = selectedPlayer;
		Args[2] = 0x36;
		TriggerScriptEvent(Args, 3, selectedPlayer);
	}


	if (flight_school_loop) {
		int Args[3];
		Args[0] = 0x3;
		Args[1] = selectedPlayer;
		Args[2] = 0x3A;
		TriggerScriptEvent(Args, 0x3, selectedPlayer);
	}

	if (reset_view_loop) {
		int Args[3];
		Args[0] = 0x2;
		Args[1] = selectedPlayer;
		Args[2] = 0x2e;
		TriggerScriptEvent(Args, 3, selectedPlayer);
	}


	if (hospital_bill_loop) {
		int Args[4];
		Args[0] = 0x138;
		Args[1] = selectedPlayer;
		Args[2] = 9999999;
		Args[3] = 0;
		TriggerScriptEvent(Args, 4, selectedPlayer);
	}

	if (make_fakeleave_loop) {
		int Args[3];
		Args[0] = 0x2;
		Args[1] = selectedPlayer;
		Args[2] = 0x34;
		TriggerScriptEvent(Args, 3, selectedPlayer);
	}


	if (force_golf_loop) {
		int Args[3];
		Args[0] = 0x3;
		Args[1] = selectedPlayer;
		Args[2] = 0x37;
		TriggerScriptEvent(Args, 0x3, selectedPlayer);
	}



	if (apartment_blackscreen_loop) {
		int Args[5];
		Args[0] = 0x16C;
		Args[1] = selectedPlayer;
		Args[2] = 0;
		Args[3] = 0;
		Args[4] = 0;
		TriggerScriptEvent(Args, 5, selectedPlayer);
	}



	if (random_weather) {
		char* weatherOptions[] = {
			"CLEAR",
			"CLOUDS",
			"FOGGY",
			"OVERCAST",
			"RAIN",
			"THUNDER",
			"SNOW",
			"BLIZZARD",
			"XMAS",
			"SMOG",
			"HALLOWEEN",
			"TROPICAL",
			"SANDSTORM",
			"RUSH"
		};
		setWeather(weatherOptions[GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 13)]);
	}






}
#pragma endregion
