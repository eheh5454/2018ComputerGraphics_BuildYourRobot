#pragma once
#include "stdafx.h"
#include "Arm.h"
#include "Leg.h"
#include "Wing.h"
#include "Body.h"
#include "Head.h"
#include "CollisionBox.h"
#include "Particle.h"

class Robot {
	Collisionbox m_player_box;
	Collisionbox m_sword_box;
	Particle* m_particle[100];
	Arm* m_arm;
	Leg* m_leg;
	Body* m_body;
	Wing* m_wing;
	Head* m_head;
	float l_size;
	GLenum gl_light_num;

	int select_head, select_body, select_leg;
	
	bool light_3;
	bool light_4;
	float c_r, c_g, c_b, c_a;
	GLfloat Pos1[4];
	GLfloat SportLightDirection[3];
	GLfloat AmbientLight3[4]; //주변 조명
	GLfloat SportLightExponent;
	GLfloat SportLightCutOff;
	GLfloat DiffuseLight3[4]; // 산란반사 조명
	GLfloat SpecularLight3[4]; // 거울반사 조명

	float x, y, z;
	float move_x, move_z, move_y;
	float size;
	float scale;
	RobotKey r_key;
	float angle = 180;
	float arm_leg_angle = 0;
	float jump_angle = 0;
	bool limit = false;
	bool arm_leg_limit = false;
	bool collison = false;
public:
	Robot(float x, float y, float z, float size);
	void Init();
	BOOL UpdateY();
	void SetY(float y);
	void UpdateMove();
	void DrawRobot();
	void KeyUpdate(float x, float z);
	Collisionbox GetPlayerBox();
	Collisionbox GetPlayerAttackBox();
	void SetArmLegAngle(float angle);
	void CheckCollison(bool check);
	BOOL GetRobotCheck();
	float GetX();
	float GetY();
	float GetZ();
	void AttackUpdate(float angle);
	void Select_Parts(int head, int body, int leg);
};