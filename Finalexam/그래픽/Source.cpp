#include"Character.h"
#include"map.h"
#define PIE 3.141592
GLUquadricObj *qobj;

struct vector3 {
	union
	{
		struct
		{
			double x, y, z; //������ 
		};
		double arr[2];
	};
	vector3() {}
	vector3(double _x, double _y, double _z) {
		x = _x, y = _y, z = _z;
	}
	/*
	������ �����ε��� ���� ���� ������ ������ �����մϴ�.
	*/
	//������ �Ǽ��� 
	vector3 operator * (double r) const {
		return vector3(x*r, y*r, z*r);
	} //������ ����
	vector3 operator + (vector3 other) const {
		return vector3(x + other.x, y + other.y, z + other.z);
	} //������ ���� 
	vector3 operator - (vector3 other) const {
		return vector3(x - other.x, y - other.y, z - other.z);
	} //�� ������ �� 
	bool operator == (vector3 other) const {
		return x == other.x && y == other.y && z == other.z;
	}
	bool operator < (vector3 other) const {
		return x < other.x && y < other.y && z < other.z;
	}
	//����
	const float inner(const vector3& other) {
		return x*other.x + y*other.y + z*other.z;
	}
	//����
	vector3 cross(const vector3& other) const {
		return vector3(y * other.z - z*other.y, -x * other.z + z*other.x, x * other.y - y*other.x);
	}
	const float length() {
		return sqrt(x*x + y*y + z*z);
	}
};
struct vector2 {
	union
	{
		struct
		{
			double x, y; //������ 
		};
		double arr[2];
	};
	vector2() {}
	vector2(double _x, double _y) {
		x = _x, y = _y;
	}

	vector2(int _x, int _y) {
		x = (double)_x, y = (double)_y;
	}
	//���� 
	double cross(const vector2& other) const {
		return x*other.y - y*other.x;
	}
	const float inner(const vector2& other) { //����
		return x*other.x + y*other.y;
	}
	/*
	������ �����ε��� ���� ���� ������ ������ �����մϴ�.
	*/
	//������ �Ǽ��� 
	vector2 operator * (double r) const {
		return vector2(x*r, y*r);
	} //������ ����
	vector2 operator + (vector2 other) const {
		return vector2(x + other.x, y + other.y);
	} //������ ���� 
	vector2 operator - (vector2 other) const {
		return vector2(x - other.x, y - other.y);
	} //�� ������ �� 
	bool operator == (vector2 other) const {
		return x == other.x && y == other.y;
	}
	bool operator < (vector2 other) const {
		return x < other.x && y < other.y;
	}

	vector3 getV3(double z) {
		return vector3{ x,y,z };
	}
};





double Color[3];

float xPos = 0.0;
float yPos = -0.0;
float zPos = 0.0;


//��üȸ������
float xRotation = 0.0f;
float yRotation = 0.0f;
float zRotation = 0.0f;

//ī�޶�κ�
float Eyex = 0.0;
float Eyey = 0.0;
float Eyez = 10.0;
float Centerx = 0.0;
float Centery = 0.0;
float Centerz = 1.0;
float Upx = 0.0;
float Upy = 1.0;
float Upz = 0.0;

GLfloat m_mtxLocal[16];
GLfloat m_mtxLocalT[16];

void Quit();//����
void TimerFunction(int value);
void Mouse(int button, int state, int x, int y);
void Keyboard(unsigned char key, int x, int y);
GLvoid ChangeSize(int w, int h);
void SetupRC();
void Init();
GLvoid RenderScene(GLvoid);
GLvoid Reshape(int w, int h);
GLvoid GLMatrix();
GLvoid SpecialKeyboard(int, int , int );
GLvoid Motion(int, int);



Character Main;
CMap map;

void main(int argc, char*argv[]) {
	srand((unsigned)time(NULL));
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1400, 600);
	glutCreateWindow("Final");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	SetupRC();
	Init();
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeyboard);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(100, TimerFunction, 1);
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Keyboard);
	glutMotionFunc(Motion);
	glutPassiveMotionFunc(Motion);
	glutMainLoop();
}

GLvoid RenderScene(GLvoid) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();

	glTranslatef(0.0, 0.0, -300.0);
	gluLookAt(Eyex, Eyey, Eyez,/**/ Centerx, Centery, Centerz, /**/ Upx, Upy, Upz);

	glRotated(xRotation, 1.0f, 0.0f, 0.0f);
	glRotated(yRotation, 0.0f, 1.0f, 0.0f);
	glRotated(zRotation, 0.0f, 0.0f, 1.0f);

	glTranslatef(0.0f, -50.0f, 0.0f);
	map.Render();
	Main.Render();


	glutSwapBuffers();
}
void Mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {




	}
}
void TimerFunction(int value) {
	Eyez += 10;	
	Centerz += 10;
	if (Eyez > START_DAY-310 && Eyez < START_DAY-10) {
		Eyey += 10;
		Centery += 10;
	}
	Main.Move();
	Main.Update();
	glutPostRedisplay();
	glutTimerFunc(100, TimerFunction, 1);
}

void Keyboard(unsigned char key, int x, int y) {
	Main.GetKey(key, x, y);
}
GLvoid SpecialKeyboard(int key, int x, int y) {
	Main.Getspecial(key, x, y);
}

void Quit() {
	exit(1);
}


void SetupRC() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


GLvoid ChangeSize(int w, int h)//������ ũ�� ����
{
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
	gluPerspective(45.0, fAspect, 1.0, 500.0);
	// �� �� ��� ���� �缳��
	glMatrixMode(GL_MODELVIEW);
	// ���� ���Q: ī�޶��� ��ġ ���� (�ʿ��� ���)
	//gluLookAt (Eyex, Eyey, Eyez,/**/ Centerx, Centery,Centerz, /**/ Upx, Upy, Upz);
	glLoadIdentity();
}


void Init() {
	Main.Init();
	map.Init();
	Eyez = -10.0;
	Centerz = 1.0;
}

GLvoid Motion(int x, int y) {

}