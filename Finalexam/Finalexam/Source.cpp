#include"Character.h"
#include"map.h"
#include"CGameSystem.h"
#include"LIGHT.h"
#include"define.h"
#define PIE 3.141592
GLUquadricObj *qobj;
CGameSystem* gamesys{ nullptr };
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


//��üȸ������

//ī�޶�κ�

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


Character *Main{nullptr};
CMap map;
LIGHT *light{ nullptr };
void main(int argc, char*argv[]) {
	srand((unsigned)time(NULL));
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Final");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	SetupRC();
	Init();
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeyboard);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(100, TimerFunction, 1);
	glutTimerFunc(200, TimerFunction, 2);
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Keyboard);
	glutMotionFunc(Motion);
	glutPassiveMotionFunc(Motion);
	glutMainLoop();
}

GLvoid RenderScene(GLvoid) {
	gamesys->Render();
}
void Mouse(int button, int state, int x, int y) {
	gamesys->MouseButton(button, state, x, y);
}
void TimerFunction(int value) {

}

void Keyboard(unsigned char key, int x, int y) {
	gamesys->GetKey(key, x, y);
}
GLvoid SpecialKeyboard(int key, int x, int y) {
//	Main->Getspecial(key, x, y);
}

void Quit() {
	exit(1);
}


void SetupRC() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


GLvoid ChangeSize(int w, int h)//������ ũ�� ����
{
	gamesys->ChangeSize(w, h);
}


void Init() {
	gamesys = new CGameSystem;
	Main = new Character;
	Main->Init();
	light = new LIGHT(0, 500, 0, 1.0f);
	light->Init();
	map.Init();
	Eyez = -10.0;
	Centerz = 1.0;
}

GLvoid Motion(int x, int y) {
	gamesys->MouseMotion(x, y);
}