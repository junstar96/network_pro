#include "Time.h"
#include "resource.h"
#include "stdafx.h"
#include "Ghost.h"
#include "Collision.h"

void TimerFunction(int value)
{
	obj_rot += 2;
	if (obj_rot > 10000)
	{
		obj_rot = 0;
	} // ������, �������� Obj ȸ��

	if (isPlayGame == true)
	{
		if (isNetwork == false) {
			for (int i = 0; i < 10; ++i) {
				Ghosts[i].MoveFoward(1.3, 30 * i);
				if (Light_rot % 120 == 0) {
					Ghosts[i].SetPosition(0, 0, 0);
				}
				collision_ghost(Ghosts[i].pos_x, Ghosts[i].pos_z);
			}
		}
		if (Light_rot < 360)
		{
			if (Bool_Sun == true)
			{
				Light_rot += 1.0;
			}
			else
			{
				Light_rot += 0.9;
			}
		}
		else
		{
			Light_rot = 0;
			Bool_Sun = true;
			PlaySound(TEXT(SOUND_FILE_NAME_MORNING), NULL, SND_ASYNC | SND_ALIAS);
		}

		if (Light_rot == 180)
		{
			Bool_Sun = false;
			PlaySound(TEXT(SOUND_FILE_NAME_DARK), NULL, SND_ASYNC | SND_ALIAS);
		}
	}
	else
	{
		Light_rot = 0;
	}

	glutPostRedisplay();   // ȭ�� �� ��� 
	glutTimerFunc(timef, TimerFunction, 60); // Ÿ�̸��Լ� �� ����
} // �ð