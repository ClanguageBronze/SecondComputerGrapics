#include"define.h"
#pragma once
#pragma comment(lib,"winmm.lib")

#define INTRO_BGM "Sound/Intro.wav"
#define INGAME_BGM "Sound/FLY.wav"
#define INGAME_BGM2 "Sound/Underthesea.wav"
#define GAME_OVERBGM "Sound/dead.wav"
#define FINISH "Sound/Clear.wav"



#define INTRO 0
#define INGAME 1
#define INGAME2 2
#define CLEAR1 3
#define CLEAR2 4

class CSoundManager {
public:
	CSoundManager();
	~CSoundManager();
	void PlayBGM(int);
	void PlayEffect(int);

};