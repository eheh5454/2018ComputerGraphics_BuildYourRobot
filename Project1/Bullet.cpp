#include "Bullet.h"


Bullet::Bullet(float size, float x, float y, float z, float c_x_angle, float c_y_angle, bool what_view) :what_view_make{what_view} // 현재 캐릭터의 위치값, true 면 1인칭
{
	collision = false;
	this->size = size / 2;
	this->x = x, this->y = y, this->z = z;
	if (c_y_angle <= -170.f)
		c_y_angle = -160.f;
	this->m_x = size * sin((c_y_angle)* DEG2RAD) * sin((c_x_angle)* DEG2RAD)*2;
	this->m_y = size * cos((c_y_angle)* DEG2RAD)*2;
	this->m_z = size * sin((c_y_angle)* DEG2RAD) * cos((c_x_angle)* DEG2RAD)*2;

	m_player_bullet = Collisionbox(this->x, this->y, this->z, this->size);

}
Bullet::~Bullet()
{

}

void Bullet::SetX(float x)
{
	this->x = x;
}
void Bullet::SetY(float y)
{
	this->y = y;
}
void Bullet::SetZ(float z)
{
	this->z = z;
}
void Bullet::SetMX(float m_x)
{
	this->m_x = m_x;
}
void Bullet::SetMY(float m_y)
{
	this->m_y = m_y;
}
void Bullet::SetMZ(float m_z)
{
	this->m_z = m_z;
}
void Bullet::SetSize(float size)
{
	this->size = size;
}

float Bullet::GetX()
{
	return x;
}
float Bullet::GetY()
{
	return y;
}
float Bullet::GetZ()
{
	return z;
}
float Bullet::GetMX()
{
	return m_x;
}
float Bullet::GetMY()
{
	return m_y;
}
float Bullet::GetMZ()
{
	return m_z;
}
float Bullet::GetSize()
{
	return size;
}

void Bullet::UpdateBullet()
{
	if (what_view_make)
	{
		x += m_x, y += m_y, z += m_z;
		m_player_bullet.UpdateBox(x, y, z);
		if (x <= -WindowWidth || x >= WindowWidth || y <= 0 || y >= WindowHeight / 2 || z <= -WindowWidth || z >= WindowWidth)
		{
			collision = true;
		}
	}
	else
	{
		x += (m_x*4), z += (m_z*4);
		m_player_bullet.UpdateBox(x, y, z);
		if (x <= -WindowWidth || x >= WindowWidth || z <= -WindowWidth || z >= WindowWidth)
		{
			collision = true;
		}
	}
	
}
void Bullet::DrawBullet()
{
	glPushMatrix();
	{
		glColor3f(0.7f, 0.7f, 0.7f);
		glTranslatef(x, y+(size*20), z);
		glutSolidSphere(size, size * 2, size * 2);
	}
	glPopMatrix();
}
BOOL Bullet::GetOutOfMap() // 화면 밖용
{
	return this->collision;
}
Collisionbox Bullet::GetPlayerBulletBox()
{
	return m_player_bullet;
}