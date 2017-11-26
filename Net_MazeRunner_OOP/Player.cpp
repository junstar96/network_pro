#include "Player.h"
#include "stdafx.h"
#include "resource.h"


CPlayer::CPlayer()
{
	Camera_x = 0;
	Camera_y = 0;
	Camera_z = 0;
	PlayerID = rand()%3;
}


CPlayer::~CPlayer()
{
}

void CPlayer::SetPosition() {
	switch (PlayerID) {
	case 0:
		Camera_x = 20.0f, Camera_z = -3.5f, Camera_y = 1.75f; // ±âº»0,5,1.75
		break;
	case 1:
		Camera_x = -18.0f, Camera_z = -3.5f, Camera_y = 1.75f; // ±âº»0,5,1.75
		break;
	case 2:
		Camera_x = 0.5f, Camera_z = 17.0f, Camera_y = 1.75f; // ±âº»0,5,1.75
		break;
	case 3:
		Camera_x = 0.5f, Camera_z = -21.0f, Camera_y = 1.75f; // ±âº»0,5,1.75
		break;
	}
}

void CPlayer::Render() {
	glPushMatrix();
	{
		glTranslatef(Camera_x, Camera_y-1, Camera_z - 3);
		glRotatef(180 - (angle + deltaAngle)*180.0 / 3.14, 0.0, 1.0, 0.0);
		glColor3f(1, 8, 1);
		glScalef(0.4, 0.45, 0.4);

		glBegin(GL_QUADS);
		{
			//À­¸é
			glColor3f(0.0f, 0.0f, 1.0f);// Blue
			glVertex3f(1, 1, 1);
			glColor3f(0.0f, 1.0f, 0.0f);// Green
			glVertex3f(1, 1, -1);
			glColor3f(1.0f, 0.0f, 0.0f);// Red
			glVertex3f(-1, 1, -1);
			glColor3f(1.0f, 1.0f, 0.0f);// Yellow
			glVertex3f(-1.0, 1.0, 1.0f);

			//µÞ¸é
			glColor3f(0.0f, 1.0f, 0.0f);// Green
			glVertex3f(1, 1, -1);
			glColor3f(0.0f, 0.0f, 0.0f);// Black
			glVertex3f(1, -1, -1);
			glColor3f(1.0f, 1.0f, 1.0f);// White
			glVertex3f(-1, -1, -1);
			glColor3f(1.0f, 0.0f, 0.0f);// Red
			glVertex3f(-1, 1, -1);

			//¾Æ·§¸é
			glColor3f(1.0f, 0.0, 1.0f);// Magenta
			glVertex3f(-1, -1, 1);
			glColor3f(1.0f, 1.0f, 1.0f);// White
			glVertex3f(-1, -1, -1);
			glColor3f(0.0f, 0.0f, 0.0f);// Black
			glVertex3f(1, -1, -1);
			glColor3f(0.0f, 1.0f, 1.0f);// Cyan
			glVertex3f(1, -1, 1);

			//¿Þ¸é
			glColor3f(1.0f, 0.0f, 0.0f);// Red
			glVertex3f(-1, 1, -1);
			glColor3f(1.0f, 1.0f, 1.0f);// White
			glVertex3f(-1, -1, -1);
			glColor3f(1.0f, 0.0, 1.0f);// Magenta
			glVertex3f(-1, -1, 1);
			glColor3f(1.0f, 1.0f, 0.0f);// Yellow
			glVertex3f(-1.0, 1.0, 1.0f);

			//¿À¸¥¸é

			glColor3f(0.0f, 0.0f, 1.0f);// Blue
			glVertex3f(1, 1, 1);
			glColor3f(0.0f, 1.0f, 1.0f);// Cyan
			glVertex3f(1, -1, 1);
			glColor3f(0.0f, 0.0f, 0.0f);// Black
			glVertex3f(1, -1, -1);
			glColor3f(0.0f, 1.0f, 0.0f);// Green
			glVertex3f(1, 1, -1);
		}
		glEnd();

		glLineWidth(2);
		glColor3f(0.5, 0.5, 0.5);
		//glBegin(GL_LINE_LOOP);
		//{
		//	glVertex3f(static_person.max_x + 15, 2, static_person.max_z + 15);
		//	glVertex3f(static_person.min_x + 15, 2, static_person.max_z + 15);
		//	glVertex3f(static_person.min_x + 15, 2, static_person.min_z + 15);
		//	glVertex3f(static_person.max_x + 15, 2, static_person.min_z + 15);
		//}
		//glEnd();
		glLineWidth(1);

	}
	glPopMatrix();
}