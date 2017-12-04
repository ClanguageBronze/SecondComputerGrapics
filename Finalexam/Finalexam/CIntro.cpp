#include"CIntro.h"
CIntro::CIntro() {
	glGenTextures(3, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	Texbits = LoadDIBitmap("Title.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, Texbits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	Texbits = LoadDIBitmap("START.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, Texbits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	Texbits = LoadDIBitmap("Quit.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, Texbits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
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
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS); {
		glTexCoord2f(0, 0);
		glVertex2i(-400,-300);
		glTexCoord2f(1, 0);
		glVertex2i(-400, 300);
		glTexCoord2f(1, 1);
		glVertex2i(400, 300);
		glTexCoord2f(0, 1);
		glVertex2i(400, -300);
	}glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS); {
		glTexCoord2f(0, 0);
		glVertex2i(-100, 100);
		glTexCoord2f(1, 0);
		glVertex2i(-100, 150);
		glTexCoord2f(1, 1);
		glVertex2i(100, 150);
		glTexCoord2f(0, 1);
		glVertex2i(100, 100);
	}glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS); {
		glTexCoord2f(0, 0);
		glVertex2i(-100, 200);
		glTexCoord2f(1, 0);
		glVertex2i(-100, 250);
		glTexCoord2f(1, 1);
		glVertex2i(100, 250);
		glTexCoord2f(0, 1);
		glVertex2i(100, 200);
	}glEnd();
}
