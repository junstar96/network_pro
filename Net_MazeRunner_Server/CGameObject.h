#pragma once
class CGameObject
{
private:	//�������
	Position	m_Pos;
	float		m_fAngle;			//ȸ������
public:		//Get & Set
	Position*	GetPosition(void);
	void		SetPosition(Position* pos);

	float*		GetAngle(void);
	void		SetAngle(float* Angle);
public:
	CGameObject();
	~CGameObject();
};

