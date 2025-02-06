#pragma once

int submenu = 0;
int newSubmenu = 0;//PB said keep for now
int submenuLevel;
int lastSubmenu[20];
int lastOption[20];

int selectedPlayer;
int keyboardAction;
int* keyboardVar = 0;
int maxTimerCount;
int maxTimerCount2;
int instructCount;
int mov;

char* optionInfo[100]; // Array para armazenar as informações das opções

//
// int scrollerRed = 255; //cores do scroll
// int scrollerGreen = 255;
// int scrollerBlue = 255;
// int scrollerOpacity = 20;
//
// int indicatorRed = 255; //cores do indicador
// int indicatorGreen = 255;
// int indicatorBlue = 255;
// int indicatorOpacity = 255;

bool PlaySounds = true;

bool bypass_fake_e_drop = true;

float cycleTimer = 0.0f;
int colorCycle = 0;
float cycleInterval = 0.5f;   // Intervalo de tempo entre cada letra,aumente para diminuir a velocidade
int currentLetterIndex = 0;   // Índice da letra atual sendo exibida
bool isVisible = true;        // Controla se a palavra está visível ou não
float visibilityTimer = 0.0f; // Temporizador para o efeito de visibilidade

char* oped;
bool vadia;
char* baixar_animacao;
char* animacao2_nao;

bool optionPress = false;
bool rightPress = false;
bool leftPress = false;
bool fastRightPress = false;
bool fastLeftPress = false;
bool squarePress = false;
bool menuSounds = true;
bool keyboardActive = false;
bool newTimerTick2 = true;
bool newTimerTick = true;
bool instructionsSetupThisFrame;
bool xInstruction;
bool squareInstruction;
bool lrInstruction;
bool instructions = false;
char* infoText;

float SubTitleXCoord = 0.082f;


int activeLineIndexTime = 0;

char* Anim;
char* AnimID;
bool LoadingAnim;
bool LoadingPlayerAnim;

// DECLARAR AQUI
// outros
int time1; // Advanced Time Def
int int_NetworkOptions[60];
int sceneID;

bool display_fps = true;
bool display_host = true;
bool display_script_host = true;
bool display_modders = false;
bool display_hex_host = false;
bool display_temperature = true;
bool display_session_status = true;
bool toggleRedux1 = false;
int InfoFont = 6;
char* str;

int maxOptions = 20; // antiga a debaixo vale mais
float MenuWidth = 0.21f;
int currentOption;
int optionCount;
int MaxOption = 25;
float menuXCoord = 0.100f;
float menuYCoord = 0.140f;

float textXCoord = 0.032f;
// float buf = InfiniteScroll(optionCount);
// float textYCoord = (buf * 0.025f + 0.135f);

int bannerTextFont = 6; // fonte do titulo


int BannerColorR = 0;
int BannerColorG = 0;
int BannerColorB = 0;
int BannerColorA = 210;

int MenuColorR = 0;
int MenuColorG = 0;
int MenuColorB = 0;
int MenuColorA = 140;


int bannerTextRed = 255; // cores do titulo
int bannerTextGreen = 255;
int bannerTextBlue = 255;
int bannerTextOpacity = 255;

int optionsFont = 0;  // fonte das opcoes
int optionsRed = 255; // cores opcoes

int optionsGreen = 255;
int optionsBlue = 255;
int optionsOpacity = 255;
bool SPAM_MESSAGE_REAL1 = false; // Variável booleana que controlará o spam de mensagens

//
// float InfiniteScroll(float optionCurrentDrawn)
//{
//	if ((currentOption <= MaxOption && optionCurrentDrawn <= MaxOption) ||
//		((optionCurrentDrawn > (currentOption - MaxOption)) && optionCurrentDrawn <= currentOption))
//	{
//		float buf = (currentOption <= MaxOption && optionCurrentDrawn <= MaxOption) ?
//			(optionCurrentDrawn) : (optionCurrentDrawn - (currentOption - MaxOption));
//
//		return buf;
//	}
//	return 0;
//}
//
//
// float buf = InfiniteScroll(optionCount);
//
// float textYCoord = (buf * 0.025f + 0.135f);

#pragma endregion