#pragma once
#include"define.h"
#include"CSoundManager.h"
class CIntro{
	bool m_bIntro;
	GLubyte *Texbits;
	BITMAPINFO *info;
	GLuint texture[3];
public:
	CIntro();
	~CIntro();
	void Render();
	void Reshape(int, int);
	GLubyte* loadDIBitmap(const char*, BITMAPINFO**);
};