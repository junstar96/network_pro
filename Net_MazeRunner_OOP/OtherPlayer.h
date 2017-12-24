#pragma once

class OtherPlayer
{
public:
	float Camera_x, Camera_y, Camera_z;
	int PlayerID;
	float fAngle;
	float fdeltaAngle;
public:
	OtherPlayer();
	~OtherPlayer();

	void Render();
	void Render_Color();
	void SetPosition(float pos_x, float pos_y, float pos_z);
};