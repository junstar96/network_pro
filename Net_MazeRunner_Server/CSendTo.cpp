#include "stdafx.h"
#include "CSendTo.h"


bool CSendTo::SendPlayerInfo(SOCKET& sock, SOCKADDR& Sockaddr, int Iaddrlen, int retval)
{
	for (int i = 0; i < PLAYERMAX; ++i)
	{

		send(sock, (char*)&S_Server_Data.PlayerArray[i], 
			sizeof(S_Server_Data.PlayerArray[i]), 0);
	}
	return false;
}

bool CSendTo::SendMapInfo(SOCKET& sock, SOCKADDR& Sockaddr, int Iaddrlen, int retval)
{
	
	
	return false;
}

bool CSendTo::SendGhostInfo(SOCKET& sock, SOCKADDR& Sockaddr, int Iaddrlen, int retval)
{
	return false;
}

bool CSendTo::SendOtherInfo(SOCKET& sock, SOCKADDR& Sockaddr, int Iaddrlen, int retval)
{
	return false;
}

CSendTo::CSendTo() : CForServer()
{
}


CSendTo::~CSendTo()
{
}
