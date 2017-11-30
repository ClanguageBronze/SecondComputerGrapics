#pragma once
#include"define.h"

class CMap {
	float m_fSky;
	float m_fGround;
	float distance;
	float Start_point;
	float End_point;

public:
	void Init();
	void Render();
	void Start_Render();
	void Sky_Render();
	void Go_animation();

};

