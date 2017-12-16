#include"map2.h"
CMap2::CMap2() {
	for (int i = 0; i < 100; i++)m_pCloud[i] = new Cloud;
	glGenTextures(8, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	TexBits = LoadDIBitmap("바다3.bmp", &info);
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
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	TexBits = LoadDIBitmap("바닷속.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	TexBits = LoadDIBitmap("바닷속2.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	TexBits = LoadDIBitmap("바닷속3.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	TexBits = LoadDIBitmap("바다안3.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);

}
CMap2::~CMap2() {
	for (int i = 0; i < 100; i++)
		delete m_pCloud[i];
}


void CMap2::Render() {
	glEnable(GL_TEXTURE_2D);
	
	for (int i = 20; i < 40; i++) {
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

	for (int i = 20; i < 40; i++) {
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glBegin(GL_QUADS); {
			glTexCoord2f(0, 1);
			glVertex3f(-150, 460, 1000 * i);
			glTexCoord2f(0, 0);
			glVertex3f(-150, 390, 1000 * i);
			glTexCoord2f(1, 0);
			glVertex3f(-150, 390, 1000 * (i + 1));
			glTexCoord2f(1, 1);
			glVertex3f(-150, 460, 1000 * (i + 1));
		}glEnd();
	}
	for (int i = 20; i < 40; i++) {
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glBegin(GL_QUADS); {
			glTexCoord2f(0, 1);
			glVertex3f(150, 460, 1000 * i);
			glTexCoord2f(0, 0);
			glVertex3f(150, 390, 1000 * i);
			glTexCoord2f(1, 0);
			glVertex3f(150, 390, 1000 * (i + 1));
			glTexCoord2f(1, 1);
			glVertex3f(150, 460, 1000 * (i + 1));
		}glEnd();
	}
	
	Start_Render();
}
void CMap2::Start_Render() {
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.4f);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS); {
		glTexCoord2f(1, 0);
		glVertex3f(-200, 460, 20000);
		glTexCoord2f(0, 0);
		glVertex3f(200, 460, 20000);
		glTexCoord2f(0, 1);
		glVertex3f(200, 0, 20000);
		glTexCoord2f(1, 1);
		glVertex3f(-200, 0, 20000);
	}glEnd();
	glColor4f(1, 1, 1, 0.4f);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS); {
		glTexCoord2f(1, 0);
		glVertex3f(-200, 460, 40000);
		glTexCoord2f(0, 0);
		glVertex3f(200, 460, 40000);
		glTexCoord2f(0, 1);
		glVertex3f(200, 0, 40000);
		glTexCoord2f(1, 1);
		glVertex3f(-200, 0, 40000);
	}glEnd();

	glColor4f(0.192156, 0.3725490, 0.59215686, 0.5);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	for (int i = 20; i < 40; i++) {
	
			glBindTexture(GL_TEXTURE_2D, texture[0]);

			glBegin(GL_QUADS); {
				glTexCoord2f(0, 1);
				glVertex3f(-150, 400, 1000 * i);
				glTexCoord2f(0, 0);
				glVertex3f(150, 400, 1000 * i);
				glTexCoord2f(1, 0);
				glVertex3f(150, 400, 1000 * (i + 1));
				glTexCoord2f(1, 1);
				glVertex3f(-150, 400, 1000 * (i + 1));
			}glEnd();
		
	}
	
	glColor4f(0.192156, 0.3725490, 0.59215686, 0.8);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	for (int i = 20; i < 40; i++) {


		glBegin(GL_QUADS); {
			glTexCoord2f(0, 1);
			glVertex3f(150, 400, 1000 * i);
			glTexCoord2f(0, 0);
			glVertex3f(150, 0, 1000 * i);
			glTexCoord2f(1, 0);
			glVertex3f(150, 0, 1000 * (i + 1));
			glTexCoord2f(1, 1);
			glVertex3f(150, 400, 1000 * (i + 1));
		}glEnd();
	}
	glColor4f(0.192156, 0.3725490, 0.59215686, 0.8);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	for (int i = 20; i <40; i++) {

	
		glBegin(GL_QUADS); {
			glTexCoord2f(0, 1);
			glVertex3f(-150, 400, 1000 * i);
			glTexCoord2f(0, 0);
			glVertex3f(-150, 0, 1000 * i);
			glTexCoord2f(1, 0);
			glVertex3f(-150, 0, 1000 * (i + 1));
			glTexCoord2f(1, 1);
			glVertex3f(-150, 400, 1000 * (i + 1));
		}glEnd();
	}
	glColor4f(0.192156, 0.3725490, 0.59215686, 0.9);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	for (int i = 20000; i <= 40000; i+=10) {
		glBegin(GL_QUADS); {
			glTexCoord2f(0, 1);
			glVertex3f(-150, 400, i);
			glTexCoord2f(0, 0);
			glVertex3f(-150, 0,  i);
			glTexCoord2f(1, 0);
			glVertex3f(150, 0, i);
			glTexCoord2f(1, 1);
			glVertex3f(150, 400,  i);
		}glEnd();
	}
	glColor4f(0.192156, 0.3725490, 0.59215686, 0.8);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	for (int i = 20; i < 40; i++) {
		glBindTexture(GL_TEXTURE_2D, texture[4]);

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

	glDisable(GL_TEXTURE_2D);

	glColor4f(1, 1, 1, 0.3);
	for (int i = 0; i < 100; i++)
		m_pCloud[i]->Render();
	
	glDisable(GL_BLEND);
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
