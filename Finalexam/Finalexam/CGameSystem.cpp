#include"CGameSystem.h"
CGameSystem::CGameSystem() {
	m_pIntro = new CIntro();
	m_bIntro = true;
	m_pCIngame = new CIngame();

}
CGameSystem::~CGameSystem() {
	if (m_pIntro)
		delete m_pIntro;
	if (m_pCIngame)
		delete m_pCIngame;
}

void CGameSystem::SpecialKey(const int key , const int x, const int y ) {
	switch (key) {
		if (m_pCIngame){}
		else {
			switch (key) {
			case GLUT_KEY_DELETE:
				exit(0);
				break;
			default:
				if (m_bIntro) {
					m_bIntro = false;
					delete m_pIntro;
					m_pIntro = nullptr;
				}
				break;
			}
		}
	}
}
void CGameSystem::GetKey(const unsigned char key, const int x, const int y) {
	switch (key) {
	case 27:
		exit(0);
		break;


	}
}
void CGameSystem::MouseButton(const int button, const int state, const int x, const int y) {
	if (m_bIntro) {
		if (button == GLUT_LEFT_BUTTON&&state == GLUT_UP && (-100 <= x&&x <= 100) && (100 <= y&&y <= 150)) {
			if (!m_pCIngame) {
				m_bIntro = false;
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