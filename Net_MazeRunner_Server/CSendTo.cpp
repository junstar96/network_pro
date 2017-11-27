#include "stdafx.h"
#include "CSendTo.h"


bool CSendTo::SendPlayerInfo(void)
{
	return false;
}

bool CSendTo::SendMapInfo(LPVOID arg)
{
	SOCKET Map_info = (SOCKET)arg;
	//send 함수를 이용하도록 하자
	
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
