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
	bool Get_Connect(int);

	void Set_Maze(CMaze*, int x, int y);
	void Set_Ghost(CGhost*, int);
	void Set_Connect(bool, int);
	void set_forpingpong(ForPingPong*);

	void Set_Player(CPlayer* Playerinfo, int PlayerN);
public:
	CRecvFrom();
	~CRecvFrom();
};

int recvn(SOCKET s, char *buf, int len, int flags);