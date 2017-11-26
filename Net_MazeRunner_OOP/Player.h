#pragma once

class CPlayer
{
public:
	float Camera_x, Camera_y, Camera_z;
	int PlayerID;
public:
	CPlayer();
	~CPlayer();

	void SetPosition();
	void Render();
};

