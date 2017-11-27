#pragma once
#include "CForServer.h"

class CSendTo
	:public CForServer
{
public:
	bool SendPlayerInfo(SOCKET& sock, SOCKADDR& Sockaddr, int Iaddrlen, int retval);
	bool SendMapInfo(SOCKET& sock, SOCKADDR& Sockaddr, int Iaddrlen, int retval);
	bool SendGhostInfo(SOCKET& sock, SOCKADDR& Sockaddr, int Iaddrlen, int retval);
	bool SendOtherInfo(SOCKET& sock, SOCKADDR& Sockaddr, int Iaddrlen, int retval);
public:
	CSendTo();
	~CSendTo();
};

