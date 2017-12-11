#include"map2.h"
CMap2::CMap2() {
	glGenTextures(5, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	TexBits = LoadDIBitmap("바다2.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	TexBits = LoadDIBitmap("구름.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	TexBits = LoadDIBitmap("Warp.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);

	glBindTexture(GL_TEXTURE_2D, texture[3]);
	TexBits = LoadDIBitmap("바다.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
}
CMap2::~CMap2() {}


void CMap2::Render() {
	Start_Render();
	for (int i = 50; i < 100; i++) {
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glBegin(GL_QUADS); {
			glTexCoord2f(1, 0);
			glVertex3f(-150, 460, 1000 * i);
			glTexCoord2f(0, 0);
			glVertex3f(150, 460, 1000 * i);
			glTexCoord2f(0, 1);
			glVertex3f(150, 460, 1000 * (i + 1));
			glTexCoord2f(1, 1);
			glVertex3f(-150, 460, 1000 * (i + 1));
		}glEnd();
	}

	for (int i = 50; i < 100; i++) {
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glBegin(GL_QUADS); {
			glTexCoord2f(0, 1);
			glVertex3f(-150, 460, 1000 * i);
			glTexCoord2f(0, 0);
			glVertex3f(-150, 0, 1000 * i);
			glTexCoord2f(1, 0);
			glVertex3f(-150, 0, 1000 * (i + 1));
			glTexCoord2f(1, 1);
			glVertex3f(-150, 460, 1000 * (i + 1));
		}glEnd();
	}
	for (int i = 50; i < 100; i++) {
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glBegin(GL_QUADS); {
			glTexCoord2f(0, 1);
			glVertex3f(150, 460, 1000 * i);
			glTexCoord2f(0, 0);
			glVertex3f(150, 0, 1000 * i);
			glTexCoord2f(1, 0);
			glVertex3f(150, 0, 1000 * (i + 1));
			glTexCoord2f(1, 1);
			glVertex3f(150, 460, 1000 * (i + 1));
		}glEnd();
	}
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS); {
		glTexCoord2f(1, 0);
		glVertex3f(-200, 460, 100000);
		glTexCoord2f(0, 0);
		glVertex3f(200, 460, 100000);
		glTexCoord2f(0, 1);
		glVertex3f(200, 215, 100000);
		glTexCoord2f(1, 1);
		glVertex3f(-200, 215, 100000);
	}glEnd();
	glDisable(GL_TEXTURE_2D);
}
void CMap2::Start_Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	for (int i = 50; i < 100; i++) {
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glBegin(GL_QUADS); {
			glTexCoord2f(0, 1);
			glVertex3f(-150, 0, 1000 * i);
			glTexCoord2f(0, 0);
			glVertex3f(150, 0, 1000 * i);
			glTexCoord2f(1, 0);
			glVertex3f(150, 0, 1000 * (i + 1));
			glTexCoord2f(1, 1);
			glVertex3f(-150, 0, 1000 * (i + 1));
		}glEnd();
	}
}


GLubyte*CMap2::LoadDIBitmap(const char *filename, BITMAPINFO **info) {
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
