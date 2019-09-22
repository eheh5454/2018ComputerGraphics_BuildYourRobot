#pragma once
#include "stdafx.h"

class Leg{
	float size;
	float arm_leg_angle;
public:
	Leg(float size);
	~Leg();

	void Update(float arm_leg_angle);
	void Draw(int num);
	float GetSize();
};