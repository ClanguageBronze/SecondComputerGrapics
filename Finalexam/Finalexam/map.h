#pragma once
#include"define.h"


class CMap {
	GLubyte *TexBits;
	BITMAPINFO *info;
	GLuint texture[5];
public:
	CMap();
	~CMap();
	void Init();
	void Render();
	void Start_Render();
	GLubyte * LoadDIBitmap(const char *, BITMAPINFO **);
};

