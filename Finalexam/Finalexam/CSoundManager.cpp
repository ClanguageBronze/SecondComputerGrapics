#include"CSoundManager.h"
CSoundManager::CSoundManager() {}
CSoundManager::~CSoundManager() {}
void CSoundManager::PlayBGM(int Sound_Type) {
	if (Sound_Type == INTRO)PlaySound(TEXT(INTRO_BGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
	if (Sound_Type == INGAME)PlaySound(TEXT(INGAME_BGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
}
void CSoundManager::PlayEffect(int Sound_Type) {
	if (Sound_Type == CLICK_SOUND)PlaySound(TEXT(EFFECT_CLICK), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
	if (Sound_Type == MOVE_SOUND)PlaySound(TEXT(OBJ_MOVE), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
	if (Sound_Type == COLLISION_SOUND)PlaySound(TEXT(OBJ_COL), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
	if (Sound_Type == FAIL_SOUND)PlaySound(TEXT(OBJ_FAIL), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
}