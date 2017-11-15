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

enum Team {
	TEAM_Red,
	TEAM_Blue,
	TEAM_END
};