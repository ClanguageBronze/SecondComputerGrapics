#include"CGameSystem.h"
CGameSystem::CGameSystem() {
	m_pIntro = new CIntro();
	m_pCIngame = new CIngame();
	m_pSoundManager = new CSoundManager();
	m_pSoundManager->PlayBGM(INTRO);
}
CGameSystem::~CGameSystem() {
	if (m_pIntro)
		delete m_pIntro;
	if (m_pCIngame)
		delete m_pCIngame;
}

void CGameSystem::SpecialKey(const int key , const int x, const int y ) {
	
		if (m_pCIngame)m_pCIngame->Getkey(key, x, y);
		else {
			switch (key) {
			case GLUT_KEY_DELETE:
				exit(0);
				break;
			default:
				if (m_pIntro) {
					delete m_pIntro;
					m_pIntro = nullptr;
				}
				break;
			}
		
	}
}
void CGameSystem::GetKey(const unsigned char key, const int x, const int y) {
	
		if (m_pCIngame) {
			m_pCIngame->Getkey(key, x, y);
		}
		else {
			switch (key) {
			default:
				if (m_bGameOver) {
					m_bGameOver = false;
					m_pSoundManager->PlayBGM(INTRO);
					m_pIntro = new CIntro();
					delete m_pCIngame;
					m_pCIngame = nullptr;
				}
				else if (m_pIntro) {
					m_pSoundManager->PlayBGM(INGAME);
					delete m_pIntro;
					m_pIntro = nullptr;
				}
				break;
		}
	}
}
void CGameSystem::MouseButton(const int button, const int state, const int x, const int y) {

	if (m_bGameOver) {
		m_bGameOver = false;
		m_pSoundManager->PlayBGM(INTRO);
		m_pIntro = new CIntro();
		delete m_pCIngame;
		m_pCIngame = nullptr;
	}
	else if (m_pCIngame) {
		m_pCIngame->Mousebutton(button, state, x, y);
		
	}
	else if (m_pIntro) {
		if (button == GLUT_LEFT_BUTTON&&state == GLUT_UP && (-100 <= x&&x <= 100) && (100 <= y&&y <= 150)) {
			if (!m_pCIngame) {
				delete m_pIntro;
				m_pIntro = nullptr;
				m_pCIngame = new CIngame();
				m_pCIngame->Init();
			}
		}
		else if (button == GLUT_LEFT_BUTTON&&state == GLUT_UP && (-100 <= x&&x <= 100) && (200 <= y&&y <= 250)) {
			exit(0);
		}
	}
}
void CGameSystem::MouseMotion(const int x, const int y) {
	
}
void CGameSystem::Update() {

}
void CGameSystem::ChangeSize(int w, int h) {
	if (m_bIntro) { m_pIntro->Reshape(w, h); }
	else if (m_pCIngame) {
		m_pCIngame->Reshape(w, h);
	}
}
void CGameSystem::Render() {
	if (m_bIntro) {
		m_pIntro->Render();
	}
	else if (m_pCIngame)m_pCIngame->Render();
}