#include"CIngame.h"

CIngame::CIngame() {
	Main = new Character;
	light = new LIGHT(0, 430, 50000,1);
	map = new CMap;
	SoundManager = new CSoundManager;
	Eyex = 0.0;
	Eyey = 0.0;
	Eyez = 10.0;
	Centerx = 0.0;
	Centery = 0.0;
	Centerz = 1.0;
	Upx = 0.0;
	Upy = 1.0;
	Upz = 0.0;
}
CIngame::~CIngame(){
	delete Main;
	delete map;
	delete light;
	delete SoundManager;
}
void CIngame::Init() {

}

void CIngame::Mousebutton(const int button, const int state, const int x, const int y) {

}
void CIngame::Getkey(const unsigned char key, const int x, const int y) {
	Main->GetKey(key, x, y);
}


void CIngame::Render() {
	srand((unsigned)time(NULL));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(Eyex,Eyey,Eyez,Centerx,Centery,Centerz,Upx,Upy,Upz);
	light->M_FLIGHTING();
	glLoadIdentity();
	Main->Render();
	map->Render();
	glutSwapBuffers();
}
void CIngame::Reshape(int w, int h) {
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
	//   if (w <= h)
	//      glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	//   else
	//      glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);
	float fAspect;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	fAspect = (float)w / (float)h;
	gluPerspective(45.0, fAspect, 1.0, 500.0);
	// �� �� ��� ���� �缳��
	glMatrixMode(GL_MODELVIEW);
	// ���� ���Q: ī�޶��� ��ġ ���� (�ʿ��� ���)
	//gluLookAt (Eyex, Eyey, Eyez,/**/ Centerx, Centery,Centerz, /**/ Upx, Upy, Upz);
	glLoadIdentity();
}
void CIngame::Update(int value) {
	switch (value) {
	case 1:
		
		Main->Move();
		
		break;
	case 2:
		Main->M_Ffalling();
		break;
	}
}