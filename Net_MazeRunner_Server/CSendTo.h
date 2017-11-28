#pragma once
#include "CForServer.h"

class CSendTo
	:public CForServer
{
public:
	bool SendPlayerInfo(SOCKET& sock);
	bool SendMapInfo(SOCKET& sock);
	bool SendGhostInfo(SOCKET& sock);
	bool SendOtherInfo(SOCKET& sock);
public:
	CSendTo();
	~CSendTo();
};

