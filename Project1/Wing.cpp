#include "stdafx.h"
#include "Wing.h"

Wing::Wing(float size) : size{ size }
{

}
Wing::~Wing()
{

}
float Wing::GetSize()
{
	return size;
}
void Wing::Draw(int num)
{
	glPushMatrix();//陳偃
	{
		glPushMatrix();
		{
			glTranslatef(0, size * 9 / 2 + (size / 2), 0);
			glPushMatrix();
			{
				glPushMatrix();
				{
					glRotatef(15, 0, 0, 1);
					glTranslatef(size, size, size * 2);
					glRotatef(0, 0, 0, 1);
					glTranslatef(size / 2, 0, size / 2);
					glRotatef(0, 0, 0, 1);
					glRotatef(45, 1, 0, 0);
					glRotatef(size, 1, 0, 0);
					glPushMatrix();
					{
						glColor4f(1, 1, 1, 1);
						glutWireCone(size / 2, size * 5, 4, 1);
						glColor4f(0, 0, 1, 1);
						glutSolidCone(size / 2, size * 5, 4, 1);
					}
					glPopMatrix();
					//陳偃壽
					glRotatef(-180, 1, 0, 0);
					glColor4f(1, 1, 1, 1);
					glutWireCone(size / 2, size * 3, 4, 1);
					glColor4f(0, 0, 1, 1);
					glutSolidCone(size / 2, size * 3, 4, 1);
				}
				glPopMatrix();
				glPushMatrix();
				{
					glRotatef(-15, 0, 0, 1);
					glPushMatrix();
					{
						glTranslatef(-size, size, size * 2);
						glRotatef(0, 0, 0, 1);
						glTranslatef(-size / 2, 0, size / 2);
						glRotatef(0, 0, 0, 1);
						glRotatef(45, 1, 0, 0);
						glRotatef(size, 1, 0, 0);
						glPushMatrix();
						{
							glColor4f(1, 1, 1, 1);
							glutWireCone(size / 2, size * 5, 4, 1);
							glColor4f(0, 0, 1, 1);
							glutSolidCone(size / 2, size * 5, 4, 1);
						}
						glPopMatrix();
						//陳偃壽
						glRotatef(-180, 1, 0, 0);
						glColor4f(1, 1, 1, 1);
						glutWireCone(size / 2, size * 3, 4, 1);
						glColor4f(0, 0, 1, 1);
						glutSolidCone(size / 2, size * 3, 4, 1);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();
		{
			glPushMatrix();
			{
				glTranslatef(0, size * 3, size * 2);
				glRotatef(0, 0, 0, 1);
				glTranslatef(size / 2, 0, size / 2);
				glRotatef(0, 0, 0, 1);
				glRotatef(45, 1, 0, 0);
				glRotatef(size, 1, 0, 0);
				glPushMatrix();					//陳偃壽
				{
					glColor4f(1, 1, 1, 1);
					glutWireCone(size / 2, size * 3, 4, 1);
					glColor4f(0, 0, 1, 1);
					glutSolidCone(size / 2, size * 3, 4, 1);
				}
				glPopMatrix();

				glRotatef(180, 1, 0, 0);
				glColor4f(1, 1, 1, 1);
				glutWireCone(size / 2, size * 3, 4, 1);
				glColor4f(0, 0, 1, 1);
				glutSolidCone(size / 2, size * 3, 4, 1);
			}
			glPopMatrix();
			glPushMatrix();
			{
				glTranslatef(0, size * 3, size * 2);
				glRotatef(0, 0, 0, 1);
				glTranslatef(-size / 2, 0, size / 2);
				glRotatef(0, 0, 0, 1);
				glRotatef(45, 1, 0, 0);
				glRotatef(size, 1, 0, 0);
				glPushMatrix();					//陳偃壽
				{
					glColor4f(1, 1, 1, 1);
					glutWireCone(size / 2, size * 3, 4, 1);
					glColor4f(0, 0, 1, 1);
					glutSolidCone(size / 2, size * 3, 4, 1);
				}
				glPopMatrix();

				glRotatef(-180, 1, 0, 0);
				glColor4f(1, 1, 1, 1);
				glutWireCone(size / 2, size * 3, 4, 1);
				glColor4f(0, 0, 1, 1);
				glutSolidCone(size / 2, size * 3, 4, 1);
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
}