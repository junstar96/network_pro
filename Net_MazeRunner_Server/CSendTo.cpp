#include "stdafx.h"
#include "CSendTo.h"


bool CSendTo::SendPlayerInfo(void)
{
	return false;
}

bool CSendTo::SendMapInfo(LPVOID arg)
{
	SOCKET Map_info = (SOCKET)arg;
	//send �Լ��� �̿��ϵ��� ����
	
	return false;
}

bool CSendTo::SendGhostInfo(void)
{
	return false;
}

bool CSendTo::SendOtherInfo(void)
{
	return false;
}

CSendTo::CSendTo()
{
}


CSendTo::~CSendTo()
{
}
