#include"CIngame.h"

CIngame::CIngame() {
	Main = new Character;
	light = new LIGHT(0, 420, 0, 1);
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
	line = 0;
	speed = 0;
	Main->Init();
	light->Init();
	map->Init();
}

void CIngame::Mousebutton( int button,  int state, int x, int y) {}
void CIngame::Getkey(unsigned char key,int x,int y) {
	Main->GetKey(key, x, y);
}
void CIngame::MouseMotion(int x,int y){}

void CIngame::Render() {
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -300.0);
	gluLookAt(Eyex, Eyey, Eyez, Centerx, Centery, Centerz, Upx, Upy, Upz);
	glTranslatef(0.0, -50.0, 0.0);
	map->Render();
	Main->Render();
	light->M_FLIGHTING();
}

void CIngame::Update() {
	light->Update();
		Main->Move();
		Filming();
		Main->M_Ffalling();
}
void CIngame::Filming() {
	Eyez += SPEED+speed;
	Centerz += SPEED+speed;
//	line += SPEED;
	if (Eyez > START_DAY - 310 && Eyez < START_DAY - 10) {
		Eyey += SPEED;
		Centery += SPEED;
	}
//	if (line % 1000 == 0) {
//		speed += 2;
//	}
//
}
bool CIngame::M_FDead() {
	return Main->M_FDead();
}