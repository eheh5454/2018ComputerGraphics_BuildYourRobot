#pragma once
#include "stdafx.h"
#include "CollisionBox.h"

//적 유닛 클래스 
class Enermy {
private:
	float size;
	float rotate;
	float x, y, z;
	float m_x, m_y, m_z;
	GLfloat move_time;
	float r_leg_rotate;
	float l_leg_rotate;
	float leg_rotate_speed;
	Collisionbox m_enermy_box;
public:
	Enermy(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _size) :x{ _x }, y{ _y }, z{ _z }, size{ _size }
	{
		m_enermy_box = Collisionbox(x, y, z, size);
		r_leg_rotate = 0.f;
		l_leg_rotate = 0.f;
		leg_rotate_speed = 10.f;
	};

	void Draw()
	{
		glPushMatrix();
		{
			glColor3f(0.f, 8.f, 0.f);
			glTranslatef(x, size, z);
			glRotatef(rotate, 0.f, 1.f, 0.f);

			//바디 
			glutSolidCube(size);

			//머리 
			glPushMatrix();
			{
				glTranslatef(0.f, size * 0.75f, 0.f);
				glutSolidCube(size / 2.f);
				//눈
				glPushMatrix();
				{
					glColor3f(1.f, 0.f, 0.f);
					glTranslatef(size / 8.f, size / 8.f, -size / 4.f);
					glutSolidSphere(size / 16.f, 50, 50);
				}
				glPopMatrix();

				glPushMatrix();
				{
					glColor3f(1.f, 0.f, 0.f);
					glTranslatef(-size / 8.f, size / 8.f, -size / 4.f);
					glutSolidSphere(size / 16.f, 50, 50);
				}
				glPopMatrix();
			}
			glPopMatrix();

			//다리 
			glPushMatrix();
			{
				glColor3f(0.f, 0.f, 0.f);
				glTranslatef(0.f, -size / 2.f, 0.f);

				//오른다리
				glPushMatrix();
				{
					glTranslatef(0.f, size / 2.f, 0.f);
					glRotatef(r_leg_rotate, 1.f, 0.f, 0.f);
					glTranslatef(size / 2.f, -size / 2.f, 0.f);


					glPushMatrix();
					{
						glScalef(1.f, 5.f, 1.f);
						glutSolidCube(size / 5.f);
					}
					glPopMatrix();

					//오른발
					glPushMatrix();
					{
						glTranslatef(0.f, -size / 2.f, -size / 4.f);
						glScalef(1.f, 1.f, 2.f);
						glutSolidCube(size / 5.f);
					}
					glPopMatrix();

				}
				glPopMatrix();

				//왼다리 
				glPushMatrix();
				{
					glTranslatef(0.f, size / 2.f, 0.f);
					glRotatef(l_leg_rotate, 1.f, 0.f, 0.f);
					glTranslatef(-size / 2.f, -size / 2.f, 0.f);

					glPushMatrix();
					{
						glScalef(1.f, 5.f, 1.f);
						glutSolidCube(size / 5.f);
					}
					glPopMatrix();

					//왼발
					glPushMatrix();
					{
						glTranslatef(0.f, -size / 2.f, -size / 4.f);
						glScalef(1.f, 1.f, 2.f);
						glutSolidCube(size / 5.f);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

	void Update(float r_x, float r_y, float r_z) {
		SetAngle(r_x, r_y, r_z);

		r_leg_rotate += leg_rotate_speed;
		l_leg_rotate -= leg_rotate_speed;

		if (r_leg_rotate > 45.f)
			leg_rotate_speed = -leg_rotate_speed;
		if (r_leg_rotate < -45.f)
			leg_rotate_speed = -leg_rotate_speed;

	}

	void SetAngle(float r_x, float r_y, float r_z) {
		GLfloat v1[3] = { 0.f,0.f,-1.f };
		GLfloat v2[3] = { r_x - x,r_y - y, r_z - z };
		GLfloat angle = acosf((v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]) /
			sqrt(pow(v1[0], 2) + pow(v1[1], 2) + pow(v1[2], 2) +
				pow(v2[0], 2) + pow(v2[1], 2) + pow(v2[2], 2)));
		angle = angle * (180.f / PI);

		rotate = (v2[0] * v1[2] - v1[0] * v2[2] > 0.0f) ? angle : -angle;

		GLfloat vector[3] = { r_x, r_y, r_z };
		Move(vector);

	}

	void Move(GLfloat v2[3]) {
		GLfloat vector[3] = { v2[0] - x, v2[1] - y, v2[2] - z };
		GLfloat value = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
		vector[0] /= value;
		vector[1] /= value;
		vector[2] /= value;
		x += vector[0] * ENERMY_SPEED / 2.f;
		z += vector[2] * ENERMY_SPEED / 2.f;
		m_enermy_box.UpdateBox(x, y, z);
	}
	Collisionbox GetEnermyBox()
	{
		return m_enermy_box;
	}
	float GetX()
	{
		return this->x;
	}
	float GetY()
	{
		return this->y;
	}
	float GetZ()
	{
		return this->z;
	}
};