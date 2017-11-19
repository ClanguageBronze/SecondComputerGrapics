#include"map.h"


void CMap::Init() {
	Start_point = 0.0;
	End_point = RESULT;



}

void CMap::Render() {
	Start_Render();
	Go_animation();



}
void CMap::Start_Render() {
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS); {
		glVertex3f(-300,0, -500);
		glVertex3f(300,0, -500);
		glVertex3f(300, 0, 450);
		glVertex3f(-300,0, 450);
	}glEnd();
	glColor3f(1, 1, 0);

	glBegin(GL_QUADS); {
		glVertex3f(-5, 1, -100);
		glVertex3f(5, 1, -100);
		glVertex3f(5, 1, 100);
		glVertex3f(-5, 1, 100);
	}glEnd();

	glBegin(GL_QUADS); {
		glVertex3f(-5, 1, 150);
		glVertex3f(5, 1, 150);
		glVertex3f(5, 1, 350);
		glVertex3f(-5, 1, 350);
	}glEnd();


	glBegin(GL_QUADS); {
		glVertex3f(-5, 1, 370);
		glVertex3f(5, 1, 370);
		glVertex3f(5, 1, 450);
		glVertex3f(-5, 1, 450);
	}glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_QUADS); {
		glVertex3f(-300, 0, 450);
		glVertex3f(300, 0, 450);
		glVertex3f(300, 0, 500);
		glVertex3f(-300, 0, 500);
	}
	glEnd();
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS); {
		glVertex3f(-5, 1, 450);
		glVertex3f(5, 1, 450);
		glVertex3f(5, 1, 500);
		glVertex3f(-5, 1, 500);
	}
	glEnd();
}
void CMap::Go_animation() {
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS); {
		glVertex3f(100, 120, 500);
		glVertex3f(50, 120, 500);
		glVertex3f(50, 110, 500);
		glVertex3f(100, 110, 500);

		glVertex3f(100, 110, 500);
		glVertex3f(90, 110, 500);
		glVertex3f(90, 80, 500);
		glVertex3f(100, 80, 500);

		glVertex3f(90, 90, 500);
		glVertex3f(50, 90, 500);
		glVertex3f(50, 80, 500);
		glVertex3f(90, 80, 500);

		glVertex3f(60, 100, 500);
		glVertex3f(45, 100, 500);
		glVertex3f(45, 90, 500);
		glVertex3f(60, 90, 500);

		glVertex3f(50, 90, 500);
		glVertex3f(45, 90, 500);
		glVertex3f(45, 70, 500);
		glVertex3f(50, 70, 500);

		
	}glEnd();


}