#include"Character.h"
#include"map.h"
#include"CGameSystem.h"
#include"LIGHT.h"
#include"define.h"
#define PIE 3.141592
GLUquadricObj *qobj;
CGameSystem* gamesys{ nullptr };

void Quit();//종료
void TimerFunction(int value);
void Mouse(int button, int state, int x, int y);
void Keyboard(unsigned char key, int x, int y);
GLvoid ChangeSize(int w, int h);
void SetupRC();
void Init();
GLvoid RenderScene(GLvoid);
GLvoid SpecialKeyboard(int, int , int );
GLvoid Motion(int, int);
void main(int argc, char*argv[]) {
	srand((unsigned)time(NULL));
	glutInit(&argc, argv);
	glutInitWindowPosition(460, 340);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Final");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	SetupRC();
	Init();
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeyboard);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(UPDATE_FPS, TimerFunction, 1);
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Keyboard);
	glutMotionFunc(Motion);
	glutPassiveMotionFunc(Motion);
	glutMainLoop();
}

GLvoid RenderScene(GLvoid) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
//	
	gamesys->Render();
	glutSwapBuffers();
}
void Mouse(int button, int state, int x, int y) {
	gamesys->MouseButton(button, state, x, y);
	glutPostRedisplay();
}
void TimerFunction(int value) {
		gamesys->Update();
		glutPostRedisplay();
		glutTimerFunc(UPDATE_FPS, TimerFunction, 1);
}

void Keyboard(unsigned char key, int x, int y) {
	gamesys->GetKey(key, x, y);
	glutPostRedisplay();
}
GLvoid SpecialKeyboard(int key, int x, int y) {
	gamesys->SpecialKey(key, x, y);
	glutPostRedisplay();
}

void Quit() {
	exit(1);
}


void SetupRC() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


GLvoid ChangeSize(int w, int h)//윈도위 크기 변경
{
	gamesys->ChangeSize(w, h);
}


void Init() {
	gamesys = new CGameSystem;
}

GLvoid Motion(int x, int y) {
	gamesys->MouseMotion(x, y);
}