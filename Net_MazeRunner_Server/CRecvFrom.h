#pragma once
#include "CForServer.h"
#include "stdafx.h"

class CRecvFrom
	:public CForServer
{
public:
	bool RecvPlayerInfo(SOCKET&);
	bool RecvMapInfo(SOCKET&);
public:
	CRecvFrom();
	~CRecvFrom();
};

int recvn(SOCKET s, char *buf, int len, int flags);