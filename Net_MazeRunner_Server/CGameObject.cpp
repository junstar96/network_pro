#include "stdafx.h"
#include "CGameObject.h"


void CGameObject::SetPosition(Position * pos)
{
	m_Pos = *pos;
}

void CGameObject::SetPosition2(Position pos)
{
	m_Pos = pos;
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

float * CGameObject::GetSize(void)
{
	return &m_fSize;
}

void CGameObject::SetSize(float * Size)
{
	m_fSize = *Size;
}