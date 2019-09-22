#pragma once
#include "stdafx.h"

class Body {
	float size;
public:
	Body(float size);
	~Body();

	void Draw(int num);
	float GetSize();
};