#include "Letter.h"
#include "stdafx.h"

//////////////////////////////////////
//			Letter.cpp				//
//									//
//	게임에서 활용되는 문자들을			//
//	관리하는 cpp입니다.				//
//									//
//////////////////////////////////////

void letter_Play()
{
	glColor3f(1, 1, 1);
	char *string = "";    glRasterPos2f(0, -40);  // 문자 출력할 위치 설정  
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);

	glColor3f(1, 1, 1);
	char *string_1 = "HP	:";    glRasterPos2f(-80, -60);  // 문자 출력할 위치 설정  
	int len_1 = (int)strlen(string);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string_1[i]);

	glColor3f(1, 1, 1);
	char *string_2 = "KEY	:";    glRasterPos2f(-80, -40);  // 문자 출력할 위치 설정  
	int len_2 = (int)strlen(string);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string_2[i]);
}

void letter_Menu()
{
	glColor3f(1, 1, 1);
	char *string_10 = "START";    glRasterPos2f(-68, -70);  // 문자 출력할 위치 설정  
	int len_10 = (int)strlen(string_10);
	for (int i = 0; i < len_10; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string_10[i]);

	glColor3f(1, 1, 1);
	char *string_11 = "NETWORK";    glRasterPos2f(-25, -70);  // 문자 출력할 위치 설정  
	int len_11 = (int)strlen(string_11);
	for (int i = 0; i < len_11; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string_11[i]);

	glColor3f(1, 1, 1);
	char *string_12 = "QUIT";    glRasterPos2f(43, -70);  // 문자 출력할 위치 설정  
	int len_12 = (int)strlen(string_12);
	for (int i = 0; i < len_12; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string_12[i]);
}

void letter_item()
{
	if (item_rand == ItemState::KEY)
	{
		glColor3f(1, 1, 1);
		char *string_20 = "NEW ITEM : GET KEY";    glRasterPos2f(-30, -40);  // 문자 출력할 위치 설정  
		int len_20 = (int)strlen(string_20);
		for (int i = 0; i < len_20; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string_20[i]);
	}

	if (item_rand == ItemState::SPEED)
	{
		char *string_21 = "NEW ITEM : SPEED UP";    glRasterPos2f(-30, -40);  // 문자 출력할 위치 설정  
		int len_21 = (int)strlen(string_21);
		for (int i = 0; i < len_21; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string_21[i]);
	}

	if (item_rand == ItemState::HP)
	{
		char *string_22 = "NEW ITEM : HP! UP";    glRasterPos2f(-30, -40);  // 문자 출력할 위치 설정  
		int len_22 = (int)strlen(string_22);
		for (int i = 0; i < len_22; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string_22[i]);
	}

	if (item_rand == ItemState::MINIMAP)
	{
		char *string_23 = "NEW ITEM : WIDE VIEW";    glRasterPos2f(-30, -40);  // 문자 출력할 위치 설정  
		int len_23 = (int)strlen(string_23);
		for (int i = 0; i < len_23; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string_23[i]);
	}

	if (item_rand == ItemState::CUTOFF)
	{
		char *string_24 = "NEW ITEM : GET KEY";    glRasterPos2f(-30, -40);  // 문자 출력할 위치 설정  
		int len_24 = (int)strlen(string_24);
		for (int i = 0; i < len_24; i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string_24[i]);
	}
}

void letter_time()
{
	char HP_char[20];
	char SPEED_char[20];
	char KEY_char[20];
	sprintf(HP_char, "HP	 : [ %d ]", Level_HP);
	sprintf(SPEED_char, "Speed: [ %d ]", Level_Speed);
	sprintf(KEY_char, "KEY	: [ %d ]", Level_Key);
	//sprintf(t, "%d", mainscore);

	char *kp;
	glRasterPos3f(-80, -40, 0);
	for (kp = KEY_char; *kp != '\0'; kp++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *kp);
	} // 블록 깨기

	char *cp;
	glRasterPos3f(-80, -60, 0);
	for (cp = HP_char; *cp != '\0'; cp++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *cp);
	} // 블록 깨기

	char *cs;
	glRasterPos3f(-80, -80, 0);
	for (cs = SPEED_char; *cs != '\0'; cs++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *cs);
	} // 속도
}