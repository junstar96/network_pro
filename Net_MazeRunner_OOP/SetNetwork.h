#pragma once
#include "Player.h"
#include "stdafx.h"

//player
struct SetPlayer_Net {
	unsigned int	uiSerialNum;	//고유번호
	int				iMyTeam;		//팀 소속

	Position		Pos;			//위치값
										//Position	Vector;	//보류
};
