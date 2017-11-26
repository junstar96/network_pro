#include "RenderScene.h"
#include "stdafx.h"
#include "resource.h"
#include "Light.h"
#include "Collision.h"
#include "Letter.h"
#include "Player.h"

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
				glPopMatrix(); // �� ǥ��

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
				glLineWidth(1); // �� ��ġ
			}
			else if (MazeBoard[i][j] == 2)
			{
				glPushMatrix();
				{
					glTranslatef(i * 1.1 - 15, 0, j * 1.1 - 15);
					Draw_Item();
				}
				glPopMatrix(); // ������ ǥ��

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
				glLineWidth(1); // ������ ��ġ
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
				glLineWidth(1); // ������ ��ġ
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
				//glLineWidth(1); // ������ ��ġ
			}
			if (MazeBoard[i][j] == 5)
			{
				glPushMatrix();
				{
					glTranslatef(i * 1.1 - 15, 0, j * 1.1 - 15);
					Draw_SideLineObj();
				}
				glPopMatrix(); // �� ǥ��

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
				glLineWidth(1); // �� ��ġ
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

// ��� ȭ�鿡 �׷����� ��������
void RenderSceneALL()
{
	//effectonoff();
	//glRotatef(obj_rot, 0, 1, 0);
	gluLookAt(look_x, look_y, look_z, center_x, center_y, center_z, up_x, up_y, up_z);

	//drawxyz(); // Greed �׷��ֱ�

	glPushMatrix();
	{
		glRotatef(Light_rot, 0, 0, -1);
		Light_Sun();
	}
	glPopMatrix();

	if (!Bool_Network) {
		for (int i = 0; i < 10; ++i) {
			Ghosts[i].Render();
			collision_ghost(Ghosts[i].pos_x, Ghosts[i].pos_z);
			//cout << "[" <<	i << "]	" << Ghosts[i].pos_x << endl;
		}
	}
}

// ����������1
void RenderSceneW1() {
	glutSetWindow(subWindow1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	if (Level_HP != 0)
	{
		gluLookAt(player.Camera_x, player.Camera_y, player.Camera_z,
			player.Camera_x + lx, player.Camera_y + ly, player.Camera_z + lz,
			0.0f, 1.0f, 0.0f);
	}
	else
	{
		gluLookAt(player.Camera_x, player.Camera_y, player.Camera_z + 100,
			player.Camera_x + lx, player.Camera_y + ly, player.Camera_z + lz,
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
		//glTranslatef(Camera_x, Camera_y - 1.5, Camera_z);
		//glRotatef(180 - (angle + deltaAngle)*180.0 / 3.14, 0.0, 1.0, 0.0);
		
		//�÷��̾� ����
		player.Render();
		
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

	if (!Bool_Network) { // ��Ʈ��ũ ����� �� �浹üũ�� ��Ʈ��ũ���� �˻�
		for (int i = 0; i < B_SIZE; i++)
		{
			for (int j = 0; j < B_SIZE; j++)
			{
				if (MazeBoard[i][j] == 0) // �׳� ��...
				{
					if (collision_track(Collision_Maze[i][j])) {
						MazeBoard[i][j] = 4;
					}
				}
				if (MazeBoard[i][j] == 1) // �� �ε�ġ�� ���� out6
				{
					collision(Collision_Maze[i][j], i, j);
				}
				if (MazeBoard[i][j] == 2) // ������ �Ա�
				{
					collision_item(Collision_Maze[i][j]);
					if (Bool_item == true)
					{
						MazeBoard[i][j] = 0;
						Bool_item = false;
					}
				}
				if (MazeBoard[i][j] == 3) // ���� ��
				{
					collision_endline(Collision_Maze[i][j]);
					if (Bool_item == true)
					{
						MazeBoard[i][j] = 0;
						Bool_item = false;
					}
				}
				if (MazeBoard[i][j] == 5) // ���� ��
				{
					collision_sideline(Collision_Maze[i][j], i, j);
				}
			}
		} // �� �ε�ġ�°� üũ
		if (Level_HP == 0)
		{
			Bool_Sun = true;
			Bool_PlayGame = false;
		}
	}

	// ������ ǥ��
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

// ���������� 2
void RenderSceneW2() {
	glutSetWindow(subWindow2);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(player.Camera_x, player.Camera_y + 3 + Level_Minimap, player.Camera_z,
		player.Camera_x, player.Camera_y - 1, player.Camera_z,
		lx, 0, lz);

	// ���� �� ī�޶�
	glPushMatrix();
	{
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(player.Camera_x, player.Camera_y, player.Camera_z);
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

	// ����


	glPushMatrix();
	{
		glColor3f(1.0, 0.0, 0.0);
		//glTranslatef(Camera_x, Camera_y - 1.5, Camera_z);
		//glRotatef(180 - (angle + deltaAngle)*180.0 / 3.14, 0.0, 1.0, 0.0);

		player.Render();
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

// ���������� 3
void RenderSceneW3()
{
	glutSetWindow(subWindow3);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(
		0, 0, 200,
		0, 1, 0,
		0, 1, 0);

	// ���� ��
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(player.Camera_x, player.Camera_y, player.Camera_z);
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

// ��ü ������
void DrawScene()
{
	// Ű���� �̵� üũ
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