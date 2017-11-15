#pragma once
#include "stdafx.h"

//////////////////////////////////////
//			Input.h					//
//									//
//	게임 작동이 주로 키보드이기에		//
//	마우스 부분은 추가구현 하지		//
//	않는다면 사용하지 않습니다.		//
//									//
//////////////////////////////////////

void Keyboard(unsigned char key, int xx, int yy);
void SpecialKeyboard(int key, int xx, int yy);
void releaseKey(int key, int x, int y);

void MouseMove(int x, int y);
void Mouse(int button, int state, int x, int y);

void init();