#include "Input.h"
#include "stdafx.h"
#include "resource.h"
#include "Network.h"
#include "Player.h"

//////////////////////////////////////
//			Input.cpp				//
//									//
//	���� �۵��� �ַ� Ű�����̱⿡		//
//	���콺 �κ��� �߰����� ����		//
//	�ʴ´ٸ� ������� �ʽ��ϴ�.		//
//									//
//////////////////////////////////////

// -----------------------------------
//             KEYBOARD
// -----------------------------------

void Keyboard(unsigned char key, int xx, int yy)
{
	if (key == ']') {
		Level_Minimap += 10;
	}
	if (key == ' ')
	{
		if (Bool_PlayGame == false)
		{
			if (cageX == -55) // cage�� Play�� ���� ��
			{
				FILE *fp;

				PlaySound(TEXT(SOUND_FILE_NAME_ON), NULL, SND_ASYNC | SND_SYNC); // �޴��� ������...!
				fp = fopen(MAP_TEST, "rt"); // NET_MAP / MAP_TEST
				
				if (fp == NULL)
				{
					printf("\n�� ����µ� �����߽��ϴ�.\n");
				}
				else {
					cout << "���� ��������ϴ�." << endl;
				}

				printf("\n�Ϸ�\n");

				int cha;

				while (feof(fp) == 0)
				{
					for (int i = 0; i < B_SIZE; i++)
					{
						for (int j = 0; j < B_SIZE; j++)
						{
							fscanf(fp, "%d", &cha);
							MazeBoard[i][j] = cha;
						}
					}
				}
				fclose(fp);

				Bool_PlayGame = true;
				Level_HP += 1;
				player.SetPosition();
			}
			else if (cageX == 0) // cage�� �ι� ° �޴��� ���� ��
			{
				CreateThread(NULL, 0, Network, NULL, 0, NULL);
				//network();
			}
			else // cage�� ���ῡ ���� ��
			{
				PlaySound(TEXT(SOUND_FILE_NAME_ON), NULL, SND_ASYNC | SND_ALIAS);
				exit(-1);
			}
		}
	}

	if (key == '1')
	{
		LargeView();
	}
	if (key == '2')
	{
		TopView();
	}
	if (key == '3')
	{
		CameraView();
	}
}

void SpecialKeyboard(int key, int xx, int yy)
{
	if (Bool_PlayGame == true) // ���� �� Ű ����
	{
		if (key == GLUT_KEY_LEFT)
		{
			deltaAngle = -0.05f;
		}
		if (key == GLUT_KEY_RIGHT)
		{
			deltaAngle = 0.05f;
		}
		if (key == GLUT_KEY_UP)
		{
			deltaMove = 1 + speedup;
		}
		if (key == GLUT_KEY_DOWN)
		{
			deltaMove = -1 - speedup;
		}
	}
	else // ������ ���� ������ �� Ű ����
	{
		if (key == GLUT_KEY_LEFT)
		{
			if (cageX > -55)
			{
				cageX -= 55;
			}
		}
		if (key == GLUT_KEY_RIGHT)
		{
			if (cageX < 55)
			{
				cageX += 55;
			}
		}
	}

	glutSetWindow(mainWindow);
	glutPostRedisplay();
}

void releaseKey(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		//replaySave(key::Left);
	case GLUT_KEY_RIGHT: deltaAngle = 0;
		//replaySave(key::Right);
		break;

	case GLUT_KEY_UP:
		//replaySave(key::Up);
	case GLUT_KEY_DOWN: deltaMove = 0;
		//replaySave(key::Down);
		break;
	}
}

// -----------------------------------
//             MOUSE
// -----------------------------------
void MouseMove(int x, int y) {
	if (xOrigin >= 0) {

		// ī�޶� �ޱ�
		deltaAngle = (x - xOrigin) * 0.001f;

		// ī�޶� �𷺼�
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			angle += deltaAngle;
			deltaAngle = 0.0f;
			xOrigin = -1;
		}
		else
		{
			xOrigin = x;
		}
	}
}

void init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	// Ű���� ���콺 �ݹ�
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeyboard);
	glutSpecialUpFunc(releaseKey);
	//glutMouseFunc(Mouse);
	//glutMotionFunc(MouseMove);
}