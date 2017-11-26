#pragma once
#include "stdafx.h"

//////////////////////////////////////
//			resource.cpp			//
//									//
//	게임에서 활용되는 resource들을	//
//	모아놓은 cpp입니다.				//
//	0. 사운드, 맵, 크기 define		//
//	1. 맵에서 사용되는 Obj			//
//	2. 투영(Projection)관련 함수		//
//	3. 비트맵(글씨), 텍스쳐(그림)		//
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

#define B_SIZE 30 // 맵 사이즈
#define PLAYERMAX 4
#define GHOSTMAX 10

enum fourEdge {
	EDGE_Left,
	EDGE_Right,
	EDGE_Top,
	EDGE_Bottom,
	EDGE_END
};

//블럭타입 변수
enum BlockType {
	BLOCK_Empty,	//일반 길
	BLOCK_Wall,		//벽
	BLOCK_Item,		//아이템
	BLOCK_Goal,		//목적지
	BLOCK_Track,	//발자취
	BLOCK_Blocked,	//나갈 수 없는 길
};

//나의 팀
enum Team {
	TEAM_Red,
	TEAM_Blue,
	TEAM_END
};

//게임오브젝트
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

// 비트맵 String
void renderBitmapString(float x, float y, float z, void *font, char *string);

//extern GLubyte * LoadDIBitmap(const char *filename, BITMAPINFO **info);


///////////////////////////
//       텍스쳐			 //
///////////////////////////


//extern GLubyte *LoadDIBitmap(const char *filename, BITMAPINFO **info);
//extern GLubyte *pBytes; // 데이터를 가리킬 포인터
//extern BITMAPINFO *info; // 비트맵 헤더 저장할 변수
//extern GLuint textures[2];
//void initTextures();
/////////////////////////////
//
//// 텍스쳐 초기화
//void initTextures();
//
//void draw_hp();