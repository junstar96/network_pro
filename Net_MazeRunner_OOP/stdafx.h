#pragma once
#pragma comment(lib,"winmm") 
#pragma warning(disable:4996)
//#include "resource.h"

#include "Ghost.h"
#include "Player.h"


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include <windows.h>
#include <string>
#include <random>
#include <mmsystem.h>
#include <time.h>
#include <fstream>
#include <list>
#include <vector>

#define B_SIZE 30 // 맵 사이즈

using namespace std;

///////////////////////////////////////////////////////////
//                     Sub Menu                          //
///////////////////////////////////////////////////////////

// cheat
extern float speedup;
extern int Level_Key;
extern int Level_Speed;
extern int Level_HP;
extern int Level_Minimap;
extern int item_rand;

extern clock_t start, finish;

//bool 값
extern bool Bool_Greed;
extern bool Bool_item;
extern bool bool_line;
extern bool Bool_Shading;
extern bool Bool_Depth;
extern bool cullingone;
extern bool Bool_PlayGame;
extern bool Bool_Network;

///////////////////////////////////////////////////////////
//                     Lookat
///////////////////////////////////////////////////////////

extern float look_x;
extern float look_y;
extern float look_z;
extern float center_x;
extern float center_y;
extern float center_z;
extern float up_x;
extern float up_y;
extern float up_z;

///////////////////////////////////////////////////////////
//                   Light & Fog
///////////////////////////////////////////////////////////

extern float ambientL;
extern float diffuseL;
extern float specularL;
extern int timef;

extern bool Bool_Sun;
extern int Light_rot;

extern GLfloat fog_color[4];
extern GLfloat density;
extern GLfloat start_fog;
extern GLfloat end_fog;

extern int cutoff;

///////////////////////////////////////////////////////////
//                    Board & Ghost                      //
///////////////////////////////////////////////////////////

extern Ghost Ghosts[10];
extern CPlayer player;

extern int MazeBoard[B_SIZE][B_SIZE];

///////////////////////////////////////////////////////////
//                 Camera & Window                       //
///////////////////////////////////////////////////////////

// 각
extern float angle;

//벡터
extern float lx, lz, ly;

// 이동 변수
extern float deltaAngle;
extern float deltaMove;
extern int xOrigin;

// 높낮이
extern int h, w;

//프레임
extern int frame;
extern long timing, timebase;
extern char s[50];
extern char t[50];

//윈도우
extern int mainWindow, subWindow1, subWindow2, subWindow3;
extern int border;
extern float distribution;

/////////////////////////////////////////////

struct point
{
	float min_x = -15 - 0.5;
	float min_z = -15 + 0.5;
	float max_x = -15 + 0.5;
	float max_z = -15 - 0.5;
};

extern point Collision_Maze[B_SIZE][B_SIZE];

//////////////////////////////////////////////////////////

extern int cageX;
extern int cageY;

// 게임 내 활용
extern float obj_rot;
extern int startingpoint;

// 좌표계산
void computePos(float deltaMove);

void computeDir(float deltaAngle);

// enum

enum ItemState {
	KEY, SPEED, HP, MINIMAP, CUTOFF
};

void LargeView();

void TopView();

void CameraView();


struct Position {
	float fX;
	float fY;
	float fZ;

	Position() {}
	Position(float X, float Y, float Z)		//간편 생성용 생성자
		: fX(X), fY(Y), fZ(Z)
	{}
};