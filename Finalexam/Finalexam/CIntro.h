#pragma once
#include"define.h"
#include"LIGHT.h"
#include"CSoundManager.h"
class CIntro{
	GLubyte *Texbits;
	BITMAPINFO *info;
	GLuint texture[3];
	float Eyex;
	float Eyey;
	float Eyez;
	float Centerx;
	float Centery;
	float Centerz;
	float Upx;
	float Upy;
	float Upz;
	LIGHT *light{nullptr};
public:
	CIntro();
	~CIntro();
	void Render();
	
	GLubyte* loadDIBitmap(const char*, BITMAPINFO**);
};