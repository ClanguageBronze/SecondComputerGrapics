#include"CIngame.h"

CIngame::CIngame() {
	Main = new Character;
	light = new LIGHT(0, 420, 0, 1);
	map = new CMap;
	map2 = new CMap2;
	m_pSoundManager = new CSoundManager;

	Monster = new COpengl(0, 55, -300);
	Eyex = 0.0;
	Eyey = 0.0;
	Eyez = -10.0;
	Centerx = 0.0;
	Centery = 0.0;
	Centerz = 1.0;
	Upx = 0.0;
	Upy = 1.0;
	Upz = 0.0;
	xRotation = 0.0;
	yRotation = 0.0;
	Sound = false;
	zRotation = 0.0;
}
CIngame::~CIngame(){
	delete Main;
	delete map;
	delete light;
	m_pSoundManager->Stop();
	delete m_pSoundManager;
	delete Monster;
	delete map2;
}
void CIngame::Init() {
	line = 0;
	speed = 0;
	Main->Init();
	light->Init();
	Sea = false;
}

void CIngame::Mousebutton( int button,  int state, int x, int y) {

}
void CIngame::Getkey(unsigned char key,int x,int y) {
	Main->GetKey(key, x, y);
}
void CIngame::MouseMotion(int x,int y){
	
}

void CIngame::Render() {
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -300.0);
	gluLookAt(Eyex, Eyey, Eyez, Centerx, Centery, Centerz, Upx, Upy, Upz);
//	glRotated(xRotation, 1.0f, 0.0f, 0.0f);
//	glRotated(yRotation, 0.0f, 1.0f, 0.0f);
//	glRotated(zRotation, 0.0f, 0.0f, 1.0f);

	glTranslatef(0.0, -50.0, 0.0);

	map->Render();
	Main->Render();
	Monster->Render();
	
	map2->Render();
	light->M_FLIGHTING();

}

void CIngame::Update() {
		light->Update();
		Main->Move();
		Filming();
		Main->M_Ffalling();
		Monster->Rotation();
}
void CIngame::Filming() {
	Eyez += SPEED;
	Centerz += SPEED;
//	line += SPEED;
	if (Eyez > START_DAY - 310 && Eyez < START_DAY - 10) {
		Eyey += SPEED;
		Centery += SPEED;
	}
	if (Eyez > 20000)
		Sea = true;
	speed = Main->speed;
//	if (line % 1000 == 0) {
//		speed += 2;
//	}
//
	if (Eyez >= 19990&&Eyez<=19998) {
		Sound = true;
	}
	if (Sound) {
		m_pSoundManager->PlayBGM(BGM_INGAME);
		Sound = false;
	}
}
bool CIngame::M_FDead() {
	return Main->M_FDead();
}
bool CIngame::M_FFinish() {
	return Main->M_FSuccess();
}