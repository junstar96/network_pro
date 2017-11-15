#include "Ghost.h"
#include "resource.h"

Ghost::Ghost()
{
	pos_x = 0;
	pos_y = 0;
	pos_z = 0;
	rot_angle = 0;
	movespeed = 0;
}


Ghost::~Ghost()
{
}

void Ghost::SetPosition(float x, float y, float z) {
	pos_x = x;
	pos_y = y;
	pos_z = z;
}

void Ghost::SetRotation(float angle) {
	rot_angle = angle;
}

void Ghost::MoveFoward(float deltaMove, float deltaAngle)  {
	movespeed = deltaMove;
	rot_angle = deltaAngle;
	pos_x +=  deltaMove* sin(deltaAngle) * 0.1f;
	pos_z += deltaMove * -cos(deltaAngle) * 0.1f;
}

void Ghost::Render() {
	glEnable(GL_BLEND);
	glPushMatrix();
	{
		glTranslatef(pos_x, pos_y, pos_z);
		glRotatef(180 - rot_angle*180.0 / 3.14, 0.0, 1.0, 0.0);
		//glRotatef(rot_angle, 0, 1, 0);

		glRotatef(0, 0, 1, 0);
		glBlendFunc(GL_ONE, GL_ONE);
		glColor3f(1.0f, 1.0f, 1.0f);

		glTranslatef(0.0f, 0.85f, 0.0f);
		glutSolidSphere(0.9f, 20, 20);

		glTranslatef(0.0f, 1.15f, 0.0f);
		glutSolidSphere(0.50f, 20, 20);

		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glTranslatef(0.07f, 0.14f, 0.45f);
		glutSolidSphere(0.13f, 10, 10);
		glTranslatef(-0.2f, 0.0f, 0.0f);
		glutSolidSphere(0.13f, 10, 10);
		glPopMatrix();

		glColor3f(1.0f, 0.5f, 0.5f);
		glutSolidCone(0.2f, 1.0f, 10, 2);
	}
	glPopMatrix();
	glDisable(GL_BLEND);
}