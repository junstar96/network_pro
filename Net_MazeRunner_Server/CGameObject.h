#pragma once
class CGameObject
{
protected:	//멤버변수
	Position	m_Pos;
	float		m_fAngle;			//회전각도
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

