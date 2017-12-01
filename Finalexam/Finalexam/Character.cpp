#include"Character.h"
Character::Character() {
	for (int i = 0; i < 40; i++) {
		spee[i] = new CSphere;
	}
	for (int i = 0; i < 2; i++) {
		Engine_obj[i] = gluNewQuadric();
		gluQuadricDrawStyle(Engine_obj[i], GLU_FILL);
		gluQuadricNormals(Engine_obj[i], GLU_SMOOTH);


		Equipment_other[i] = gluNewQuadric();
		gluQuadricDrawStyle(Equipment_other[i], GLU_FILL);
		gluQuadricNormals(Equipment_other[i], GLU_SMOOTH);
	}
	for (int i = 0; i < 4; i++) {



		Tail_wing_part[i] = gluNewQuadric();
		gluQuadricDrawStyle(Tail_wing_part[i], GLU_FILL);
		gluQuadricNormals(Tail_wing_part[i], GLU_SMOOTH);

		Wing_part[i] = gluNewQuadric();
		gluQuadricDrawStyle(Wing_part[i], GLU_FILL);
		gluQuadricNormals(Wing_part[i], GLU_SMOOTH);

		Wing_other_part[i] = gluNewQuadric();
		gluQuadricDrawStyle(Wing_other_part[i], GLU_FILL);
		gluQuadricNormals(Wing_other_part[i], GLU_SMOOTH);
	}
	Fire = gluNewQuadric();
	gluQuadricDrawStyle(Fire, GLU_FILL);
	gluQuadricNormals(Fire, GLU_SMOOTH);

	for (int i = 0; i < 6; i++) {
		Equipment[i] = gluNewQuadric();
		gluQuadricDrawStyle(Equipment[i], GLU_FILL);
		gluQuadricNormals(Equipment[i], GLU_SMOOTH);
	}

	for (int i = 0; i < 8; i++) {
		Tail_wing_otherpart[i] = gluNewQuadric();
		gluQuadricDrawStyle(Tail_wing_otherpart[i], GLU_FILL);
		gluQuadricNormals(Tail_wing_otherpart[i], GLU_SMOOTH);
	}
	body_obj = gluNewQuadric();
	Front_obj = gluNewQuadric();
	Tail_obj = gluNewQuadric();
	Glass_part = gluNewQuadric();
	Mouth_obj = gluNewQuadric();
	gluQuadricDrawStyle(body_obj, GLU_FILL);
	gluQuadricNormals(body_obj, GLU_SMOOTH);
	gluQuadricDrawStyle(Front_obj, GLU_FILL);
	gluQuadricNormals(Front_obj, GLU_SMOOTH);
	gluQuadricDrawStyle(Tail_obj, GLU_FILL);
	gluQuadricNormals(Tail_obj, GLU_SMOOTH);
	gluQuadricDrawStyle(Mouth_obj, GLU_FILL);
	gluQuadricNormals(Mouth_obj, GLU_SMOOTH);
	gluQuadricDrawStyle(Glass_part, GLU_FILL);
	gluQuadricNormals(Glass_part, GLU_SMOOTH);
}
Character::~Character() {
	gluDeleteQuadric(body_obj);
	gluDeleteQuadric(Front_obj);
	gluDeleteQuadric(Tail_obj);
	gluDeleteQuadric(Mouth_obj);
	gluDeleteQuadric(Fire);
	gluDeleteQuadric(Glass_part);
	for (int i = 0; i < 8;i++)gluDeleteQuadric(Tail_wing_otherpart[i]);
	for (int i = 0; i < 6;i++)gluDeleteQuadric(Equipment[i]);
	for (int i = 0; i < 4; i++) {
		gluDeleteQuadric(Wing_other_part[i]);
		gluDeleteQuadric(Wing_part[i]);
		gluDeleteQuadric(Tail_wing_part[i]);
	}
	for (int i = 0; i < 2; i++) {
		gluDeleteQuadric(Engine_obj[i]);
		gluDeleteQuadric(Equipment_other[i]);
	}
	for (int i = 0; i < 40; i++)delete spee[i];
}
void Character::Init() {
	m_bMove = false;//이동가능 여부
	speed = 10;
	direction = 0;
	x_angle = 0.0f;
	z_angle = 0.0f;
	xPos = 0.0f;
	yPos = 0.0f;
	y_angle = 0.0f;
	hp = 100.0;
	gage = 0.0;
	Start_Z = 0.0;
	Dead = false;
	Boom_Radius = 20;
	memset(m_mtxlocal,0, sizeof(m_mtxlocal));
	m_mtxlocal[0] = m_mtxlocal[5] = m_mtxlocal[10] = m_mtxlocal[15] = 1;
	memset(m_mtxlocalt, 0, sizeof(m_mtxlocalt));
	m_mtxlocalt[0] = m_mtxlocalt[5] = m_mtxlocalt[10] = m_mtxlocalt[15] = 1;
	for (int i = 0; i < 40; i++)spee[i]->Init();
}
void Character::Render() {
	glPushMatrix();
	glTranslatef(xPos, 10.0+yPos,Start_Z);
	//glRotatef(180, 0, 1, 0);

	//glMultMatrixf(m_mtxlocalt);
	//glMultMatrixf(m_mtxlocal);
	if (Dead) {
		glColor3f(1, 1, 0);
		glPushMatrix(); {
			glTranslatef( 0, -5, 0);
			gluSphere(Fire,Boom_Radius, 20, 20);
		}glPopMatrix();
	}


	glRotatef(x_angle, 1, 0, 0);
	glRotatef(y_angle, 0, 1, 0);
	glRotatef(z_angle, 0, 0, 1);

	glPushMatrix(); {//전체 


		glScalef(0.5f, 0.5f, 1.0f);
		

		

		//몸통
	
		glColor3f(0.2117f, 0.2705f, 0.3098f);
		gluCylinder(body_obj, 20, 30, 50, 5, 8);
		gluDisk(Tail_obj, 0.0, 20, 5, 3);

		glPushMatrix(); {//앞부분
			glTranslatef(0.0, 0.0, 50.0);
			gluCylinder(Front_obj, 30, 15, 15, 5, 8);
			glPushMatrix(); {
				glColor3f(0.2627f, 0.8549f, 0.9254f);//67,218,236
				glTranslatef(0, 25, 0.0);

				gluSphere(Glass_part, 10, 20, 20);
			}glPopMatrix();
		}glPopMatrix();
		glColor3f(0.2117f, 0.2705f, 0.3098f);
		glPushMatrix(); {//앞부분
			glTranslatef(0.0, 0.0, 65.0);
			gluCylinder(Mouth_obj, 15, 0.0, 20, 5, 8);
		}glPopMatrix();
		glPushMatrix(); {
			//출력부분.
			glTranslatef(10, 0, -3);
			gluCylinder(Engine_obj[0], 10, 6, 3, 6, 6);
			for (int i = 0; i < 20; i++)spee[i]->Render();
		}glPopMatrix();
		glPushMatrix();
		glColor3f(0.2117f, 0.2705f, 0.3098f);
		glTranslatef(-10, 0, -3);
		gluCylinder(Engine_obj[1], 10, 6, 3, 6, 6);
		for (int i = 20; i < 40; i++)spee[i]->Render();
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.2117f, 0.2705f, 0.3098f);
		glPushMatrix();

		glTranslatef(50, 0, 25);
		//glRotatef(-36.0, 0.0, 0.0, 1.0);
		glScalef(1.0, 0.1, 1.0);
		glRotatef(10, 0.0, 1.0, 0.0);
		gluCylinder(Wing_part[0], 60, 60, 10, 4, 20);
		gluDisk(Wing_other_part[0], 0.0, 60, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 10);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Wing_other_part[1], 0.0, 60, 4, 3);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();

		glTranslatef(-50, 0, 25);
		glRotatef(-10, 0.0, 1.0, 0.0);
		glScalef(1.0, 0.1, 1.0);
		gluCylinder(Wing_part[1], 60, 60, 10, 4, 20);
		gluDisk(Wing_other_part[2], 0.0, 60, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 10);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Wing_other_part[3], 0.0, 60, 4, 3);
		glPopMatrix();
		glPopMatrix();

		//꼬리부분
		glPushMatrix();
		glTranslatef(30.0, 0.0, 0.0);
		glRotatef(10, 0.0, 1.0, 0.0);
		glScalef(1.0, 0.1, 1.0);
		gluCylinder(Tail_wing_part[0], 30, 30, 8, 4, 20);
		gluDisk(Tail_wing_otherpart[0], 0.0, 30, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 8);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Tail_wing_otherpart[1], 0.0, 30, 4, 3);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-30.0, 0.0, 0.0);
		glRotatef(-10, 0.0, 1.0, 0.0);
		glScalef(1.0, 0.1, 1.0);
		gluCylinder(Tail_wing_part[1], 30, 30, 8, 4, 20);
		gluDisk(Tail_wing_otherpart[2], 0.0, 30, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 8);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Tail_wing_otherpart[3], 0.0, 30, 4, 3);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(20.0, 8.0, 5.0);
		glRotatef(60, 0.0, 0.0, 1.0);
		glScalef(1.0, 0.1, 1.0);
		gluCylinder(Tail_wing_part[2], 30, 30, 6, 4, 20);
		gluDisk(Tail_wing_otherpart[4], 0.0, 30, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 6);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Tail_wing_otherpart[5], 0.0, 30, 4, 3);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-20.0, 8.0, 5.0);
		glRotatef(-60, 0.0, 0.0, 1.0);
		glScalef(1.0, 0.1, 1.0);

		gluCylinder(Tail_wing_part[2], 30, 30, 6, 4, 20);
		gluDisk(Tail_wing_otherpart[6], 0.0, 30, 4, 3);
		glPushMatrix();
		glScalef(1.0, 10.0, 1.0);
		glTranslatef(0, 0, 6);
		glScalef(1.0, 0.1, 1.0);
		gluDisk(Tail_wing_otherpart[7], 0.0, 30, 4, 3);
		glPopMatrix();
		glPopMatrix();


		//무기
		glPushMatrix();
		glTranslatef(35, -10, 25);
		gluCylinder(Equipment[0], 6, 6, 10, 20, 8);
		gluDisk(Equipment_other[0], 0, 6, 20, 3);
		glPushMatrix();



		glTranslatef(4, 0.2, 6);
		gluCylinder(Equipment[2], 2, 2, 10, 20, 8);

		glPopMatrix();

		glPushMatrix();
		glTranslatef(-2, 0.2, 6);
		gluCylinder(Equipment[3], 2, 2, 10, 20, 8);

		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-35, -10, 25);
		gluCylinder(Equipment[1], 6, 6, 10, 20, 8);
		gluDisk(Equipment_other[1], 0, 6, 20, 3);
		glPushMatrix();



		glTranslatef(-4, 0.2, 6);
		gluCylinder(Equipment[4], 2, 2, 10, 20, 8);

		glPopMatrix();

		glPushMatrix();
		glTranslatef(2, 0.2, 6);
		gluCylinder(Equipment[5], 2, 2, 10, 20, 8);

		glPopMatrix();


		glPopMatrix();



	}glPopMatrix();



	glPopMatrix();
}

