#pragma once
#include"define.h"

class CMap2 {

	GLubyte *TexBits;
	BITMAPINFO *info;
	GLuint texture[5];
public:
	CMap2();
	~CMap2();
	void Render();
	void Start_Render();
	GLubyte * LoadDIBitmap(const char *, BITMAPINFO **);
};