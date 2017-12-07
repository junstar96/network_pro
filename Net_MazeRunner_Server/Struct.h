#pragma once

//position
struct Position{
	float fX;
	float fY;
	float fZ;

	Position(){}
	Position(float X, float Y, float Z)		//���� ������ ������
		: fX(X), fY(Y), fZ(Z)
	{}
};

//player
struct Player {
	unsigned int	uiSerialNum;	//������ȣ
	int				iMyTeam;		//�� �Ҽ�
	bool            connect;
	Position		Pos;			//��ġ��
	float			fAngle;			//ȸ������
	float			fDeltaAngle;		//���ۿ���������
	//Position	Vector;	//����
};

//map
struct Maze
{
	int			iStatus;			//ENUM������ ���� �Ӽ��� ��Ÿ��
	float		fEdge[EDGE_END];	//�߾Ӱ� +- �۾� ����...
};
// example
// Maze MyMaze[B_SIZE][B_SIZE]
// if( MyMaze[i][j].iStatus == BLOCK_Empty ) { }...
// MyMaze[i][j].fEdge[EDGE_Right] = 15.f + 3.f;

//ghost
struct Ghost
{
	Position		Pos;
	float			fAngle;
};

//illuminate			30��
#pragma pack(1)
struct ForPingPong {
	Player	PlayerArray[PLAYERMAX];
	Maze	MazeArray[B_SIZE][B_SIZE];
	Ghost	GhostArray[GHOSTMAX];

	int		iLightRotation;
};