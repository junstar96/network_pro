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
