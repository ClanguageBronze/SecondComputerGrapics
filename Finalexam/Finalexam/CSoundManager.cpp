#include"CSoundManager.h"
CSoundManager::CSoundManager() {}
CSoundManager::~CSoundManager() {}
void CSoundManager::PlayBGM(int Sound_Type) {
	if (Sound_Type == INTRO)PlaySound(TEXT(INTRO_BGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	if (Sound_Type == INGAME2)PlaySound(TEXT(INGAME_BGM2), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	if (Sound_Type == CLEAR2)PlaySound(TEXT(FINISH), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	if (Sound_Type == INGAME) PlaySound(TEXT(INGAME_BGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	if (Sound_Type == CLEAR1) PlaySound(TEXT(GAME_OVERBGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	
}
