#pragma once
#include"define.h"
#include"Character.h"
#include"CSoundManager.h"
#include"CObstacle.h"
class CIngame {
	Character* Main{ nullptr };
	CSoundManager* SoundManager{ nullptr };
public:
	CIngame();
	~CIngame();
	void Init();
	void Getkey(const unsigned char, const int, const int);
	void Render();
	void Reshape(const int, const int);
	void Mousebutton(const int, const int, const int, const int);

};