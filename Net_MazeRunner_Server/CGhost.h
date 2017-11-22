#pragma once
#include "CGameObject.h"
class CGhost :
	public CGameObject
{
private://멤버 변수
	float m_fSpeed;

public://get & set함수
	float*	GetSpeed(void);
	void	SetSpeed(float* Speed);

public:
	CGhost();
	~CGhost();
};

