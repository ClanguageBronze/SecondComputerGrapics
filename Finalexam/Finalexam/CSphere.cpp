#include"CSphere.h"

CSphere::CSphere() {
	xPos = rand() % 6 - 3;
	yPos = rand() % 6 - 3;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	radius = 3;
	
}
CSphere::~CSphere() {
	gluDeleteQuadric(qobj);
}
void CSphere::Init() {
	speed =1;
	speed2 = rand() % 4 + 1;
	m_bparticle = false;
}
void CSphere::Render() {

		if (speed < 10)
			glColor3f(1, 1, 0);
		else if (speed > 10 && speed < 30)
			glColor3f(1, 0, 0);
		glPushMatrix();
		{
			glTranslatef(xPos ,yPos, -speed);
			gluSphere(qobj, radius, 20, 8);
		}
		glPopMatrix();
	
}

void CSphere::Particle() {
	speed+=speed2;
	if (speed > 30) {
		speed = 0;
	}
}
