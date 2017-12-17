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
	CMaze();		//�⺻������
					//�߾� ��ġ, size�� �Է����ָ� m_fEdge�迭���ٰ� �����صΰ�
	~CMaze();
};