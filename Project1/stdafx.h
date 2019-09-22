#pragma once
// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

#include <tchar.h>
#include <gl/freeglut.h>
#include <iostream>
#include <random>
#include <ctime>
#include <time.h>
#include <cmath>
#include <random>
#include "Basic.h"

extern int boss_hp;
extern int player_view;
extern int hp;
extern GameState now_game_state;

extern bool s_or_g;
extern int arm_num;
extern int head_num;
extern int body_num;
extern int leg_num;
extern int parts_num;
