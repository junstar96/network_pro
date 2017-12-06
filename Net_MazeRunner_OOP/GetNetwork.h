#pragma once
#include "resource.h"
#include "stdafx.h"

//player
struct GetPlayer_Net {
	unsigned int	uiSerialNum;	//������ȣ
	int				iMyTeam;		//�� �Ҽ�
	bool            connect;
	Position		Pos;			//��ġ��
	float			fAngle;			//ȸ������
	float			fDeltaAngle;		//���ۿ���������
										//Position	Vector;	//����
};

//map
struct Maze_Net
{
	int			iStatus;			//ENUM������ ���� �Ӽ��� ��Ÿ��
	float		fEdge[EDGE_END];	//�߾Ӱ� +- �۾� ����...
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
