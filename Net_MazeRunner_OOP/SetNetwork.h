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

SetPlayer_Net CSendtoServer() {
	SetPlayer_Net client_player;

	client_player.Pos.fX = player.Camera_x;
	client_player.Pos.fY = player.Camera_y;
	client_player.Pos.fZ = player.Camera_z;

	client_player.uiSerialNum = player.PlayerID;

	return client_player;
}