#include"CIntro.h"
CIntro::CIntro() {


}
CIntro::~CIntro() {


}
void CIntro::Reshape(int w, int h) {
	w = WINDOW_SIZE_WIDTH;
	h = WINDOW_SIZE_HEIGHT1;
	glViewport(0, 0, w, h);
	glOrtho(-w / 2, w / 2, h / 2, -h / 2, -100, 100);
}
void CIntro::Render() {
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS); {
		glVertex2i(-400,-300);
		glVertex2i(-400, 300);
		glVertex2i(400, 300);
		glVertex2i(400, -300);
	}glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS); {
		glVertex3f(-200, -100, 0);
		glVertex3f(-50, -100, 0);
		glVertex3f(-50, -25, 0);
		glVertex3f(-200, -25, 0);

		glVertex3f(-200, -25, 0);
		glVertex3f(-175, -25, 0);
		glVertex3f(-175, 100, 0);
		glVertex3f(-200, 100, 0);

		glVertex3f(-175, 0, 0);
		glVertex3f(-100, 0, 0);
		glVertex3f(-100, 40, 0);
		glVertex3f(-175, 40, 0);

		glVertex3f(-25, -100, 0);
		glVertex3f(25, -100, 0);
		glVertex3f(25, 150, 0);
		glVertex3f(-25,150, 0);

		glVertex3f(80, -100, 0);
		glVertex3f(160, -50, 0);
		glVertex3f(130, -20, 0);
		glVertex3f(50, -80, 0);

		glVertex3f(180,-100,0);
		glVertex3f(200, -80, 0);
		glVertex3f(80,)
	}glEnd();
}
