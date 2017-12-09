#pragma once
#include"define.h"
#include"CIntro.h"
#include"CSoundManager.h"
#include"CIngame.h"
#include"GameOver.h"
class CGameSystem {
	CIntro*m_pCIntro{ nullptr };
	CIngame* m_pCIngame{ nullptr };
	CSoundManager* m_pSoundManager{ nullptr };
	CGameOver *m_pCGameOver{ nullptr };
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

	void GetKey(unsigned char, int, int);
	void SpecialKey(int,  int, int);
	void MouseButton( int , int ,int, int);
	void MouseMotion( int,  int);
	void Update();
	void Render();
	GLubyte* loadDIBitmap(const char*, BITMAPINFO**);
	void ChangeSize(int w, int h);
};