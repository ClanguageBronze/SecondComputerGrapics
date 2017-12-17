#include"CGameSystem.h"
CGameSystem::CGameSystem() {
//	m_pCIngame = new CIngame;
//	m_pCIngame->Init();
	m_pSoundManager = new CSoundManager;
	m_pSoundManager->SetSounds();
	m_pSoundManager->PlayBGM(BGM_INTRO);
	m_pCIntro = new CIntro;
	speed = 0;
	Dead = false;
	Count = 0;
	Finish = false;
}
CGameSystem::~CGameSystem() {
	if (m_pCIngame)delete m_pCIngame;
	if (m_pCIntro)delete m_pCIntro;
	if (m_pSoundManager)delete m_pSoundManager;
	if (m_pCGameOver)delete m_pCGameOver;
}

void CGameSystem::SpecialKey(const int key , const int x, const int y ) {
	if (m_pCIngame) {
		if (key == GLUT_KEY_END) {
			delete m_pCIngame;
			m_pCIngame = nullptr;
			m_pCIntro = new CIntro;
			Count = 0;
			m_pSoundManager->PlayBGM(BGM_INTRO);
		}
	}
	else {
		switch (key) {
		case GLUT_KEY_DELETE:
			exit(1);
			break;
		default:

			break;
		}

	}
}
void CGameSystem::GetKey(const unsigned char key, const int x, const int y) {
	if (m_pCIngame) {
		m_pCIngame->Getkey(key, x, y);
	}
	else if(m_pCIntro) {
		if (key == 'q' || key == 'Q')
		{
			delete m_pCIntro;
			m_pCIntro = nullptr;
			exit(1);
		}
		if (key == 's' || key == 'S') {

				delete m_pCIntro;
				m_pCIntro = nullptr;
				m_pCIngame = new CIngame;
				m_pCIngame->Init();
				m_pSoundManager->Stop();
		}
	}
	else {
		if (Dead) {
			if (key == 'e' || key == 'E') {
				delete m_pCGameOver;
				m_pCGameOver = nullptr;
				Dead = false;
				m_pCIntro = new CIntro;
				Count = 0;
				m_pSoundManager->Stop(BGM_CLEAR1);
				m_pSoundManager->PlayBGM(BGM_INTRO);
			}
			if (key == 'a' || key == 'A') {
				delete m_pCGameOver;

				m_pCGameOver = nullptr;
				Count = 0;
				m_pCIngame = new CIngame;
				m_pCIngame->Init();
				m_pSoundManager->Stop(BGM_CLEAR1);
			}
		}
		else if (Finish) {
			if (key == 'q' || key == 'Q') {
				delete m_pCGameOver;
				m_pCGameOver = nullptr;
				exit(1);
			}
			if (key == 's' || key == 'S') {
				delete m_pCGameOver;
				m_pCGameOver = nullptr;
				Finish = false;
				m_pCIntro = new CIntro;
				Count = 0;
				m_pSoundManager->Stop(BGM_CLEAR2);
				m_pSoundManager->PlayBGM(BGM_INTRO);
			}
		}
	}
	
}
void CGameSystem::MouseButton(const int button, const int state, int x, int y) {
	mouse_x = x - 400;
	mouse_y = y - 300;
	if (m_pCIntro) {
		if (button == GLUT_LEFT_BUTTON&&state == GLUT_UP) {
			if (-100 <= mouse_x&&mouse_x <= 100 && 200 <= mouse_y&&mouse_y <= 250) {
				m_pSoundManager->Stop();
				delete m_pCIntro;
				m_pCIntro = nullptr;
				exit(1);
			}
			if (-100 <= mouse_x&&mouse_x <= 100 && 100 <= mouse_y&&mouse_y <= 150) {
				if (!m_pCIngame) {
					m_pSoundManager->Stop(BGM_INTRO);
					delete m_pCIntro;
					m_pCIntro = nullptr;
					m_pCIngame = new CIngame;
					m_pCIngame->Init();
				}
			}
			m_pSoundManager->PlayEffect(EFFECT_CLICK_BUTTON_00);
		}
	}
	if (m_pCIngame) {
		m_pCIngame->Mousebutton(button, state, x, y);
	}

}
void CGameSystem::MouseMotion( int x, int y) {
	if (m_pCIngame)m_pCIngame->MouseMotion(x,y);
}
void CGameSystem::Update() {
	if (m_pCIngame) {
		m_pCIngame->Update();
		Dead = m_pCIngame->M_FDead();
		Finish = m_pCIngame->M_FFinish();
		speed = m_pCIngame->speed;
	}
	if (Dead == true || Finish == true) {
		delete m_pCIngame;
		m_pCIngame = nullptr;
		m_pCGameOver = new CGameOver(Dead, Finish);
		if (Dead) {
			Count++;
			if (Count == 1)
				m_pSoundManager->PlayBGM(BGM_CLEAR1);
		}
		if (Finish) {
			Count++;
			if (Count == 1)
				m_pSoundManager->PlayBGM(BGM_CLEAR2);
		}
	}
}
void CGameSystem::ChangeSize(int w, int h) {
	GLfloat nRange = 250.0f;
	// h�� 0�� ��
	if (h == 0)
		h = 1;
	// �������� ���� ���� ����
	glViewport(0, 0, w, h);
	// ���� ��� ���� �缳��
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Ŭ���� ���� ����
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);
	float fAspect;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	fAspect = (float)w / (float)h;
	gluPerspective(45.0, fAspect, 1.0, 10000000.0);
	// �� �� ��� ���� �缳��
	glMatrixMode(GL_MODELVIEW);
	// ���� ���Q: ī�޶��� ��ġ ���� (�ʿ��� ���)
	//gluLookAt (Eyex, Eyey, Eyez,/**/ Centerx, Centery,Centerz, /**/ Upx, Upy, Upz);
	glLoadIdentity();
}
void CGameSystem::Render() {
	if (m_pCIngame)m_pCIngame->Render();
	else if (m_pCIntro)
		m_pCIntro->Render();
	else if (m_pCGameOver)
		m_pCGameOver->Render();
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
