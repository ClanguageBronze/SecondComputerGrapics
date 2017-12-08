#pragma once
#include"define.h"
#include"Character.h"
#include"CSoundManager.h"
#include"CObstacle.h"
#include"map.h"
#include"LIGHT.h"
class CIngame {
	Character* Main{ nullptr };
	CSoundManager* SoundManager{ nullptr };
	CMap * map{ nullptr };
	LIGHT* light{ nullptr };
	float Eyex ;
	float Eyey ;
	float Eyez ;
	float Centerx;
	float Centery;
	float Centerz;
	float Upx;
	float Upy;
	float Upz;
public:
	CIngame();
	~CIngame();
	void Init();
	void Getkey(const unsigned char, const int, const int);
	void Render();
	void Reshape(const int, const int);
	void Mousebutton(const int, const int, const int, const int);
	void MouseMotion(int, int);
	void Update(int);
	void Filming();
};