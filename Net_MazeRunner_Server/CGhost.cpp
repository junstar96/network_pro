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

CGhost::CGhost()
{
}


CGhost::~CGhost()
{
}
