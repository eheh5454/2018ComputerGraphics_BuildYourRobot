#pragma once
#include "stdafx.h"
#include "CollisionBox.h"

class Bullet {
	bool what_view_make;
	bool collision;
	float x, y, z;
	float m_x, m_y, m_z;
	float size;
	Collisionbox m_player_bullet;
public:
	Bullet(float size, float x, float y, float z,float c_x_angle,float c_y_angle,bool what_view);
	~Bullet();

	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);
	void SetMX(float m_x);
	void SetMY(float m_y);
	void SetMZ(float m_z);
	void SetSize(float size);
	
	float GetX();
	float GetY();
	float GetZ();
	float GetMX();
	float GetMY();
	float GetMZ();
	float GetSize();

	Collisionbox GetPlayerBulletBox();
	BOOL GetOutOfMap();
	void UpdateBullet();
	void DrawBullet();
};
