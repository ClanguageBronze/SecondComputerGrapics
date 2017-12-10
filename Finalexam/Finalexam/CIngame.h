#pragma once
#include"define.h"
#include"Character.h"
#include"CSoundManager.h"
#include"CObstacle.h"
#include"map.h"
#include"Opengl.h"
#include"LIGHT.h"
class CIngame {
	Character* Main{ nullptr };
	COpengl *Monster{ nullptr };
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
	int mouse_x;
	int mouse_y;
	int line;
	int Fast_z;
	float xRotation;
	float yRotation;
	float zRotation;
public:
	int speed;
	CIngame();
	~CIngame();
	void Init();
	void Getkey(unsigned char,  int,  int);
	void Render();
	void Mousebutton( int, int,int,int);
	void MouseMotion(int, int);
	void Update();
	void Filming();
	bool M_FDead();
	bool M_FFinish();
};