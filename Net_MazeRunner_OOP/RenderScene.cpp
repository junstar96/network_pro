#include "RenderScene.h"
#include "stdafx.h"
#include "resource.h"
#include "Light.h"
#include "Collision.h"
#include "Letter.h"

void board_maker()
{
	random_device seed_gen;
	mt19937 engine(seed_gen());
	uniform_real_distribution<> dist(0, 1);

	glDisable(GL_BLEND);

	for (int i = 0; i < B_SIZE; i++)
	{
		for (int j = 0; j < B_SIZE; j++)
		{
			if (MazeBoard[i][j] == 1)
			{
				glPushMatrix();
				{
					glTranslatef(i * 1.1 - 15, 0, j * 1.1 - 15);
					Draw_MazeObj();
				}
				glPopMatrix(); // 블럭 표시

				glColor3f(1, 0, 0);
				glLineWidth(1);
				//glBegin(GL_LINE_LOOP);
				//{
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].min_z);
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].min_z);
				//}
				//glEnd();
				glLineWidth(1); // 블럭 위치
			}
			else if (MazeBoard[i][j] == 2)
			{
				glPushMatrix();
				{
					glTranslatef(i * 1.1 - 15, 0, j * 1.1 - 15);
					Draw_Item();
				}
				glPopMatrix(); // 아이템 표시

				glColor3f(0, 1, 0);
				glLineWidth(1);
				//glBegin(GL_LINE_LOOP);
				//{
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].min_z);
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].min_z);
				//}
				//glEnd();
				glLineWidth(1); // 아이템 위치
			}
			else if (MazeBoard[i][j] == 3)
			{
				glPushMatrix();
				{
					glTranslatef(i * 1.1 - 15, 0, j * 1.1 - 15);
					glEnable(GL_BLEND);
					glPushMatrix();
					{
						glBlendFunc(GL_SRC_ALPHA, GL_ONE);
						//glColor3f(0.7, 0.2, 0.2);
						glTranslatef(0, 2, 0);
						glColor4f(dist(engine), dist(engine), dist(engine), dist(engine));
						glRotatef(obj_rot, 0, 1, 0);
						glutSolidCube(0.5);
					}
					glPopMatrix();

					glPushMatrix();
					{
						glColor4f(dist(engine), dist(engine), dist(engine), dist(engine));
						glTranslatef(0, 2.0, 0);
						glRotatef(obj_rot, 0, 1, 0);
						glRotatef(90, -1, 0, -1);
						glutSolidCube(1.0);
					}
					glPopMatrix();

					glDisable(GL_BLEND);
				}
				glPopMatrix();

				glColor3f(0, 0, 1);
				glLineWidth(1);
				//glBegin(GL_LINE_LOOP);
				//{
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].min_z);
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].min_z);
				//}
				//glEnd();
				glLineWidth(1); // 도착지 위치
			}
			else if (MazeBoard[i][j] == 4)
			{
				glPushMatrix();
				{
					glTranslatef(i * 1.1 - 15, 0, j * 1.1 - 15);
					Draw_TrackObj();
				}
				glPopMatrix();

				glColor3f(0, 1, 0);
				//glLineWidth(1);
				//glBegin(GL_LINE_LOOP);
				//{
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].min_z);
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].min_z);
				//}
				//glEnd();
				//glLineWidth(1); // 아이템 위치
			}
			if (MazeBoard[i][j] == 5)
			{
				glPushMatrix();
				{
					glTranslatef(i * 1.1 - 15, 0, j * 1.1 - 15);
					Draw_SideLineObj();
				}
				glPopMatrix(); // 블럭 표시

				glColor3f(1, 0, 0);
				glLineWidth(1);
				//glBegin(GL_LINE_LOOP);
				//{
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].max_z);
				//	glVertex3f(static_block[i][j].min_x, 1, static_block[i][j].min_z);
				//	glVertex3f(static_block[i][j].max_x, 1, static_block[i][j].min_z);
				//}
				//glEnd();
				glLineWidth(1); // 블럭 위치
			}
		}
	}
}

