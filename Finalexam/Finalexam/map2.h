#pragma once
#include"define.h"
#include"Cloud.h"
class CMap2 {
	Cloud *m_pCloud[100]{ nullptr };
	GLubyte *TexBits;
	BITMAPINFO *info;
	GLuint texture[8];
public:
	CMap2();
	~CMap2();
	void Render();
	void Start_Render();
	GLubyte * LoadDIBitmap(const char *, BITMAPINFO **);
};