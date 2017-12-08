#pragma once
#include"define.h"
#include"CIntro.h"
#include"CSoundManager.h"
#include"CIngame.h"
class CGameSystem {
	CIngame* m_pCIngame{ nullptr };
	CSoundManager* m_pSoundManager{ nullptr };
	bool m_bIntro;
	bool m_bFixed;
	bool m_bGameOver{ false };
	GLubyte *Texbits;
	BITMAPINFO *info;
	GLuint texture[3];
	int mouse_x;
	int mouse_y;
	bool left_button;
public:
	CGameSystem();
	~CGameSystem();
	void GetKey(const unsigned char, const int, const int);
	void SpecialKey(const int, const int, const int);
	void MouseButton(const int ,const int ,int, int);
	void MouseMotion( int,  int);
	void Update(int);
	void Render();
	GLubyte* loadDIBitmap(const char*, BITMAPINFO**);
	void ChangeSize(int w, int h);
};