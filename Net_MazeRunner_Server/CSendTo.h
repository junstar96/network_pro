#pragma once
#include "CForServer.h"

class CSendTo
	:public CForServer
{
public:
	bool SendPlayerInfo(void);
	bool SendMapInfo(void);
	bool SendGhostInfo(void);
	bool SendOtherInfo(void);
public:
	CSendTo();
	~CSendTo();
};

