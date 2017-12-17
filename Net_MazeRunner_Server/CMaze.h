#pragma once
#include "CGameObject.h"
class CMaze :
	public CGameObject
{
private:
	int			m_iStatus;
	float		m_fEdge[EDGE_END];
	bool		bitem[5];
	bool		bGoal[5];
public:
	int	GetStatus(void);
	void	SetStatus(int Status);

	float*   GetEdge(int EdgeWhat);
	void	SetEdge(float Edge, int EdgeWhat);

	bool	Getbitem(int i);
	void	Setbitem(bool item, int i);

	void	SetbGoal(bool Goal, int i);
	bool	GetbGoal(int i);
public:
	CMaze();		//기본생성자
					//중앙 위치, size를 입력해주면 m_fEdge배열에다가 저장해두고
	~CMaze();
};