void renderScene()
{
	glutSetWindow(mainWindow);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

// 모든 화면에 그려지는 랜더링씬
void RenderSceneALL()
{
	//effectonoff();
	//glRotatef(obj_rot, 0, 1, 0);
	gluLookAt(look_x, look_y, look_z, center_x, center_y, center_z, up_x, up_y, up_z);

	//drawxyz(); // Greed 그려주기

	glPushMatrix();
	{
		glRotatef(Light_rot, 0, 0, -1);
		Light_Sun();
	}
	glPopMatrix();

	for (int i = 0; i < 10; ++i) {
		Ghosts[i].Render();
		collision_ghost(Ghosts[i].pos_x, Ghosts[i].pos_z);
		//cout << "[" <<	i << "]	" << Ghosts[i].pos_x << endl;
	}
}

// 서브윈도우1
void RenderSceneW1() {
	glutSetWindow(subWindow1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	if (Level_HP != 0)
	{
		gluLookAt(Camera_x, Camera_y, Camera_z,
			Camera_x + lx, Camera_y + ly, Camera_z + lz,
			0.0f, 1.0f, 0.0f);
	}
	else
	{
		gluLookAt(Camera_x, Camera_y, Camera_z + 100,
			Camera_x + lx, Camera_y + ly, Camera_z + lz,
			0.0f, 1.0f, 0.0f);
	}

	if (deltaAngle)
	{
		computeDir(deltaAngle);
	}
	
	RenderSceneALL();
	board_maker();

	glPushMatrix();
	{
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(Camera_x, Camera_y - 1.5, Camera_z - 3);
		glRotatef(180 - (angle + deltaAngle)*180.0 / 3.14, 0.0, 1.0, 0.0);
		
		//플레이어 관련
		Draw_PlayerObj();
		
		Light_Lantern();

		if (Bool_Greed == true)
		{
			glPushMatrix();
			{
				glTranslated(0, 0.3, 0);
				Draw_Greed();
			}
			glPopMatrix();
		}


	}
	glPopMatrix();


	for (int i = 0; i < B_SIZE; i++)
	{
		for (int j = 0; j < B_SIZE; j++)
		{
			if (MazeBoard[i][j] == 0) // 그냥 길...
			{
				if (collision_track(Collision_Maze[i][j])) {
					MazeBoard[i][j] = 4;
				}
			}
			if (MazeBoard[i][j] == 1) // 벽 부딪치면 게임 out6
			{
				collision(Collision_Maze[i][j], i, j);
			}
			if (MazeBoard[i][j] == 2) // 아이템 먹기
			{
				collision_item(Collision_Maze[i][j]);
				if (Bool_item == true)
				{
					MazeBoard[i][j] = 0;
					Bool_item = false;
				}
			}
			if (MazeBoard[i][j] == 3) // 게임 끝
			{
				collision_endline(Collision_Maze[i][j]);
				if (Bool_item == true)
				{
					MazeBoard[i][j] = 0;
					Bool_item = false;
				}
			}
			if (MazeBoard[i][j] == 5) // 막힌 길
			{
				collision_sideline(Collision_Maze[i][j], i, j);
			}
		}
	} // 벽 부딪치는거 체크
	if (Level_HP == 0)
	{
		Bool_Sun = true;
		Bool_PlayGame = false;
	}

	// 프레임 표시
	frame++;

	glColor3f(0.0, 1.0, 0.0);
	timing = glutGet(GLUT_ELAPSED_TIME);
	if (timing - timebase > 1000) {
		sprintf(s, "3D_MazeRunner - FPS:%4.2f",
			frame*1000.0 / (timing - timebase));
		timebase = timing;
		frame = 0;
	}
	glColor3f(1.0, 1.0, 1.0);

	setOrthographicProjection();

	glPushMatrix();
	glLoadIdentity();
	renderBitmapString(5, 30, 0, GLUT_BITMAP_HELVETICA_12, s);
	glPopMatrix();

	restorePerspectiveProjection();

	glutSwapBuffers();
}

// 서브윈도우 2
void RenderSceneW2() {
	glutSetWindow(subWindow2);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(Camera_x, Camera_y + 3 + Level_Minimap, Camera_z,
		Camera_x, Camera_y - 1, Camera_z,
		lx, 0, lz);


	// 레드 콘 카메라
	glPushMatrix();
	{
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(Camera_x, Camera_y, Camera_z);
		glRotatef(180 - (angle + deltaAngle)*180.0 / 3.14, 0.0, 1.0, 0.0);
		glutSolidCone(0.2, 0.8f, 4, 4);
	}
	glPopMatrix();

	if (deltaAngle)
	{
		computeDir(deltaAngle);
	}

	RenderSceneALL();
	board_maker();

	// 유령


	glPushMatrix();
	{
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(Camera_x, Camera_y - 1.5, Camera_z - 3);
		glRotatef(180 - (angle + deltaAngle)*180.0 / 3.14, 0.0, 1.0, 0.0);
		Draw_PlayerObj();
		Light_Lantern();



		if (Bool_Greed == true)
		{
			glPushMatrix();
			{
				glTranslated(0, 0.3, 0);
				Draw_Greed();
			}
			glPopMatrix();
		}
	}
	glPopMatrix();

	glutSwapBuffers();
}

// 서브윈도우 3
void RenderSceneW3()
{
	glutSetWindow(subWindow3);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(
		0, 0, 200,
		0, 1, 0,
		0, 1, 0);

	// 레드 콘
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(Camera_x, Camera_y, Camera_z);
	glRotatef(180 - (angle + deltaAngle)*180.0 / 3.14, 0.0, 1.0, 0.0);
	glutSolidCone(0.2, 0.8f, 4, 4);
	glPopMatrix();

	RenderSceneALL();

	if (Bool_PlayGame == true)
	{
		letter_Play();
		letter_item();
		letter_time();
	}
	else
	{
		Draw_Cage();
		letter_Menu();
	}

	//initTextures();
	//draw_hp();

	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();
}

// 전체 랜더링
void DrawScene()
{
	// 키보드 이동 체크
	if (deltaMove)
	{
		computePos(deltaMove);
		glutSetWindow(mainWindow);
		glutPostRedisplay();
	}

	RenderSceneW1();
	RenderSceneW2();
	RenderSceneW3();
}