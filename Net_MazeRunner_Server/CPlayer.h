#pragma once
#include "CGameObject.h"

class CPlayer :
	public CGameObject
{
private://�������
	unsigned int   m_uiSerialNum;   //������ȣ
	int            m_iMyTeam;      //�� �Ҽ�

	float         m_fDeltaAngle;      //���ۿ���������
	float         m_fSpeed;

	int				ikey;

	bool			m_bCollCheck;
public:// Get & Set
	unsigned int*   GetSerialNum(void);
	void         SetSerialNum(unsigned int* SerialNum);

	int*         GetMyTeam(void);
	void         SetMyTeam(int* Myteam);

	float*         GetDeltaAngle(void);
	void         SetDeltaAngle(float* DeltaAngle);

	float*         GetSpeed(void);
	void         SetSpeed(float Speed);

	bool			GetColli(void);
	void			SetColli(bool Coll);

	void			SetKey(int *key);
	int*				GetKey();
public:
	CPlayer();
	~CPlayer();
};