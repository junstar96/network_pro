#pragma once
class CGameObject
{
protected:	//�������
	Position	m_Pos;
	float		m_fAngle;			//ȸ������
	float       m_fSize;
public:		//Get & Set
	Position*	GetPosition(void);
	void		SetPosition(Position* pos);
	void		SetPosition2(Position pos);

	float*      GetSize(void);
	void      SetSize(float* Size);

	float*		GetAngle(void);
	void		SetAngle(float* Angle);
public:
	CGameObject();
	~CGameObject();
};

