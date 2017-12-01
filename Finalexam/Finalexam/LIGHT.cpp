#include"LIGHT.h"

LIGHT::LIGHT(float x, float y, float z, float a) {
	xPos = x;
	yPos = y;
	zPos = z;
	Alpha = a;
}
LIGHT::~LIGHT() {

}
void LIGHT::Init() {
	for (int i = 0; i < 4; i++) {
		Ambient_light[i] = 1.0f;
		Diffuse_light[i] = 1.0f;
		if (i == 2) {
			Diffuse_light[i] = 0.0f;
		}
		specref[i] = 1.0f;

	}
	Light_Pos[0] = xPos;
	Light_Pos[1] = yPos;
	Light_Pos[2] = zPos;
	Light_Pos[3] = Alpha;
}

void LIGHT::M_FLIGHTING() {
	Update();
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse_light);
	glLightfv(GL_LIGHT0, GL_POSITION, Light_Pos);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specref);
	glMateriali(GL_FRONT,GL_SHININESS, 64);
}
void LIGHT::Update() {
	Light_Pos[3] += 10;
}