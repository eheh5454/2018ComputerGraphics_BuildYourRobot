#pragma once
#include "stdafx.h"
#include "Gun.h"
#include "Sword.h"

class Arm{
	float size;
	float arm_leg_angle;
	float s_angle;

	Gun* m_gun;
	Sword* m_sword;
public:
	Arm(float size);
	~Arm();
	
	void Update(float arm_leg_angle);
	void Draw(int num);
	float GetSize();
	void AttackUpdate(float angle);
};