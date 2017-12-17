#pragma once
#include"define.h"
#include "Sound\FMOD\include\fmod.hpp"


#define MAX_SOUND 50

// BGM ä�� ��ȣ
#define BGM_INTRO 0
#define BGM_INGAME 1
#define BGM_CLEAR1 2
#define BGM_CLEAR2 3
// stage bgm�� �� �þ �� ����

// EFFECT ä�� ��ȣ

// �ý��� ���� ȿ����
#define EFFECT_CLICK_BUTTON_00 10

// ���� ���� ȿ����
#define EFFECT_OBJ_MOVE_00 20
#define EFFECT_OBJ_MOVE_01 21
#define EFFECT_OBJ_DEAD_00 22
#define EFFECT_OBJ_UPDATE_00 23


class CSoundManager {
public:
	CSoundManager();
	~CSoundManager();

	void SetSounds();

	bool AddSound(
		size_t idx
		, LPCSTR szPath
		, bool bBGM = false
		);

	void Stop(bool bMasterStop = false);
	void PlayEffect(size_t idx);
	void PlayBGM(size_t idx);


private:
	FMOD::System	*m_System{ nullptr };
	FMOD::Channel	*m_Channel{ nullptr };	// bgm�� ���� ä��
	FMOD::Sound		*m_Sound[MAX_SOUND];
};
