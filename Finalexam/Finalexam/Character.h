#pragma once
#include"define.h"
#include"CSphere.h"
class Character {
protected:
	GLUquadricObj *body_obj;
	GLUquadricObj *Front_obj;
	GLUquadricObj *Engine_obj[2];
	GLUquadricObj *Tail_obj;
	GLUquadricObj *Mouth_obj;
	GLUquadricObj *Glass_part;
	GLUquadricObj *Wing_part[4];
	GLUquadricObj *Wing_other_part[4];
	GLUquadricObj *Tail_wing_part[4];
	GLUquadricObj *Tail_wing_otherpart[8];
	GLUquadricObj *Equipment[6];
	GLUquadricObj *Equipment_other[2];
	CSphere*spee[40]{ nullptr };
	GLUquadricObj *Fire;
	
	int angle;
	int Fast_Z;
	float Boom_Radius;
	
	float x_angle;
	float z_angle;
	float y_angle;
	float xPos;
	float yPos;
	int shape;
	float hp;
	float gage;
	int direction = 0;
	bool m_bMove;
	bool m_bsuccess;
	bool drop;
	int Start_Z;
	bool Dead;
	int Break_x;
	int Break_y;
	int Break_z;
	GLfloat m_mtxlocal[16];
	GLfloat m_mtxlocalt[16];
public:
	int speed;
	bool M_FDead();
	bool M_FSuccess();
	Character();
	~Character();
	void M_Ffalling();
	void Init();
	void Render();
	void Move();
	void Collision();
	void GetKey( unsigned char,  int,  int);
	void Death();
	void Update();
};