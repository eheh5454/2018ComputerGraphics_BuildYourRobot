#pragma once
#include "stdafx.h"

class Gun {
	float size;
	float angle;

public:
	Gun(float size): size{ size }
	{
		angle = 0;
	}
	void DrawGun()
	{
		glPushMatrix();
		{
			glRotatef(angle, 0, 0, 0);
			glPushMatrix();
			{
				glPushMatrix();
				{
					glTranslatef(size * 2, -size * 2, 0);
					glScalef(2, 2, 1);
					glColor3f(0.1, 0.1, 0.1);
					glutSolidCube(size);
					glLineWidth(8.f);
					glColor3f(0.25, 0.25, 0.25);
					glutWireCube(size);
					glLineWidth(1.f);
				}
				glPopMatrix();

				glPushMatrix();
				{
					glTranslatef(size * 2, size, 0);
					glPushMatrix();
					{
						glTranslatef(0, size / 3, 0);
						glScalef(1, 0.25, 0.125);
						glColor3f(1, 0, 0);
						glutSolidCube(size);
					}
					glPopMatrix();
					glScalef(1, 0.5, 0.25);
					glColor3f(0.25, 0.25, 0.25);
					glutSolidCube(size);
				}
				glPopMatrix();



				glPushMatrix();//ÃÑ±¸
				{
					glTranslatef(-size * 3, size / 2, 0);
					glScalef(1, 0.5, 0.5);
					glColor3f(0.25, 0.25, 0.25);
					glutSolidCube(size);

					glLineWidth(8.f);
					glColor3f(0, 0, 0);
					glutWireCube(size);
					glLineWidth(1.f);
				}
				glPopMatrix();

				glPushMatrix();
				{
					glTranslatef(-size * 2, 0, -size / 1.5);
					glScalef(2, 1, 0.5);

					glColor3f(0.25, 0.25, 0.25);
					glutSolidCube(size);

					glLineWidth(8.f);
					glColor3f(0.5, 0.5, 0.5);
					glutWireCube(size);
					glLineWidth(1.f);
				}
				glPopMatrix();

				glPushMatrix();
				{
					glTranslatef(-size * 2, 0, size / 1.5);
					glScalef(2, 1, 0.5);

					glColor3f(0.25, 0.25, 0.25);
					glutSolidCube(size);

					glLineWidth(8.f);
					glColor3f(0.5, 0.5, 0.5);
					glutWireCube(size);
					glLineWidth(1.f);
				}
				glPopMatrix();

				glPushMatrix();
				{
					glLineWidth(8.f);
					glColor3f(1, 1, 1);
					glTranslatef(0, size / 2, 0);
					glScalef(6, 1, 1);
					glutWireCube(size);
					glLineWidth(1.f);
					glColor3f(0, 0, 0);
					glutSolidCube(size);
				}
				glPopMatrix();
				glColor3f(0.1, 0.1, 0.1);
				glScalef(6, 2, 1);
				glutSolidCube(size);
				glLineWidth(8.f);
				glColor3f(0.25, 0.25, 0.25);
				glutWireCube(size);
				glLineWidth(1.f);
			}
			glPopMatrix();
		}
		glPopMatrix();

	}
};