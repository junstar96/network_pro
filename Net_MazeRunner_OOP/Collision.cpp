#include "Collision.h"
#include "stdafx.h"
#include "resource.h"

//////////////////////////////////////
//			Collision.cpp			//
//									//
//	게임 내 충돌체크를 담당하는 부분을	//
//	모아놓은 cpp입니다.				//
//	1. 플레이어 to 맵(미로 내부)		//
//	2. 플레이어 to 맵(외곽 라인)		//
//	3. 플레이어 to 아이템				//
//	4. 플레이어 to 길(점수 획득용)	//
//	5. 플레이어 to 도착지점			//
//	6. 플레이어 to 유령				//
//	7. 플레이어 to 길(트렉)			//
//									//
//////////////////////////////////////


void collision(point a, int i, int j)
{
	if (a.max_x > player.Camera_x && a.min_x < player.Camera_x && a.max_z<player.Camera_z - 3 && a.min_z > player.Camera_z - 3)
	{
		PlaySound(TEXT(SOUND_FILE_NAME_CRASH), NULL, SND_ASYNC | SND_ALIAS);
		if (Level_HP == 1)
		{
			startinit();
			PlaySound(TEXT(SOUND_FILE_NAME_FAIL), NULL, SND_ASYNC | SND_ALIAS);
			Level_HP++;
		}
		//cout << "crash" << endl;
		player.SetPosition();
		Level_HP -= 1;
	}
}

void collision_sideline(point a, int i, int j)
{
	if (a.max_x > player.Camera_x && a.min_x < player.Camera_x && a.max_z<player.Camera_z - 3 && a.min_z > player.Camera_z - 3)
	{
		if (Level_Key >= 3) {
			MazeBoard[i][j] = 4;
			PlaySound(TEXT(SOUND_FILE_NAME_ON), NULL, SND_ASYNC | SND_ALIAS);
		}
		else {
			PlaySound(TEXT(SOUND_FILE_NAME_CRASH), NULL, SND_ASYNC | SND_ALIAS);
			if (Level_HP == 1)
			{
				startinit();
				PlaySound(TEXT(SOUND_FILE_NAME_FAIL), NULL, SND_ASYNC | SND_ALIAS);
				Level_HP++;
			}
			//cout << "crash" << endl;
			player.SetPosition();
			Level_HP -= 1;
		}
	}
}

void collision_item(point a)
{
	if (a.max_x > player.Camera_x && a.min_x < player.Camera_x && a.max_z<player.Camera_z - 3 && a.min_z > player.Camera_z - 3)
	{
		Bool_item = true;
		//cout << "get item" << endl;
		PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_ASYNC | SND_ALIAS);

		srand((unsigned)time(NULL));

		item_rand = rand() % 5;
		switch (item_rand)
		{
		case ItemState::KEY:
			Level_Key++;
			break;
		case ItemState::SPEED:
			speedup += 0.1; // 속도증가
			Level_Speed++;
			break;
		case ItemState::HP:
			Level_HP++; // 체력 증가
			break;
		case ItemState::MINIMAP:
			Level_Minimap += 1;
			break;
		case ItemState::CUTOFF: // 임시로 KEy하나 추가
			Level_Key++;
			//cutoff += 10; // 밝기증가
			break;
		}
	}
}

void collision_endline(point a)
{
	if (a.max_x > player.Camera_x && a.min_x < player.Camera_x && a.max_z<player.Camera_z - 3 && a.min_z > player.Camera_z - 3)
	{
		PlaySound(TEXT(SOUND_FILE_NAME_FINISH), NULL, SND_ASYNC | SND_ALIAS);

		Level_HP = 0;
		startinit();
	}
}

void collision_ghost(float pos_x, float pos_z)
{
	glColor3f(0, 1, 0);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(pos_x + 1, 1, pos_z + 1);
		glVertex3f(pos_x - 1, 1, pos_z + 1);
		glVertex3f(pos_x - 1, 1, pos_z - 1);
		glVertex3f(pos_x + 1, 1, pos_z - 1);
	}
	glEnd();
	glLineWidth(1); // 유령 콜리젼 박스

	if (pos_x+1 > player.Camera_x && pos_x-1 < player.Camera_x && pos_z+1 <player.Camera_z - 3 && pos_z-1 > player.Camera_z - 3)
	{
		cout << "crash ghost" <<endl;
		PlaySound(TEXT(SOUND_FILE_NAME_CRASH), NULL, SND_ASYNC | SND_ALIAS);
		if (Level_HP == 1)
		{
			startinit();
			Bool_Sun = true;
			PlaySound(TEXT(SOUND_FILE_NAME_FAIL), NULL, SND_ASYNC | SND_ALIAS);

			Level_HP++;
		}

		printf("%3f \n", player.Camera_x);
		printf("%3f \n\n", player.Camera_z);

		player.SetPosition();
		Level_HP -= 1;
		//light_1 = true;
	}
}

bool collision_track(point a)
{
	if (a.max_x > player.Camera_x && a.min_x < player.Camera_x && a.max_z<player.Camera_z - 3 && a.min_z > player.Camera_z - 3)
		return true;
	else
		return false;
}