#pragma once
#include "CGameObject.h"
class CMaze :
	public CGameObject
{
private:
	int			m_iStatus;
	float		m_fEdge[EDGE_END];
	bool		bitem;
public:
	int	GetStatus(void);
	void	SetStatus(int Status);

	float*   GetEdge(int EdgeWhat);
	void	SetEdge(float Edge, int EdgeWhat);

	bool	Getbitem();
	void	Setbitem(bool item);
public:
	CMaze();		//�⺻������
					//�߾� ��ġ, size�� �Է����ָ� m_fEdge�迭���ٰ� �����صΰ�
	~CMaze();
};

