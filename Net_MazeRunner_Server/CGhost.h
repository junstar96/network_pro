#pragma once
#include "CGameObject.h"
class CGhost :
	public CGameObject
{
private://��� ����
	float m_fSpeed;
	int  m_iCollision;
public://get & set�Լ�
	float*	GetSpeed(void);
	void	SetSpeed(float* Speed);

	int	GetCollision(void);
	void	SetCollision(int SetColli);
public:
	CGhost();
	~CGhost();
};

