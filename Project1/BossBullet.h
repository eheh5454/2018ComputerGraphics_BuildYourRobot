#pragma once
#include "stdafx.h"
#include "CollisionBox.h"

class BossBullet {
private:
	GLfloat x, y, z;
	GLfloat size;
	GLfloat speed;
	Collisionbox box;
	GLfloat vx, vz;

public:
	BossBullet(){}
	BossBullet(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _size, GLfloat _speed, GLfloat _vx, GLfloat _vz): x(_x), y(_y), z(_z), size(_size), speed(_speed), vx(_vx), vz(_vz) {
		box = Collisionbox(x, y, z,size);
		
	}
	Collisionbox GetBox() {
		return box;
	}
	void Draw() {
		glPushMatrix();
		{
			glTranslatef(x, y, z);
			glutSolidSphere(size, 50, 50);
		}
		glPopMatrix();
	}

	void Update()
	{
		x += speed * vx;
		z += speed * vz;
		box.UpdateBox(x, y, z);
	}
	float GetX()
	{
		return x;
	}
	float GetY()
	{
		return y;
	}
	float GetZ()
	{
		return z;
	}
};
