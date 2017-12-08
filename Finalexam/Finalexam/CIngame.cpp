#include"CIngame.h"

CIngame::CIngame() {
	Main = new Character;
	light = new LIGHT(0, 500, 0,1);
	map = new CMap;
	SoundManager = new CSoundManager;
	Eyex = 0.0;
	Eyey = 0.0;
	Eyez = -10.0;
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
	Main->Init();
	light->Init();
	map->Init();
}

void CIngame::Mousebutton(const int button, const int state, const int x, const int y) {}
void CIngame::Getkey(const unsigned char key, const int x, const int y) {
	Main->GetKey(key, x, y);
}
void CIngame::MouseMotion(int x,int y){}

void CIngame::Render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
//	glLoadIdentity();
	glTranslatef(0.0, 0.0, -300.0);
	gluLookAt(Eyex, Eyey, Eyez, Centerx, Centery, Centerz, Upx, Upy, Upz);
//	glTranslatef(0.0, -50.0, 0.0);
	Main->Render();
	map->Render();
	light->M_FLIGHTING();
}
void CIngame::Reshape(int w, int h) {
	GLfloat nRange = 250.0f;
	// h가 0일 때
	if (h == 0)
		h = 1;
	// 윈도우의 폭과 넓이 설정
	glViewport(0, 0, w, h);
	// 투영 행렬 스택 재설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// 클리핑 공간 설정
	//   if (w <= h)
	//      glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	//   else
	//      glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);
	float fAspect;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	fAspect = (float)w / (float)h;
	gluPerspective(45.0, fAspect, 1.0, 500.0);
	// 모델 뷰 행렬 스택 재설정
	glMatrixMode(GL_MODELVIEW);
	// 관측 변홖: 카메라의 위치 설정 (필요핚 경우)
	//gluLookAt (Eyex, Eyey, Eyez,/**/ Centerx, Centery,Centerz, /**/ Upx, Upy, Upz);
	glLoadIdentity();
}
void CIngame::Update(int value) {
	switch (value) {
	case 1:
		Main->Move();
		Filming();
		break;
	case 2:
		Main->M_Ffalling();
		break;
	}
}
void CIngame::Filming() {
	Eyez += SPEED;
	Centerz += SPEED;
	if (Eyez > START_DAY - 310 && Eyez < START_DAY - 10) {
		Eyey += SPEED;
		Centery += SPEED;
	}

}