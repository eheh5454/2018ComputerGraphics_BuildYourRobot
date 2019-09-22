#pragma once
#include "stdafx.h"
#include "Robot.h"

class Title
{
	char title[100] = " Build Your Robot";
	char click[100] = " Click To Start";
	int title_len;
	int click_len;
	Robot *robot;
	
public:
	Title();
	~Title();

	void Draw();
};

