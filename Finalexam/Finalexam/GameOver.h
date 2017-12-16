#pragma once
#include"define.h"
#include"CSoundManager.h"
class CGameOver {
	GLubyte *texbits;
	BITMAPINFO *info;
	GLuint texture[2];
	float Eyex;
	float Eyey;
	float Eyez;
	float Centerx;
	float Centery;
	float Centerz;
	float Upx;
	float Upy;
	float Upz;
	int Select;
	
public:
	CGameOver(bool,bool);
	~CGameOver();
	void Render();
	GLubyte* loadDIBitmap(const char*, BITMAPINFO**);
};