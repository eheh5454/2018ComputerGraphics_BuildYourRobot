#pragma once
#include "stdafx.h"

class UI {
	
	XYZPOS cross[4];
	XYZPOS hp_bar;
	XYZPOS all_object[MAX_OBJECT];
public:
	UI();
	~UI();

	void InitUi();
	void SetCross(bool shoot);// ¹Ýµ¿
	void SetHpBar();
	void SetMiniMap();
	void DrawMiniMap();
	void DrawHpBar();
	void DrawCrossHair();
	void DrawGameState();
	void UpdateMiniMap(int i,XYZPOS pos);
};