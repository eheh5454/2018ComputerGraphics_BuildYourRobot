#include "stdafx.h"
#include "Leg.h"

Leg::Leg(float size) : size{ size }
{
	arm_leg_angle = 0;
}
Leg::~Leg()
{

}
float Leg::GetSize()
{
	return size;
}
void Leg::Update(float arm_leg_angle)
{
	this->arm_leg_angle = arm_leg_angle;
}
void Leg::Draw(int num)
{
	glPushMatrix();//다리
	{
		switch (num)
		{
		case 1:
			glPushMatrix();
			{
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glTranslatef(-size * 2 / 3, size, 0);//여기서부터 다리 움직임 
				glRotatef(arm_leg_angle, 1, 0, 0);//다리 움직임용
				glScalef(1, 2, 1);
				glutSolidCube(size / 2);
				glScalef(1, 0.5, 1);
				glPushMatrix();//발
				{
					glTranslatef(0, -size / 2, 0);
					glColor4f(0.f, 0.f, 1.f, 1.f);
					glutWireCube(size);
					glColor4f(1.f, 1.f, 1.f, 1.f);
					glutSolidCube(size);
					glPushMatrix();//발앞
					{
						glTranslatef(0, 0, -size / 3);
						glPushMatrix();
						{
							glTranslatef(0, -size * 0.325, size / 5);
							glColor4f(0, 0, 1, 1);
							glScalef(0.7, 0.325, 1.015);
							glutSolidSphere(size, size, size);
						}
						glPopMatrix();
						glColor4f(1.f, 1.f, 1.f, 1.f);
						glScalef(1, 1, 2);
						glutSolidTorus(size / 3, size / 5, size, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//다리
			{
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glTranslatef(size * 2 / 3, size, 0);//여기서부터 다리 움직임 
				glScalef(1, 2, 1);
				glRotatef(-arm_leg_angle, 1, 0, 0);//다리 움직임용
				glutSolidCube(size / 2);
				glScalef(1, 0.5, 1);
				glPushMatrix();//발
				{
					glTranslatef(0, -size / 2, 0);
					glColor4f(0.f, 0.f, 1.f, 1.f);
					glutWireCube(size);
					glColor4f(1.f, 1.f, 1.f, 1.f);
					glutSolidCube(size);
					glPushMatrix();//발앞
					{
						glTranslatef(0, 0, -size / 3);
						glPushMatrix();
						{
							glTranslatef(0, -size * 0.325, size / 5);
							glColor4f(0, 0, 1, 1);
							glScalef(0.7, 0.325, 1.015);
							glutSolidSphere(size, size, size);
						}
						glPopMatrix();
						glColor4f(1.f, 1.f, 1.f, 1.f);
						glScalef(1, 1, 2);
						glutSolidTorus(size / 3, size / 5, size, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			break;
		case 2:
			glPushMatrix();
			{
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glTranslatef(-size * 2 / 3, size, 0);//여기서부터 다리 움직임 
				glRotatef(arm_leg_angle, 1, 0, 0);//다리 움직임용
				glScalef(1, 2, 1);
				glutSolidCube(size / 2);
				glScalef(1, 0.5, 1);
				glPushMatrix();//발
				{
					glTranslatef(0, -size / 2, 0);
					glColor4f(1, 0, 0, 1);
					glutWireCube(size);
					glColor4f(1.f, 1.f, 1.f, 1.f);
					glutSolidCube(size);
					glPushMatrix();//발앞
					{
						glTranslatef(0, 0, -size / 3);
						glPushMatrix();
						{
							glTranslatef(0, -size * 0.325, size / 5);
							glColor4f(1, 0, 0, 1);
							glScalef(0.7, 0.325, 1.015);
							glutSolidSphere(size, size, size);
						}
						glPopMatrix();
						glColor4f(1.f, 1.f, 1.f, 1.f);
						glScalef(1, 1, 2);
						glutSolidTorus(size / 3, size / 5, size, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//다리
			{
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glTranslatef(size * 2 / 3, size, 0);//여기서부터 다리 움직임 
				glScalef(1, 2, 1);
				glRotatef(-arm_leg_angle, 1, 0, 0);//다리 움직임용
				glutSolidCube(size / 2);
				glScalef(1, 0.5, 1);
				glPushMatrix();//발
				{
					glTranslatef(0, -size / 2, 0);
					glColor4f(1, 0, 0, 1);
					glutWireCube(size);
					glColor4f(1.f, 1.f, 1.f, 1.f);
					glutSolidCube(size);
					glPushMatrix();//발앞
					{
						glTranslatef(0, 0, -size / 3);
						glPushMatrix();
						{
							glTranslatef(0, -size * 0.325, size / 5);
							glColor4f(1, 0, 0, 1);
							glScalef(0.7, 0.325, 1.015);
							glutSolidSphere(size, size, size);
						}
						glPopMatrix();
						glColor4f(1.f, 1.f, 1.f, 1.f);
						glScalef(1, 1, 2);
						glutSolidTorus(size / 3, size / 5, size, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			break;
		case 3:
			glPushMatrix();
			{
				glColor4f(0, 0.3, 0.3, 1);
				glTranslatef(-size * 2 / 3, size, 0);//여기서부터 다리 움직임 
				glRotatef(arm_leg_angle, 1, 0, 0);//다리 움직임용
				glScalef(1, 2, 1);
				glutSolidCube(size / 2);
				glScalef(1, 0.5, 1);
				glPushMatrix();//발
				{
					glTranslatef(0, -size / 2, 0);
					glColor4f(0, 0, 0, 1);
					glutWireCube(size);
					glColor4f(0, 0.3, 0.3, 1);
					glutSolidCube(size);
					glPushMatrix();//발앞
					{
						glTranslatef(0, 0, -size / 3);
						glPushMatrix();
						{
							glTranslatef(0, -size * 0.325, size / 5);
							glColor4f(0, 0.3, 0.3, 1);
							glScalef(0.7, 0.325, 1.015);
							glutSolidSphere(size, size, size);
						}
						glPopMatrix();
						glColor4f(0, 0.3, 0.3, 1);
						glScalef(1, 1, 2);
						glutSolidTorus(size / 3, size / 5, size, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//다리
			{
				glColor4f(0, 0.3, 0.3, 1);
				glTranslatef(size * 2 / 3, size, 0);//여기서부터 다리 움직임 
				glScalef(1, 2, 1);
				glRotatef(-arm_leg_angle, 1, 0, 0);//다리 움직임용
				glutSolidCube(size / 2);
				glScalef(1, 0.5, 1);
				glPushMatrix();//발
				{
					glTranslatef(0, -size / 2, 0);
					glColor4f(0, 0, 0, 1);
					glutWireCube(size);
					glColor4f(0, 0.3, 0.3, 1);
					glutSolidCube(size);
					glPushMatrix();//발앞
					{
						glTranslatef(0, 0, -size / 3);
						glPushMatrix();
						{
							glTranslatef(0, -size * 0.325, size / 5);
							glColor4f(0, 0.3, 0.3, 1);
							glScalef(0.7, 0.325, 1.015);
							glutSolidSphere(size, size, size);
						}
						glPopMatrix();
						glColor4f(0, 0.3, 0.3, 1);
						glScalef(1, 1, 2);
						glutSolidTorus(size / 3, size / 5, size, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			break;
		}
		
	}
	glPopMatrix();
}