void Character::M_Ffalling() {
	if (Start_Z > START_DAY) {
		yPos -= speed;
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(0, -10, 0);
		glMultMatrixf(m_mtxlocalt);
		glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
		glPopMatrix();
	}
}


void Character::  Move() {
	Start_Z += speed;
	if (Start_Z > START_DAY) {
		m_bMove = true;
	}
	glPushMatrix(); {
		glLoadIdentity();
		glTranslatef(0.0, 0.0, speed);
		glMultMatrixf(m_mtxlocalt);
		glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
	}glPopMatrix();
	if (Start_Z >= START_DAY-300 && Start_Z <= START_DAY) {
		glPushMatrix(); {

			yPos += 10;
			glLoadIdentity();
			glTranslatef(0.0, speed , 0.0);
			glMultMatrixf(m_mtxlocalt);
			glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
		}glPopMatrix();
		if (x_angle > -35) {
			glPushMatrix(); {
				x_angle -= 5.0f;
				glLoadIdentity();
				glRotatef(-ANGLE, 1, 0, 0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}
			glPopMatrix();
		}
	}
	for (int i = 0; i < 40; i++)spee[i]->Particle();
	
	switch (m_bMove) {
	case true:
		if (x_angle < 0) {
			x_angle += 2.5f;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(ANGLE-2.5, 1.0, 0.0, 0.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
		else if (x_angle > 0) {
			x_angle -= 2.5f;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(-ANGLE+2.5, 1.0, 0.0, 0.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
		if (z_angle < 0) {
			z_angle += 2.5f;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(ANGLE-2.5, 0.0, 0.0, 1.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();
		}
		else if (z_angle > 0) {
			z_angle -= 2.5f;
			glPushMatrix(); {
				glLoadIdentity();
				glRotatef(-ANGLE+2.5, 0.0, 0.0, 1.0);
				glMultMatrixf(m_mtxlocal);
				glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
			}glPopMatrix();

		}
		break;
	default:
		break;
	}
	switch (Dead) {
	case true:
		y_angle += 50.0f;
		yPos -= 10;
		if (Boom_Radius > 150) {
			Boom_Radius = 150;
		}
		else
		Boom_Radius += 10;
		break;
	default:
		break;
	}
	
	
}
void Character::Getspecial(const int key, const int x, const int y) {
	
}

void Character::GetKey(const unsigned char key, const int x, const int y) {
	if (m_bMove) {
		switch (key) {
		case 'W':
		case 'w':
			if (yPos < 400) {
				yPos += speed*2;
				glPushMatrix(); {
					glLoadIdentity();
					glTranslatef(0, speed+10, 0.0);
					glMultMatrixf(m_mtxlocalt);
					glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
				}glPopMatrix();
			}
			if (x_angle >-45) {
				x_angle -= 5.0f;
				glPushMatrix(); {
					glLoadIdentity();
					glRotatef(-ANGLE, 1.0, 0.0, 0.0);
					glMultMatrixf(m_mtxlocal);
					glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
				}glPopMatrix();
			}
			break;
		case 'd':
		case 'D':
			if (xPos > -200) {
				xPos += -200;
				glPushMatrix(); {
					glLoadIdentity();
					glTranslatef(-200, 0.0, 0.0);
					glMultMatrixf(m_mtxlocalt);
					glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
				}glPopMatrix();
			}
			if (z_angle< 20) {
				z_angle += 40.0f;
				glPushMatrix(); {
					glLoadIdentity();
					glRotatef(ANGLE, 0.0, 0.0, 1.0);
					glMultMatrixf(m_mtxlocal);
					glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
				}glPopMatrix();
			}
			break;
		case 'a':
		case 'A':
			if (xPos < 200) {
				xPos += 200;
				glPushMatrix(); {
					glLoadIdentity();
					glTranslatef(200, 0.0, 0.0);
					glMultMatrixf(m_mtxlocalt);
					glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocalt);
				}glPopMatrix();
			}
			if (z_angle > -20) {
				z_angle -= 40.0f;
				glPushMatrix(); {
					glLoadIdentity();
					glRotatef(-ANGLE, 0.0, 0.0, 1.0);
					glMultMatrixf(m_mtxlocal);
					glGetFloatv(GL_MODELVIEW_MATRIX, m_mtxlocal);
				}glPopMatrix();
			}
			break;
		}

	}
		

}


void Character::Death() {
	if (hp < 0.0) {
		Dead = true;
		m_bMove = false;
	}
	if (Start_Z > START_DAY) {
		if (yPos < 215) {
			Dead = true;
			m_bMove = false;
		}
	}
}
void Character::Update() {
	
	/*if (hp < 0.0) {
		hp = -1;
	}
	else {
		hp-=1.0;
	}
	Death();*/
}