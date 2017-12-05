#include "stdafx.h"
#include "Network.h"

///////////////////////////////////////////////////////////
//                     Sub Menu                          //
///////////////////////////////////////////////////////////

float speedup = 0;
int Level_Key = 0;
int Level_Speed = 0;
int Level_HP = 0;
int Level_Minimap = 1;
int item_rand = 8;

clock_t start, finish;

//bool 값
bool isGreed = true;
bool isItem = false;
bool isLine = false;
bool isShading = true;
bool isDepth = true;
bool isCulling = true;
bool isPlayGame = false;
bool isNetwork = false;

///////////////////////////////////////////////////////////
//                     Lookat
///////////////////////////////////////////////////////////

float look_x = 0;
float look_y = 0;
float look_z = -3;
float center_x = 0;
float center_y = 0;
float center_z = -100;
float up_x = 0;
float up_y = 1;
float up_z = 0;

///////////////////////////////////////////////////////////
//                   Light & Fog
///////////////////////////////////////////////////////////

float ambientL = 0.2;
float diffuseL = 0.7;
float specularL = 0.9;
int timef = 100;

bool Bool_Sun = true;
int Light_rot = 0;

GLfloat fog_color[4] = { static_cast<float>(0.18), static_cast<float>(0.18), static_cast<float>(0.18), static_cast<float>(0.3) };
GLfloat density = 0.3;
GLfloat start_fog = -4.0;
GLfloat end_fog = 4.0;

int cutoff = 10;

///////////////////////////////////////////////////////////
//                    Board & Ghost                      //
///////////////////////////////////////////////////////////

int MazeBoard[B_SIZE][B_SIZE] = { 0 };
Ghost Ghosts[10];
CPlayer player;
///////////////////////////////////////////////////////////
//                 Camera & Window                       //
///////////////////////////////////////////////////////////

// 각
float angle = 0.0f;

//벡터
float lx = 0.0f, lz = -1.0f, ly = 0.0f;

// 이동 변수
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

// 높낮이
int h, w;

//프레임
int frame;
long timing, timebase;
char s[50];
char t[50];

int mainscore = 0;

//윈도우
int mainWindow, subWindow1, subWindow2, subWindow3;
int border = 6;
float distribution = 0.5;

float obj_rot = 0;
int startingpoint = 0;

/////////////////////////////////////////////

point Collision_Maze[B_SIZE][B_SIZE];

//////////////////////////////////////////////////////////

// 메뉴선택 바
int cageX = -55;
int cageY = -65;

// 좌표계산
void computePos(float deltaMove)
{

	player.Camera_x += deltaMove * lx * 0.1f;
	player.Camera_z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void LargeView()
{
	look_x = 0.00001;
	look_y = 13;
	look_z = 9;
	center_x = 0;
	center_y = -130;
	center_z = -200;
	up_x = 0;
	up_y = 1;
	up_z = 0;
}

void TopView()
{
	look_x = 0.00001;
	look_y = 30;
	look_z = 0.00001;
	center_x = 0;
	center_y = 1;
	center_z = 0;
	up_x = 0;
	up_y = -1;
	up_z = 0;
}

void CameraView()
{
	look_x = 0;
	look_y = 0;
	look_z = -3;
	center_x = 0;
	center_y = 0;
	center_z = -100;
	up_x = 0;
	up_y = 1;
	up_z = 0;
}