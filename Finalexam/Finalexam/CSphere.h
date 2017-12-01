#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<GL/freeglut.h>
#include<GL/GLU.h>
#include<GL/glut.h>
#include<GL/GL.h>
#include<math.h>

class CSphere {
	float xPos;
	float yPos;
	float zPos;
	float radius;
	float speed;
	float speed2;
	GLUquadricObj *qobj;
	bool m_bparticle;
public:
	CSphere();
	~CSphere();
	void Init();
	void Render();
	void Particle();
};