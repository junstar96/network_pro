#include "stdafx.h"
#include "CForServer.h"
#include <iostream>
#pragma warning(disable: 4996)   //for file open
#include <iostream>

void CForServer::Update_Ghost(void)
{
	for (int i = 0; i < GHOSTMAX; ++i)
	{
		Position TempPos = *m_GhostArray[i].GetPosition();
		float fTempSpeed = *m_GhostArray[i].GetSpeed();
		float fTempAngle = *m_GhostArray[i].GetAngle();

		TempPos.fX += fTempSpeed * cos(fTempAngle * 3.141592f / 180.f) * m_fElapsedTime;
		TempPos.fZ += fTempSpeed * sin(fTempAngle * 3.141592f / 180.f) * m_fElapsedTime;
		
		m_GhostArray[i].SetPosition(&TempPos);
	}
}

void CForServer::Update_Angle(void)
{
	m_iLightAngle %= 360;

	static float fCooltime = 0.f;
	fCooltime += m_fElapsedTime;

	if (fCooltime >= m_fLightRotCooltime)
	{
		fCooltime = 0.f;
		++m_iLightAngle;
	}
}

void CForServer::CollisionCheck(void)
{
	CollCheck_PlayerAndMaze();
	CollCheck_PlayerAndGhost();
}

bool CForServer::CollCheck_PlayerAndMaze(void)
{

	for (int i = 0; i < PLAYERMAX; ++i)
	{
		for (int j = 0; j < B_SIZE; ++j)
		{//렉트충돌체크
			for (int k = 0; k < B_SIZE; ++k)
			{
				Position fplayerpos = *m_PlayerArray[i].GetPosition();
				float fplayerSize = *m_PlayerArray[i].GetSize();

				float fplayerEdge[EDGE_END];
				fplayerEdge[EDGE_Left] = fplayerpos.fX - fplayerSize;
				fplayerEdge[EDGE_Right] = fplayerpos.fX + fplayerSize;
				fplayerEdge[EDGE_Top] = fplayerpos.fZ + fplayerSize;
				fplayerEdge[EDGE_Bottom] = fplayerpos.fZ - fplayerSize;

				//충돌일때
				if (fplayerEdge[EDGE_Left] <= m_MazeArray[j][k].GetPosition()->fX + 0.5 &&
					fplayerEdge[EDGE_Right] >= m_MazeArray[j][k].GetPosition()->fX - 0.5 &&
					fplayerEdge[EDGE_Top] >= m_MazeArray[j][k].GetPosition()->fZ + 3 - 0.5&&
					fplayerEdge[EDGE_Bottom] <= m_MazeArray[j][k].GetPosition()->fZ + 3 + 0.5)
				{
					if (m_MazeArray[j][k].GetStatus() == 1) // 벽과 충돌 했을 때
					{
						if (fplayerpos.fX != 0) {
							printf("☆★충돌★☆[%d, %d]pos: %f <= %f   [%d]\n", j, k, fplayerpos.fX, m_MazeArray[j][k].GetPosition()->fX, m_MazeArray[j][k].GetStatus());
						}
					}
					if (m_MazeArray[j][k].GetStatus() == 2) // 아이템과 충돌 했을 때
					{
						printf("☆★아이템★☆[%d, %d]pos: %f <= %f   [%d]\n", j, k, fplayerpos.fX, m_MazeArray[j][k].GetPosition()->fX,
							m_MazeArray[j][k].GetStatus());

						m_MazeArray[j][k].SetStatus(0); // 충돌하면 그 위치 0으로
						m_MazeArray[j][k].Setbitem(true, i + 1);
					}
					else if (m_MazeArray[j][k].GetStatus() == 3) {
						if (*m_PlayerArray[i].GetKey() >= 3) {
							printf("☆★도 착★☆[%d, %d]pos: %f <= %f   [%d]\n", j, k, fplayerpos.fX, m_MazeArray[j][k].GetPosition()->fX, m_MazeArray[j][k].GetStatus());
							m_MazeArray[j][k].SetbGoal(true, i + 1);
							m_MazeArray[j][k].SetStatus(0);
						}
						else {
							printf("key가 더 필요합니다.\n");
						}
					}
				}
				else
					m_PlayerArray[i].SetColli(false);

				if (m_PlayerArray[i].GetColli() && i == 1)
					printf("값 : %d \n", m_PlayerArray[i].GetColli());
			}
		}
		//printf("%d\n", temp);
	}
	return false;
}

bool CForServer::CollCheck_PlayerAndGhost(void)
{
	int tempColli[GHOSTMAX] = { 999 ,999 ,999 ,999 ,999 ,999 ,999 ,999, 999, 999 };
	for (int i = 0; i < PLAYERMAX; ++i)
	{
		for (int j = 0; j < GHOSTMAX; ++j)
		{//원충돌체크
			float fDisX = m_PlayerArray[i].GetPosition()->fX - (m_GhostArray[j].GetPosition()->fX);
			/*if (i == 1)
				printf("fDisX: %f", fDisX);*/
			float fDisZ = m_PlayerArray[i].GetPosition()->fZ - (m_GhostArray[j].GetPosition()->fZ + 3);
			/*if (i == 1)
				printf("fDisZ: %f\n", fDisZ);*/

			float fDis = sqrtf(fDisX * fDisX + fDisZ * fDisZ);
			if (fDis <= 0.2f / 2.f + *m_GhostArray[j].GetSize() / 2.f)
			{//충돌했을 때
			 //재리스폰 처리 -> 위치 바꾸기 // 30 * 30
				tempColli[j] = *m_PlayerArray[i].GetSerialNum();
				if (i == 1)
					printf("충돌 %d \n", m_GhostArray[j].GetCollision());
			}
		}
	}
	for (int j = 0; j < GHOSTMAX; ++j)
	{
		m_GhostArray[j].SetCollision(tempColli[j]);
		if (m_GhostArray[j].GetCollision() != 999)
		{
			printf("고스트 충돌 %d\n", m_GhostArray[j].GetCollision());
		}
	}

	//
	return false;
}

