#include "stdafx.h"
#include "CForServer.h"
#include <iostream>
#pragma warning(disable: 4996)   //for file open


void CForServer::Update_Ghost(void)
{/*
 for (int i = 0; i < GHOSTMAX; ++i)
 {
 Position TempPos = *m_GhostArray[i].GetPosition();
 float fTempSpeed = *m_GhostArray[i].GetSpeed();
 float fTempAngle = *m_GhostArray[i].GetAngle();

 TempPos.fX += fTempSpeed * sin(fTempAngle) * m_fElapsedTime;
 TempPos.fZ += fTempSpeed * -cos(fTempAngle) * m_fElapsedTime;

 m_GhostArray[i].SetPosition(&TempPos);
 }*/

 /*static float tempPrintCooltime = 0.f;
 tempPrintCooltime += m_fElapsedTime;
 if (tempPrintCooltime >= 1.f)
 {
 tempPrintCooltime = 0.f;
 for (int i = 0; i < GHOSTMAX; ++i)
 {
 std::cout << 1 << "��° ��Ʈ: [" << m_GhostArray[0].GetPosition()->fX << " , " << m_GhostArray[0].GetPosition()->fZ << "]" << std::endl;
 }
 }*/
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
		if (m_PlayerArray[i] == NULL)
			break;

		//��
		for (int j = 0; j < B_SIZE; ++j)
		{//��Ʈ�浹üũ
			for (int k = 0; k < B_SIZE; ++k)
			{
				Position fplayerpos = *m_PlayerArray[i]->GetPosition();
				float fplayerSize = *m_PlayerArray[i]->GetSize();

				float fplayerEdge[EDGE_END];
				fplayerEdge[EDGE_Left] = fplayerpos.fX - fplayerSize;
				fplayerEdge[EDGE_Right] = fplayerpos.fX + fplayerSize;
				fplayerEdge[EDGE_Top] = fplayerpos.fY + fplayerSize;
				fplayerEdge[EDGE_Bottom] = fplayerpos.fY - fplayerSize;

				//�浹�� �ƴ� ���̽�
				if (fplayerEdge[EDGE_Left] > *m_MazeArray[j][k].GetEdge(EDGE_Right))
					break;
				if (fplayerEdge[EDGE_Right] < *m_MazeArray[j][k].GetEdge(EDGE_Left))
					break;
				if (fplayerEdge[EDGE_Top] < *m_MazeArray[j][k].GetEdge(EDGE_Bottom))
					break;
				if (fplayerEdge[EDGE_Bottom] > *m_MazeArray[j][k].GetEdge(EDGE_Top))
					break;

				//�浹�ߴ�.
				if (0)
				{//�浹���� ��.. ���ǵ常ŭ�� �о��ָ��
				 //�ݻ�.. //�÷��̾��� ���ǵ� * ���� + //���� ���̳ʽ�
					int i = 0;
				}
			}
		}
	}
	return false;
}

bool CForServer::CollCheck_PlayerAndGhost(void)
{
	for (int i = 0; i < PLAYERMAX; ++i)
	{
		if (m_PlayerArray[i] == NULL)
			break;
		for (int j = 0; j < GHOSTMAX; ++j)
		{//���浹üũ
			float fDisX = m_PlayerArray[i]->GetPosition()->fX - m_GhostArray[j].GetPosition()->fX;
			float fDisZ = m_PlayerArray[i]->GetPosition()->fZ - m_GhostArray[j].GetPosition()->fZ;
			float fDis = sqrtf(fDisX * fDisX + fDisZ * fDisZ);
			if (fDis <= *m_PlayerArray[i]->GetSize() / 2.f + *m_GhostArray[j].GetSize() / 2.f)
			{//�浹���� ��
			 //�縮���� ó�� -> ��ġ �ٲٱ�
				std::cout << "�浹!" << std::endl;
			}
		}
	}
	return false;
}

void CForServer::SetElapsedTime(float ElapsedTime)
{
	m_fElapsedTime = ElapsedTime;
}

CPlayer* CForServer::GetPlayer(int PlayerN)
{
	if (PlayerN > PLAYERMAX)
		return NULL;
	return m_PlayerArray[PlayerN];
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

	fp = fopen("MAP_TEST.txt", "rt"); // NET_MAP / MAP_TEST

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
				m_MazeArray[i][j].SetStatus(&cha);

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

	//�÷��̾�
	for (int i = 0; i < PLAYERMAX; ++i)
		m_PlayerArray[i] = NULL;

	CPlayer* tempPlayer = new CPlayer();
	tempPlayer->SetPosition(&Position(0, 0, 0));
	m_PlayerArray[0] = tempPlayer;

	//��Ʈ >> ����, ����,,, 
	for (int i = 0; i < GHOSTMAX; ++i)
	{
		Position* Pos = new Position(0.f, 0.f, 0.f);   //rand 
		float temp = 1.f;
		m_GhostArray[i].SetPosition(Pos);
		m_GhostArray[i].SetSize(&temp);
		temp = 10.f*(i + 1);
		m_GhostArray[i].SetAngle(&temp);
		temp = 0.05f;
		m_GhostArray[i].SetSpeed(&temp);
	}

	m_iLightAngle = 0.f;
}


CForServer::~CForServer()
{
}