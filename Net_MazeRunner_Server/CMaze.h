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
	CMaze();		//기본생성자
					//중앙 위치, size를 입력해주면 m_fEdge배열에다가 저장해두고
	~CMaze();
};

