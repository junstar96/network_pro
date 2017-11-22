#include "stdafx.h"
#include "CGameObject.h"


void CGameObject::SetPosition(Position * pos)
{
	m_Pos = *pos;
}

float * CGameObject::GetAngle(void)
{
	return &m_fAngle;
}

void CGameObject::SetAngle(float * Angle)
{
	m_fAngle = *Angle;
}

Position * CGameObject::GetPosition(void)
{
	return &m_Pos;
}

CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
}
