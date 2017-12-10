#include"smallstar.h"

Small_star::Small_star() {
	sphere = gluNewQuadric();
	gluQuadricDrawStyle(sphere, GLU_FILL);
	gluQuadricNormals(sphere, GLU_SMOOTH);
	
}
Small_star::~Small_star(){}
void Small_star::Init() {
	red = 0.0f;
	blue = 0.5f;
	green = 1.0f;
	Change_color = true;
	for (int i = 0; i < 3; i++) {
		m_Color[i] = rand() % 255;
		m_Color[i] /= 255;
	}
	xPos = rand() % 298 - 150;
	yPos = 459;
	zPos = rand() % 500;
	zPos *= 100;

}

void Small_star::Shape() {
	GLfloat AmbientLight[] = {1.0f,1.0f,1.0f,1.0f};
	GLfloat DiffuseLight[] = {1.0,1.0f,1.0f,1.0f};
	GLfloat SpecularLight[] = {1.0f,1.0f,1.0f,1.0f};
	GLfloat lightPos[] = {xPos,yPos,zPos,1.0f};
	GLfloat specref[] = {1.0f,1.0f,1.0f,1.0f};
//	glEnable(GL_LIGHTING);
//	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, DiffuseLight);
//	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight);
//	glLightfv(GL_LIGHT1, GL_POSITION, lightPos);
//	glEnable(GL_LIGHT1);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
//	glMateriali(GL_FRONT, GL_SHININESS, 128);
//	glColor3f(m_Color[0]-red, m_Color[1]-blue, m_Color[2]+green);
//		glPushMatrix(); {
//			glTranslatef(xPos, yPos, zPos);
//			gluSphere(sphere, 0.5, 20, 3);
//		}glPopMatrix();
//
}

void Small_star::Timer() {
	if (red > 1.0) {
		Change_color = false;
	}
	if (red < 0.1) {
		Change_color = true;
	}

	if (Change_color) {
		red += 0.1;
		green -= 0.1;
		blue -= 0.1;
	}
	else {
		red -= 0.1;
		green += 0.1;
		blue += 0.1;
	}

}