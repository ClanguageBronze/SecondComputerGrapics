#include"GameOver.h"

CGameOver::CGameOver(bool Dead,bool Finish) {
	if(Dead==true)
	Select = 1;
	else if (Finish==true)Select = 2;
	
	Eyex = 0.0;
	Eyey = 0.0;
	Eyez = -10.0;
	Centerx = 0.0;
	Centery = 0.0;
	Centerz = 1.0;
	Upx = 0.0;
	Upy = 1.0;
	Upz = 0.0;
	glGenTextures(2, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	texbits = loadDIBitmap("과제.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, texbits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	texbits = loadDIBitmap("종강.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, texbits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
}
CGameOver::~CGameOver(){

}

void CGameOver:: Render() {
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -300.0);
	gluLookAt(Eyex, Eyey, Eyez, Centerx, Centery, Centerz, Upx, Upy, Upz);
	glTranslatef(0.0, -50.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	if (Select == 1) {
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glBegin(GL_QUADS); {
			glTexCoord2f(0, 0);
			glVertex3f(175, -90, 0.0);
			glTexCoord2f(0, 1);
			glVertex3f(175, 180, 0.0);
			glTexCoord2f(1, 1);
			glVertex3f(-175, 180, 0.0);
			glTexCoord2f(1, 0);
			glVertex3f(-175, -90, 0.0);
		}; glEnd();
	}
	else {
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glBegin(GL_QUADS); {
			glTexCoord2f(0, 0);
			glVertex3f(175, -90, 0.0);
			glTexCoord2f(0, 1);
			glVertex3f(175, 180, 0.0);
			glTexCoord2f(1, 1);
			glVertex3f(-175, 180, 0.0);
			glTexCoord2f(1, 0);
			glVertex3f(-175, -90, 0.0);
		}; glEnd();
	}
	glDisable(GL_TEXTURE_2D);
}

GLubyte* CGameOver::loadDIBitmap(const char*filename, BITMAPINFO **info) {
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
