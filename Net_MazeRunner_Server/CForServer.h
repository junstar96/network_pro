#pragma once
#include "CGameObject.h"
#include "CPlayer.h"
#include "CGhost.h"
#include "CMaze.h"

class CForServer
{
private:	//멤버변수
	CPlayer m_PlayerArray[PLAYERMAX];
	CMaze	m_MazeArray[B_SIZE][B_SIZE];
	CGhost	m_GhostArray[GHOSTMAX];

public://업데이트
	void Update_Ghost(void);
public://충돌체크
	void CollisionCheck(void);
	bool CollCheck_PlayerAndMaze(void);
	bool CollCheck_PlayerAndGhost(void);

	//
public:
	CForServer();
	~CForServer();
};


