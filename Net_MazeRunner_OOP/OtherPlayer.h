#pragma once

class OtherPlayer
{
public:
	float Camera_x, Camera_y, Camera_z;
	int PlayerID;
public:
	OtherPlayer();
	~OtherPlayer();

	void Render(float pos_x, float pos_y, float pos_z);
};