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
		S_Server_Data.PlayerArray[i].Pos.fX = 0.0f;
		S_Server_Data.PlayerArray[i].Pos.fY = 0.0f;
		S_Server_Data.PlayerArray[i].Pos.fZ = 0.0f;
	}
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
	S_Server_Data.PlayerArray[PlayerN].uiSerialNum = *Playerinfo->GetSerialNum();
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
