#include "OtherPlayer.h"
#include "stdafx.h"
#include "resource.h"
#include "GetNetwork.h"


OtherPlayer::OtherPlayer()
{
	Camera_x = 0;
	Camera_y = 0;
	Camera_z = 0;
	PlayerID = 0;
	fAngle = 0;
	fdeltaAngle = 0;
}


OtherPlayer::~OtherPlayer()
{
}

void OtherPlayer::Render() {
	glPushMatrix();
	{
		glTranslatef(Camera_x, Camera_y, Camera_z-3);
		glRotatef(180 - (fAngle + fdeltaAngle)*180.0 / 3.14, 0.0, 1.0, 0.0);
		glColor3f(1, 8, 1);
		glScalef(0.4, 0.45, 0.4);
		glutWireSphere(3,10,10);

		//glBegin(GL_QUADS);
		//{
		//	//À­¸é
		//	glColor3f(0.0f, 0.0f, 1.0f);// Blue
		//	glVertex3f(1, 1, 1);
		//	glColor3f(0.0f, 1.0f, 0.0f);// Green
		//	glVertex3f(1, 1, -1);
		//	glColor3f(1.0f, 0.0f, 0.0f);// Red
		//	glVertex3f(-1, 1, -1);
		//	glColor3f(1.0f, 1.0f, 0.0f);// Yellow
		//	glVertex3f(-1.0, 1.0, 1.0f);

		//	//µÞ¸é
		//	glColor3f(0.0f, 1.0f, 0.0f);// Green
		//	glVertex3f(1, 1, -1);
		//	glColor3f(0.0f, 0.0f, 0.0f);// Black
		//	glVertex3f(1, -1, -1);
		//	glColor3f(1.0f, 1.0f, 1.0f);// White
		//	glVertex3f(-1, -1, -1);
		//	glColor3f(1.0f, 0.0f, 0.0f);// Red
		//	glVertex3f(-1, 1, -1);

		//	//¾Æ·§¸é
		//	glColor3f(1.0f, 0.0, 1.0f);// Magenta
		//	glVertex3f(-1, -1, 1);
		//	glColor3f(1.0f, 1.0f, 1.0f);// White
		//	glVertex3f(-1, -1, -1);
		//	glColor3f(0.0f, 0.0f, 0.0f);// Black
		//	glVertex3f(1, -1, -1);
		//	glColor3f(0.0f, 1.0f, 1.0f);// Cyan
		//	glVertex3f(1, -1, 1);

		//	//¿Þ¸é
		//	glColor3f(1.0f, 0.0f, 0.0f);// Red
		//	glVertex3f(-1, 1, -1);
		//	glColor3f(1.0f, 1.0f, 1.0f);// White
		//	glVertex3f(-1, -1, -1);
		//	glColor3f(1.0f, 0.0, 1.0f);// Magenta
		//	glVertex3f(-1, -1, 1);
		//	glColor3f(1.0f, 1.0f, 0.0f);// Yellow
		//	glVertex3f(-1.0, 1.0, 1.0f);

		//	//¿À¸¥¸é

		//	glColor3f(0.0f, 0.0f, 1.0f);// Blue
		//	glVertex3f(1, 1, 1);
		//	glColor3f(0.0f, 1.0f, 1.0f);// Cyan
		//	glVertex3f(1, -1, 1);
		//	glColor3f(0.0f, 0.0f, 0.0f);// Black
		//	glVertex3f(1, -1, -1);
		//	glColor3f(0.0f, 1.0f, 0.0f);// Green
		//	glVertex3f(1, 1, -1);
		//}
		//glEnd();

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

void OtherPlayer::SetPosition(float pos_x, float pos_y, float pos_z) {
	Camera_x = pos_x;
	Camera_y = pos_y;
	Camera_z = pos_z;
}