#pragma once
#include "stdafx.h"

//////////////////////////////////////
//			resource.cpp			//
//									//
//	���ӿ��� Ȱ��Ǵ� resource����	//
//	��Ƴ��� cpp�Դϴ�.				//
//	0. ����, ��, ũ�� define		//
//	1. �ʿ��� ���Ǵ� Obj			//
//	2. ����(Projection)���� �Լ�		//
//	3. ��Ʈ��(�۾�), �ؽ���(�׸�)		//
//									//
//////////////////////////////////////

#define SOUND_FILE_NAME			"sound/item.wav"
#define SOUND_FILE_NAME_ON		"sound/on.wav"
#define SOUND_FILE_NAME_BGM_1	"sound/bgm_1.wav"
#define SOUND_FILE_NAME_FINISH	"sound/finish.wav"
#define SOUND_FILE_NAME_DARK	"sound/dark.wav"
#define SOUND_FILE_NAME_FAIL	"sound/IB.wav"
#define SOUND_FILE_NAME_CRASH	"sound/crash.wav"
#define SOUND_FILE_NAME_MORNING "sound/morning.wav"

#define MAP_1 "MAP_Veryeasy.txt"
#define MAP_2 "MAP_Easy.txt"
#define MAP_3 "MAP_Normal.txt"
#define MAP_4 "MAP_Hard.txt"
#define MAP_5 "MAP_Veryhard.txt"
#define NET_MAP "MAP_NET.txt"
#define MAP_TEST "MAP_TEST.txt"

#define B_SIZE 30 // �� ������
#define PLAYERMAX 4
#define GHOSTMAX 10

enum fourEdge {
	EDGE_Left,
	EDGE_Right,
	EDGE_Top,
	EDGE_Bottom,
	EDGE_END
};

//��Ÿ�� ����
enum BlockType {
	BLOCK_Empty,	//�Ϲ� ��
	BLOCK_Wall,		//��
	BLOCK_Item,		//������
	BLOCK_Goal,		//������
	BLOCK_Track,	//������
	BLOCK_Blocked,	//���� �� ���� ��
};

//���� ��
enum Team {
	TEAM_Red,
	TEAM_Blue,
	TEAM_END
};

//���ӿ�����Ʈ
enum eGameObj {
	OBJ_PLAYER,
	OBJ_MAZE,
	OBJ_GHOST,
	OBJ_end
};

void Draw_GhostObj();

void Draw_PlayerObj();

void Draw_MazeObj();

void Draw_SideLineObj();

void Draw_TrackObj();

void Draw_PlaneObj();

void Draw_Greed(void);

void Draw_Item();

void Draw_Cage();

void startinit();

// Projection

void setProjection(int w, int h);

void restorePerspectiveProjection();

void setOrthographicProjection();

// ��Ʈ�� String
void renderBitmapString(float x, float y, float z, void *font, char *string);

//extern GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info);


///////////////////////////
//       �ؽ���			 //
///////////////////////////


//extern GLubyte *LoadDIBitmap(const char *filename, BITMAPINFO **info);
//extern GLubyte *pBytes; // �����͸� ����ų ������
//extern BITMAPINFO *info; // ��Ʈ�� ��� ������ ����
//extern GLuint textures[2];
//void initTextures();
/////////////////////////////
//
//// �ؽ��� �ʱ�ȭ
//void initTextures();
//
//void draw_hp();