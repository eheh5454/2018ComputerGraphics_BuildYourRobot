#pragma once
#include "stdafx.h"

class Sword {
	float size;
public:
	Sword(float size) :size{ size } {}

	void DrawSword()
	{
		glPushMatrix();
		{
			glPushMatrix();
			{
				glColor3f(0.8f, 0.8f, 0.8f);
				glutSolidCylinder(size / 2, size * 2, size * 5, size * 5);
			}
			glPopMatrix();

			glPushMatrix();
			{
				glColor3f(1.f, 1.f, 1.f);
				glTranslatef(0, 0, size * 2);
				glutSolidCone(size / 2, size * 10, size*5, size * 5);
			}
			glPopMatrix();
		}
		glPopMatrix();
	}

};