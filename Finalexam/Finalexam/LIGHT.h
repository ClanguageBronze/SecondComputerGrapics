#pragma once
#include"define.h"
class LIGHT {
	float xPos;
	float yPos;
	float zPos;
	float Alpha;
	GLfloat Ambient_light[4];
	GLfloat Diffuse_light[4];
	GLfloat Specular_light[4];
	GLfloat Light_Pos[4];
	GLfloat specref[4];

public:
	LIGHT(float, float, float, float);
	~LIGHT();
	void Init();
	void M_FLIGHTING();
	void Update();
};