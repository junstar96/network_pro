#include "OtherPlayer.h"
#include "stdafx.h"
#include "resource.h"
#include "GetNetwork.h"


OtherPlayer::OtherPlayer()
{
	Camera_x = 9999;
	Camera_y = 9999;
	Camera_z = 9999;
	PlayerID = 9999;
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
		glScalef(0.8, 0.4, 0.8);

		glTranslatef(0, -1.5, 0);
		glColor3f(0.8, 0.8, 0.8);
		glutWireSphere(0.4, 20, 20);
		glTranslatef(0, 0.8, 0);
		glColor3f(0.3, 0.3, 0.3);
		glutSolidSphere(0.8, 25, 25);
		glColor3f(0.8, 0.8, 0.8);
		glTranslatef(0, 0.8, 0);
		glutWireSphere(0.4, 20, 20);

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

void OtherPlayer::Render_Color() {
	glPushMatrix();
	{
		glTranslatef(Camera_x, Camera_y, Camera_z - 3);
		glRotatef(180 - (fAngle + fdeltaAngle)*180.0 / 3.14, 0.0, 1.0, 0.0);
		glScalef(0.8, 0.4, 0.8);

		glTranslatef(0, -1.5, 0);
		glColor3f(0.8, 0.0, 0.0);
		glutWireSphere(0.4, 20, 20);
		glTranslatef(0, 0.8, 0);
		glColor3f(0.0, 0.3, 0.0);
		glutSolidSphere(0.8, 25, 25);
		glColor3f(0.0, 0.0, 0.8);
		glTranslatef(0, 0.8, 0);
		glutWireSphere(0.4, 20, 20);

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