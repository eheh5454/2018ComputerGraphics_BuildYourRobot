#include "stdafx.h"
#include "Robot.h"

Robot::Robot(float x, float y, float z, float size) : x(x), y(y), z(z), size(size)
{
	select_head = 1;
	select_body = 1;
	select_leg = 1;

	{
		m_arm = new Arm(size);
		m_leg = new Leg(size);
		m_wing = new Wing(size);
		m_body = new Body(size);
		m_head = new Head(size);
	}

	m_player_box = Collisionbox(this->x, this->y, this->z, this->size);
	m_sword_box = Collisionbox(this->x, this->y, this->z, this->size+30);
	l_size = size;
	Pos1[0] = x;
	Pos1[1] = y+100;
	Pos1[2] = z;
	Pos1[3] = 1;

	AmbientLight3[0] = 1;
	AmbientLight3[1] = 1;
	AmbientLight3[2] = 1;
	AmbientLight3[3] = 1;

	SpecularLight3[0] = 0;
	SpecularLight3[1] = 0;
	SpecularLight3[2] = 0;
	SpecularLight3[3] = 1;

	DiffuseLight3[0] = 1;
	DiffuseLight3[1] = 1;
	DiffuseLight3[2] = 1;
	DiffuseLight3[3] = 1;

	SportLightDirection[0] = 0;
	SportLightDirection[1] = -1;
	SportLightDirection[2] = 0;

	SportLightExponent = 0;
	SportLightCutOff = 20;


	c_r = 0.1, c_g = 0.1, c_b = 0.1, c_a = 0.1;
	light_3 = true;
	light_4 = true;
	move_y = 0;
	
	for (int i = 0; i < 100; ++i)
	{
		m_particle[i] = NULL;
	}
}

void Robot::SetY(float y)
{
	this->y = 0;
}
void Robot::Init()
{
	for (int i = 0; i < 100; ++i)
	{
		m_particle[i] = NULL;
	}
	x = 0, y = 0, z = 0;
	move_y = 0;
	r_key = r_no;
	angle = 180;
	arm_leg_angle = 0;
	jump_angle = 0;
	limit = false;
	arm_leg_limit = false;
}
void Robot::CheckCollison(bool check)
{
	this->collison = check;
	if (collison)
	{
		//std::cout << "Ãæµ¹" << std::endl;
		for (int i = 0; i < 100; ++i)
		{
			m_particle[i] = new Particle(x, y, z, size);
		}
	}
}
BOOL Robot::GetRobotCheck()
{
	return this->collison;
}
void Robot::SetArmLegAngle(float angle)
{
	this->arm_leg_angle = angle;
}
void Robot::UpdateMove()
{
	for (int i = 0; i < 100; ++i)
	{
		if (m_particle[i] != NULL)
			m_particle[i]->Update();
	}
	if (!this->arm_leg_limit)
	{
		this->arm_leg_angle += 2.f;
		if (this->arm_leg_angle >= 30.f)
		{
			this->arm_leg_limit = true;
		}
		m_arm->Update(arm_leg_angle);
		m_leg->Update(arm_leg_angle);
	}
	else if (this->arm_leg_limit)
	{
		this->arm_leg_angle -= 2.f;
		if (this->arm_leg_angle <= -30.f)
		{
			this->arm_leg_limit = false;
		}
		m_arm->Update(arm_leg_angle);
		m_leg->Update(arm_leg_angle);
	}
}
Collisionbox Robot::GetPlayerAttackBox()
{
	return m_sword_box;
}
BOOL Robot::UpdateY()
{
	if (!this->limit)
	{
		this->y += 2.f;
		if (this->y >= 30.f)
		{
			this->limit = true;
			return true;
		}
	}
	else if (this->limit)
	{
		this->y -= 2.f;
		if (this->y <= 0.f)
		{
			this->y = 0;
			this->limit = false;
			return false;
		}
	}
}
void Robot::KeyUpdate(float x, float z)
{
	this->x = x, this->z = z;
	m_player_box.UpdateBox(x, y, z);
	m_sword_box.UpdateBox(x, y, z);
	UpdateMove();
}
void Robot::DrawRobot()
{
	/*glMateriali(GL_FRONT, GL_SHININESS, 128);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);*/
	/*glPushMatrix();
	{
		glLightfv(GL_LIGHT3, GL_AMBIENT, AmbientLight3);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, DiffuseLight3);
		glLightfv(GL_LIGHT3, GL_SPECULAR, SpecularLight3);
		glLightfv(GL_LIGHT3, GL_POSITION, Pos1);
		if (light_3)
			glEnable(GL_LIGHT3);
		else if (!light_3)
			glDisable(GL_LIGHT3);
	}
	glPopMatrix();*/

	glPushMatrix();
	{
		for (int i = 0; i < 100; ++i)
		{
			if (m_particle[i] != NULL)
				m_particle[i]->DrawParticle();
		}
	}
	glPopMatrix();
	
	if (now_game_state == title_game)
	{
		m_head->Draw(1);
		m_body->Draw(1);
		m_arm->Draw(1);
		m_leg->Draw(1);
	}
	else
	{
		if (player_view == 2)
			glTranslatef(-size * 1.5, 0, size);
		if (player_view != 1)
			m_head->Draw(select_head);
		m_body->Draw(select_body);
		m_arm->Draw(select_body);
		m_leg->Draw(select_leg);
	}

	//================================
	
	
}
Collisionbox Robot::GetPlayerBox()
{
	return m_player_box;
}
float Robot::GetX()
{
	return x;
}
float Robot::GetY()
{
	return y;
}
float Robot::GetZ()
{
	return z;
}
void Robot::AttackUpdate(float angle)
{
	m_arm->AttackUpdate(angle);
}

void Robot::Select_Parts(int head, int body, int leg)
{
	select_head = head;
	select_body = body;
	select_leg = leg;
}