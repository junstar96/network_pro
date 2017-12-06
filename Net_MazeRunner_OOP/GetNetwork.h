#pragma once
#include "resource.h"
#include "stdafx.h"

//player
struct GetPlayer_Net {
	unsigned int	uiSerialNum;	//고유번호
	int				iMyTeam;		//팀 소속
	bool            connect;
	Position		Pos;			//위치값
	float			fAngle;			//회전각도
	float			fDeltaAngle;		//조작에따른각도
										//Position	Vector;	//보류
};

//map
struct Maze_Net
{
	int			iStatus;			//ENUM값으로 블럭의 속성을 나타냄
	float		fEdge[EDGE_END];	//중앙값 +- 작업 진행...
};
// example
// Maze MyMaze[B_SIZE][B_SIZE]
// if( MyMaze[i][j].iStatus == BLOCK_Empty ) { }...
// MyMaze[i][j].fEdge[EDGE_Right] = 15.f + 3.f;

//ghost
struct Ghost_Net
{
	Position		Pos;
	float			fAngle;
};

#pragma pack(1)
struct ForPingPong {
	GetPlayer_Net	PlayerArray[PLAYERMAX];
	Maze_Net	MazeArray[B_SIZE][B_SIZE];
	Ghost_Net	GhostArray[GHOSTMAX];

	int iLightRotation;
	int connect_num;
};
