#pragma once
#include"define.h"

class CObstacle {
protected:
	bool m_bBreak;
public:
	CObstacle();
	~CObstacle();
	virtual void Init() {};
	virtual void Render() {};
	virtual void Update() {};

};
