#include "stdafx.h"
#include "CPlayer.h"


unsigned int * CPlayer::GetSerialNum(void)
{
	return &m_uiSerialNum;
}

void CPlayer::SetSerialNum(unsigned int * SerialNum)
{
	m_uiSerialNum = *SerialNum;
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

float * CPlayer::GetSpeed(void)
{
	return &m_fSpeed;
}

void CPlayer::SetSpeed(float Speed)
{
	m_fSpeed = Speed;
}

bool CPlayer::GetColli(void)
{
	return m_bCollCheck;
}

void CPlayer::SetColli(bool Coll)
{
	m_bCollCheck = Coll;
}

void CPlayer::SetKey(int *key) {
	ikey = *key;
}

int* CPlayer::GetKey() {
	return &ikey;
}

CPlayer::CPlayer()
{
	m_fSize = 0.1;
}


CPlayer::~CPlayer()
{
}