#pragma once
#include "stdafx.h"

class Head {
	float size;
public:
	Head(float size);
	~Head();

	void Draw(int num);
	float GetSize();
};