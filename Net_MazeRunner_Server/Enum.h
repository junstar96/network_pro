#pragma once

//4���� �𼭸� use for array
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