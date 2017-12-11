#include"Opengl.h"
COpengl::COpengl(float x,float y,float z) {
	for (int i = 0; i < 30; i++) {
		Cube[i] = gluNewQuadric();
		gluQuadricDrawStyle(Cube[i], GLU_FILL);
		gluQuadricNormals(Cube[i], GLU_SMOOTH);
	}
	xPos = x;
	yPos = y;
	i = 0;
	zPos = z;
	color[0] = 184;
	color[0] /= 255;
	color[1] = 184;
	color[1] /= 255;
	color[2] = 178;
	color[2] /= 255;
	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	Texbits = loadDIBitmap("opengl.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, Texbits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
}
COpengl::~COpengl() {
	for (int i = 0; i < 30; i++) {
		gluDeleteQuadric(Cube[i]);
	}
}
void COpengl::Init() {
	
}
void COpengl::Render() {
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glRotatef(180, 0, 1, 0);
	glPushMatrix();
	glColor3f(color[0], color[1], color[2]);
	
	glTranslated(0, 160, -30);
	//glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glTranslatef(0, 50, 0);
	glutSolidSphere(5, 20, 8);
	glPopMatrix();
	glRotatef(90, 1, 0, 0);
	glColor3f(color[0], color[1], color[2]);
	glPushMatrix();
	glRotatef(45 + i, 0, 0, 1);
	glTranslated(0, 20, -50);
	glScaled(0.03, 1, 0.03);
	glutSolidCube(100);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90 + i, 0, 0, 1);
	glTranslated(0, 20, -50);
	glScaled(0.03, 1, 0.03);
	glutSolidCube(100);
	glPopMatrix();
	glPushMatrix();
	glRotatef(135 + i, 0, 0, 1);
	glTranslated(0, 20, -50);
	glScaled(0.03, 1, 0.03);
	glutSolidCube(100);
	glPopMatrix();
	glPushMatrix();
	glRotatef(180 + i, 0, 0, 1);
	glTranslated(0, 20, -50);
	glScaled(0.03, 1, 0.03);
	glutSolidCube(100);
	glPopMatrix();
	glPushMatrix();
	glRotatef(225 + i, 0, 0, 1);
	glTranslated(0, 20, -50);
	glScaled(0.03, 1, 0.03);
	glutSolidCube(100);
	glPopMatrix();
	glPushMatrix();
	glRotatef(270 + i, 0, 0, 1);
	glTranslated(0, 20, -50);
	glScaled(0.03, 1, 0.03);
	glutSolidCube(100);
	glPopMatrix();
	glPushMatrix();
	glRotatef(315 + i, 0, 0, 1);
	glTranslated(0, 20, -50);
	glScaled(0.03, 1, 0.03);
	glutSolidCube(100);
	glPopMatrix();
	glPushMatrix();
	glRotatef(360 + i, 0, 0, 1);
	glTranslated(0, 20, -50);
	glScaled(0.03, 1, 0.03);
	glutSolidCube(100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 20, -47.5);
	//	glRotatef(90, 1, 0, 0);
	glScalef(0.1, 1, 0.1);
	glutSolidCube(80);
	glPopMatrix();


	glPopMatrix();
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS); {
		glVertex3f(50, 0, 20);
		glVertex3f(50, 200, 20);
		glVertex3f(-50, 200, 20);
		glVertex3f(-50, 0, 20);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 0, 20);
		glVertex3f(50, 0, 110);
		glVertex3f(50, 200, 110);
		glVertex3f(50, 200, 20);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-50, 0, 20);
		glVertex3f(-50, 0, 110);
		glVertex3f(-50, 200, 110);
		glVertex3f(-50, 200, 20);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 0, 110);
		glVertex3f(50, 200, 110);
		glVertex3f(-50, 200, 110);
		glVertex3f(-50, 0, 110);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 0, 20);
		glVertex3f(50, 0, 110);
		glVertex3f(-50, 0, 110);
		glVertex3f(-50, 0, 20);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 200, 20);
		glVertex3f(50, 200, 110);
		glVertex3f(-50, 200, 110);
		glVertex3f(-50, 200, 20);
	}glEnd();

	//¸Ó¸®
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS); {
		glVertex3f(5, 210, 49);
		glVertex3f(-5, 210, 49);
		glVertex3f(-5, 215, 49);
		glVertex3f(5, 215, 49);
	}glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS); {
		glVertex3f(30, 200, 50);
		glVertex3f(-30, 200, 50);
		glVertex3f(-30, 240, 50);
		glVertex3f(30, 240, 50);
	}glEnd();
	
	glBegin(GL_QUADS); {
		glVertex3f(30, 200, 80);
		glVertex3f(-30, 200, 80);
		glVertex3f(-30, 240, 80);
		glVertex3f(30, 240, 80);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(30, 200, 80);
		glVertex3f(30, 200, 50);
		glVertex3f(30, 240, 50);
		glVertex3f(30, 240, 80);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-30, 200, 80);
		glVertex3f(-30, 200, 50);
		glVertex3f(-30, 240, 50);
		glVertex3f(-30, 240, 80);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(30, 240, 80);
		glVertex3f(30, 240, 50);
		glVertex3f(-30, 240, 50);
		glVertex3f(-30, 240, 80);
	}glEnd();
	//ÆÈ
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS); {
		glVertex3f(50, 180, 50);
		glVertex3f(80, 180, 50);
		glVertex3f(80, 100, 50);
		glVertex3f(50, 100, 50);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 180, 50);
		glVertex3f(80, 180, 50);
		glVertex3f(80, 180, 80);
		glVertex3f(50, 180, 80);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 180, 80);
		glVertex3f(80, 180, 80);
		glVertex3f(80, 100, 80);
		glVertex3f(50, 100, 80);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(80, 180, 80);
		glVertex3f(80, 180, 50);
		glVertex3f(80, 100, 50);
		glVertex3f(80, 100, 80);
	}glEnd();
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(50, 85, 65);
	glRotatef(90, 0, 1, 0);
	gluCylinder(Cube[18], 15, 15, 30, 20, 8);
	gluDisk(Cube[19], 0, 15, 20, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(80, 85, 65);
	glRotatef(90, 0, 1, 0);
	gluDisk(Cube[20], 0, 15, 20, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-80, 85, 65);
	glRotatef(90, 0, 1, 0);
	gluCylinder(Cube[21], 15, 15, 30, 20, 8);
	gluDisk(Cube[22], 0, 15, 20, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-50, 85, 65);
	glRotatef(90, 0, 1, 0);
	gluDisk(Cube[23], 0, 15, 20, 8);
	glPopMatrix();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS); {
		glVertex3f(-50, 180, 50);
		glVertex3f(-80, 180, 50);
		glVertex3f(-80, 100, 50);
		glVertex3f(-50, 100, 50);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-50, 180, 50);
		glVertex3f(-80, 180, 50);
		glVertex3f(-80, 180, 80);
		glVertex3f(-50, 180, 80);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-50, 180, 80);
		glVertex3f(-80, 180, 80);
		glVertex3f(-80, 100, 80);
		glVertex3f(-50, 100, 80);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-80, 180, 80);
		glVertex3f(-80, 180, 50);
		glVertex3f(-80, 100, 50);
		glVertex3f(-80, 100, 80);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 100, 55);
		glVertex3f(80, 100, 55);
		glVertex3f(80, 100, 10);
		glVertex3f(50, 100, 10);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 70, 55);
		glVertex3f(80, 70, 55);
		glVertex3f(80, 70, 10);
		glVertex3f(50, 70, 10);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 100, 10);
		glVertex3f(80, 100, 10);
		glVertex3f(80, 70, 10);
		glVertex3f(50, 70, 10);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(50, 100, 10);
		glVertex3f(50, 100,55);
		glVertex3f(50, 70, 55);
		glVertex3f(50, 70, 10);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(80, 100, 10);
		glVertex3f(80, 100, 55);
		glVertex3f(80, 70, 55);
		glVertex3f(80, 70, 10);
	}glEnd();

	//
	glBegin(GL_QUADS); {
		glVertex3f(-50, 100, 55);
		glVertex3f(-80, 100, 55);
		glVertex3f(-80, 100, 10);
		glVertex3f(-50, 100, 10);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-50, 70, 55);
		glVertex3f(-80, 70, 55);
		glVertex3f(-80, 70, 10);
		glVertex3f(-50, 70, 10);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-50, 100, 10);
		glVertex3f(-80, 100, 10);
		glVertex3f(-80, 70, 10);
		glVertex3f(-50, 70, 10);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-50, 100, 10);
		glVertex3f(-50, 100,55);
		glVertex3f(-50, 70, 55);
		glVertex3f(-50, 70, 10);
	}glEnd();
	glBegin(GL_QUADS); {
		glVertex3f(-80, 100, 10);
		glVertex3f(-80, 100, 55);
		glVertex3f(-80, 70, 55);
		glVertex3f(-80, 70, 10);
	}glEnd();
	if (zPos > 50000) {
		glPushMatrix(); {
			glColor3f(color[0], color[1], color[2]);
			glPushMatrix();
			glTranslatef(0, 0, 50);
			glRotatef(90, 1, 0, 0);
			gluCylinder(Cube[0], 15, 15, 60, 20, 8);
			gluDisk(Cube[1], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, -60, 50);
			glRotatef(90, 1, 0, 0);
			gluDisk(Cube[2], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, -45, 50);
			gluCylinder(Cube[3], 15, 15, 60, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, -45, 110);
			gluDisk(Cube[4], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, -45, -20);
			gluCylinder(Cube[5], 15, 15, 60, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0, -45, -20);
			gluDisk(Cube[6], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-70, -45, 50);
			glRotatef(90, 0, 1, 0);
			gluCylinder(Cube[7], 15, 15, 60, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-70, -45, 50);
			glRotatef(90, 0, 1, 0);
			gluDisk(Cube[8], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(10, -45, 50);
			glRotatef(90, 0, 1, 0);
			gluCylinder(Cube[7], 15, 15, 60, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(70, -45, 50);
			glRotatef(90, 0, 1, 0);
			gluDisk(Cube[8], 0, 15, 20, 8);
			glPopMatrix();
		}glPopMatrix();
	}
	else {


		glPushMatrix(); {
			glColor3f(color[0], color[1], color[2]);
			glTranslatef(10, -15, 65);
			glRotatef(90, 0, 1, 0);
			gluCylinder(Cube[0], 15, 15, 40, 20, 8);
			gluDisk(Cube[2], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50, -15, 65);
			glRotatef(90, 0, 1, 0);
			gluDisk(Cube[12], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(10, -40, 48);
			glRotatef(90, 0, 1, 0);
			gluCylinder(Cube[1], 15, 15, 40, 20, 8);
			gluDisk(Cube[3], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50, -40, 48);
			glRotatef(90, 0, 1, 0);
			gluDisk(Cube[13], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(10, -40, 81);
			glRotatef(90, 0, 1, 0);
			gluCylinder(Cube[4], 15, 15, 40, 20, 8);
			gluDisk(Cube[5], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(50, -40, 81);
			glRotatef(90, 0, 1, 0);
			gluDisk(Cube[14], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glColor3f(color[0], color[1], color[2]);
			glTranslatef(-50, -15, 65);
			glRotatef(90, 0, 1, 0);
			gluCylinder(Cube[6], 15, 15, 40, 20, 8);
			gluDisk(Cube[7], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-10, -15, 65);
			glRotatef(90, 0, 1, 0);
			gluDisk(Cube[15], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50, -40, 48);
			glRotatef(90, 0, 1, 0);
			gluCylinder(Cube[8], 15, 15, 40, 20, 8);
			gluDisk(Cube[9], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-10, -40, 48);
			glRotatef(90, 0, 1, 0);
			gluDisk(Cube[16], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-50, -40, 81);
			glRotatef(90, 0, 1, 0);
			gluCylinder(Cube[10], 15, 15, 40, 20, 8);
			gluDisk(Cube[11], 0, 15, 20, 8);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-10, -40, 81);
			glRotatef(90, 0, 1, 0);
			gluDisk(Cube[17], 0, 15, 20, 8);
		}
		glPopMatrix();
	}


	glPushMatrix(); {
		glTranslatef(-15, 230, 49);
		gluDisk(Cube[24], 2.5, 5, 20, 8);
	}glPopMatrix();
	glPushMatrix(); {
		glTranslatef(15, 230, 49);
		gluDisk(Cube[25], 2.5, 5, 20, 8);
	}glPopMatrix();
	glPushMatrix(); {
		glTranslatef(30, 230, 65);
		glRotatef(90, 1, 0, 0);
		glRotatef(45, 0, 0, 1);
		gluCylinder(Cube[26], 5, 5, 10, 4, 8);
	}glPopMatrix();
	glPushMatrix(); {
		glTranslatef(-30, 230, 65);
		glRotatef(90, 1, 0, 0);
		glRotatef(45, 0, 0, 1);
		gluCylinder(Cube[27], 5, 5, 10, 4, 8);
	}glPopMatrix();
	//glColor3f(1, 0, 1);
	glPushMatrix(); {
		glTranslatef(0, 150, 15);
		glRotatef(90, 1, 0, 0);
		glRotatef(45, 0, 0, 1);
		gluCylinder(Cube[29], 20, 20, 50, 4, 8);
	}glPopMatrix();
	if (zPos > 50000) {
		glPushMatrix();
		glColor3f(0, 0, 1);
		glTranslatef(0, 20, 50);
		glRotatef(90, 1, 0, 0);
		glutSolidTorus(50, 100, 20, 8);
		glPopMatrix();
	}
	glPopMatrix();
}
void COpengl::Rotation(){
	i += 60;
	if (zPos > -10) {
		zPos += SPEED;
	}
	else {
		zPos += (SPEED+5);
	}
}

GLubyte* COpengl:: loadDIBitmap(const char*filename, BITMAPINFO **info) {
	FILE *fp;
	GLubyte *bits;
	int bitsize, infosize;
	BITMAPFILEHEADER header;
	if ((fp = fopen(filename, "rb")) == NULL)return NULL;
	if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1) { fclose(fp); return NULL; }
	if (header.bfType != 'MB') { fclose(fp); return NULL; }
	infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
	if ((*info = (BITMAPINFO*)malloc(infosize)) == NULL) { fclose(fp); exit(0); return NULL; }
	if (fread(*info, 1, infosize, fp) < (unsigned int)infosize) { free(*info); fclose(fp); return NULL; }
	if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
		bitsize = ((*info)->bmiHeader.biWidth*((*info)->bmiHeader.biHeight)) * 3;
	if ((bits = (unsigned char *)malloc(bitsize)) == NULL) { free(*info); fclose(fp); return NULL; }
	if (fread(bits, 1, bitsize, fp) < (unsigned int)bitsize) { free(*info); free(bits); fclose(fp); return NULL; }
	fclose(fp);
	return bits;
}