void CForServer::SetElapsedTime(float ElapsedTime)
{
	m_fElapsedTime = ElapsedTime;
}
							//리시브의 정보를 준다.
void CForServer::SetPlayer(Player PlayerInfo, int PlayerN)
{
	//printf("struct %f\n",PlayerInfo.Pos.fX);
	m_PlayerArray[PlayerN].SetPosition(&PlayerInfo.Pos);
	m_PlayerArray[PlayerN].SetSpeed(PlayerInfo.fSpeed);
	//printf("class %f\n", m_PlayerArray[PlayerN].GetPosition()->fX);
	m_PlayerArray[PlayerN].SetSerialNum(&PlayerInfo.uiSerialNum);
	m_PlayerArray[PlayerN].SetAngle(&PlayerInfo.fAngle);
	m_PlayerArray[PlayerN].SetDeltaAngle(&PlayerInfo.fDeltaAngle);
	m_PlayerArray[PlayerN].SetColli(&PlayerInfo.bColl);
	m_PlayerArray[PlayerN].SetKey(&PlayerInfo.ikey);
}

void CForServer::SetMaze(Maze MazeInfo, int X, int Y)
{
	for (int i = 0; i < EDGE_END; ++i)
	{
		m_MazeArray[X][Y].SetEdge(MazeInfo.fEdge[i], i);
	}
	m_MazeArray[X][Y].SetStatus(MazeInfo.iStatus);
}

void CForServer::SetGhost(Ghost GhostInfo, int GhostN)
{
	m_GhostArray[GhostN].SetPosition(&GhostInfo.Pos);
	m_GhostArray[GhostN].SetAngle(&GhostInfo.fAngle);
	m_GhostArray[GhostN].SetCollision(GhostInfo.iCollision);
}

CPlayer* CForServer::GetPlayer(int PlayerN)
{
	if (PlayerN > PLAYERMAX)
		return NULL;
	return &m_PlayerArray[PlayerN];
}

CMaze* CForServer::GetMaze(int X, int Y)
{
	if (X > B_SIZE || Y > B_SIZE)
		return NULL;
	return &m_MazeArray[X][Y];
}

CGhost* CForServer::GetGhost(int GhostN)
{
	if (GhostN > GHOSTMAX)
		return NULL;

	return &m_GhostArray[GhostN];
}

void CForServer::UpdatingAll(void)
{

	Update_Ghost();
	Update_Angle();

	CollisionCheck();

}

CForServer::CForServer()
	: m_fLightRotCooltime(0.1f)
{
	//맵
	FILE *fp;

	fp = fopen("MapMain.txt", "rt"); // NET_MAP / MAP_TEST

	if (fp == NULL)
	{
		printf("\n맵 만드는데 실패했습니다.\n");
		return;
	}

	std::cout << "맵 생성 완료" << std::endl;

	int cha;

	while (feof(fp) == 0)
	{
		for (int i = 0; i < B_SIZE; i++)
		{
			for (int j = 0; j < B_SIZE; j++)
			{
				fscanf(fp, "%d", &cha);
				m_MazeArray[i][j].SetStatus(cha);
				Position pos = Position(i * 1.1 - 15, 0, j * 1.1 - 15);
				m_MazeArray[i][j].SetPosition(&pos);

				m_MazeArray[i][j].SetEdge(m_MazeArray[i][j].GetPosition()->fX - 0.5f, EDGE_Left);
				m_MazeArray[i][j].SetEdge(m_MazeArray[i][j].GetPosition()->fX + 0.5f, EDGE_Right);
				m_MazeArray[i][j].SetEdge(m_MazeArray[i][j].GetPosition()->fZ + 0.5f, EDGE_Top);
				m_MazeArray[i][j].SetEdge(m_MazeArray[i][j].GetPosition()->fZ - 0.5f, EDGE_Bottom);
			}
		}
	}
	fclose(fp);

	//고스트 >> 파일, 생성,,, 
	for (int i = 0; i < GHOSTMAX; ++i)
	{
		Position* Pos = new Position(0.f, 0.f, 0.f);   //rand 
		float temp = 1.f;
		m_GhostArray[i].SetPosition(Pos);
		m_GhostArray[i].SetSize(&temp);
		temp = 30.f*(i + 1);
		m_GhostArray[i].SetAngle(&temp);
		temp = 10.f;
		m_GhostArray[i].SetSpeed(&temp);
	}

	m_iLightAngle = 0.f;

	//delete tempPlayer;
}


CForServer::~CForServer()
{
}
