#include "stdafx.h"
#include "CRecvFrom.h"


bool CRecvFrom::RecvPlayerInfo(void)
{
	return false;
}

bool CRecvFrom::RecvMapInfo(void)
{
	return false;
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