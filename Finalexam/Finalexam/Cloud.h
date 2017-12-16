#pragma once
#include"define.h"

class Cloud {
	float xPos;
	float yPos;
	float zPos;
public:
	Cloud();
	~Cloud();
	void Init();
	void Render();
};