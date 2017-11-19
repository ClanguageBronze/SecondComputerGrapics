#pragma once
#include"define.h"
#include"CIntro.h"
class CGameSystem {
	CIntro* m_pIntro{ nullptr };
	bool m_bIntro;
	bool m_bFixed;
	bool m_bGameOver{ false };

public:
	CGameSystem();
	~CGameSystem();
	void GetKey(const unsigned char, const int, const int);
	void SpecialKey(const int, const int, const int);
	void MouseButton(const int ,const int ,const int, const int);
	void MouseMotion(const int, const int);
	void Update();
	void Render();
	void ChangeSize(int w, int h);



};