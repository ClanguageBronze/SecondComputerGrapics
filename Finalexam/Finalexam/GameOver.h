#pragma once
#include"define.h"
class CGameOver {
	GLubyte *texbits;
	BITMAPINFO *info;
	GLuint texture[1];
	float Eyex;
	float Eyey;
	float Eyez;
	float Centerx;
	float Centery;
	float Centerz;
	float Upx;
	float Upy;
	float Upz;
public:
	CGameOver();
	~CGameOver();
	void Render();
	GLubyte* loadDIBitmap(const char*, BITMAPINFO**);
};