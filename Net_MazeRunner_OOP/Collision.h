#pragma once
#include "stdafx.h"

//////////////////////////////////////
//			Collision.h				//
//									//
//	게임 내 충돌체크를 담당하는 부분을	//
//	모아놓은 cpp입니다.				//
//	1. 플레이어 to 맵(미로 내부)		//
//	2. 플레이어 to 맵(외곽 라인)		//
//	3. 플레이어 to 아이템				//
//	4. 플레이어 to 길(점수 획득용)	//
//	5. 플레이어 to 도착지점			//
//	6. 플레이어 to 유령				//
//	7. 플레이어 to 길(트렉)			//
//									//
//////////////////////////////////////

void collision(point a, int i, int j);
void collision_sideline(point a, int i, int j);
void collision_item(point a);
void collision_endline(point a);
void collision_ghost(float pos_x, float pos_z);
bool collision_track(point a);