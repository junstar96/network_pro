#include "stdafx.h"
#include "CRecvFrom.h"


bool CRecvFrom::RecvPlayerInfo(SOCKET& sock)
{
	int retval;
	for (int i = 0; i < PLAYERMAX; ++i)
	{
		retval = recvn(sock, (char*)&S_Server_Data.PlayerArray[i],
			sizeof(S_Server_Data.PlayerArray[i]), 0);

		if (retval == SOCKET_ERROR)
		{
			err_quit("server recvn()");
			return false;
		}
	}
	return true;
}

bool CRecvFrom::RecvMapInfo(SOCKET& sock)
{
	int retval;
	for (int i = 0; i < B_SIZE; ++i)
	{
		for (int j = 0; j < B_SIZE; ++j)
		{
			retval = recvn(sock, (char*)&S_Server_Data.MazeArray[i][j],
				sizeof(S_Server_Data.MazeArray[i][j]), 0);

			if (retval == SOCKET_ERROR)
			{
				err_quit("server recvn()");
				return false;
			}
		}
	}
	return true;
}

CRecvFrom::CRecvFrom()
{
}


CRecvFrom::~CRecvFrom()
{
}

int recvn(SOCKET s, char *buf, int len, int flags) {
	int received;
	char *ptr = buf;
	int left = len;

	while (left > 0) {
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR) {
			return SOCKET_ERROR;
		}
		else if (received == 0) {
			break;
		}
		left -= received;
		ptr += received;
	}

	return (len - left);
}

ForPingPong* CRecvFrom::get_forpingpong(void)
{
	return &S_Server_Data;
}

void CRecvFrom::set_forpingpong(ForPingPong * get_ping)
{
	S_Server_Data = *get_ping;
}

