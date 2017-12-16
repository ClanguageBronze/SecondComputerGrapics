#include"Cloud.h"

Cloud::Cloud() {
	xPos = rand() % 200 - 100;
	yPos = rand() % 200 + 200;
	zPos = rand() % 19000;
}
Cloud::~Cloud(){}
void Cloud::Render() {
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glScalef(1, 0.2, 0.4);
	glutSolidSphere(60, 20, 3);
	glPopMatrix();
}