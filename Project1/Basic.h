#pragma once
#include "stdafx.h"

#define WindowWidth 1600.f
#define WindowHeight 900.f

//원용
#define PI 3.141592f
#define DEG2RAD PI/180.f
#define RAD2DEG 180.f/PI


#define HERO_SIZE		5.f

#define MOVE_SPEED		10.f
#define ENERMY_SPEED	10.f

#define MAX_ENERMY		10
#define MAX_BOSS_BULLET_NUM		500
#define MAX_BULLET				30
#define MAX_POINT				190
#define MAX_Piramid				4
#define MAX_SNOW				200000
#define MAX_OBJECT		MAX_ENERMY+MAX_BULLET+MAX_BOSS_BULLET_NUM+2

#define BOARD_SIZE		150		//바닥 사이즈

#define TITLE_SOUND_NAME "../sound/title.wav"
#define GUN_SOUND_NAME "../sound/gun.wav"
#define START_SOUND_NAME "../sound/start.wav"
#define SWORD_SOUND_NAME "../sound/sword.wav"

#pragma comment(lib,"winmm")
#include <mmsystem.h>

enum GameState {
	title_game,
	select_model,
	start_game,
	win_game,
	lose_game
};
struct Vector2D
{
	GLfloat x;
	GLfloat y;
};

struct Vector3D
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

struct Matirx
{
	Vector3D r1;
	Vector3D r2;
	Vector3D r3;
};


struct save_pos {
	GLfloat m_points[3][3][3];
};

struct Pos
{
	float x, y, z;
};

struct XYZPOS {
	float x, y, z;
};
struct ParticlePos {
	Pos m_pos;
	float m_x, m_y, m_z;
};

enum RobotKey
{
	r_left,
	r_up,
	r_right,
	r_down,
	r_jump,
	r_no
};
