#pragma once
#include"define.h"

class Small_star {
	GLUquadricObj *sphere;
	float m_Color[3];
	float xPos;
	float yPos;
	float zPos;
	int location;
	float red;
	float blue;
	float green;
	bool Change_color;
public:
	Small_star();
	void Init() ;
	~Small_star();
	void Shape ();
	void Timer();


};