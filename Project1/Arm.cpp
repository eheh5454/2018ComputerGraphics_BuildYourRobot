#include "stdafx.h"
#include "Arm.h"

Arm::Arm(float size) :size{ size }
{
	arm_leg_angle = 0;
	s_angle = 0;
	m_gun = new Gun(size/3);
	m_sword = new Sword(size / 2);
}
Arm::~Arm()
{

}
float Arm::GetSize()
{
	return size;
}
void Arm::Update(float arm_leg_angle)
{
	this->arm_leg_angle = arm_leg_angle;
}
void Arm::AttackUpdate(float angle)
{
	this->s_angle = angle;
}
void Arm::Draw(int num)
{
	switch (num)
	{
	case 1:
		glPushMatrix();//¾î±ú
		{
			glTranslatef(-(3 * size / 2), size * 4, 0);
			glRotatef(-arm_leg_angle, 1, 0, 0);//¾î±ú±îÁö ÇÔ²² ¿òÁ÷ÀÌ°Ô
			glPushMatrix();
			{
				glPushMatrix();//°üÀý
				{
					glTranslatef(-size / 3, -size * 2 / 3, 0);
					glPushMatrix();//ÆÈ
					{
						glTranslatef(0, -size / 2, 0);
						glPushMatrix();
						{
							glTranslatef(0, -size * 2 / 3, 0);
							glPushMatrix();//¼Õ
							{
								glTranslatef(0, -size / 4, 0);
								glColor4f(1.f, 1.f, 1.f, 1.f);
								glutSolidCube(size / 1.5);

							}
							glPopMatrix();
							glColor4f(0, 0.3, 0.3, 1);
							glScalef(1, 1.5, 1);
							glutSolidCube(size / 3);
						}
						glPopMatrix();
						glScalef(1, 2, 1);
						glColor4f(0.f, 0.f, 1.f, 1.f);
						glutWireCube(size / 2);
						glColor4f(1.f, 1.f, 1.f, 1.f);
						glutSolidCube(size / 2);
					}
					glPopMatrix();
					glColor4f(0, 0.3, 0.3, 1);
					glScalef(1, 2, 1);
					glutSolidCube(size / 3);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glRotatef(-40, 0, 0, 1);
			glPushMatrix();
			{
				glPushMatrix();//¾î±ú»ÏÁ·
				{
					glTranslatef(-size * 2 / 3, 0, -size / 1.5);
					glRotatef(60, 0, 0, 1);
					glColor4f(1.f, 1.f, 1.f, 1.f);
					glutSolidCylinder(size / 1.5, size*1.5, 3, size);
				}
				glPopMatrix();
				glScalef(1, 1.05, 1.5);
				glPushMatrix();
				{
					glColor4f(0, 0, 1, 1);
					glutWireCube(size);
				}
				glPopMatrix();
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glutSolidCube(size);
				//glScalef(0.5, 1, 1);
			}
			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();//¾î±ú
		{
			glTranslatef((3 * size / 2), size * 4, 0);
			//glRotatef(arm_leg_angle, 1, 0, 0);//¾î±ú±îÁö ÇÔ²² ¿òÁ÷ÀÌ°Ô
			if (now_game_state == start_game)
			{
				if (!s_or_g)
				{
					glRotatef(90, 1, 0, 0);
				}
				else
				{
					glRotatef(s_angle, 1, 0, 0);
				}
			}
			glPushMatrix();
			{
				glPushMatrix();//°üÀý
				{
					glTranslatef(size / 3, -size * 2 / 3, 0);
					glPushMatrix();//ÆÈ
					{
						glTranslatef(0, -size / 2, 0);
						glPushMatrix();
						{
							glTranslatef(0, -size * 2 / 3, 0);
							glPushMatrix();//¼Õ
							{
								glTranslatef(0, -size / 4, 0);
								glColor4f(1.f, 1.f, 1.f, 1.f);
								glutSolidCube(size / 1.5);

								glPushMatrix();
								{
									if (now_game_state == start_game)
									{
										if (s_or_g)
										{
											glRotatef(-180, 0, 1, 0);
											m_sword->DrawSword();
										}
										else
										{
											if (player_view == 1)
											{
												glTranslatef(-size, size, 0);
												glRotatef(-90, 0, 1, 0);
												glRotatef(90, 0, 0, 1);
												m_gun->DrawGun();
											}
											else
											{
												glRotatef(-90, 0, 1, 0);
												glRotatef(90, 0, 0, 1);
												glTranslatef(-size, size, 0);
												m_gun->DrawGun();
											}
										}
									}
								}
								glPopMatrix();
							}
							glPopMatrix();
							glColor4f(0, 0.3, 0.3, 1);
							glScalef(1, 1.5, 1);
							glutSolidCube(size / 3);
						}
						glPopMatrix();
						glScalef(1, 2, 1);
						glColor4f(0.f, 0.f, 1.f, 1.f);
						glutWireCube(size / 2);
						glColor4f(1.f, 1.f, 1.f, 1.f);
						glutSolidCube(size / 2);
					}
					glPopMatrix();
					glColor4f(0, 0.3, 0.3, 1);
					glScalef(1, 2, 1);
					glutSolidCube(size / 3);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glRotatef(40, 0, 0, 1);
			glPushMatrix();//ÆÈ
			{
				glPushMatrix();//¾î±ú»ÏÁ·
				{
					glColor4f(1.f, 1.f, 1.f, 1.f);
					glTranslatef(size * 2 / 3, 0, -size / 1.5);
					glRotatef(0, 0, 0, 1);
					glutSolidCylinder(size / 1.5, size*1.5, 3, size);
				}
				glPopMatrix();
				glScalef(1, 1.05, 1.5);
				glPushMatrix();
				{
					glColor4f(0, 0, 1, 1);
					glutWireCube(size);
				}
				glPopMatrix();
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glutSolidCube(size);
				//glScalef(0.5, 1, 1);
			}
			glPopMatrix();
		}
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();//¾î±ú
		{
			glTranslatef(-(3 * size / 2), size * 4, 0);
			glRotatef(-arm_leg_angle, 1, 0, 0);//¾î±ú±îÁö ÇÔ²² ¿òÁ÷ÀÌ°Ô
			glPushMatrix();
			{
				glPushMatrix();//°üÀý
				{
					glTranslatef(-size / 3, -size * 2 / 3, 0);
					glPushMatrix();//ÆÈ
					{
						glTranslatef(0, -size / 2, 0);
						glPushMatrix();
						{
							glTranslatef(0, -size * 2 / 3, 0);
							glPushMatrix();//¼Õ
							{
								glTranslatef(0, -size / 4, 0);
								glColor4f(1.f, 1.f, 1.f, 1.f);
								glutSolidCube(size / 1.5);

							}
							glPopMatrix();
							glColor4f(1, 0, 0, 1);
							glScalef(1, 1.5, 1);
							glutSolidCube(size / 3);
						}
						glPopMatrix();
						glScalef(1, 2, 1);
						glColor4f(1, 0, 0, 1);
						glutWireCube(size / 2);
						glColor4f(1.f, 1.f, 1.f, 1.f);
						glutSolidCube(size / 2);
					}
					glPopMatrix();
					glColor4f(1, 0, 0, 1);
					glScalef(1, 2, 1);
					glutSolidCube(size / 3);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glRotatef(-40, 0, 0, 1);
			glPushMatrix();
			{
				glScalef(1, 1.05, 1.5);
				glPushMatrix();
				{
					glColor4f(1, 0, 0, 1);
					glutWireCube(size);
				}
				glPopMatrix();
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glutSolidCube(size);
				//glScalef(0.5, 1, 1);
			}
			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();//¾î±ú
		{
			glTranslatef((3 * size / 2), size * 4, 0);
			//glRotatef(arm_leg_angle, 1, 0, 0);//¾î±ú±îÁö ÇÔ²² ¿òÁ÷ÀÌ°Ô
			if (now_game_state == start_game)
			{
				if (!s_or_g)
				{
					glRotatef(90, 1, 0, 0);
				}
				else
				{
					glRotatef(s_angle, 1, 0, 0);
				}
			}
			glPushMatrix();
			{
				glPushMatrix();//°üÀý
				{
					glTranslatef(size / 3, -size * 2 / 3, 0);
					glPushMatrix();//ÆÈ
					{
						glTranslatef(0, -size / 2, 0);
						glPushMatrix();
						{
							glTranslatef(0, -size * 2 / 3, 0);
							glPushMatrix();//¼Õ
							{
								glTranslatef(0, -size / 4, 0);
								glColor4f(1.f, 1.f, 1.f, 1.f);
								glutSolidCube(size / 1.5);

								glPushMatrix();
								{
									if (now_game_state == start_game)
									{
										if (s_or_g)
										{
											glRotatef(-180, 0, 1, 0);
											m_sword->DrawSword();
										}
										else
										{
											if (player_view == 1)
											{
												glTranslatef(-size, size, 0);
												glRotatef(-90, 0, 1, 0);
												glRotatef(90, 0, 0, 1);
												m_gun->DrawGun();
											}
											else
											{
												glRotatef(-90, 0, 1, 0);
												glRotatef(90, 0, 0, 1);
												glTranslatef(-size, size, 0);
												m_gun->DrawGun();
											}
										}
									}
								}
								glPopMatrix();
							}
							glPopMatrix();
							glColor4f(1, 0, 0, 1);
							glScalef(1, 1.5, 1);
							glutSolidCube(size / 3);
						}
						glPopMatrix();
						glScalef(1, 2, 1);
						glColor4f(1, 0, 0, 1);
						glutWireCube(size / 2);
						glColor4f(1.f, 1.f, 1.f, 1.f);
						glutSolidCube(size / 2);
					}
					glPopMatrix();
					glColor4f(1, 0, 0, 1);
					glScalef(1, 2, 1);
					glutSolidCube(size / 3);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glRotatef(40, 0, 0, 1);
			glPushMatrix();//ÆÈ
			{
				glScalef(1, 1.05, 1.5);
				glPushMatrix();
				{
					glColor4f(1, 0, 0, 1);
					glutWireCube(size);
				}
				glPopMatrix();
				glColor4f(1.f, 1.f, 1.f, 1.f);
				glutSolidCube(size);
				//glScalef(0.5, 1, 1);
			}
			glPopMatrix();
		}
		glPopMatrix();
		break;
	case 3:
		glPushMatrix();//¾î±ú
		{
			glTranslatef(-(3 * size / 2), size * 4, 0);
			glRotatef(-arm_leg_angle, 1, 0, 0);//¾î±ú±îÁö ÇÔ²² ¿òÁ÷ÀÌ°Ô
			glPushMatrix();
			{
				glPushMatrix();//°üÀý
				{
					glTranslatef(-size / 3, -size * 2 / 3, 0);
					glPushMatrix();//ÆÈ
					{
						glTranslatef(0, -size / 2, 0);
						glPushMatrix();
						{
							glTranslatef(0, -size * 2 / 3, 0);
							glPushMatrix();//¼Õ
							{
								glTranslatef(0, -size / 4, 0);
								glColor4f(0, 0.3, 0.3, 1);
								glutSolidCube(size / 1.5);

							}
							glPopMatrix();
							glColor4f(0, 0.3, 0.3, 1);
							glScalef(1, 1.5, 1);
							glutSolidCube(size / 3);
						}
						glPopMatrix();
						glScalef(1, 2, 1);
						glColor4f(0, 0, 0, 1);
						glutWireCube(size / 2);
						glColor4f(0, 0.3, 0.3, 1);
						glutSolidCube(size / 2);
					}
					glPopMatrix();
					glColor4f(0, 0.3, 0.3, 1);
					glScalef(1, 2, 1);
					glutSolidCube(size / 3);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glRotatef(-40, 0, 0, 1);
			glPushMatrix();
			{
				glScalef(1, 1.05, 1.5);
				glPushMatrix();
				{
					glColor4f(0, 0, 0, 1);
					glutWireCube(size);
				}
				glPopMatrix();
				glColor4f(0, 0.3, 0.3, 1);
				glutSolidCube(size);
				//glScalef(0.5, 1, 1);
			}
			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();//¾î±ú
		{
			glTranslatef((3 * size / 2), size * 4, 0);
			//glRotatef(arm_leg_angle, 1, 0, 0);//¾î±ú±îÁö ÇÔ²² ¿òÁ÷ÀÌ°Ô
			if (now_game_state == start_game)
			{
				if (!s_or_g)
				{
					glRotatef(90, 1, 0, 0);
				}
				else
				{
					glRotatef(s_angle, 1, 0, 0);
				}
			}
			glPushMatrix();
			{
				glPushMatrix();//°üÀý
				{
					glTranslatef(size / 3, -size * 2 / 3, 0);
					glPushMatrix();//ÆÈ
					{
						glTranslatef(0, -size / 2, 0);
						glPushMatrix();
						{
							glTranslatef(0, -size * 2 / 3, 0);
							glPushMatrix();//¼Õ
							{
								glTranslatef(0, -size / 4, 0);
								glColor4f(0, 0.3, 0.3, 1);
								glutSolidCube(size / 1.5);

								glPushMatrix();
								{
									if (now_game_state == start_game)
									{
										if (s_or_g)
										{
											glRotatef(-180, 0, 1, 0);
											m_sword->DrawSword();
										}
										else
										{
											if (player_view == 1)
											{
												glTranslatef(-size, size, 0);
												glRotatef(-90, 0, 1, 0);
												glRotatef(90, 0, 0, 1);
												m_gun->DrawGun();
											}
											else
											{
												glRotatef(-90, 0, 1, 0);
												glRotatef(90, 0, 0, 1);
												glTranslatef(-size, size, 0);
												m_gun->DrawGun();
											}
										}
									}
								}
								glPopMatrix();
							}
							glPopMatrix();
							glColor4f(0, 0.3, 0.3, 1);
							glScalef(1, 1.5, 1);
							glutSolidCube(size / 3);
						}
						glPopMatrix();
						glScalef(1, 2, 1);
						glColor4f(0, 0, 0, 1);
						glutWireCube(size / 2);
						glColor4f(0, 0.3, 0.3, 1);
						glutSolidCube(size / 2);
					}
					glPopMatrix();
					glColor4f(0, 0.3, 0.3, 1);
					glScalef(1, 2, 1);
					glutSolidCube(size / 3);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glRotatef(40, 0, 0, 1);
			glPushMatrix();//ÆÈ
			{
				glScalef(1, 1.05, 1.5);
				glPushMatrix();
				{
					glColor4f(0, 0, 0, 1);
					glutWireCube(size);
				}
				glPopMatrix();
				glColor4f(0, 0.3, 0.3, 1);
				glutSolidCube(size);
				//glScalef(0.5, 1, 1);
			}
			glPopMatrix();
		}
		glPopMatrix();

		break;
	}
	
}