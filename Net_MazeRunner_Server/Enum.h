#pragma once

//4개의 모서리 use for array
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