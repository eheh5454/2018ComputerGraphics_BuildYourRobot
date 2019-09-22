#include "stdafx.h"
#include "Head.h"

Head::Head(float size) : size{ size }
{

}
Head::~Head()
{

}
float Head::GetSize()
{
	return size;
}
void Head::Draw(int num)
{
	switch (num)
	{
	case 1:
		glPushMatrix();
		{
			if (now_game_state != select_model)
				glTranslatef(0, size * 9 / 2 + (size / 2), 0);
			glPushMatrix();//»Ô
			{
				glColor4f(1, 1, 0, 1);
				glTranslatef(-size / 5, size / 2, -size);
				glRotatef(30, 0, 0, 1);
				glRotatef(-60, 1, 0, 0);
				glutSolidCone(size / 4, size * 2, 3, size);
				glPushMatrix();
				{
					glColor4f(1, 1, 0, 1);
					glRotatef(-180, 1, 0, 0);
					glutSolidCone(size / 4, size / 1.5, 3, size);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//»Ô
			{
				glColor4f(1, 1, 0, 1);
				glTranslatef(size / 5, size / 2, -size);
				glRotatef(-30, 0, 0, 1);
				glRotatef(-60, 1, 0, 0);
				glutSolidCone(size / 4, size * 2, 3, size);
				glPushMatrix();
				{
					glColor4f(1, 1, 0, 1);
					glRotatef(-180, 1, 0, 0);
					glutSolidCone(size / 4, size / 1.5, 3, size);
				}
				glPopMatrix();
			}
			glPopMatrix();

			glPushMatrix();//´«
			{
				glTranslatef(size / 4, 0, -size);
				glRotatef(-60, 0, 0, 1);
				glRotatef(-90, 1, 0, 0);
				glPushMatrix();//³ë¶õ ´«µ¿ÀÚ
				{
					glColor4f(1, 1, 0, 1);
					glTranslatef(0, size / 8, 0);
					glutSolidCone(size / 4, size / 4, 3, size);
					glRotatef(-200, 1, 0, 0);
					glPushMatrix();//³ë¶õ ´«µ¿ÀÚ
					{
						glColor4f(1, 1, 0, 1);
						glutSolidCone(size / 4, size / 6, 3, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
				glPushMatrix();//´«À§
				{
					glColor4f(1, 0.3, 0, 1);
					glutSolidCone(size / 4, size / 2, 3, size);
					glRotatef(-180, 1, 0, 0);
					glPushMatrix();//´«¾Æ·¡
					{
						glutSolidCone(size / 4, size / 5, 3, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//´«
			{
				glTranslatef(-size / 4, 0, -size);
				glRotatef(60, 0, 0, 1);
				glRotatef(-90, 1, 0, 0);
				glPushMatrix();//³ë¶õ ´«µ¿ÀÚ
				{
					glColor4f(1, 1, 0, 1);
					glTranslatef(0, size / 8, 0);
					glutSolidCone(size / 4, size / 4, 3, size);
					glRotatef(-200, 1, 0, 0);
					glPushMatrix();//³ë¶õ ´«µ¿ÀÚ
					{
						glColor4f(1, 1, 0, 1);
						glutSolidCone(size / 4, size / 6, 3, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
				glColor4f(1, 0.3, 0, 1);
				glutSolidCone(size / 4, size / 2, 3, size);
				glRotatef(-180, 1, 0, 0);
				glutSolidCone(size / 4, size / 5, 3, size);

			}
			glPopMatrix();


			glPushMatrix();//¸Ó¸® ¾ç¿·
			{
				glTranslatef(-size / 1.5, -size / 2, 0);
				glPushMatrix();
				{
					glTranslatef(0, size / 4, -size / 2.5);
					glColor4f(0, 0.3, 0.3, 1);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
				}
				glPopMatrix();
				glScalef(0.7, 2, 2);
				glColor4f(1, 1, 1, 1);
				glutSolidCube(size / 2);
			}
			glPopMatrix();
			glPushMatrix();//¸Ó¸® ¾ç¿·
			{
				glTranslatef(size / 1.5, -size / 2, 0);
				glPushMatrix();
				{
					glTranslatef(0, size / 4, -size / 2.5);
					glColor4f(0, 0.3, 0.3, 1);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
				}
				glPopMatrix();
				glScalef(0.7, 2, 2);
				glColor4f(1, 1, 1, 1);
				glutSolidCube(size / 2);
			}
			glPopMatrix();

			glColor4f(1, 1, 1, 1);//¿©±â¼­ºÎÅÍ ¾ó±¼
			glScalef(0.75, 1, 1);
			glutSolidSphere(size, size, size);//¸Ó¸®

			glPushMatrix();//¸¶½ºÅ©
			{
				glTranslatef(0, -size / 2, -size);
				glColor4f(1, 1, 1, 1);
				glutSolidCylinder(size / 3, size / 4, 6, size);
				glColor4f(0, 0.3, 0.3, 1);
				glutWireCylinder(size / 3, size / 4, 6, 3);
				glPushMatrix();//¸¶½ºÅ© À§
				{
					glRotatef(180, 1, 0, 0);
					glColor4f(0, 0.3, 0.3, 1);
					glutWireCone(size / 3, size / 8, 6, 1);
				}
				glPopMatrix();
				glPushMatrix();
				{
					glColor4f(1, 0, 0, 1);
					glTranslatef(0, -size / 3, 0);
					glPushMatrix();
					{
						glTranslatef(0, size / 4, 0);
						glutSolidCube(size / 4);
					}
					glPopMatrix();
					glRotatef(-45, 1, 0, 0);
					glRotatef(45, 0, 0, 1);
					glutSolidCone(size / 4, size / 2, 4, 1);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();
			{
				glColor4f(1, 1, 1, 1);
				glTranslatef(0, size / 3, 0);
				glScalef(0.5, 1, 0.8);
				glutSolidSphere(size, size, size);
				glTranslatef(0, 0, -size / 8);
				glColor4f(0, 0, 1, 1);
				glScalef(1, 1, 1.75);
				glutSolidCube(size);
			}
			glPopMatrix();
		}
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		{
			if (now_game_state != select_model)
				glTranslatef(0, size * 9 / 2 + (size / 2), 0);
			glPushMatrix();//»Ô
			{
				glColor4f(1, 0, 0, 1);
				glTranslatef(-size / 5, size / 2, -size);
				glRotatef(30, 0, 0, 1);
				glRotatef(-60, 1, 0, 0);
				glutSolidCone(size / 4, size * 2, 3, size);
				glPushMatrix();
				{
					glColor4f(1, 1, 0, 1);
					glRotatef(-180, 1, 0, 0);
					glutSolidCone(size / 4, size / 1.5, 3, size);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//»Ô
			{
				glColor4f(1, 0, 0, 1);
				glTranslatef(size / 5, size / 2, -size);
				glRotatef(-30, 0, 0, 1);
				glRotatef(-60, 1, 0, 0);
				glutSolidCone(size / 4, size * 2, 3, size);
				glPushMatrix();
				{
					glColor4f(1, 1, 0, 1);
					glRotatef(-180, 1, 0, 0);
					glutSolidCone(size / 4, size / 1.5, 3, size);
				}
				glPopMatrix();
			}
			glPopMatrix();

			glPushMatrix();//´«
			{
				glTranslatef(size / 4, 0, -size);
				glRotatef(-60, 0, 0, 1);
				glRotatef(-90, 1, 0, 0);
				glPushMatrix();//´«À§
				{
					glColor4f(0, 0, 0, 1);
					glutSolidCone(size / 4, size / 2, 3, size);
					glRotatef(-180, 1, 0, 0);
					glPushMatrix();//´«¾Æ·¡
					{
						glutSolidCone(size / 4, size / 5, 3, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//´«
			{
				glTranslatef(-size / 4, 0, -size);
				glRotatef(60, 0, 0, 1);
				glRotatef(-90, 1, 0, 0);
				glColor4f(0, 0, 0, 1);
				glutSolidCone(size / 4, size / 2, 3, size);
				glRotatef(-180, 1, 0, 0);
				glutSolidCone(size / 4, size / 5, 3, size);

			}
			glPopMatrix();


			glPushMatrix();//¸Ó¸® ¾ç¿·
			{
				glTranslatef(-size / 1.5, -size / 2, 0);
				glPushMatrix();
				{
					glTranslatef(0, size / 4, -size / 2.5);
					glColor4f(0, 0.3, 0.3, 1);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
				}
				glPopMatrix();
				glScalef(0.7, 2, 2);
				glColor4f(1, 0, 0, 1);
				glutSolidCube(size / 2);
			}
			glPopMatrix();
			glPushMatrix();//¸Ó¸® ¾ç¿·
			{
				glTranslatef(size / 1.5, -size / 2, 0);
				glPushMatrix();
				{
					glTranslatef(0, size / 4, -size / 2.5);
					glColor4f(0, 0.3, 0.3, 1);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
				}
				glPopMatrix();
				glScalef(0.7, 2, 2);
				glColor4f(1, 0, 0, 1);
				glutSolidCube(size / 2);
			}
			glPopMatrix();

			glColor4f(1, 1, 1, 1);//¿©±â¼­ºÎÅÍ ¾ó±¼
			glScalef(0.75, 1, 1);
			glutSolidSphere(size, size, size);//¸Ó¸®

			glPushMatrix();//¸¶½ºÅ©
			{
				glTranslatef(0, -size / 2, -size);
				glColor4f(1, 1, 1, 1);
				glutSolidCylinder(size / 3, size / 4, 6, size);
				glColor4f(0, 0.3, 0.3, 1);
				glutWireCylinder(size / 3, size / 4, 6, 3);
				glPushMatrix();//¸¶½ºÅ© À§
				{
					glRotatef(180, 1, 0, 0);
					glColor4f(0, 0.3, 0.3, 1);
					glutWireCone(size / 3, size / 8, 6, 1);
				}
				glPopMatrix();
				glPushMatrix();
				{
					glColor4f(1, 0, 0, 1);
					glTranslatef(0, -size / 3, 0);
					glPushMatrix();
					{
						glTranslatef(0, size / 4, 0);
						glutSolidCube(size / 4);
					}
					glPopMatrix();
					glRotatef(-45, 1, 0, 0);
					glRotatef(45, 0, 0, 1);
					glutSolidCone(size / 4, size / 2, 4, 1);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();
			{
				glColor4f(1, 0, 0, 1);
				glTranslatef(0, size / 3, 0);
				glScalef(0.5, 1, 0.8);
				glutSolidSphere(size, size, size);
				glTranslatef(0, 0, -size / 8);
				glColor4f(1, 0, 0, 1);
				glScalef(1, 1, 1.75);
				glutSolidCube(size);
			}
			glPopMatrix();
		}
		glPopMatrix();
		break;
	case 3:
		glPushMatrix();
		{
			if (now_game_state != select_model)
				glTranslatef(0, size * 9 / 2 + (size / 2), 0);
			glPushMatrix();//»Ô
			{
				glColor4f(0.25, 0.25, 0.25, 1);
				glTranslatef(-size / 5, size / 2, -size);
				glRotatef(30, 0, 0, 1);
				glRotatef(-60, 1, 0, 0);
				glutSolidCone(size / 4, size * 2, 3, size);
				glPushMatrix();
				{
					glColor4f(0.25, 0.25, 0.25, 1);
					glRotatef(-180, 1, 0, 0);
					glutSolidCone(size / 4, size / 1.5, 3, size);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//»Ô
			{
				glColor4f(0.25, 0.25, 0.25, 1);
				glTranslatef(size / 5, size / 2, -size);
				glRotatef(-30, 0, 0, 1);
				glRotatef(-60, 1, 0, 0);
				glutSolidCone(size / 4, size * 2, 3, size);
				glPushMatrix();
				{
					glColor4f(0.25, 0.25, 0.25, 1);
					glRotatef(-180, 1, 0, 0);
					glutSolidCone(size / 4, size / 1.5, 3, size);
				}
				glPopMatrix();
			}
			glPopMatrix();

			glPushMatrix();//´«
			{
				glTranslatef(size / 4, 0, -size);
				glRotatef(-60, 0, 0, 1);
				glRotatef(-90, 1, 0, 0);
				glPushMatrix();//´«À§
				{
					glColor4f(0, 0, 0, 1);
					glutSolidCone(size / 4, size / 2, 3, size);
					glRotatef(-180, 1, 0, 0);
					glPushMatrix();//´«¾Æ·¡
					{
						glutSolidCone(size / 4, size / 5, 3, size);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();//´«
			{
				glTranslatef(-size / 4, 0, -size);
				glRotatef(60, 0, 0, 1);
				glRotatef(-90, 1, 0, 0);
				glColor4f(0, 0, 0, 1);
				glutSolidCone(size / 4, size / 2, 3, size);
				glRotatef(-180, 1, 0, 0);
				glutSolidCone(size / 4, size / 5, 3, size);

			}
			glPopMatrix();


			glPushMatrix();//¸Ó¸® ¾ç¿·
			{
				glTranslatef(-size / 1.5, -size / 2, 0);
				glPushMatrix();
				{
					glTranslatef(0, size / 4, -size / 2.5);
					glColor4f(0, 0.3, 0.3, 1);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
				}
				glPopMatrix();
				glScalef(0.7, 2, 2);
				glColor4f(0.5, 0.5, 0.5, 1);
				glutSolidCube(size / 2);
			}
			glPopMatrix();
			glPushMatrix();//¸Ó¸® ¾ç¿·
			{
				glTranslatef(size / 1.5, -size / 2, 0);
				glPushMatrix();
				{
					glTranslatef(0, size / 4, -size / 2.5);
					glColor4f(0, 0.3, 0.3, 1);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
					glTranslatef(0, -size / 4, 0);
					glutWireCube(size / 4);
				}
				glPopMatrix();
				glScalef(0.7, 2, 2);
				glColor4f(0.5, 0.5, 0.5, 1);
				glutSolidCube(size / 2);
			}
			glPopMatrix();

			glColor4f(0.5, 0.5, 0.5, 1);//¿©±â¼­ºÎÅÍ ¾ó±¼
			glScalef(0.75, 1, 1);
			glutSolidSphere(size, size, size);//¸Ó¸®

			glPushMatrix();//¸¶½ºÅ©
			{
				glTranslatef(0, -size / 2, -size);
				glColor4f(0.5, 0.5, 0.5, 1);
				glutSolidCylinder(size / 3, size / 4, 6, size);
				glColor4f(0.5, 0.5, 0.5, 1);
				glutWireCylinder(size / 3, size / 4, 6, 3);
				glPushMatrix();//¸¶½ºÅ© À§
				{
					glRotatef(180, 1, 0, 0);
					glColor4f(0, 0.3, 0.3, 1);
					glutWireCone(size / 3, size / 8, 6, 1);
				}
				glPopMatrix();
				glPushMatrix();
				{
					glColor4f(0.5, 0.5, 0.5, 1);
					glTranslatef(0, -size / 3, 0);
					glPushMatrix();
					{
						glTranslatef(0, size / 4, 0);
						glutSolidCube(size / 4);
					}
					glPopMatrix();
					glRotatef(-45, 1, 0, 0);
					glRotatef(45, 0, 0, 1);
					glutSolidCone(size / 4, size / 2, 4, 1);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glPushMatrix();
			{
				glColor4f(0.5, 0.5, 0.5, 1);
				glTranslatef(0, size / 3, 0);
				glScalef(0.5, 1, 0.8);
				glutSolidSphere(size, size, size);
				glTranslatef(0, 0, -size / 8);
				glColor4f(0.5, 0.5, 0.5, 1);
				glScalef(1, 1, 1.75);
				glutSolidCube(size);
			}
			glPopMatrix();
		}
		glPopMatrix();
		break;
	}
	
}

