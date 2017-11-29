#pragma once
#include "CForServer.h"

class CSendTo
{
private:
	ForPingPong S_Server_Data;

public:
	bool SendPlayerInfo(SOCKET& sock);
	bool SendMapInfo(SOCKET& sock);
	bool SendGhostInfo(SOCKET& sock);
	bool SendOtherInfo(SOCKET& sock);

	void get_maze(int i, int j, int get_map)
	{
		S_Server_Data.MazeArray[i][j].iStatus = get_map;
	}

	
	void set_forpingpong(ForPingPong*);
	ForPingPong* get_forpingpong(void);
public:
	CSendTo();
	~CSendTo();
};

