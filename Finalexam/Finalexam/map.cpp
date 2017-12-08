#include"map.h"
CMap::CMap() {
	glGenTextures(2, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	TexBits = LoadDIBitmap("opengl.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	TexBits = LoadDIBitmap("¸Ô±¸¸§.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);


}
CMap::~CMap(){}

void CMap::Init() {
	Start_point = 0.0;
	End_point = RESULT;

}

void CMap::Render() {
	Start_Render();
	Go_animation();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS); {
		glTexCoord2f(1, 0);
		glVertex3f(-500, 440, -500);
		glTexCoord2f(0, 0);
		glVertex3f(500, 440, -500);
		glTexCoord2f(0, 1);
		glVertex3f(500, 440, 1000);
		glTexCoord2f(1, 1);
		glVertex3f(-500, 440, 1000);
	}glEnd();
	for (int i = 1; i < 10000; i++) {
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glBegin(GL_QUADS); {
			glTexCoord2f(1, 0);
			glVertex3f(-500, 440, 1000*i);
			glTexCoord2f(0, 0);
			glVertex3f(500, 440, 1000*i);
			glTexCoord2f(0, 1);
			glVertex3f(500, 440, 1000*(i+1));
			glTexCoord2f(1, 1);
			glVertex3f(-500, 440, 1000*(i+1));
		}glEnd();
	}

}
void CMap::Start_Render() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS); {
		glTexCoord2f(1,0);
		glVertex3f(-450,0, -500);
		glTexCoord2f(0, 0);
		glVertex3f(450,0, -500);
		glTexCoord2f(0, 1);
		glVertex3f(450, 0, 500);
		glTexCoord2f(1, 1);
		glVertex3f(-450,0, 500);
	}glEnd();
	
}
void CMap::Go_animation() {
//	glColor3f(1, 0, 0);
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

GLubyte*CMap:: LoadDIBitmap(const char *filename, BITMAPINFO **info) {
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
