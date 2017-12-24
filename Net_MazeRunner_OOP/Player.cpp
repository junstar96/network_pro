#include "Player.h"
#include "stdafx.h"
#include "resource.h"


CPlayer::CPlayer()
{
	Camera_x = 0;
	Camera_y = 0;
	Camera_z = 0;
	PlayerID = 999;	// 0 1 2 << 
}


CPlayer::~CPlayer()
{
}

void CPlayer::SetPosition() {
	switch (PlayerID) { //Position pos = Position(i * 1.1 - 15, 0, j * 1.1 - 15);
	case 1:   // red
		Camera_x = 1.1f - 15.f, Camera_y = 1.75f, Camera_z = 1.1f*3.4f - 15.f; // ±âº»0,5,1.75
		break;
	case 2: //blue
		Camera_x = 1.1f*27.f - 15.0f, Camera_y = 1.75f, Camera_z = 1.1f*4.f - 15.f; // ±âº»0,5,1.75
		break;
	case 3:   //red
		Camera_x = 1.1*2.f - 15.f, Camera_y = 1.75f, Camera_z = 1.1*3.4f - 15.f; // ±âº»0,5,1.75
		break;
	case 4: //blue
		Camera_x = 1.1f*28.f - 15.f, Camera_y = 1.75f, Camera_z = 1.1*8.f - 15.f; // ±âº»0,5,1.75
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