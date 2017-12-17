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
	unsigned int   uiSerialNum;   //������ȣ
	int            iMyTeam;      //�� �Ҽ�
	bool            connect;
	Position      Pos;         //��ġ��
	float         fAngle;         //ȸ������
	float         fDeltaAngle;      //���ۿ���������
	float         fSpeed;         //�÷��̾� �ӵ�
	int			  ikey;

								  //Position   Vector;   //����
	float		bColl = false;			//�浹üũ
};

//map
struct Maze
{
	int			iStatus;			//ENUM������ ���� �Ӽ��� ��Ÿ��
	float		fEdge[EDGE_END];	//�߾Ӱ� +- �۾� ����...
	bool		bitem[5];
	bool		bGoal[5];
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

	int			iCollision;
};

//illuminate			30��
#pragma pack(1)
struct ForPingPong {
	Player	PlayerArray[PLAYERMAX];
	Maze	MazeArray[B_SIZE][B_SIZE];
	Ghost	GhostArray[GHOSTMAX];

	bool bgetitem;
	int		iplayernum;
	int		iLightRotation;
};