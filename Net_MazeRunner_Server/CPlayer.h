#pragma once
#include "CGameObject.h"

class CPlayer :
	public CGameObject
{
private://�������
	unsigned int	m_uiSerialNum;	//������ȣ
	int				m_iMyTeam;		//�� �Ҽ�

	float			m_fDeltaAngle;		//���ۿ���������
public:// Get & Set
	unsigned int*	GetSerialNum(void);
	void			SetSerialNum(unsigned int* SerialNum);

	int*			GetMyTeam(void);
	void			SetMyTeam(int* Myteam);

	float*			GetDeltaAngle(void);
	void			SetDeltaAngle(float* DeltaAngle);

public:
	CPlayer();
	~CPlayer();
};

