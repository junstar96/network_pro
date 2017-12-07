#pragma once

//position
struct Position{
	float fX;
	float fY;
	float fZ;

	Position(){}
	Position(float X, float Y, float Z)		//간편 생성용 생성자
		: fX(X), fY(Y), fZ(Z)
	{}
};

//player
struct Player {
	unsigned int	uiSerialNum;	//고유번호
	int				iMyTeam;		//팀 소속
	bool            connect;
	Position		Pos;			//위치값
	float			fAngle;			//회전각도
	float			fDeltaAngle;		//조작에따른각도
	//Position	Vector;	//보류
};

//map
struct Maze
{
	int			iStatus;			//ENUM값으로 블럭의 속성을 나타냄
	float		fEdge[EDGE_END];	//중앙값 +- 작업 진행...
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

//illuminate			30번
#pragma pack(1)
struct ForPingPong {
	Player	PlayerArray[PLAYERMAX];
	Maze	MazeArray[B_SIZE][B_SIZE];
	Ghost	GhostArray[GHOSTMAX];

	int		iLightRotation;
};