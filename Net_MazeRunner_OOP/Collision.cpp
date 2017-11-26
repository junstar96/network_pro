#include "Collision.h"
#include "stdafx.h"
#include "resource.h"

//////////////////////////////////////
//			Collision.cpp			//
//									//
//	���� �� �浹üũ�� ����ϴ� �κ���	//
//	��Ƴ��� cpp�Դϴ�.				//
//	1. �÷��̾� to ��(�̷� ����)		//
//	2. �÷��̾� to ��(�ܰ� ����)		//
//	3. �÷��̾� to ������				//
//	4. �÷��̾� to ��(���� ȹ���)	//
//	5. �÷��̾� to ��������			//
//	6. �÷��̾� to ����				//
//	7. �÷��̾� to ��(Ʈ��)			//
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
			speedup += 0.1; // �ӵ�����
			Level_Speed++;
			break;
		case ItemState::HP:
			Level_HP++; // ü�� ����
			break;
		case ItemState::MINIMAP:
			Level_Minimap += 1;
			break;
		case ItemState::CUTOFF: // �ӽ÷� KEy�ϳ� �߰�
			Level_Key++;
			//cutoff += 10; // �������
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
	glLineWidth(1); // ���� �ݸ��� �ڽ�

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