#pragma once
#include "CForServer.h"
#include "stdafx.h"

class CRecvFrom
	:public CForServer
{
public:
	bool RecvPlayerInfo(LPVOID);
	bool RecvMapInfo(LPVOID);
public:
	CRecvFrom();
	~CRecvFrom();
};

int recvn(SOCKET s, char *buf, int len, int flags);