#pragma once
#include "CGameObject.h"
class CMaze :
	public CGameObject
{
private:
	int			m_iStatus;
	float		m_fEdge[EDGE_END];

public:
	int*	GetStatus(void);
	void	SetStatus(int* Status);

	float*	GetEdge(void);
	void	SetEdge(float Edge, int EdgeWhat);
public:
	CMaze();		//�⺻������
					//�߾� ��ġ, size�� �Է����ָ� m_fEdge�迭���ٰ� �����صΰ�
	~CMaze();
};

