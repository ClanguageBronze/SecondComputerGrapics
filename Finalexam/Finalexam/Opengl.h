#pragma once
#include"define.h"

class COpengl {
	GLUquadricObj* Cube[30];
	GLubyte *Texbits;
	BITMAPINFO *info;
	GLuint texture[20];
	float  xPos;
	float yPos;
	float zPos;
	int speed;
	int i;
	int shape;
	float color[3];
public:
	COpengl(float,float,float);
	~COpengl();
	void Init();
	void Render();
	void Rotation();
	GLubyte* loadDIBitmap(const char*, BITMAPINFO **);
};