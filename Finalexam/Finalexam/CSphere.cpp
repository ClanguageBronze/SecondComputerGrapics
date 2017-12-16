#include"CSphere.h"

CSphere::CSphere() {
	xPos = rand() % 6 - 3;
	yPos = rand() % 6 - 3;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	radius = 3;
	Effect = 1;
}
CSphere::~CSphere() {
	gluDeleteQuadric(qobj);
}
void CSphere::Init() {
	speed =1;
	speed2 = rand() % 4 + 1;
	m_bparticle = false;
	Effect = 1;
}
void CSphere::Render() {
	if (Effect == 1) {
		if (speed < 10)
			glColor3f(1, 1, 0);
		else if (speed > 10 && speed < 30)
			glColor3f(1, 0, 0);
		glPushMatrix();
		{
			glTranslatef(xPos, yPos, -speed);
			gluSphere(qobj, radius, 20, 8);
		}
		glPopMatrix();
	}
	else {
		glColor4f(1, 1, 1, 0.5);
		glPushMatrix();
		{
			glTranslatef(xPos*2, yPos+speed, 0);
			gluSphere(qobj, radius, 20, 8);
		}
		glPopMatrix();
	}
}

void CSphere::Particle(int effect) {
	Effect = effect;
	speed+=speed2;
	if (speed > 30) {
		speed = 0;
	}
}
