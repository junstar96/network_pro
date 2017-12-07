#include "stdafx.h"
#include "CSendTo.h"


bool CSendTo::SendPlayerInfo(SOCKET& sock)
{
	int retval;
	for (int i = 0; i < PLAYERMAX; ++i)
	{

		retval = send(sock, (char*)&S_Server_Data.PlayerArray[i], 
			sizeof(S_Server_Data.PlayerArray[i]), 0);

		if (retval == SOCKET_ERROR)
		{
			err_quit("server send()");
			return false;
		}
		
	}
	//printf("send %f %f\n",S_Server_Data.PlayerArray[0].Pos.fX, S_Server_Data.PlayerArray[0].Pos.fZ);
	return true;
}

/*CPlayer m_PlayerArray[PLAYERMAX];
CMaze	m_MazeArray[B_SIZE][B_SIZE];
CGhost	m_GhostArray[GHOSTMAX];*/

bool CSendTo::SendMapInfo(SOCKET& sock)
{
	int retval;
	for (int i = 0; i < B_SIZE; ++i)
	{
		for (int j = 0; j < B_SIZE; ++j)
		{
			retval = send(sock, (char*)&S_Server_Data.MazeArray[i][j],
				sizeof(S_Server_Data.MazeArray[i][j]), 0);

			if (retval == SOCKET_ERROR)
			{
				err_quit("server send()");
				return false;
			}
		}
	}
	
	return true;
}

bool CSendTo::SendGhostInfo(SOCKET& sock)
{
	int retval;
	for (int i = 0; i < GHOSTMAX; ++i)
	{
		retval = send(sock, (char*)&S_Server_Data.GhostArray[i],
			sizeof(S_Server_Data.GhostArray[i]), 0);

		if (retval == SOCKET_ERROR)
		{
			err_quit("server send()");
			return false;
		}
	}
	return true;
}

bool CSendTo::SendOtherInfo(SOCKET& sock)
{
	int retval;

	retval = send(sock, (char*)&S_Server_Data.iLightRotation, sizeof(S_Server_Data.iLightRotation), 0);
	if (retval == SOCKET_ERROR)
	{
		err_quit("server send()");
		return false;
	}

	return true;
}

CSendTo::CSendTo()
{
	for (int i = 0; i < PLAYERMAX; ++i)
	{
		S_Server_Data.PlayerArray[i].iMyTeam = 1;
		S_Server_Data.PlayerArray[i].uiSerialNum = 1;
		S_Server_Data.PlayerArray[i].connect = false;
	}

	/*for (int i = 0; i < GHOSTMAX; ++i)
	{
		S_Server_Data.GhostArray[i].Pos.fX = 0.0f;
		S_Server_Data.GhostArray[i].Pos.fY = 0.0f;
		S_Server_Data.GhostArray[i].Pos.fZ = 0.0f;
	}*/
}


CSendTo::~CSendTo()
{
}

void CSendTo::set_forpingpong(ForPingPong* Get_S)
{
	S_Server_Data = *Get_S;
}

ForPingPong * CSendTo::get_forpingpong(void)
{
	return &S_Server_Data;
}

void CSendTo::Set_Player(CPlayer* Playerinfo, int PlayerN)
{
	S_Server_Data.PlayerArray[PlayerN].fAngle = *Playerinfo->GetAngle();
	S_Server_Data.PlayerArray[PlayerN].fDeltaAngle = *Playerinfo->GetDeltaAngle();
	//S_Server_Data.
	//Array[PlayerN].uiSerialNum = *Playerinfo->GetSerialNum();
	S_Server_Data.PlayerArray[PlayerN].Pos = *Playerinfo->GetPosition();
	printf("업글이 보내는 값 : %f  ", Playerinfo->GetPosition()->fX);
	printf("%d 번째 send가 받는 값 : %f\n",PlayerN, S_Server_Data.PlayerArray[PlayerN].Pos.fX);
}

void CSendTo::Set_Maze(CMaze* Mazeinfo, int X, int Y)
{
	for (int i = 0; i < EDGE_END; ++i)
	{
		S_Server_Data.MazeArray[X][Y].fEdge[i] = *Mazeinfo->GetEdge(i);
	}
	S_Server_Data.MazeArray[X][Y].iStatus = *Mazeinfo->GetStatus();
}



void CSendTo::Set_Ghost(CGhost* GhostInfo, int GhostN)
{
	S_Server_Data.GhostArray[GhostN].Pos = *GhostInfo->GetPosition();
	S_Server_Data.GhostArray[GhostN].fAngle = *GhostInfo->GetAngle();
}

void CSendTo::Set_Connect(bool get, int connectN)
{
	S_Server_Data.PlayerArray[connectN].Pos.fX = 20.0f * (connectN + 1);
	S_Server_Data.PlayerArray[connectN].Pos.fY = 3.0f;
	S_Server_Data.PlayerArray[connectN].Pos.fZ = 20.0f * (connectN + 1);
	S_Server_Data.PlayerArray[connectN].fAngle = 0;
	S_Server_Data.PlayerArray[connectN].fDeltaAngle = 0;
	S_Server_Data.PlayerArray[connectN].connect = get;
	S_Server_Data.PlayerArray[connectN].uiSerialNum = connectN + 1;
	S_Server_Data.PlayerArray[connectN].iMyTeam = (connectN + 1) % 2; //0 팀과 1팀으로 나누는 것이 좋을 것 같다.
}

bool CSendTo::Get_Connect(int connectN)
{
	return S_Server_Data.PlayerArray[connectN].connect;
}
