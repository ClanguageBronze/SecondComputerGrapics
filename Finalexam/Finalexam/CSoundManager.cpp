
#include "CSoundManager.h"

#pragma comment(lib, "Sound/FMOD/lib/fmod64_vc.lib")

CSoundManager::CSoundManager()
{
	FMOD::System_Create(&m_System);
	m_System->init(
		FMOD_MAX_CHANNEL_WIDTH
		, FMOD_INIT_NORMAL
		, nullptr
		);

	for (auto& p : m_Sound) p = nullptr;

	SetSounds();
}

CSoundManager::~CSoundManager()
{
	for (auto& p : m_Sound) {
		if (p) p->release();
		p = nullptr;
	}

	m_System->close();
	m_System->release();
}

void CSoundManager::SetSounds()
{
	AddSound(BGM_INTRO, ("Sound/bgm/Intro.mp3"), true);
	AddSound(BGM_INGAME, ("Sound/bgm/Samuel E. Wright-06-Under The Sea.mp3"), true);
	AddSound(BGM_CLEAR1, ("Sound/bgm/retire.mp3"), true);
	AddSound(BGM_CLEAR2, ("Sound/bgm/Clear.mp3"), true);
	AddSound(EFFECT_CLICK_BUTTON_00, ("Sound/effect/Click.mp3"));
	AddSound(EFFECT_OBJ_MOVE_00, ("Sound/effect/Motor_Running.mp3"),true);
	AddSound(EFFECT_OBJ_MOVE_01, ("Sound/effect/Shutter.mp3"),true);
	AddSound(EFFECT_OBJ_UPDATE_00, ("Sound/effect/Machine_Rumble.mp3"), true);
	AddSound(EFFECT_OBJ_DEAD_00, ("Sound/effect/Boom.mp3"));
}

bool CSoundManager::AddSound(size_t idx, LPCSTR szPath, bool bBGM)
{
	if (idx < 0)return false;
	if (idx >= MAX_SOUND)return false;

	FMOD_RESULT res;

	if (bBGM) {
		res = m_System->createStream(
			szPath
			, FMOD_LOOP_NORMAL | FMOD_2D
			, nullptr
			, &m_Sound[idx]
			);
	}
	else {
		res = m_System->createSound(
			szPath
			, FMOD_DEFAULT
			, nullptr
			, &m_Sound[idx]
			);
	}

	return (res == FMOD_OK);
}

void CSoundManager::Stop(bool bMasterStop)
{
	if (nullptr == m_Channel)return;
	bool bNowPlaying;
	m_Channel->isPlaying(&bNowPlaying);
	if (bNowPlaying)
		m_Channel->stop();

	if (!bNowPlaying)return;

	FMOD::ChannelGroup *cg_master{ nullptr };
	m_System->getMasterChannelGroup(&cg_master);
	cg_master->stop();
}

void CSoundManager::PlayEffect(size_t idx)
{
	if (idx < 0)return;
	if (idx >= MAX_SOUND)return;

	m_System->playSound(m_Sound[idx]
		, nullptr, false, nullptr);
}

void CSoundManager::PlayBGM(size_t idx)
{
	if (idx < 0)return;
	if (idx >= MAX_SOUND)return;
	m_System->playSound(m_Sound[idx]
		, nullptr, false, &m_Channel);
}
