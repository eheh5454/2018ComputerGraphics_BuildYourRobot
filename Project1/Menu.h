#pragma once
#include "stdafx.h"
#include "Select_Part.h"

class Menu {
	GLfloat diffuse[4] = { 1.f,1.f,1.f,1.f };
	GLfloat amb[4] = { 0.f,0.f,0.f,1.f };
	GLfloat spc[4] = { 1.f,1.f,1.f,1.f };
	GLfloat title_lightpos[4] = { 0.f, 600.f, 180.f, 1.f };
	GLfloat spot_dir[4] = { 0.f,-1.f,0.f,1.f };

public:
	Menu();
	~Menu();

	Select_Part up_sp;
	Select_Part middle_sp;
	Select_Part down_sp;

	void DrawMenu();
};