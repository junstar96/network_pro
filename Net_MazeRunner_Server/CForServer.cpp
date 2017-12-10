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
		{//��Ʈ�浹üũ
			for (int k = 0; k < B_SIZE; ++k)
			{
				Position fplayerpos = *m_PlayerArray[i].GetPosition();
				float fplayerSize = *m_PlayerArray[i].GetSize();

				float fplayerEdge[EDGE_END];
				fplayerEdge[EDGE_Left] = fplayerpos.fX - fplayerSize;
				fplayerEdge[EDGE_Right] = fplayerpos.fX + fplayerSize;
				fplayerEdge[EDGE_Top] = fplayerpos.fZ + fplayerSize;
				fplayerEdge[EDGE_Bottom] = fplayerpos.fZ - fplayerSize;

				//�浹�϶�
				if (fplayerEdge[EDGE_Left] <= m_MazeArray[j][k].GetPosition()->fX + 0.5 &&
					fplayerEdge[EDGE_Right] >= m_MazeArray[j][k].GetPosition()->fX - 0.5 &&
					fplayerEdge[EDGE_Top] >= m_MazeArray[j][k].GetPosition()->fZ + 3 - 0.5&&
					fplayerEdge[EDGE_Bottom] <= m_MazeArray[j][k].GetPosition()->fZ + 3 + 0.5)
				{
					////�޾� �� �÷��̾� �ӵ��� ���⸸ŭ �о �ֱ�
					//float fPlayerAngle = 10.f;//*m_PlayerArray[i].GetAngle();
					//float fPlayerSpeed = 1.f;//*m_PlayerArray[i].GetSpeed();
					//fplayerpos.fX -= fPlayerSpeed * cos(fPlayerAngle * 3.141592f / 180.f);
					//fplayerpos.fZ -= fPlayerSpeed * sin(fPlayerAngle * 3.141592f / 180.f);
					if (m_MazeArray[j][k].GetStatus() == 1) // ���� �浹 ���� ��
					{
						if (fplayerpos.fX != 0) {
							printf("�١��浹�ڡ�[%d, %d]pos: %f <= %f	[%d]\n", j, k, fplayerpos.fX, m_MazeArray[j][k].GetPosition()->fX, m_MazeArray[j][k].GetStatus());
						}
					}
					if (m_MazeArray[j][k].GetStatus() == 2) // �����۰� �浹 ���� ��
					{
						printf("�١ھ����ۡڡ�[%d, %d]pos: %f <= %f	[%d]\n", j, k, fplayerpos.fX, m_MazeArray[j][k].GetPosition()->fX, m_MazeArray[j][k].GetStatus());
						
						m_MazeArray[j][k].SetStatus(0); // �浹�ϸ� �� ��ġ 0����
						m_MazeArray[j][k].Setbitem(true);
					}
				}
			}
		}
		//printf("%d\n", temp);
	}
	return false;
}

bool CForServer::CollCheck_PlayerAndGhost(void)
{
	for (int i = 0; i < PLAYERMAX; ++i)
	{
		for (int j = 0; j < GHOSTMAX; ++j)
		{//���浹üũ
			float fDisX = m_PlayerArray[i].GetPosition()->fX - m_GhostArray[j].GetPosition()->fX;
			float fDisZ = m_PlayerArray[i].GetPosition()->fZ - m_GhostArray[j].GetPosition()->fZ;
			float fDis = sqrtf(fDisX * fDisX + fDisZ * fDisZ);
			if (fDis <= *m_PlayerArray[i].GetSize() / 2.f + *m_GhostArray[j].GetSize() / 2.f)
			{//�浹���� ��
			 //�縮���� ó�� -> ��ġ �ٲٱ� // 30 * 30
				Position Pos = Position(0.f, 0.f, 0.f);
				int iRandX, iRandY = 0.f;

				if (*m_PlayerArray[i].GetMyTeam() == TEAM_Red)
				{
					iRandX = rand() % 1 + 1; // 1 or 2
				}
				else if (*m_PlayerArray[i].GetMyTeam() == TEAM_Blue)
				{
					iRandX = rand() % 1 + 27;   // 27 or 28
				}
				else
					break;

				if (iRandX == 0)
				{
					printf("�߸��� ��!\n");
					break;
				}
				iRandY = rand() % 27 + 1; //   1 ~ 28 ������ ��

				m_PlayerArray[i].SetPosition(m_MazeArray[iRandX][iRandY].GetPosition());
				printf("[���� �浹�߽��ϴ�.]\n");
			}
		}
	}
	return false;
}

void CForServer::SetElapsedTime(float ElapsedTime)
{
	m_fElapsedTime = ElapsedTime;
}
							//���ú��� ������ �ش�.
void CForServer::SetPlayer(Player PlayerInfo, int PlayerN)
{
	//printf("struct %f\n",PlayerInfo.Pos.fX);
	m_PlayerArray[PlayerN].SetPosition(&PlayerInfo.Pos);
	m_PlayerArray[PlayerN].SetSpeed(PlayerInfo.fSpeed);
	//printf("class %f\n", m_PlayerArray[PlayerN].GetPosition()->fX);
	m_PlayerArray[PlayerN].SetSerialNum(&PlayerInfo.uiSerialNum);
	m_PlayerArray[PlayerN].SetAngle(&PlayerInfo.fAngle);
	m_PlayerArray[PlayerN].SetDeltaAngle(&PlayerInfo.fDeltaAngle);
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
	//��
	FILE *fp;

	fp = fopen("MAP_NET.txt", "rt"); // NET_MAP / MAP_TEST

	if (fp == NULL)
	{
		printf("\n�� ����µ� �����߽��ϴ�.\n");
		return;
	}

	std::cout << "�� ���� �Ϸ�" << std::endl;

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

	//��Ʈ >> ����, ����,,, 
	for (int i = 0; i < GHOSTMAX; ++i)
	{
		Position* Pos = new Position(0.f, 0.f, 0.f);   //rand 
		float temp = 1.f;
		m_GhostArray[i].SetPosition(Pos);
		m_GhostArray[i].SetSize(&temp);
		temp = 10.f*(i + 1);
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
