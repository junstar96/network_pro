#include "Input.h"
#include "stdafx.h"
#include "resource.h"
#include "Network.h"
#include "Player.h"

//////////////////////////////////////
//			Input.cpp				//
//									//
//	게임 작동이 주로 키보드이기에		//
//	마우스 부분은 추가구현 하지		//
//	않는다면 사용하지 않습니다.		//
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
			if (cageX == -55) // cage가 Play에 있을 때
			{
				FILE *fp;

				PlaySound(TEXT(SOUND_FILE_NAME_ON), NULL, SND_ASYNC | SND_SYNC); // 메뉴바 선택음...!
				fp = fopen(MAP_TEST, "rt"); // NET_MAP / MAP_TEST
				
				if (fp == NULL)
				{
					printf("\n맵 만드는데 실패했습니다.\n");
				}
				else {
					cout << "맵이 만들어집니다." << endl;
				}

				printf("\n완료\n");

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
			else if (cageX == 0) // cage가 두번 째 메뉴에 있을 때
			{
				CreateThread(NULL, 0, Network, NULL, 0, NULL);
				//network();
			}
			else // cage가 종료에 있을 때
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
	if (Bool_PlayGame == true) // 게임 중 키 관리
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
	else // 게임이 끝난 상태일 때 키 관리
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

		// 카메라 앵글
		deltaAngle = (x - xOrigin) * 0.001f;

		// 카메라 디렉션
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
	// 키보드 마우스 콜백
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeyboard);
	glutSpecialUpFunc(releaseKey);
	//glutMouseFunc(Mouse);
	//glutMotionFunc(MouseMove);
}