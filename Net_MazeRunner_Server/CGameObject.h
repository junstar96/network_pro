#pragma once
class CGameObject
{
private:	//멤버변수
	Position	m_Pos;
	float		m_fAngle;			//회전각도
public:		//Get & Set
	Position*	GetPosition(void);
	void		SetPosition(Position* pos);

	float*		GetAngle(void);
	void		SetAngle(float* Angle);
public:
	CGameObject();
	~CGameObject();
};

