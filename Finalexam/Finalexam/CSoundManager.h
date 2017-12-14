#include"define.h"
#pragma once
#pragma comment(lib,"winmm.lib")

#define INTRO_BGM "Sound/Kirby_bgm.wav"
#define INGAME_BGM "resource.wav"
#define EFFECT_CLICK "resource.wav" 
#define OBJ_MOVE "resource.wav"
#define OBJ_COL "resource.wav"
#define OBJ_FAIL "resource.wav"

#define INTRO 0
#define INGAME 1
#define CLICK_SOUND 0x1
#define MOVE_SOUND 0x2
#define COLLISION_SOUND 0x3
#define FAIL_SOUND 0x4

class CSoundManager {
public:
	CSoundManager();
	~CSoundManager();
	void PlayBGM(int);
	void PlayEffect(int);

};