#pragma once
#include "CGameObject.h"
#include "CPlayer.h"
#include "CGhost.h"
#include "CMaze.h"

class CForServer
{
private:   //멤버변수
   CPlayer* m_PlayerArray[PLAYERMAX];
   CMaze   m_MazeArray[B_SIZE][B_SIZE];
   CGhost   m_GhostArray[GHOSTMAX];

   int      m_iLightAngle;
   float   m_fElapsedTime;

   const float   m_fLightRotCooltime;
public:
   void UpdatingAll(void);

   void SetElapsedTime(float ElapsedTime);

   void SetPlayer(Player PlayerInfo, int PlayerN);
   void SetMaze(Maze MazeInfo, int X, int Y);
   void SetGhost(Ghost GhostInfo, int GhostN);

   CPlayer* GetPlayer(int PlayerN);
   CMaze* GetMaze(int X, int Y);
   CGhost* GetGhost(int GhostN);

private://업데이트 & 충돌체크
   void Update_Ghost(void);
   void Update_Angle(void);

   void CollisionCheck(void);
   bool CollCheck_PlayerAndMaze(void);
   bool CollCheck_PlayerAndGhost(void);
public:
   CForServer();
   ~CForServer();
};
