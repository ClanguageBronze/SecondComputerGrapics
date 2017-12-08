#include"CGameSystem.h"
CGameSystem::CGameSystem() {
	m_pSoundManager = new CSoundManager();
	m_pSoundManager->PlayBGM(INTRO); glGenTextures(3, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	Texbits = loadDIBitmap("Title.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, Texbits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	Texbits = loadDIBitmap("START.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, Texbits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	Texbits = loadDIBitmap("Quit.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, Texbits);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
}
CGameSystem::~CGameSystem() {
	
}

void CGameSystem::SpecialKey(const int key , const int x, const int y ) {
	
	
			switch (key) {
			case GLUT_KEY_DELETE:
				exit(0);
				break;
			default:
			
				break;
			}
		
	
}
void CGameSystem::GetKey(const unsigned char key, const int x, const int y) {
	if (key == 'q' || key == 'Q')
	{
		exit(1);
	}
	
		
	
}
void CGameSystem::MouseButton(const int button, const int state, int x, int y) {
	mouse_x = x - 400;
	mouse_y = y - 300;
	if (button == GLUT_LEFT_BUTTON&&state == GLUT_UP) {
		if (-100 <= mouse_x&&mouse_x <= 100 && 200 <= mouse_y&&mouse_y <= 250) { 
			exit(1);
		}
	}

	
}
void CGameSystem::MouseMotion( int x, int y) {
	
}
void CGameSystem::Update(int value) {

}
void CGameSystem::ChangeSize(int w, int h) {

	glViewport(0, 0, w, h);
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -100, 100);
	
}
void CGameSystem::Render() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS); {
		glTexCoord2f(0, 0);
		glVertex3f(-400, -300, 0);
		glTexCoord2f(0, 1);
		glVertex3f(-400, 300, 0);
		glTexCoord2f(1, 1);
		glVertex3f(400, 300, 0);
		glTexCoord2f(1, 0);
		glVertex3f(400, -300, 0);
	}glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS); {
		glTexCoord2f(0, 1);
		glVertex3f(-100, -100, 0);
		glTexCoord2f(0, 0);
		glVertex3f(-100, -150, 0);
		glTexCoord2f(1, 0);
		glVertex3f(100, -150, 0);
		glTexCoord2f(1, 1);
		glVertex3f(100, -100, 0);
	}glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glBegin(GL_QUADS); {
		glTexCoord2f(0, 1);
		glVertex2i(-100, -200);
		glTexCoord2f(0, 0);
		glVertex2i(-100, -250);
		glTexCoord2f(1, 0);
		glVertex2i(100, -250);
		glTexCoord2f(1, 1);
		glVertex2i(100, -200);
	}glEnd();
	glutSwapBuffers();
}
GLubyte* CGameSystem::loadDIBitmap(const char*filename, BITMAPINFO **info) {
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
