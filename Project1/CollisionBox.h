#pragma once
#include "stdafx.h"

class Collisionbox {
public:
	GLfloat x, y, z;
	GLfloat size;

	Collisionbox(){}
	Collisionbox(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _size):x(_x),y(_y),z(_z),size(_size){}

	void Draw() {
		/*glPushMatrix();
		{
			glColor3f(1.f, 0.f, 0.f);
			glutSolidCube(size);
		}
		glPopMatrix();*/
	}

	void UpdateBox(float x, float y, float z)
	{
		this->x = x, this->y = y, this->z = z;
	}

	//충돌박스 충돌체크
	bool Collision_Check(Collisionbox b) {
		GLfloat left_a = x - size / 2;
		GLfloat right_a = x + size / 2;
		GLfloat top_a = z - size / 2;
		GLfloat bottom_a = z + size / 2;

		GLfloat left_b = b.x - b.size / 2;
		GLfloat right_b = b.x + b.size / 2;
		GLfloat top_b = b.z - b.size / 2;
		GLfloat bottom_b = b.z + b.size / 2;

		if (left_a >= right_b)
			return false;
		if (right_a <= left_b)
			return false;
		if (top_a >= bottom_b)
			return false;
		if (bottom_a <= top_b)
			return false;

		return true;
	}

};