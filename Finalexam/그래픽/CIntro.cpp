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

	}glEnd();
}