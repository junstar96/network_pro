#pragma once
#include "Player.h"
#include "stdafx.h"

//player
struct SetPlayer_Net {
	unsigned int	uiSerialNum;	//������ȣ
	int				iMyTeam;		//�� �Ҽ�

	Position		Pos;			//��ġ��
										//Position	Vector;	//����
};

SetPlayer_Net CSendtoServer() {
	SetPlayer_Net client_player;

	client_player.Pos.fX = player.Camera_x;
	client_player.Pos.fY = player.Camera_y;
	client_player.Pos.fZ = player.Camera_z;

	client_player.uiSerialNum = player.PlayerID;

	return client_player;
}