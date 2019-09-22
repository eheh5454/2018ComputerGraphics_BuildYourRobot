#pragma once
#include "stdafx.h"

class Wing {
	float size;
public:
	Wing(float size);
	~Wing();

	void Draw(int num);
	float GetSize();
};