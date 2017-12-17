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

			//printf("%d ", S_Server_Data.MazeArray[i][j].bitem);

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
	for (int i = 0; i < PLAYERMAX; ++i)
	{
		S_Server_Data.PlayerArray[i].Pos.fX = 0.0f;
		S_Server_Data.PlayerArray[i].Pos.fY = 3.0f;
		S_Server_Data.PlayerArray[i].Pos.fZ = 0.0f;
		S_Server_Data.PlayerArray[i].fAngle = 0;
		S_Server_Data.PlayerArray[i].fDeltaAngle = 0;
		S_Server_Data.PlayerArray[i].iMyTeam = i;
		S_Server_Data.PlayerArray[i].uiSerialNum = i;
		S_Server_Data.PlayerArray[i].ikey = 0;
		S_Server_Data.PlayerArray[i].connect = false;
	}

	for (int i = 0; i < GHOSTMAX; ++i)
	{
		S_Server_Data.GhostArray[i].Pos.fX = 0.0f;
		S_Server_Data.GhostArray[i].Pos.fY = 0.0f;
		S_Server_Data.GhostArray[i].Pos.fZ = 0.0f;
	}

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

Player CRecvFrom::Get_Player(int PlayerN)
{
	return S_Server_Data.PlayerArray[PlayerN];
}

Maze CRecvFrom::Get_Maze(int X, int Y)
{
	return S_Server_Data.MazeArray[X][Y];
}

Ghost CRecvFrom::Get_Ghost(int GhostN)
{
	return S_Server_Data.GhostArray[GhostN];
}

bool CRecvFrom::Get_Connect(int connectN)
{
	return S_Server_Data.PlayerArray[connectN].connect;
}

void CRecvFrom::set_forpingpong(ForPingPong * get_ping)
{
	S_Server_Data = *get_ping;
}

void CRecvFrom::Set_Ghost(CGhost* GhostInfo, int GhostN)
{
	S_Server_Data.GhostArray[GhostN].Pos = *GhostInfo->GetPosition();
	S_Server_Data.GhostArray[GhostN].fAngle = *GhostInfo->GetAngle();
	S_Server_Data.GhostArray[GhostN].iCollision = GhostInfo->GetCollision();
}

void CRecvFrom::Set_Player(CPlayer* Playerinfo, int PlayerN)
{
	S_Server_Data.PlayerArray[PlayerN].fAngle = *Playerinfo->GetAngle();
	S_Server_Data.PlayerArray[PlayerN].fDeltaAngle = *Playerinfo->GetDeltaAngle();
	S_Server_Data.PlayerArray[PlayerN].Pos = *Playerinfo->GetPosition();
	S_Server_Data.PlayerArray[PlayerN].bColl = Playerinfo->GetColli();
	S_Server_Data.PlayerArray[PlayerN].ikey = *Playerinfo->GetKey();
}

void CRecvFrom::Set_Connect(bool get, int connectN)
{
	S_Server_Data.PlayerArray[connectN].connect = get;
	S_Server_Data.PlayerArray[connectN].uiSerialNum = connectN + 1;
	S_Server_Data.PlayerArray[connectN].iMyTeam = (connectN + 1) % 2; //0 팀과 1팀으로 나누는 것이 좋을 것 같다.
}

void CRecvFrom::Set_Maze(CMaze* Mazeinfo, int X, int Y)
{
	for (int i = 0; i < EDGE_END; ++i)
	{
		S_Server_Data.MazeArray[X][Y].fEdge[i] = *Mazeinfo->GetEdge(i);
	}
	S_Server_Data.MazeArray[X][Y].iStatus = Mazeinfo->GetStatus();
	for (int i = 0; i < 5; ++i) {
		S_Server_Data.MazeArray[X][Y].bitem[i] = Mazeinfo->Getbitem(i);
	}
}