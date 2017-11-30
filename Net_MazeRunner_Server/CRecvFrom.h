#pragma once
#include "CForServer.h"
#include "stdafx.h"

//struct ForPingPong {
//	Player	PlayerArray[PLAYERMAX];
//	Maze	MazeArray[B_SIZE][B_SIZE];
//	Ghost	GhostArray[GHOSTMAX];
//
//	int		iLightRotation;
//};

class CRecvFrom
{
private:
	ForPingPong S_Server_Data;
public:
	bool RecvPlayerInfo(SOCKET&);
	bool RecvMapInfo(SOCKET&);
	ForPingPong* get_forpingpong(void);
	Player Get_Player(int);
	Maze Get_Maze(int, int);
	Ghost Get_Ghost(int);

	void set_forpingpong(ForPingPong*);
public:
	CRecvFrom();
	~CRecvFrom();
};

int recvn(SOCKET s, char *buf, int len, int flags);