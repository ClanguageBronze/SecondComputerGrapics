#include"CGameSystem.h"
CGameSystem::CGameSystem() {
	m_pIntro = new CIntro();
	m_bIntro = true;

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
void CGameSystem::MouseButton(const int, const int, const int, const int) {

}
void CGameSystem::MouseMotion(const int, const int) {

}
void CGameSystem::Update() {

}
void CGameSystem::ChangeSize(int w, int h) {
	if (m_bIntro) { m_pIntro->Reshape(w, h); }

}
void CGameSystem::Render() {

}