#include "stdafx.h"
#include "CGhost.h"


float * CGhost::GetSpeed(void)
{
	return &m_fSpeed;
}

void CGhost::SetSpeed(float * Speed)
{
	m_fSpeed = *Speed;
}

int CGhost::GetCollision(void)
{
	return m_iCollision;
}

void CGhost::SetCollision(int SetColli)
{
	m_iCollision = SetColli;
}

CGhost::CGhost()
{
	m_iCollision = 999;
	m_fSize = 0.5f;
}


CGhost::~CGhost()
{
}
