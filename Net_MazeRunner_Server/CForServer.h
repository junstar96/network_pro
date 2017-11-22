#pragma once
#include "CGameObject.h"
#include "CPlayer.h"
#include "CGhost.h"
#include "CMaze.h"

class CForServer
{
private:	//�������
	CPlayer m_PlayerArray[PLAYERMAX];
	CMaze	m_MazeArray[B_SIZE][B_SIZE];
	CGhost	m_GhostArray[GHOSTMAX];

public://������Ʈ
	void Update_Ghost(void);
public://�浹üũ
	void CollisionCheck(void);
	bool CollCheck_PlayerAndMaze(void);
	bool CollCheck_PlayerAndGhost(void);

	//
public:
	CForServer();
	~CForServer();
};


