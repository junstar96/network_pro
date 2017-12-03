#include "stdafx.h"
#include "CPlayer.h"


unsigned int * CPlayer::GetSerialNum(void)
{
	return &m_uiSerialNum;
}

void CPlayer::SetSerialNum(unsigned int * SerialNum)
{
	m_uiSerialNum = * SerialNum;
}

int * CPlayer::GetMyTeam(void)
{
	return &m_iMyTeam;
}

void CPlayer::SetMyTeam(int * Myteam)
{
	m_iMyTeam = *Myteam;
}

float * CPlayer::GetDeltaAngle(void)
{
	return &m_fDeltaAngle;
}

void CPlayer::SetDeltaAngle(float * DeltaAngle)
{
	m_fDeltaAngle = *DeltaAngle;
}

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}
