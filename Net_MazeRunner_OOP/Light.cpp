#include "Light.h"
#include "stdafx.h"

//////////////////////////////////////
//			Light.cpp				//
//	게임 내에서 활용하는 광원처리를	//
//	모아둔 cpp입니다.					//
//	1. 큰 해에 대한 함수				//
//		- 맵을 크게360도 회전 합니다. //
//	2. 밤이 됐을 때 활용되는 랜턴		//
//		- 플레이어를 따라다닙니다.	//
//									//
//////////////////////////////////////

void Light_Sun()
{
	GLfloat AmbientLight[] = { ambientL, ambientL, ambientL, ambientL };//주변 조명
	GLfloat DiffuseLight[] = { diffuseL, diffuseL, diffuseL, diffuseL };//산란 반사 조명
	GLfloat SpecularLight[] = { specularL, specularL, specularL, specularL };//거울반사 조명
	GLfloat lightPos[] = { -28, 0, 0, 1 };
	GLfloat specref[] = { 1,1,1,1 };
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);

	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	if (Bool_Sun == true)
	{
		glPushMatrix();
		{
			glColor3f(4, 4, 0);
			glTranslated(-75, 0, 0);
			glTranslated(0, -1, 0);
			glTranslated(0, 0, 0);
			glutSolidSphere(10, 50, 50);
		}
		glPopMatrix();

		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);
	}
	else
	{
		glDisable(GL_LIGHT0);
	}
}

void Light_Lantern()
{
	GLfloat Direction[] = { 0, 0, 1 };//주변 조명
	GLfloat lightPos[] = { 0, 1, 0, 1 };
	GLfloat specref[] = { 1,1,1,1 };

	GLfloat AmbientLight[] = { ambientL, ambientL, ambientL, ambientL };//주변 조명
	GLfloat DiffuseLight[] = { diffuseL, diffuseL, diffuseL, diffuseL };//산란 반사 조명
	GLfloat SpecularLight[] = { specularL, specularL, specularL, specularL };//거울반사 조명

	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.01);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.9);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1);

	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos);

	glEnable(GL_COLOR_MATERIAL); // 오오... 개체의 기본색을 입히는거같아..!
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	if (Bool_Sun == false)
	{
		glEnable(GL_LIGHT1);
	}
	else
	{
		glDisable(GL_LIGHT1);
	}
}