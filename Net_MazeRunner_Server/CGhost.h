#pragma once
#include "CGameObject.h"
class CGhost :
	public CGameObject
{
private://��� ����
	float m_fSpeed;

public://get & set�Լ�
	float*	GetSpeed(void);
	void	SetSpeed(float* Speed);

public:
	CGhost();
	~CGhost();
};

