#pragma once
class Ghost
{
public:
	Ghost();
	~Ghost();
	float pos_x, pos_y, pos_z;
	float rot_angle;
	float movespeed;
public:
	void SetPosition(float x, float y, float z);
	void SetRotation(float rot_angle);
	void MoveFoward(float deltaMove, float deltaAngle);
	void Render();
};